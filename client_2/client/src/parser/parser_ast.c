#include "parser_ast.h"
#include "ast.h"
#include <stddef.h>
#include <stdlib.h>

Operation get_operation_type(Node *node) {
    Node *type = node->left->left->left->left->left->left;
    if (strcmp(type->value.str_val, "CreateNode") == 0) {
        printf("CreateNode \n");
        return OPERATION__CREATE_NODE;
    }
    return OPERATION__CREATE_ENTITY;
}

char *int_to_string(int num) {
    // Calculate the number of characters needed to represent the integer, including the null terminator
    int length = snprintf(NULL, 0, "%d", num) + 1;

    // Allocate memory for the string and convert the integer to a string using sprintf
    char *num_str = (char *)malloc(length * sizeof(char));
    sprintf(num_str, "%d", num);
    return num_str;
}

Filter *get_filter(Node *node) {
    Node *selection_set = node->left->left->left->right->left->right;
    Node *parent;
    Node *parent_parent;
    while(selection_set->left != NULL) {
        parent_parent = parent;
        parent = selection_set;
        selection_set = selection_set->left;
    }
    char *field = selection_set->value.str_val;
    char *value = int_to_string(parent_parent->right->left->right->left->value.int_val);

    Filter *f = (Filter *) malloc(sizeof(Filter));
    filter__init(f);
    f->field = FIELD__ID;
    f->value = value;
    f->type = COMPARE_TYPE__ALL;

    return f;
}

char *create_buff_string(const char *from) {
    size_t string_size = strlen(from);
    char *buff = (char *) malloc(sizeof(char) * string_size);
    strcpy(buff, from);
    return buff;
}

void traverse_tree(Node* node, Element* element) {
    if (node == NULL) {
        return;
    }

    traverse_tree(node->right, element);
    traverse_tree(node->left, element);

    if (node->type != JSON_ELEMENT) return;

    Node *field = node->left->left;
    Node *value = node->right->left;
    if (strcmp(field->value.str_val, "type") == 0) {
        char *buff = create_buff_string(value->value.str_val);
        element->type = buff;
    
    } else if (strcmp(field->value.str_val, "subject_id") == 0) {
        element->subject_id = value->value.int_val;
    
    } else if (strcmp(field->value.str_val, "subject_type") == 0) {
        element->subject_type = create_buff_string(value->value.str_val);

    } else if (strcmp(field->value.str_val, "child_id") == 0) {
        element->child_id = value->value.int_val;
    
    } else if (strcmp(field->value.str_val, "child_type") == 0) {
        element->child_type = create_buff_string(value->value.str_val);
    
    } else if (strcmp(field->value.str_val, "value") == 0) {
        element->value = create_buff_string(value->value.str_val);
    
    } else if (strcmp(field->value.str_val, "subject_name") == 0) {
        element->subject_name = create_buff_string(value->value.str_val);
        // size_t string_size = strlen(value->value.str_val);
        // char *buff = (char *) malloc(sizeof(char) * string_size);
        // strcpy(buff, value->value.str_val);
        // element->subject_name = buff;
    }
        //     break;
        // default:
        //     break;
    // }
}

Request *parse_ast(Node *node) {
    bool isEntity;
    Filter *filter;
    Operation operation = get_operation_type(node);
    switch (operation) {
        case OPERATION__CREATE_ENTITY:
        case OPERATION__DELETE_ENTITY:
            isEntity = true;
            break;
        default:
            isEntity = false;
    }
    // if (operation == OPERATION__DELETE_ENTITY ||
    //     operation == OPERATION__SELECT_NODE ||
    //     operation == OPERATION__UPDATE_NODE) {
            filter = get_filter(node);
        // }
    Element *element = (Element *) malloc(sizeof(Element));
    element__init(element);
    traverse_tree(node->right, element);
    printf("Done\n");
    Request *request = (Request *) malloc(sizeof(Request));
    request__init(request);
    request->operation = operation;
    request->isentity = isEntity;
    request->filter = filter;
    request->entity = NULL;
    request->element = element;

    return request;
}
