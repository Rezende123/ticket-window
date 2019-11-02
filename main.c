#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ticket.h"
#include "time.h"

int main(void) {
    srand((unsigned)(time(NULL)));

    tLine * lineCustomers = createLine();
    tList * listServiceWindow = createList();
    tList * listAttendence = createList();

    buildScenario(lineCustomers, listServiceWindow);
    attendance(lineCustomers, listServiceWindow);
}