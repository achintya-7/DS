#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node * createNode(int data){
    struct node *n; // creating node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating mempry in heap
    n->left = NULL; // setting left and right children node
    n->right = NULL;  // setting left and right children node  
    n->data = data; // assigning data
    return n;  // returning the created node
}

struct node *searchIter(struct node* root, int key)
{
    while(root != NULL)
    {
        if(key == root->data)
            return root;
        else if(key < root->data)
            root = root->left; 
        else
            root = root->right;
    }

    return NULL;    
}
int main()
{
   
   // constructing root node and children nodes
   struct node *p = createNode(5);
   struct node *p1 = createNode(3);
   struct node *p2 = createNode(6);
   struct node *p3 = createNode(1);
   struct node *p4 = createNode(4);
   //struct node *p5 = createNode(13);

    // joining the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    struct node *n = searchIter(p, 3); // because it returns value as root which is a struct node type data
    if(n!=NULL)
        printf("Found %d \n", n->data);
    else
        printf("elements not found \n");
    /*          5
    //         / \
              3   6
    //       / \    
            1  4
    */


}