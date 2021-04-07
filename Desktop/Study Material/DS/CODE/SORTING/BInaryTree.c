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

void preorder (struct node* root){
    if(root != NULL){
        printf("%d ", root->data );
        preorder(root->left);
        preorder(root->right);
        
    }
}

void postorder (struct node* root){
    if(root != NULL){
        
        preorder(root->left);
        preorder(root->right);
        printf("%d ", root->data );
        
    }
}

void inorder (struct node* root){
    if(root != NULL){
        
        inorder(root->left);
        printf("%d ", root->data );
        inorder(root->right);
       
        
    }
}

int main()
{
    /* this is making nodes without functions
    struct node *p; // root node
    p = (struct node *)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    p->data = 1;

    // children nodes 
    struct node *p1;
    p = (struct node *)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    p->data = 2;

    struct node *p2;
    p = (struct node *)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    p->data = 3;

    p->left = p2;
    p->right = p1;
    */
   
   // constructing root node and children nodes
   struct node *p = createNode(1);
   struct node *p1 = createNode(2);
   struct node *p2 = createNode(55);
   struct node *p3 = createNode(32);
   struct node *p4 = createNode(31);
   struct node *p5 = createNode(13);

    // joining the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    
    preorder(p);
    printf("\n");
    postorder(p);

    printf("\n");
    inorder(p);

    /*          1
    //         / \
              2   55
    //       / \  /  
            32 31 13
    */


}