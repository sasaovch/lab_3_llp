cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(Client)

# Find protobuf-c and make it required (on Ubuntu it is libprotobuf-c)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PROTOBUF_C REQUIRED libprotobuf-c)

# Find flex and bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# List all protobuf object names
set(PROTO_OBJECTS
    element
    entity
    filter
    iterator
    operation
    request
)

set(BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Generate .c and .h files for each object in the proto directory
foreach(object ${PROTO_OBJECTS})
    list(APPEND PROTO_GENERATED_SRC
        ${BINARY_DIR}/${object}.pb-c.c
        ${BINARY_DIR}/${object}.pb-c.h
    )
    add_custom_command(
        OUTPUT ${BINARY_DIR}/${object}.pb-c.c ${BINARY_DIR}/${object}.pb-c.h
        COMMAND protoc-c --c_out=${BINARY_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR}/proto ${CMAKE_CURRENT_SOURCE_DIR}/proto/${object}.proto
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/proto/${object}.proto
    )
endforeach()

# Flex and Bison file generation
FLEX_TARGET(GraphQLScanner parser/graphql.l ${BINARY_DIR}/graphql_lexer.c)
BISON_TARGET(GraphQLParser parser/graphql.y ${BINARY_DIR}/graphql_parser.c)
ADD_FLEX_BISON_DEPENDENCY(GraphQLScanner GraphQLParser)

# Collect all .h and .c files from the directories in your project root (recursively)
file(GLOB_RECURSE PARSER_HEADERS "*.h" EXCLUDE build/*)
file(GLOB_RECURSE PARSER_SOURCES "*.c" EXCLUDE build/*)

# Remove the Flex and Bison generated files from the collected sources to avoid duplicates
# list(REMOVE_ITEM PARSER_SOURCES ${BISON_GraphQLParser_OUTPUTS} ${FLEX_GraphQLScanner_OUTPUTS})

# Add the Flex and Bison outputs to the sources list
list(APPEND PARSER_SOURCES ${BISON_GraphQLParser_OUTPUTS} ${FLEX_GraphQLScanner_OUTPUTS})

# Create the parser library
add_library(parser ${PARSER_SOURCES} ${PARSER_HEADERS})
target_include_directories(parser PUBLIC ${BINARY_DIR})

# Create the parser library
# add_library(parser ${BISON_GraphQLParser_OUTPUTS} ${FLEX_GraphQLScanner_OUTPUTS} parser/ast.c parser/ast.h)
# target_include_directories(parser PUBLIC ${BINARY_DIR})

# Function to build each program (serialize and deserialize)
function(build_program program_name main_src)
    add_executable(${program_name} ${CMAKE_CURRENT_SOURCE_DIR}/src/${main_src} ${PROTO_GENERATED_SRC})
    target_include_directories(${program_name} PUBLIC
                               "${PROJECT_BINARY_DIR}"
                               ${PROTOBUF_C_INCLUDE_DIRS}
    )
    target_link_libraries(${program_name} ${PROTOBUF_C_LIBRARIES} parser)
endfunction()

# Build the serialize and deserialize programs
# build_program(serialize main_serialize.c)
build_program(deser deser.c)
build_program(main main.c)
build_program(${PROJECT_NAME} main.c)
