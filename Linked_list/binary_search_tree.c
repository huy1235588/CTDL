#include "binary_search_tree.h"

static int __getKey(TNODE* __node) {
    return __node->data->key;
}

static COMPARISON __compareKey(TNODE* __this, TNODE* __that) {
    COMPARISON comparison = EQUAL_TO;
    if (__getKey(__this) > __getKey(__that)) {
        comparison = GREATER_THAN; 
    } else if (__getKey(__this) < __getKey(__that)) {
        comparison = LESS_THAN; 
    }
    return comparison;
}


TNODE* createNode(DATA* __data) {
    TNODE* __node;
    __node = (TNODE*) malloc (sizeof(TNODE));
    if (__node != NULL) {
        __node->data = __data;
        __node->left = NULL;
        __node->right = NULL;
    }    
    return __node;
}

TNODE* insert(TREE __root, TNODE* __node) {
    if (__root == NULL) {
        __root = __node;
        
    } else {
        if (__compareKey(__root, __node) == EQUAL_TO) {
            return NULL;
        }
        if (__compareKey(__root, __node) == GREATER_THAN) {
            return insert(__root->left, __node);
        } else {
            return insert(__root->right, __node);
        }
    }
    return __root;
}

TNODE* traverse(TREE __root) {
    if (__root != NULL) {
        // PreOrder: N L R
        printf("%d\n", __root->data->key);
        traverse(__root->left);
        traverse(__root->right);
    }
}

TNODE* search(TREE __root, int __key) {
    if (__root != NULL) {
        if (__getKey(__root) == __key) {
            return __root;
        }
        if (__getKey(__root) > __key) {
            return search(__root->left, __key);
        } else {
            return search(__root->right, __key);
        }
    }
    return NULL;
}
TNODE* minTreeNode(TREE __root) {
    if (__root->left == NULL) {
        return __root;
    }
    else {
        return minTreeNode(__root->left);
    }
}

void __searchStandFor(TNODE* __root, TNODE* __node) {
    if (__root->right != NULL) {
        __searchStandFor(__root->right, __node);
    } else { // Method 1: Tim nut cuc phai (LON NHAT) cua cay con TRAI 
        __node->data = __root->data;
        __node = __root;
        __root = __root->left;
    }
}

TNODE* remove(TREE __root, int __key) {
    if (__root != NULL) {
        if (__getKey(__root) > __key) {
            return remove(__root->left, __key);
        } else if (__getKey(__root) < __key) {
            return remove(__root->right, __key);
        } else { // == __key
            TNODE* __node = __root;
            if (__node->left == NULL) { // only right
                __root = __node->right;
            } else if (__node->right == NULL) { // only left
                __root = __node->left;
            } else { // both left and right
                // Method 1: Tim nut cuc phai (LON NHAT) cua cay con TRAI 
                // Method 2: Tim nut cuc trai (NHO NHAT) cua cay con PHAI
                __searchStandFor(__root->left, __node);
            }
            free(__node);
        }
    }
    return __root;
}

TNODE* getNode(TREE __root) {

}