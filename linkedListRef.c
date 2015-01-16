#include <stdlib.h>
#include "linkedListRef.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtBeginning(LLElement **first, int key) {
    LLElement * new;
    int r=0;
    new = (LLElement *)malloc(sizeof(LLElement));
    if(new != NULL) {
        new->next = *first;
        new->key = key;
        *first = new;
    }
    else
        r = -1;
    return r;
}

/*
 * Inserts the new key at the end of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtEnd(LLElement **first, int key) {
    LLElement * new;
    LLElement ** temp;
    int r=0;
    new = (LLElement *)malloc(sizeof(LLElement));
    if(new != NULL) {
        temp = first;
        while(*temp != NULL)
            temp = &((*temp)->next);
        new->next = NULL;
        new->key = key;
        *temp = new;
    }
    else
        r = -1;
    return r;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtPosition(LLElement **first, int key, int position) {
    LLElement * new;
    LLElement ** temp;
    int r=0;
    int i;
    new = (LLElement *)malloc(sizeof(LLElement));
    if(new != NULL) {
        temp = first;
        for(i=0; i<position; i++)
            temp = &((*temp)->next);
        new->next = *temp;
        new->key = key;
        *temp = new;
    }
    else
        r = -1;
    return r;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement *first) {
    int r = 0;
    while(first != NULL) {
        r++;
        first = first->next;
    }
    return r;
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int LLGetKey(LLElement *first, int position, int *key) {
    int i;
    int r=0;
    for(i=0; i<position && first != NULL; i++) {
        first = first->next;
    }
    if(first != NULL)
        *key = first->key;
    else
        r = -1;
    return r;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement *first, int key, int startPosition, int *position) {
    int r=0;
    int i;
    *position = -1;
    for(i=0; i<startPosition && first != NULL; i++) {
        first = first->next;
    }
    while(first != NULL && *position == -1) {
        if(first->key == key) {
            *position = i;
        }
        first = first->next;
        i++;
    }
    if(first == NULL)
        r = -1;
    return r;
}

/*
 * Remove the first element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveFirst(LLElement **first) {
    int r=0;
    LLElement * temp;
    if(*first != NULL) {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
    else
        r = -1;
    return r;
}

/*
 * Remove the last element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveLast(LLElement **first) {
    int r=0;
    LLElement **temp;
    if(*first != NULL) {
        temp = first;
        while((*temp)->next != NULL) {
                temp = &((*temp)->next);
            }
        free(*temp);
        *temp = NULL;
    }
    else
        r = -1;
    return r;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Returns -1 in case it does not exist any element at the specified position
 */
int LLRemoveAtPosition(LLElement **first, int position) {
    int r=0;
    LLElement ** temp;
    LLElement * pDelete;
    int i;
    
    temp = first;
    for(i=0; i<position && *temp != NULL; i++)
        temp = &((*temp)->next);
    
    if(*temp != NULL) {
        pDelete = *temp;
        if((*temp)->next != NULL) {
            *temp = (*temp)->next;
        }
        free(pDelete);
    }
    else
        r = -1;
    
    return r;
}

/*
 * Empties the list.
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int LLEmptyList(LLElement **first) {
    int r=0;
    LLElement *temp;
    if(*first != NULL) {
        while(*first != NULL) {
            temp = *first;
            *first = (*first)->next;
            free(temp);
        }
    }
    else
        r = -1;
    return r;
}