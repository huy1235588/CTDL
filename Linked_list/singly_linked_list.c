#include "singly_linked_list.h"

//*************************************************************
// Create a new node
//*************************************************************
NODE* createNode(DATA* __data){
    NODE* __node;
    __node = (NODE*) malloc (sizeof(NODE));
    if (__node != NULL) {
        __node->data = __data;
        __node->next = NULL;
    }    
    return __node;
}

//*************************************************************
// Check a list
//*************************************************************
BOOLEAN isInitialized(LIST* __list) {
    return (__list != NULL) ? (BOOLEAN) TRUE : (BOOLEAN) FALSE;
}

BOOLEAN isEmptyList(LIST* __list) {
    return (__list->head == NULL) ? (BOOLEAN) TRUE : (BOOLEAN) FALSE;
}

//*************************************************************
// Get the size (number of elements) of the list
//*************************************************************
int getSize(LIST* __list) {
    int __num_elems = 0;
    if (isInitialized(__list)) {
        NODE* __current = __list->head;
        while (__current != NULL) {
            __num_elems ++;
            __current = __current->next;
        }
    }  
    return __num_elems;
}

//*************************************************************
// Get a node at the position (0 --> size-1) in list
//*************************************************************
NODE* getNode(LIST* __list, int __position) {
    NODE* __node = NULL;
    if (isInitialized(__list)) {
        if (__list->head != NULL && __position >= 0) {
            __node = __list->head;
            int __current_position = 0;
            while (__node != NULL || __current_position == __position) {
                __current_position ++;
                __node = __node->next;
            }
        }
    }
    return __node;
}

NODE* getHead(LIST* __list) {
    return isInitialized(__list) ? __list->head : (NODE*) NULL;
}

NODE* getTail(LIST* __list) {
    NODE* __node = NULL;
    if (isInitialized(__list)) {
        __node = __list->head;
        while (__node->next != NULL) {
            __node = __node->next;
        }
    }
    return __node;
}

int getPositionByNode(LIST* __list, NODE* __node) {
    int __position = -1; // result
    if (isInitialized(__list)) {
        if (__list->head != NULL && __node != NULL) {
            NODE* __current = __list->head;
            int __current_position = 0;
            while (__current != NULL) {
                if (__current == __node) {
                    __position = __current_position;
                    break;
                }
                __current_position ++;
                __current = __current->next;
            }
        }
    }    
    return __position;
}

int getPositionByKey(LIST* __list, int __key) {
    int __position = -1; // result
    if (isInitialized(__list)) {
        if (__list->head != NULL) {
            NODE* __current = __list->head;
            int __current_position = 0;
            while (__current != NULL) {
                if (__current->data->key != __key) {
                    __position = __current_position;
                    break;
                }
                __current_position ++;
                __current = __current->next;
            }
        }
    }
    return __position;
}

NODE* getBeforeByPosition(LIST* __list, int __position) {  
	NODE* __prev = NULL;
    if (isInitialized(__list) || __list->head == NULL || __position > 0) {
        __prev = __list->head;
        NODE* __current = __prev->next;
        int __current_position = 1;
        while (__current != NULL) {
            if(__current_position == __position) {
                break;
            }
            __prev = __prev->next;
            __current = __current->next;
        }
    }
    return __prev;
}

//*************************************************************
// Print all data of the whole list
//*************************************************************
static void __printNode(NODE* __node) {
    if (__node != NULL) {
        printf("( %p :: %d :: %d )",    // ( node's address :: key :: value ) 
            __node,
            __node->data->key,
            __node->data->value
        );
    }
}

void printList(LIST* __list) {
    if (isInitialized(__list)) {
        NODE* __current = __list->head;
        while (__current != NULL) {
            printf("\n");
            __printNode(__current);
            __current = __current->next;
        } 
    }     
}

//*************************************************************
// Insert
//*************************************************************
NODE* addAtHead(LIST* __list, NODE* __node) {
    if (isInitialized(__list) && __node != NULL) {
        if (__list->head == NULL) {
            __list->head = __node;
        } else {
            __node->next = __list->head;
            __list->head = __node;
        }
        return __node;
    }
    return NULL;
}

NODE* addAtTail(LIST* __list, NODE* __node) {
    if (isInitialized(__list) && __node != NULL) {
        if (__list->head == NULL) {
            __list->head = __node;
        } else {
            NODE* __current = __list->head;
            while (__current->next != NULL) {
                __current = __current->next;
            }
            __current->next = __node;
        }
        return __node;
    }
    return NULL;
}

NODE* addAfter(LIST* __list, NODE* __prev, NODE* __node) {
    if (isInitialized(__list) && __prev != NULL && __node != NULL) {
        if (__list->head == NULL) {
            __list->head = __node;
        } else {
            // Find Previous Node
            NODE* __current = __list->head;
            while (__current != NULL) {
                if (__current == __prev) {
                    break;
                }
                __current = __current->next;
            }
            // Check Found Previous Node
            if (__current == NULL) {    // Not Found!
                return NULL;                
            }
            __node->next = __current->next;
            __current->next = __node;
        }
        return __node;
    }
    return NULL;
}

NODE* addAtPosition(LIST* __list, int __position, NODE* __node) {
    if (isInitialized(__list) && __position >= 0 && __node != NULL) {
        if (__list->head == NULL) {
            __list->head = __node;
        } else {
            // Find Previous Node
            int __index = -1;
            NODE* __current = __list->head;
            int __current_position = 0;
            while (__current != NULL) {
                if (__current_position == __position) {
                    __index = __current_position;
                    break;
                }
                __current_position ++;
                __current = __current->next;
            }
            // Check Found Previous Node
            if (__index != __position) {    // Not Found!
                return NULL;                
            }
            __node->next = __current->next;
            __current->next = __node;
        }
        return __node;
    }
    return NULL;
}

//*************************************************************
// Remove
//*************************************************************
void removeAtHead(LIST* __list) {
    if (isInitialized(__list) || __list->head != NULL) {
        NODE* __temp = __list->head;
        __list->head = __list->head->next;
        free(__temp);
    }	
}

void removeAtTail(LIST* __list) {
    if (isInitialized(__list)) {
        if (__list->head != NULL) {
            if (__list->head->next == NULL) {
                removeAtHead(__list);
            } else {
                NODE* __prev_tail = __list->head;
                NODE* __tail = __prev_tail->next;
                while (__tail->next != NULL) {
                    __prev_tail = __prev_tail->next;
                    __tail = __tail->next;
                }
                NODE* temp = __prev_tail->next;
                __prev_tail->next = NULL;
                free(temp);
            }
        }
    }
}

void removeAfter(LIST* __list, NODE* __prev) {
    if (isInitialized(__list) && __prev != NULL) {
        if (getPositionByNode(__list, __prev) >= 0) {
            NODE* __temp = __prev->next;
            if (__temp != NULL) {
                __prev->next = __temp->next;
                free(__temp);
            } else {
                removeAtHead(__list);
            }
        }
    }
}

void removeAtPosition(LIST* __list, int __position) {
    if (isInitialized(__list) && __list->head != NULL && __position >= 0) {
        if (__list->head->next == NULL && __position == 0) {
            removeAtHead(__list);
        } else {
            NODE* __prev = getBeforeByPosition(__list, __position);
            NODE* __temp = __prev->next;
            __prev->next = __temp->next;
            free(__temp);
        }
    }
}

void releaseWholeList(LIST* __list) {
    if (__list != NULL) {
        NODE* __temp;
        while (__list->head != NULL) {
            __temp = __list->head;
            __list->head = __list->head->next;
            free(__temp);
        }  
    }
}

//*************************************************************
// Sort
//*************************************************************
static BOOLEAN __swapData(NODE* __this, NODE* __that) {
    BOOLEAN __flag = FALSE;
    if(!(__this == NULL || __that == NULL)) {
        DATA* __temp = __this->data;
        __this->data = __that->data;
        __that->data = __temp;
        __flag = TRUE;
    }    
    return __flag;
}

static COMPARISON __compareData(DATA __this, DATA __that) {
    COMPARISON comparison = EQUAL_TO;
    if (__this.value > __that.value) {
        comparison = GREATER_THAN; 
    } else if (__this.value < __that.value) {
        comparison = LESS_THAN; 
    }
    return comparison;
}

static BOOLEAN __equalToData(DATA __this, DATA __that) {
    return (__this.value == __that.value) ? (BOOLEAN) TRUE : (BOOLEAN) FALSE;
}

void sort(LIST* __list, ORDER __order) {    // Selection Sort
    NODE* __min;
    NODE* __current_ext = __list->head;
    NODE* __current_int;
    while (__current_ext->next != NULL) {
        __current_int = __current_ext->next;
        __min = __current_ext;
        while (__current_int != NULL) {
            if (__compareData(*(__current_int->data), *(__min->data)) == ((__order == ASC) ? LESS_THAN : GREATER_THAN)) {
                __min = __current_int;
            }
            __current_int = __current_int->next;
        }        
        __swapData(__current_ext, __min);
        __current_ext = __current_ext->next;
    }
}

static NODE* partition(struct Node* __first, struct Node* __last, ORDER __order) { 
    NODE* __pivot = __first; 
    NODE* __front = __first; 
    while (__front != NULL && __front != __last) { 
        if (__compareData(*(__front->data), *(__last->data)) == ((__order == ASC) ? LESS_THAN : GREATER_THAN)) { 
            __pivot = __first;
            __swapData(__first, __front);
            __first = __first->next; 
        } 
        __front = __front->next; 
    }
    __swapData(__first, __last);
    return __pivot; 
} 

static void quickSort(NODE* __first, NODE* __last, ORDER __order) { 
    if (__first == __last) { 
        return;
    } 
    NODE* __pivot = partition(__first, __last, __order); 
    if (__pivot != NULL && __pivot->next != NULL) { 
        quickSort(__pivot->next, __last, __order); 
    } 
    if (__pivot != NULL && __first != __pivot) { 
        quickSort(__first, __pivot, __order); 
    } 
}
void sortByQS(LIST* __list, ORDER __order) {
    quickSort(__list->head, getTail(__list), __order);
}