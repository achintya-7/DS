#include <stdio.h>
#include <stdlib.h>

struct circularqueue 
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct circularqueue *q)
{
    if((q->r+1)%q->size == q->f)    
        return 1;
    else
        return 0;

}

int isEmpty(struct circularqueue *q)
{
    if(q->r == q->f)
        return 1;
    return 0;

}

void enqueue(struct circularqueue *q, int val)
{
    if(isFull(q))
        printf("Overflow");
    
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        
    }
}

int dequeue(struct circularqueue *q)
{
    int a = -1;
    if(isEmpty(q))
        printf("\n Underflow \n");
    else
    {
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct circularqueue q;      
    
    q.size = 2;
    q.f = q.r = 0; //different from linear queue
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 23);
    enqueue(&q, 32);
    enqueue(&q, 342);
    //dequeue(&q);
    //dequeue(&q);
    //dequeue(&q);

    if (isEmpty(&q))
    {
        printf("\n Queue is Empty \n");
    }
    if (isFull(&q))
    {
        printf("\n full queue \n");
    }
    
    return 0;
}