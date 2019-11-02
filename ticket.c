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

void makeLineCustomers(tLine * line) {
    for (int i = 0; i < 5; i++)
    {
        addClientInLine(line, false);
    }
    
    addClientInLine(line, true);
    printf("FILA");
    printLine(*line);
    printf("\n\n");
}

void makeListServiceWindow(tList * list) {
    for (int i = 0; i < 3; i++)
    {
        tNode * window = createNode(i);
        insertNodeInList(list, window);
    }

    printf("CAIXAS");
    printList(*list);    
    printf("\n\n");
}

void buildScenario(tLine * lineCustomers, tList * listServiceWindow) {
    makeLineCustomers(lineCustomers);
    makeListServiceWindow(listServiceWindow);
}

void orderAttendance(tLine * lineCustomers) {
    tNode * node = lineCustomers->first;

    while (node != NULL)
    {
        if (node->content < 100) {
            passToFrontLine(lineCustomers, node->content);
        }
        node = node->nextNode;
    }
    printf("FILA ORDENADA");
    printLine(*lineCustomers);
}

void attendance(tLine * lineCustomers, tList * listServiceWindow) {
    orderAttendance(lineCustomers);
}
