#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;


void linkedListTraversal(struct node *ptr)
{
    printf("Linked List Traversal \n");
    while (ptr != NULL)
    {
        printf("element is %d \n", ptr->data);
        ptr = ptr->next;
    }
    
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if(f==NULL){
        printf("queue is empty \n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;

}
void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(n == NULL) //check for full
        printf("\n Queue is full \n");
    else
    {
        n->data = val;
        n->next = NULL;
        if(f == NULL) //empty queue
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}



int main()
{
       
    enqueue(3); // because node f and node r is NULL in global
    enqueue(2); // u dont need to pass f and r here
    printf("dequed elemet %d \n", dequeue());
    printf("dequed element %d \n", dequeue());
    linkedListTraversal(f);
     
}