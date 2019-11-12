#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "time.h"
#include "ticket/ticket.h"

#define SIZE_LINE_CUSTOMERS 20
#define SIZE_LIST_SERVICE_WINDOWS 10

void legend() {
    printf("\n***************LEGENDA***************");
    printf("\n[P]\t- CLIENTE PRIORITÁRIO");
    printf("\n[E]\t- ATENDIMENTO EXPRESSO");
    printf("\n[N]\t- ATENDIMENTO NORMAL");
    printf("\n[C]\t- ATENDIMENTO COMPLEXO");
    printf("\n[CLOSE]\t- GUICHÊ SUSPENSO");
    printf("\n[OPEN]\t- GUICHÊ OPERANDO");
    printf("\n\n\n");
}
void roundAttendance(tLine * lineCustomers, tList * listServiceWindow) {
    attendance(lineCustomers, listServiceWindow);
    
    printLine(*lineCustomers);
}
int main(void) {
    srand((unsigned)(time(NULL)));
    
    legend();

    tLine * lineCustomers = createLine();
    tList * listServiceWindow = createList();

    buildScenario(lineCustomers, listServiceWindow, SIZE_LINE_CUSTOMERS, SIZE_LIST_SERVICE_WINDOWS);

    do
    {
        printf("\n============================RODADA DE ATENDIMENTO============================\n");
        roundAttendance(lineCustomers, listServiceWindow);
        clearWindows(listServiceWindow);
        
        int window = sortByRange(SIZE_LIST_SERVICE_WINDOWS, 1);

        printf("\nBOTÃO DO PÂNICO PARA O GUICHÊ: %d\n", window);
        blockWindow(listServiceWindow, window);
    } 
    while (lineCustomers != NULL && lineCustomers->first != NULL &&
        lineCustomers->amount >= 0);

    if (lineCustomers->amount < 0 && hasAttendence(listServiceWindow)) {
        printf("\nESVAZIANDO CAIXAS\n");
        finaleAttendence(listServiceWindow);
    }
    
}
