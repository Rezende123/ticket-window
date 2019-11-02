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

tLine * createLine() {
    tLine * line = malloc(sizeof(tLine));

    line->first = NULL;
    line->last = NULL;
    line->amount = 0;

    return line;
}

tNode * createNode(int content) {
    tNode * node = malloc(sizeof(tNode));

    node->content = content;
    node->nextNode = NULL;

    return node;
}

// LIST
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

//TODO customerTicket == 0 significa guichê disponível
void printList(tList list) {
    printf("\n======= LIST =======\n");
    tNode * node = list.initialNode;
    int count = 1;

    while (node != NULL)
    {
        int customerTicket = 0;
        
        if (node->customer != NULL) {
            customerTicket = node->customer->content;
        }
        printf("[%d][%d] - %d\n", customerTicket, count, node->content);
        node = node->nextNode;
        count++;
    }   
}

// LINE
void insertNodeInLine(tLine * line, tNode * node) {
    if (line == NULL) return;

    if (line->first == NULL) {
        line->first = line->last = node;
        return;
    }

    tNode * _node = line->last;
    line->last = _node->nextNode = node;
    line->amount++;
}
void removeNodeInLine(tLine * line) {
    if (line == NULL || line->first == NULL) return;

    tNode * node = line->first;
    line->first = node->nextNode;
    line->amount--;
}
void printLine(tLine line) {
    if (line.first == NULL) return;
    
    printf("\n======= LINE =======\n");
    tNode * node = line.first;
    int count = 1;

    while (node != NULL)
    {
        if (node->content < 100) {
            printf("[P]");
        }
        printf("\t[%d] - %d\n", count, node->content);
        node = node->nextNode;
        count++;
    }
}
void passToFrontLine(tLine * line, tNode * node, tNode * backNode) {
    backNode->nextNode = node->nextNode;
    node->nextNode = line->first;
    line->first = node;
}