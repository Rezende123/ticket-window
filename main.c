#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "model.h"

int main(void) {
    tLine * line = createLine();

    for (int i = 0; i < 5; i++)
    {
        tNode* node = createNode(i * 5);
        
        insertNodeInLine(line, node);
    }
    
    removeNodeInLine(line);
    printLine(*line);
}