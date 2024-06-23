#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "utils.h"

typedef struct TreeNode
{
    struct Data *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TNODE;
typedef TNODE *TREE;

TNODE *createTreeNode(DATA *__data);
int getSize(TREE __root);
TNODE *getNode(TREE __root);
TNODE *insert(TREE *__root, TNODE *__node);
void traverse(TREE __root); // Tree Traversal: PreOrder, InOrder,
TNODE *search(TREE __root, int __key);
TNODE *minTreeNode(TREE __root);
TNODE *remove(TREE __root, int __key);
void freeTree(TREE *__root);

#endif