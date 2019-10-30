#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ticket.h"
#include "time.h"

int main(void) {
    srand((unsigned)(time(NULL)));

    tLine * line = createLine();

    for (int i = 0; i < 5; i++)
    {
        addClientInLine(line, false);
    }
    
    addClientInLine(line, true);
    printLine(*line);
}