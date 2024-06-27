#include "hash_table.h"

static int ht_hash(const char *s, const int a, const int m)
{
	long hash = 0;
	const int len_s = strlen(s);
	for (int i = 0; i < len_s; i++)
	{
		hash += (long)pow(a, len_s - (i + 1)) * s[i];
		hash = hash % m;
	}
	return (int)hash;
}

HASHTABLE *HTHashtable_new(int size)
{
	HASHTABLE *newHashtable;
	int c = size > 0 ? size : HT_L_HASH_SIZE;
	if ((newHashtable = (HTHashtable *)HT_CALLOC(1, sizeof(HTHashtable))) == NULL)
		HT_OUTOFMEM("HTHashtable_new");

	if ((newHashtable->table = (void **)HT_CALLOC(c, sizeof(void *))) == NULL)
		HT_OUTOFMEM("HTHashtable_new");

	newHashtable->count = 0;
	newHashtable->size = c;
	return newHashtable;
}

BOOLEAN HTHashtable_delete(HASHTABLE *me)
{
	if (me)
	{
		int i;
		for (i = 0; i < me->size; i++)
		{
			HTList *l = (HTList *)me->table[i];
			if (l)
			{
				HTList *current = l;
				KEYNODE *kn;
				while ((kn = (KEYNODE *)HTList_nextObject(current)))
				{
					HT_FREE(kn->key);
					HT_FREE(kn);
				}
				HTList_delete(l);
			}
		}
		HT_FREE(me->table);
		HT_FREE(me);
		return YES;
	}
	return NO;
}

int hash_number(const char *key, int size)
{
	int hash = 0;

	if (key)
	{
		const char *ptr = key;
		for (; *ptr; ptr++)
			hash = (int)((hash * 3 + (*(unsigned char *)ptr)) % size);
	}
	return hash;
}

//*************************************************************
// Add an Element to a HashTable
//*************************************************************
BOOLEAN HTHashtable_addObject(HASHTABLE *me, const char *key,
							  void *newObject)
{
	if (me)
	{
		int size = me->size;
		int i = hash_number(key, size);
		HTList *l = (HTList *)me->table[i];
		KEYNODE *kn;
		if (!l)
			l = me->table[i] = HTList_new();
		if ((kn = (KEYNODE *)HT_CALLOC(1, sizeof(KEYNODE))) == NULL)
			HT_OUTOFMEM("HTHashtable_addObject");
		StrAllocCopy(kn->key, key);
		kn->object = newObject;
		HTList_addObject(l, kn);
		me->count++;
		return YES;
	}
	return NO;
}

//*************************************************************
// Remove an Element from the HashTable
//*************************************************************
BOOLEAN HTHashtable_removeObject(HASHTABLE *me, const char *key)
{
	if (me)
	{
		int size = me->size;
		int i = hash_number(key, size);
		HTList *l = (HTList *)me->table[i];
		if (l)
		{
			HTList *cur = l;
			KEYNODE *kn;
			while ((kn = (KEYNODE *)HTList_nextObject(cur)))
			{
				if (!strcmp(key, kn->key))
				{
					HTList_removeObject(l, kn);
					me->count--;
					return YES;
				}
			}
		}
	}
	return NO;
}

//*************************************************************
// Search for an Element in a Hash Table
//*************************************************************
void *HTHashtable_object(HASHTABLE *me, const char *key)
{
	if (me)
	{
		int size = me->size;
		int i = hash_number(key, size);
		HTList *l = (HTList *)me->table[i];
		if (l)
		{
			HTList *cur = l;
			KEYNODE *kn;
			while ((kn = (KEYNODE *)HTList_nextObject(cur)))
			{
				if (!strcmp(key, kn->key))
					return kn->object;
			}
		}
	}
	return NULL;
}

//*************************************************************
// Size of a Hash Table
//*************************************************************
int HTHashtable_count(HASHTABLE *me)
{
	if (me)
		return me->count;
	return -1;
}

//*************************************************************
// Walk all Elements in the HashTable
//*************************************************************
BOOLEAN HTHashtable_walk(HASHTABLE *me,
						 int (*walkFunc)(HASHTABLE *, char *, void *))
{
	if (me)
	{
		int i, j;
		for (i = 0; i < me->size; i++)
		{
			HTList *l = (HTList *)me->table[i];
			if (l)
			{
				HTList *cur = l;
				KEYNODE *kn, *nextkn;
				for (kn = (KEYNODE *)HTList_nextObject(cur); kn; kn = nextkn)
				{
					j = walkFunc(me, kn->key, kn->object);
					if (j == 0)
						return YES;
					nextkn = (KEYNODE *)HTList_nextObject(cur);
					if (j < 0)
					{
						HTList_removeObject(l, kn);
						me->count--;
					}
				}
			}
		}
		return YES;
	}
	return NO;
}

//*************************************************************
// Extract in a dynamic array all keys of the Hash Table
//*************************************************************
HTArray *HTHashtable_keys(HASHTABLE *me)
{
	if (me)
	{
		HTArray *keys = HTArray_new(me->count);
		int i;

		for (i = 0; i < me->size; i++)
		{
			HTList *l = (HTList *)me->table[i];
			if (l)
			{
				HTList *cur = l;
				KEYNODE *kn;
				while ((kn = (KEYNODE *)HTList_nextObject(cur)))
				{
					char *nkey = NULL;
					StrAllocCopy(nkey, kn->key);
					HTArray_addObject(keys, nkey);
				}
			}
		}
		return keys;
	}
	return NULL;
}

//*************************************************************
// Print the keys of the Hash Table
//*************************************************************

void HTHashtable_print(HASHTABLE *me)
{
	HTArray *keys = HTHashtable_keys(me);
	int i;
	HTPrint("Printing Hash Table of size %d\n", HTArray_size(keys));
	for (i = 0; i < HTArray_size(keys); i++)
	{
		HTPrint("Key %d %s\n", i, HTArray_data(keys)[i]);
	}
	for (i = 0; i < HTArray_size(keys); i++)
	{
		HT_FREE(HTArray_data(keys)[i]);
	}
	HTArray_delete(keys);
}
