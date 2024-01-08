/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: filter.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "filter.pb-c.h"
void   filter_message__init
                     (FilterMessage         *message)
{
  static const FilterMessage init_value = FILTER_MESSAGE__INIT;
  *message = init_value;
}
size_t filter_message__get_packed_size
                     (const FilterMessage *message)
{
  assert(message->base.descriptor == &filter_message__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t filter_message__pack
                     (const FilterMessage *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &filter_message__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t filter_message__pack_to_buffer
                     (const FilterMessage *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &filter_message__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
FilterMessage *
       filter_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (FilterMessage *)
     protobuf_c_message_unpack (&filter_message__descriptor,
                                allocator, len, data);
}
void   filter_message__free_unpacked
                     (FilterMessage *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &filter_message__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor filter_message__field_descriptors[4] =
{
  {
    "field",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(FilterMessage, field),
    &field_proto__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "value",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(FilterMessage, value),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "type",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(FilterMessage, type),
    &compare_type_proto__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "type_element",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(FilterMessage, type_element),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned filter_message__field_indices_by_name[] = {
  0,   /* field[0] = field */
  2,   /* field[2] = type */
  3,   /* field[3] = type_element */
  1,   /* field[1] = value */
};
static const ProtobufCIntRange filter_message__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor filter_message__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "FilterMessage",
  "FilterMessage",
  "FilterMessage",
  "",
  sizeof(FilterMessage),
  4,
  filter_message__field_descriptors,
  filter_message__field_indices_by_name,
  1,  filter_message__number_ranges,
  (ProtobufCMessageInit) filter_message__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue field_proto__enum_values_by_number[4] =
{
  { "ID", "FIELD_PROTO__ID", 0 },
  { "NAME", "FIELD_PROTO__NAME", 1 },
  { "VALUE", "FIELD_PROTO__VALUE", 2 },
  { "TYPE", "FIELD_PROTO__TYPE", 3 },
};
static const ProtobufCIntRange field_proto__value_ranges[] = {
{0, 0},{0, 4}
};
static const ProtobufCEnumValueIndex field_proto__enum_values_by_name[4] =
{
  { "ID", 0 },
  { "NAME", 1 },
  { "TYPE", 3 },
  { "VALUE", 2 },
};
const ProtobufCEnumDescriptor field_proto__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "FieldProto",
  "FieldProto",
  "FieldProto",
  "",
  4,
  field_proto__enum_values_by_number,
  4,
  field_proto__enum_values_by_name,
  1,
  field_proto__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const ProtobufCEnumValue compare_type_proto__enum_values_by_number[5] =
{
  { "GREATER", "COMPARE_TYPE_PROTO__GREATER", 0 },
  { "LOWER", "COMPARE_TYPE_PROTO__LOWER", 1 },
  { "EQUAL", "COMPARE_TYPE_PROTO__EQUAL", 2 },
  { "NOT_EQUAL", "COMPARE_TYPE_PROTO__NOT_EQUAL", 3 },
  { "ALL", "COMPARE_TYPE_PROTO__ALL", 4 },
};
static const ProtobufCIntRange compare_type_proto__value_ranges[] = {
{0, 0},{0, 5}
};
static const ProtobufCEnumValueIndex compare_type_proto__enum_values_by_name[5] =
{
  { "ALL", 4 },
  { "EQUAL", 2 },
  { "GREATER", 0 },
  { "LOWER", 1 },
  { "NOT_EQUAL", 3 },
};
const ProtobufCEnumDescriptor compare_type_proto__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "CompareTypeProto",
  "CompareTypeProto",
  "CompareTypeProto",
  "",
  5,
  compare_type_proto__enum_values_by_number,
  5,
  compare_type_proto__enum_values_by_name,
  1,
  compare_type_proto__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
