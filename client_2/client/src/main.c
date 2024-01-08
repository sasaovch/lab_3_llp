#include <stdio.h>
#include <stdlib.h>
#include "./parser/ast.h"
#include "./parser/parser_ast.h"
#include "../build/request.pb-c.h"
#include "./net/socket.h"
#include "utils/io_utils.h"

#define YY_STDINIT
#define YYSTYPE double
extern YYSTYPE yylval;

extern int yyparse(void);

extern FILE *yyin;

int main(int argc, char **argv) {
    // --argc;
    // ++argv;
    // if (argc == 0) {
    //     printf("Usage: ./parser <file.graphql>\n");
    //     return 1;
    // }
    
    // FILE *file = fopen(argv[0], "r");
    // if (file == NULL) {
    //     printf("Unable to open file: %s\n", argv[0]);
    //     return 1;
    // }
    
    char *filePath = "../simple";
    yyin = fopen(filePath, "r");
    if (!yyin) {
        printf("Can't open file %s\n", filePath);
        return 1;
    }
    yyparse();
    fclose(yyin);
    printRoot();
    Request *request = parse_ast(&root);
    printf("Done\n");
    void *buf;
    unsigned len;

    len = request__get_packed_size(request);
    buf = malloc(len);
    request__pack(request, buf);


    fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
    
    const char* filename = "output.txt";

    // Open the file in write mode
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error: unable to open file for writing.\n");
        return 1;
    }

    // Write data into the file using fwrite
    size_t bytes_written = fwrite (buf, len, 1, file);           // Write to stdout to allow direct command line piping
    if (bytes_written != 1) {
        perror("Error: unable to write the data to the file.\n");
        fclose(file); // Close the file
        return 1;
    }

    // Close the file
    fclose(file);

    printf("Successfully written %zu bytes to the file '%s'.\n", bytes_written, filename);

    int client_fd = init_socket();
    error_exit(client_fd, "Error to open socket");
    int status = connect_socket(client_fd, "1", 8080);
    error_exit(status, "Error to connect to address");
    status = send_to_socket(client_fd, len, buf);
    error_exit(status, "Error to send data to socket");
    close_socket(client_fd);

    free(buf); // Free the allocated serialized buffer
    return 0;
}

// int main(int argc, char *argv[]) {
//   --argc;
//   ++argv;
//   if (argc == 0) {
//     printf("Usage: ./parser <file.graphql>\n");
//     return 1;
//   }
  
//   FILE *file = fopen(argv[0], "r");
//   if (file == NULL) {
//     printf("Unable to open file: %s\n", argv[0]);
//     return 1;
//   }
//   yyin = file;
//   if (yyparse()) {
//     printf("Parsing failed\n");
//   }
// }