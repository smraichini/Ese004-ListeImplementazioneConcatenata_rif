#include <stdio.h>
#include <stdlib.h>

#include ".\linkedListRef.h"

#define ERRORMESSAGE_MAXLEN 100

void assertSize(int code, LLElement * first, int expectedSize);
void assertKey(int code, LLElement * first, int position, int expectedKey);
void assertPosition(int code, LLElement * first, int key, int startPosition, int expectedPosition);
void assertReturnCode(int assertionCode, int currentReturnCode, int expectedReturnCode);
void assertSuccessfullExecution(int assertionCode, int currentReturnCode);
void printAndExit(int code, char message[]);

/*
 * 
 */
int main(int argc, char** argv) {
    
    LLElement * list=NULL;
    int i, s;
    int key;
    int position;
    int ret; // return value
    
    assertSize(10, list, 0);
    
    // Operazioni 20
    ret = LLInsertAtBeginning(&list, 100);
    assertSuccessfullExecution(2000, ret);
    ret = LLInsertAtBeginning(&list, 200);
    assertSuccessfullExecution(2001, ret);
    ret = LLInsertAtBeginning(&list, 300);
    assertSuccessfullExecution(2002, ret);
    
    assertSize(20, list, 3);
    assertKey(21, list, 0, 300);
    assertKey(22, list, 0, 300);
    assertKey(23, list, 1, 200);
    assertKey(24, list, 2, 100);
    assertKey(25, list, 0, 300);
    
    // Operazioni 30
    ret = LLRemoveFirst(&list);
    assertSuccessfullExecution(3000, ret);
    
    assertSize(30, list, 2);
    assertKey(31, list, 0, 200);
    assertKey(32, list, 1, 100);
    
    // Operazioni 40
    ret = LLRemoveLast(&list);
    assertSuccessfullExecution(4000, ret);
        
    assertSize(40, list, 1);
    assertKey(41, list, 0, 200);
    
    // Operazioni 50
    for(i=0; i<5; i++) {
        ret = LLInsertAtEnd(&list, i*1000);
        assertSuccessfullExecution(5000+i, ret);
    }
    
    assertSize(50, list, 6);
    assertKey(51, list, 0, 200);
    for(i=0; i<5; i++) {
        assertKey(52, list, 1+i, i*1000);
    }
    
    // Operazioni 60
    ret = LLRemoveAtPosition(&list, 1);
    assertSuccessfullExecution(6000, ret);
    
    assertSize(60, list, 5);
    assertKey(61, list, 0, 200);
    for(i=1; i<5; i++) {
        assertKey(62, list, i, i*1000);
    }
    
    // Operazioni 70
    ret = LLInsertAtPosition(&list, 10000, 3);
    assertSuccessfullExecution(7000, ret);
    
    assertSize(70, list, 6);
    assertKey(71, list, 3, 10000);
    
    // Operazioni 80
    ret = LLInsertAtEnd(&list, 10000);
    assertSuccessfullExecution(8000, ret);
    assertSize(80, list, 7);
    assertKey(81, list, 3, 10000);
    assertKey(82, list, 6, 10000);
    assertPosition(83, list, 10000, 0, 3);
    assertPosition(84, list, 10000, 4, 6);

    // Operazioni 90
    // Svuoto la lista
    s = LLSize(list);
    for(i=0; i<s; i++) {
        ret = LLRemoveLast(&list);
        assertSuccessfullExecution(9000+i, ret);
    }
    
    assertSize(90, list, 0);
    
    
    // Operazioni 100
    for(i=0; i<10; i++) {
        ret = LLInsertAtEnd(&list, 10+i);
        assertSuccessfullExecution(10000+i, ret);
    }
    assertSize(100, list, 10);
    for(i=0; i<10; i++)
        assertKey(101, list, i, 10+i);
    
    // Operazioni 110
    ret = LLEmptyList(&list);   // always free the memory when the list is not
                                // needed anymore
    assertSuccessfullExecution(11000, ret);
    assertSize(110, list, 0);
    
    // Operazioni 120
    ret = LLEmptyList(&list);
    assertReturnCode(12000, ret, -1); // the list is empty
    
    // Operazioni 130
    ret = LLGetKey(list, 17, &key);
    assertReturnCode(13000, ret, -1); // the list is empty
    
    // Operazioni 140
    ret = LLRemoveFirst(&list);
    assertReturnCode(14000, ret, -1); // the list is empty
    
    // Operazioni 150
    ret = LLRemoveLast(&list);
    assertReturnCode(15000, ret, -1); // the list is empty
    
    // Operazioni 160
    ret = LLRemoveAtPosition(&list, 17);
    assertReturnCode(16000, ret, -1); // the list is empty
    
     // Operazioni 170
    ret = LLFindKey(list, 17, 0, &position);
    assertReturnCode(16000, ret, -1); // the list is empty
    
    puts("Ottimo lavoro! Sembra proprio che tutto funzioni correttamente.\n");
    return (EXIT_SUCCESS);
}

void assertSize(int code, LLElement * first, int expectedSize) {
    int currentSize = LLSize(first);
    char message[ERRORMESSAGE_MAXLEN];
    if(currentSize != expectedSize) {
        sprintf(message, "Dimensione attesa: %d - Dimensione corrente: %d\n", expectedSize, currentSize);
        printAndExit(code, message);
    }
    else
        printf("Asserzione %d verificata\n", code);
    return;
}


void assertKey(int code, LLElement * first, int position, int expectedKey) {
    int currentKey;    
    char message[ERRORMESSAGE_MAXLEN];
    LLGetKey(first, position, &currentKey); // do not care to the return value
    if(expectedKey != currentKey) {
        sprintf(message, "Posizione %d. Valore atteso: %d - Valore corrente: %d\n", position, expectedKey, currentKey);
        printAndExit(code, message);
    }
    else
        printf("Asserzione %d verificata\n", code);
    return;
}

void assertPosition(int code, LLElement * first, int key, int startPosition, int expectedPosition) {
    int currentPosition;    
    char message[ERRORMESSAGE_MAXLEN];
    LLFindKey(first, key, startPosition, &currentPosition); // do not care to the return value
    if(expectedPosition != currentPosition) {
        sprintf(message, "Ricerca valore %d da posizione %d. Posizione attesa: %d - Posizione corrente: %d\n", 
                key, 
                startPosition, 
                expectedPosition, 
                currentPosition);
        printAndExit(code, message);
    }
    else
        printf("Asserzione %d verificata\n", code);
    return;
}

void assertReturnCode(int assertionCode, int currentReturnCode, int expectedReturnCode) {
    char message[ERRORMESSAGE_MAXLEN];
    if(currentReturnCode != expectedReturnCode) {
        sprintf(message, "Valore di ritorno corrente: %d - Valore di ritorno atteso: %d\n", currentReturnCode, expectedReturnCode);
        printAndExit(assertionCode, message);
    }
    else
        printf("Asserzione %d verificata\n", assertionCode);
    return;
}

void assertSuccessfullExecution(int assertionCode, int currentReturnCode) {
    assertReturnCode(assertionCode, currentReturnCode, 0);
    return;
}

void printAndExit(int code, char message[]) {
    fprintf(stderr, "Asserzione %d fallita. %s", code, message);
    exit(code);
}

