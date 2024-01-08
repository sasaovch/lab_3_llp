#include "ast.h"
#include "../binary/operation.pb-c.h"
#include "../binary/filter.pb-c.h"
#include "../binary/request.pb-c.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

OperationProto get_operation_type(Node *node);
FilterMessage *get_filter(Node *node);

RequestMessage *parse_ast(Node *node);
TypeOfElementProto get_element_type_for_query(Node *node) ;
void construct_element(Node* node, RequestMessage *request, TypeOfElementProto type) ;
void construct_node(Node *node, NodeMessage *element);
void construct_relationship(Node *node, RelationshipMessage *element);
void construct_property(Node *node, PropertyMessage *element);