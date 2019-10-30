#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "model.h"

int main(void) {
    tList * list = createList();

    for (int i = 0; i < 5; i++)
    {
        tNode* node = createNode(i * 5);
        
        insertNodeInList(list, node);
    }
    
    printList(*list);
}