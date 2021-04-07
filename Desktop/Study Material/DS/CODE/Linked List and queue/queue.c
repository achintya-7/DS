#include <stdio.h>
#include <stdlib.h>

struct queue 
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q)
{
    if(q->r == q->size-1)
        return 1;
    return 0;

}

int isEmpty(struct queue *q)
{
    if(q->r == q->f)
        return 1;
    return 0;

}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
        printf("Overflow");
    
    else
    {
        q->r = q->r+1;
        q->arr[q->r] = val;
        
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
        printf("\n Underflow \n");
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;      
    
    q.size = 3;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 23);
    enqueue(&q, 32);
    enqueue(&q, 33);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    if (isEmpty(&q))
    {
        printf("\n Queue is Empty \n");
    }
    
    return 0;
}