typedef struct node
{
    int content;
    struct node* nextNode;
} tNode;


typedef struct list
{
    tNode * initialNode;
    int amountNodes;
} tList;

tList * createList();
tNode * createNode(int content);
void insertNodeInList(tList * list, tNode * node);
bool removeNodeInList(tList * list, int content);
void printList(tList list);
