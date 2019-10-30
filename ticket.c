#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "model.h"


// TODO Clientes especiais Devem ter números de 2 dígitos
void addClientInLine(tLine * line, bool isSpecial) {
    int range = (isSpecial) ? 100 : 1000;

    int ticket = rand() % range; 
    
    tNode * client = createNode(ticket);
    
    insertNodeInLine(line, client);
}