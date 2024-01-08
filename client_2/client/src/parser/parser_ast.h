#include "ast.h"
#include "../build/operation.pb-c.h"
#include "../build/filter.pb-c.h"
#include "../build/element.pb-c.h"
#include "../build/request.pb-c.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Operation get_operation_type(Node *node);
Filter *get_filter(Node *node);
void traverse_tree(Node* node, Element* element);

Request *parse_ast(Node *node);