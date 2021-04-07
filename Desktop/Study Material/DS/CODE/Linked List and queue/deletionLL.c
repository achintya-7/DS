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

struct node * deleteFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node * deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node * deleteLast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node * deleteAtValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;

    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == value)
    {
       p->next = q->next;
       free(q); 
    }

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth = (struct node *)malloc(sizeof(struct node));

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 2;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 222;
    third->next = forth;

    forth->data = 2222;
    forth->next=NULL;

    traversal(head);
    printf("linked list after deletion \n");

    //head = deleteFirst(head);
    //head = deleteAtIndex(head, 1);
    //head = deleteLast(head);
    head = deleteAtValue(head, 22);
    traversal(head);
}