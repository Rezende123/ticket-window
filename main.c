#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ticket.h"
#include "time.h"

void legend() {
    printf("\n***************Legend***************");
    printf("\n[0] - Window available");
    printf("\n[P] - Priority customer");
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
    tList * listAttendence = createList();

    int sizeLineCustomers, sizeListServiceWindow;

    printf("Digite a quantidade de clientes na fila: ");
    scanf("%d", &sizeLineCustomers);

    printf("Digite a quantidade de guichês de atendimento: ");
    scanf("%d", &sizeListServiceWindow);

    printf("\n===============================================\n");

    buildScenario(lineCustomers, listServiceWindow, sizeLineCustomers, sizeListServiceWindow);

    while (lineCustomers != NULL && lineCustomers->first != NULL)
    {
        roundAttendance(lineCustomers, listServiceWindow);
        clearWindows(listServiceWindow);
    }
    
}