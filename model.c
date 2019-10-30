#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "model.h"

tList * createList() {
    tList * list = malloc(sizeof(tList));

    list->initialNode = NULL;
    list->amountNodes = 0;

    return list;
}

tNode * createNode(int content) {
    tNode * node = malloc(sizeof(tNode));

    node->content = content;
    node->nextNode = NULL;

    return node;
}

void insertNodeInList(tList * list, tNode * node) {
    if (list == NULL) return;

    tNode * currentNode = list->initialNode;

    if (currentNode == NULL) {
        list->initialNode = createNode(node->content);
        list->amountNodes++;
        return;
    }
    
    while (currentNode->nextNode != NULL && currentNode != currentNode->nextNode)
    {
        currentNode = currentNode->nextNode;
    }

    currentNode->nextNode = node;
    list->amountNodes++;
}

bool removeNodeInList(tList * list, int content) {
    tNode * currentNode = list->initialNode;
    tNode * backNode;

    while (currentNode->nextNode != NULL && currentNode->content != content)
    {
        backNode = currentNode;
        currentNode = currentNode->nextNode;
    }
    
    if (currentNode->content == content) {
        backNode->nextNode = currentNode->nextNode;
        list->amountNodes --;
        
        return true;
    }

    return false;
}

void printList(tList list) {
    printf("\n\n======= LIST =======\n");
    tNode * node = list.initialNode;
    int count = 1;

    while (node != NULL)
    {
        printf("[%d] - %d\n", count, node->content);
        node = node->nextNode;
        count++;
    }
    
}