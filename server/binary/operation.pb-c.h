/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: operation.proto */

#ifndef PROTOBUF_C_operation_2eproto__INCLUDED
#define PROTOBUF_C_operation_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1005000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif




/* --- enums --- */

typedef enum _OperationProto {
  OPERATION_PROTO__CREATE_NODE = 0,
  OPERATION_PROTO__INSERT_NODE = 1,
  OPERATION_PROTO__UPDATE_NODE = 2,
  OPERATION_PROTO__SELECT_NODE = 3,
  OPERATION_PROTO__DELETE_NODE = 4,
  OPERATION_PROTO__CREATE_ENTITY = 5,
  OPERATION_PROTO__DELETE_ENTITY = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(OPERATION_PROTO)
} OperationProto;

/* --- messages --- */

/* --- per-message closures --- */


/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    operation_proto__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_operation_2eproto__INCLUDED */
