#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "hash_utils.c"
#include "hash_string.h"

typedef struct HashData
{
    char *key;
    char *number;
} HASHDATA;

typedef struct keyNode
{
    struct HashData hashData;
    struct keyNode *next;
} KEYNODE;

typedef struct Hashtable
{
    struct keyNode **table;
    int size;  // kích thước của bảng băm
    int count; // how full it is
} HASHTABLE;

//*************************************************************
// function prototype
//*************************************************************
void demonstrate_singly_linked_lists(); // demo function

// Create and deletes a Hash Table
HASHTABLE *HTHashtable_new(int size);

BOOLEAN  HTHashtable_delete(HASHTABLE *me);

// Add an Element to a HashTable
BOOLEAN HTHashtable_addObject(HASHTABLE *me, const char *key, const char *number);

// Remove an Element from a HashTable
BOOLEAN HTHashtable_removeObject(HASHTABLE *me, const char *key);

// Size of a Hash Table
int HTHashtable_count(HASHTABLE *me);

// Print the keys of the Hash Table
void HTHashtable_print (HASHTABLE *me);

#endif