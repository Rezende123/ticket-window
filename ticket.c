#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "model.h"


// TODO Clientes especiais Devem ter números de 2 dígitos
void addClientInLine(tLine * line, bool isSpecial) {
    int range = (isSpecial) ? 100 : 1000;

    int ticket = rand() % (range + 1 - range/10) + range/10; 
    
    tNode * client = createNode(ticket);
    
    insertNodeInLine(line, client);
}