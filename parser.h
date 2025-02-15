#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct TreeNode {
    char *name;
    struct TreeNode **children;
    int num_children;
    char *value;
} TreeNode;

TreeNode* create_node(char *name, char *value, int num_children, ...);
void print_tree(TreeNode *node, int level);

#endif