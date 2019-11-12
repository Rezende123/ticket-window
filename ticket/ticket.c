#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../model/model.h"

#define RATE_PREFERENTIAL 5
double timer;

int sortByRange(int max_range, int min_range) {
    return rand() % (max_range + 1 - (min_range + 1)) + (min_range + 1); 
}

bool sortPreferential() {
    int sort = rand() % 10;
    
    return (sort % RATE_PREFERENTIAL == 0);
}

// TODO Clientes especiais Devem ter números de 2 dígitos
void addClientInLine(tLine * line, bool isSpecial) {
    int range = (isSpecial) ? 99 : 999;

    int ticket = sortByRange(range,(range/10));
    
    tNode * client = createNode(ticket);
    
    insertNodeInLine(line, client);
}

void makeLineCustomers(tLine * line, int sizeLineCustomers) {
    for (int i = 1; i <= sizeLineCustomers; i++)
    {

        bool isPeferential = sortPreferential();
        addClientInLine(line, isPeferential);
    }

    printf("FILA");
    printLine(*line);
    printf("\n\n");
}

void makeListServiceWindow(tList * list, int sizeListServiceWindow) {
    for (int i = 1; i <= sizeListServiceWindow; i++)
    {
        tNode * window = createNode(i);
        insertNodeInList(list, window);
    }

    printf("GUICHÊS");
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

void clearWindows(tList * list) {
    tNode * window = list->initialNode;

    while (window != NULL)
    {
        if (window->customer != NULL && window->customer->timeAttendence < window->timeAttendence) {
            window->customer = NULL;
            window->timeAttendence = 0;
        }
        window->content = abs(window->content);
        window = window->nextNode;
    }

    printf("\nGUICHÊS REINICIADOS");
    printList(*list);
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
    printf("\nFILA ORDENADA");
    printLine(*lineCustomers);
}
bool hasAttendence(tList * list) {
    tNode * window = list->initialNode;

    while (window != NULL)
    {
        if (window->customer != NULL) {
            return true;
        }
        window = window->nextNode;
    }

    return false;
}
void finaleAttendence(tList * list) {
    while (hasAttendence(list))
    {
        tNode * window = list->initialNode;

        while (window != NULL)
        {
            if (window->customer != NULL &&
                window->customer->timeAttendence < window->timeAttendence) {

                window->customer = NULL;
                window->timeAttendence = 0;
                
                printf("\nGUICHÊS EM ATENDIMENTO");
                printList(*list);   
                printf("\n\n");
            } else {
                window->timeAttendence++;
            }
            window = window->nextNode;
        }
    }
}

void attendance(tLine * lineCustomers, tList * listServiceWindow) {
    orderAttendance(lineCustomers);

    tNode * window = listServiceWindow->initialNode;
    tNode * customer = lineCustomers->first;

    while (window != NULL && customer != NULL)
    {
        if (window->customer == NULL && window->content >= 0) {
            window->customer = customer;
            customer = customer->nextNode;
            removeNodeInLine(lineCustomers);
        }

        if (window->content >= 0) {
            window->timeAttendence++;
        } else {
            window->timeAttendence = 0;
        }

        window = window->nextNode;
    }
    
    printf("\nGUICHÊS EM ATENDIMENTO");
    printList(*listServiceWindow);   
    printf("\n\n");
}
void blockWindow(tList * list, int windowContent) {
    tNode * window = list->initialNode;

    while (window != NULL && window->content != windowContent)
    {
        window = window->nextNode;
    }

    if (window->content == windowContent && window->customer == NULL) {
        window->content = windowContent * -1;
    }
}