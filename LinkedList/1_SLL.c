#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int item;
    struct node *nxt;

};

//[Data|Next] -> [Data|Next] -> [Data|NULL]

//TRAVERSE Node
void printlist(struct node * node)
{
    /* data */
    while (node != NULL)
    {
        /* code */
        printf("%d-> ",node->item);
        node = node->nxt;
    }
    printf("NULL\n");
    
};


int main()
{
    //Creating 3 Nodes 
    struct node *head = NULL;
    struct node *P2 = NULL;
    struct node *P3 = NULL;

    //Allocate memory for nodes in the heap
    head =(struct node*)malloc(sizeof(struct node));
    P2 =(struct node*)malloc(sizeof(struct node));
    P3 =(struct node*)malloc(sizeof(struct node));

    // Assign data to nodes and link them
    head->item  = 1;     //first node
    head->nxt   = P2;    //link first node with second

    P2->item    = 2;    //second node
    P2->nxt     = P3;   //link second node with third

    P3->item    = 3;    //Third/Last node
    P3->nxt     = NULL; // last node point to Null

    /*Print the Node*/
    printlist(head);

    return 0;
}