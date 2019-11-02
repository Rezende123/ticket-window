#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "model.h"


// TODO Clientes especiais Devem ter números de 2 dígitos
void addClientInLine(tLine * line, bool isSpecial) {
    int range = (isSpecial) ? 99 : 999;

    int ticket = rand() % (range + 1 - ((range/10) + 1)) + ((range/10) + 1); 
    
    tNode * client = createNode(ticket);
    
    insertNodeInLine(line, client);
}

void makeLineCustomers(tLine * line, int sizeLineCustomers) {
    for (int i = 0; i < sizeLineCustomers; i++)
    {
        int sort = rand() % 10;

        bool isPeferencial = (sort%2 != 0);
        addClientInLine(line, isPeferencial);
    }

    printf("LINE");
    printLine(*line);
    printf("\n\n");
}

void makeListServiceWindow(tList * list, int sizeListServiceWindow) {
    for (int i = 0; i < sizeListServiceWindow; i++)
    {
        tNode * window = createNode(i);
        insertNodeInList(list, window);
    }

    printf("WINDOW");
    printList(*list);    
    printf("\n\n");
}

void buildScenario(
    tLine * lineCustomers, 
    tList * listServiceWindow,
    int sizeLine,
    int sizeList
    ) {
    makeLineCustomers(lineCustomers, sizeLine);
    makeListServiceWindow(listServiceWindow, sizeList);
}

void orderAttendance(tLine * lineCustomers) {
    tNode * node = lineCustomers->first;
    tNode * backNode = lineCustomers->first;

    while (node != NULL)
    {
        if (node->content < 100 && 
            node != lineCustomers->first &&
            backNode->content > 100
            ) {
            passToFrontLine(lineCustomers, node, backNode);
        }
        backNode = node;
        node = node->nextNode;
    }
    printf("ORDENED LINE");
    printLine(*lineCustomers);
}

void attendance(tLine * lineCustomers, tList * listServiceWindow) {
    orderAttendance(lineCustomers);

    tNode * window = listServiceWindow->initialNode;
    tNode * customer = lineCustomers->first;

    while (window != NULL && customer != NULL)
    {
        if (window->customer == NULL) {
            window->customer = customer;
            customer = customer->nextNode;
            removeNodeInLine(lineCustomers);
        }

        window = window->nextNode;
    }
    
    printf("\nWINDOW IN ATTENDMENT");
    printList(*listServiceWindow);   
    printf("\n\n");
}
