#include<stdio.h>
#include<stdlib.h>

struct node{
    int item;
    struct node * nxt;
};

void nodesCreate(int noNodes)
{   struct node * head = NULL;
    struct node * temp = NULL;
    struct node * tail = NULL;
    for(int i=0 ; i < noNodes; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        if(temp == NULL)
        {
            printf("Memory not created\n");
        }
        printf("Enter the data for %d node:",i+1);
        scanf("%d",&temp->item);
        temp->nxt = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else{
            tail->nxt = temp;
            tail = temp;
        }
    }
}

int main()
{
    int no_nodes =  0;
    printf("Enter the nodes need to create : ");
    scanf("%d",&no_nodes);
    nodesCreate(no_nodes);
    return 0;
}