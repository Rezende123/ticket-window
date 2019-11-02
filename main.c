#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ticket.h"
#include "time.h"

int main(void) {
    srand((unsigned)(time(NULL)));

    tLine * line = createLine();
    makeLineCustomers(line);
    printf("\n\n");
    tList * list = createList();
    makeListServiceWindow(list);
}