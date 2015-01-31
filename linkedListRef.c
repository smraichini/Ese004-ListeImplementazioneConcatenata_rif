#include <stdlib.h>
#include "linkedListRef.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtBeginning(LLElement **first, int key) {
    LLElement *new_element;
    int allocation_of_memory=NULL;
    new_element=(LLElement *)malloc(sizeof(LLElement));
    if(new_element!=NULL)
    {
        new_element->next=*first;
        new_element->key=key;
        *first=new_element;
        allocation_of_memory=0;   
    }        
    else
    {
      allocation_of_memory = -1;
    }
    
    return allocation_of_memory;
}

/*
 * Inserts the new key at the end of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtEnd(LLElement **first, int key) {
    // TODO Implementation needed
    return -1;
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
    // TODO Implementation needed
    return -1;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement *first) {
    int size_of_list=0;
    while(first!=NULL)
    {
        size_of_list++;
        first=first->next;
               
    } 
    return size_of_list;
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int LLGetKey(LLElement *first, int position, int *key) {
    int key_state=NULL;
    LLElement **slide;
    int i=0;
    slide=&first; 
    while(i<position)
    {
        slide=&((*slide)->next);
        i++;
    }
    *key=(*slide)->key;
    if(position>=LLSize(first))
    {
        key_state=0;
    }
    else
    {
        key_state=-1;
    }
    return key_state;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement *first, int key, int startPosition, int *position) {
    // TODO Implementation needed
    return -1;
}

/*
 * Remove the first element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in case of empty list.
 */
int LLRemoveFirst(LLElement **first) 
{
    int state_of_list=-1;
    if((*first)!=NULL)
    {
    LLElement *temp;
    temp=*first;
    *first=(*first)->next;
    free(temp);
    state_of_list=0;
    }
    else
    {
    state_of_list=-1;
    }
    return state_of_list;
}

/*
 * Remove the last element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveLast(LLElement **first) 
{
    int state_of_list=-1;
    int i;
    int dim=LLSize(*first);
    if(*first!=NULL)
    {
        while(i<dim)
        {
         *first=(*first)->next;
        }
        
        free((*first)->next);
        (*first)->next=NULL;
        state_of_list=0;
    }
    else
    {
    state_of_list=-1;
    }
    
    return state_of_list;
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
    // TODO Implementation needed
    return -1;
}

/*
 * Empties the list.
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int LLEmptyList(LLElement **first) {
    int list_state=NULL;
    if(*first!=NULL)
    {
        list_state=0;
    }
    else
    {
        list_state=-1;
    }
    return list_state;
}
