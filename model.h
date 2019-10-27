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
