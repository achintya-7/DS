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


// basically inorder traversal 
int isBST (struct node* root){
    
    static struct node *prev = NULL; //prevents the change of value in recursions
    
    if(root != NULL){
        if(!isBST(root->left))
            return 0;

        if(prev!=NULL && root->data <= prev->data)
            return 0;
        
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
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
    
    inorder(p);    
    printf("\n");
    printf("%d", isBST(p)); // 1 for BST and 0 for Not a BST
    


    /*          5
    //         / \
              3   6
    //       / \    
            1  4
    */


}