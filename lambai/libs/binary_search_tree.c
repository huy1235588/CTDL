#include "binary_search_tree.h"

static int __getKey(TNODE *__node)
{
    return __node->data->key;
}

static COMPARISON __compareKey(TNODE *__this, TNODE *__that)
{
    COMPARISON comparison = EQUAL_TO;
    if (__getKey(__this) > __getKey(__that))
    {
        comparison = GREATER_THAN;
    }
    else if (__getKey(__this) < __getKey(__that))
    {
        comparison = LESS_THAN;
    }
    return comparison;
}

TNODE *createTreeNode(DATA *__data)
{
    TNODE *__node;
    __node = (TNODE *)malloc(sizeof(TNODE));
    if (__node != NULL)
    {
        __node->data = __data;
        __node->left = NULL;
        __node->right = NULL;
    }
    return __node;
}

TNODE *insertTreeNode(TREE *__root, TNODE *__node)
{
    if (*__root == NULL)
    {
        *__root = __node;
    }
    else
    {
        if (__compareKey(*__root, __node) == GREATER_THAN)
        {
            return insertTreeNode(&(*__root)->left, __node);
        }
        else if (__compareKey(*__root, __node) == LESS_THAN)
        {
            return insertTreeNode(&(*__root)->right, __node);
        }
    }
    return *__root;
}

void traverse(TREE __root)
{
    if (__root != NULL)
    {
        // PreOrder: N L R
        printf("%d :: %d\n", __root->data->key, __root->data->value);
        traverse(__root->left);
        traverse(__root->right);

        // In-order: L N R
        // traverse(__root->left);
        // printf("%d :: %d\n", __root->data->key, __root->data->value);
        // traverse(__root->right);

        // Post-order: L R N
        //  traverse(__root->left);
        // traverse(__root->right);
        // printf("%d :: %d\n", __root->data->key, __root->data->value);
    }
}

TNODE *searchTreeNode(TREE __root, int __key)
{
    if (__root != NULL)
    {
        if (__getKey(__root) == __key)
        {
            return __root;
        }
        if (__getKey(__root) > __key)
        {
            return searchTreeNode(__root->left, __key);
        }
        else
        {
            return searchTreeNode(__root->right, __key);
        }
    }
    return NULL;
}

TNODE *minTreeNode(TREE __root)
{
    if (__root->left == NULL)
    {
        return __root;
    }
    else
    {
        return minTreeNode(__root->left);
    }
}

TNODE *maxTreeNode(TREE __root)
{
    if (__root->right == NULL)
    {
        return __root;
    }
    else
    {
        return maxTreeNode(__root->right);
    }
}

void __searchStandFor(TNODE **__root, TNODE **__node)
{
    if ((*__root)->right != NULL)
    {
        __searchStandFor(&(*__root)->right, __node);
    }
    else
    {
        // Replace the data of the node to be deleted with the in-order predecessor's data
        (*__node)->data = (*__root)->data;
        TNODE *temp = *__root;
        *__root = (*__root)->left;
        free(temp);
    }
}

TNODE *removeTreeNode(TREE __root, int __key)
{
    if (__root != NULL)
    {
        if (__getKey(__root) > __key)
        {
            __root->left = removeTreeNode(__root->left, __key);
        }
        else if (__getKey(__root) < __key)
        {
            __root->right = removeTreeNode(__root->right, __key);
        }
        else
        { // == __key
            TNODE *__node = __root;
            if (__node->left == NULL)
            { // only right
                __root = __node->right;
                free(__node);
            }
            else if (__node->right == NULL)
            { // only left
                __root = __node->left;
                free(__node);
            }
            else
            { // both left and right
                TNODE *__temp = maxTreeNode(__root->left);
                __root->data = __temp->data;
                __root->left = removeTreeNode(__root->left, __getKey(__root));
            }
        }
    }
    return __root;
}

TNODE *getNode(TREE __root)
{
}

void freeTree(TREE *__root)
{
    if (*__root != NULL)
    {
        freeTree(&(*__root)->left);
        freeTree(&(*__root)->right);
        free(*__root);
        free((*__root)->data);
        *__root = NULL;
    }
}