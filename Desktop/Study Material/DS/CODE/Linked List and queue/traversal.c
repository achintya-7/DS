#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void traversal(struct node *p)
{   
    while (p != NULL)
    {
        printf("value : %d \n", p->data);
        p = p->next; 
        /* code */
    }
    
    
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 2;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 222;
    third->next = NULL;

    traversal(head);
}