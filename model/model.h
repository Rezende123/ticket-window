#include <stdbool.h>

typedef struct node
{
    int content;
    struct node * nextNode;

    struct node * customer;  
} tNode;

typedef struct list
{
    tNode * initialNode;
    int amountNodes;
} tList;

typedef struct line {
	tNode * first;
	tNode * last;
	int amount; 
} tLine;

tNode * createNode(int content);

tList * createList();
void insertNodeInList(tList * list, tNode * node);
bool removeNodeInList(tList * list, int content);
void printList(tList list);

tLine * createLine();
void insertNodeInLine(tLine * line, tNode * node);
void removeNodeInLine(tLine * line);
void printLine(tLine line);
void passToFrontLine(tLine * line, tNode * node, tNode * backNode);