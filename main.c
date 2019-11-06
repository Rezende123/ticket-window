#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "time.h"
#include "ticket/ticket.h"

void legend() {
    printf("\n***************Legend***************");
    printf("\n[0] - Window available");
    printf("\n[P] - Priority customer");
    printf("\n[address negative] - Window block");
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

    int sizeLineCustomers, sizeListServiceWindow;

    printf("Digite a quantidade de clientes na fila: ");
    scanf("%d", &sizeLineCustomers);

    printf("Digite a quantidade de guichês de atendimento: ");
    scanf("%d", &sizeListServiceWindow);

    printf("\n===============================================\n");

    buildScenario(lineCustomers, listServiceWindow, sizeLineCustomers, sizeListServiceWindow);

    while (lineCustomers != NULL && lineCustomers->first != NULL && lineCustomers->amount > 0)
    {
        roundAttendance(lineCustomers, listServiceWindow);
        clearWindows(listServiceWindow);
        
        int window;
        printf("Informe qual guichê será bloqueado para a próxima rodada: ");
        scanf("%d", &window);
        
        blockWindow(listServiceWindow, window);
    }
    
}
