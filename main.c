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

int main(void) {
    srand((unsigned)(time(NULL)));
    legend();

    tLine * lineCustomers = createLine();
    tList * listServiceWindow = createList();
    tList * listAttendence = createList();

    buildScenario(lineCustomers, listServiceWindow);
    attendance(lineCustomers, listServiceWindow);
    printf("LINE");
    printLine(*lineCustomers);
}