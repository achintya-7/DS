#include <stdio.h>
#include <stdlib.h>

struct node
{
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

struct node * insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct node * insertAtEnd(struct node *head, int data)
{   
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;
   
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

struct node * insertAfterNode(struct node *head ,struct node *prevnode, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;

    return head;
}

struct node * insertAtIndex(struct node *head, int data, int index)
{   
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while(i != index-1)  //takes p to the node just before we want to add
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;

    return head;
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
    printf("\n\nlinked list after insertion \n \n");


    //head = insertAtFirst(head, 1020);
    //head = insertAtIndex(head, 2001, 2);    
    //head = insertAtEnd(head, 2222);
    head = insertAfterNode(head, second, 212312);
    traversal(head);
}