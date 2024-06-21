#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "utils.h"

typedef struct TreeNode {
    struct Data* data;
    struct TreeNode* left;
    struct TreeNode* right;
} TNODE;
typedef TNODE* TREE;



TNODE* createNode(DATA* __data);
int getSize(TREE __root);
TNODE* getNode(TREE __root);
TNODE* insert(TREE __root);
TNODE* search(TREE __root);
TNODE* traverse(TREE __root); //Tree Traversal: PreOrder, InOrder,
TNODE* remove(TREE __root);



#endif