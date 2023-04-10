#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int height;
    int value;
}Nd;
Nd*glob_root=NULL;

void display(Nd*root)
{
    
    printf("%d  ",root->value);
    if (root->left!=NULL) printf("%d  ",root->left->value);
    if (root->right!=NULL) printf("%d",root->right->value);
    printf("\n");
    if (root->left!=NULL) display((root->left));
    if (root->right!=NULL) display((root->right));

}
Nd* newNode(int value)
{
    Nd* node = (Nd*)malloc(sizeof(Nd));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->value = value;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int height(Nd* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

void rightRotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* leftChild = root->left;
    Nd* leftChildRightChild = leftChild->right;
    leftChild->right = root;
    root->left = leftChildRightChild;
    root->height = max(height(root->left), height(root->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;
    *root_adr = leftChild;
}

void leftRotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* rightChild = root->right;
    Nd* rightChildLeftChild = rightChild->left;
    rightChild->left = root;
    root->right = rightChildLeftChild;
    root->height = max(height(root->left), height(root->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;
    *root_adr = rightChild;
}

void insert(Nd** root_adr, int value)
{
    Nd *root = *root_adr;
    if (root == NULL)
    {
        root = newNode(value);
        *root_adr = root;
        return;
    }
    if (root->value > value)
        insert(&(root->left), value);
    else if (root->value < value)
        insert(&(root->right), value);
    else
        return;
    root->height = max(height(root->left), 
                       height(root->right)) +1;
    int balance = height(root->left) - height(root->right);
    if (balance > 1)
    {
        if (value > root->left->value)
        {
            leftRotation(&(root->left));
            rightRotation(&root);
        }
        else
            rightRotation(&root);
    }
    if (balance < -1)
    {
        if (value < root->right->value)
        {
            rightRotation(&(root->right));
            leftRotation(&root);
        }
        else
            leftRotation(&root);
    }
    *root_adr = root;
}

bool find(Nd* root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    else if (root->value > value)
        return find(root->left, value);
    else
        return find(root->right, value);
}
void treefree(Nd*root)
{
    if (root==NULL) return;

    if (root->left!=NULL)
    {
        treefree(root->left);
    }
    if (root->right!=NULL)
    {
        treefree(root->right);
    }
    free(root);
    
}
int Min(Nd**root_adr)
{

    Nd*root=*root_adr;
    
    if(root->left==NULL) 
    {


        int a=root->value;
        Nd*tem=root;
        *root_adr=tem->right;
        free(root);
        return a;
    }
    else  
    {
      
        int tem=Min(&(root->left));
        root->height = max(height(root->left), 
                            height(root->right)) +1;
        int balance = height(root->left) - height(root->right);
        
        if (balance > 1)
        {
            if (root->left->left==NULL)
            {
                leftRotation(&(root->left));
                rightRotation(&root);
               

            }
            else
                rightRotation(&root);
                
        }
        if (balance < -1)
        {
            if ( root->right->right==NULL)
            {
                rightRotation(&(root->right));
                leftRotation(&root);
                

            }
            else
                leftRotation(root_adr);
        }
        return tem;
    }
    


}

void delete(Nd**root_adr,int k)
{
    Nd*root=*root_adr;
    int curent=root->value;
    if (root == NULL)return ;
    if (root->value==k)
    {
        if(root->right==NULL)
        {
            *root_adr=root->left;return ;
        }
        int min=Min(&(root->right));
        root->value=min;

    }

    else if (root->value > k)
        delete(&(root->left), k);
    else
        delete(&(root->right),k);

    root->height = max(height(root->left), 
                       height(root->right)) +1;
    int balance = height(root->left) - height(root->right);
   
   if (balance > 1)
    {
        if (root->left->left==NULL)
        {
            leftRotation(&(root->left));
            rightRotation(root_adr);
            

        }
        else
            rightRotation(root_adr);
           
    }
    if (balance < -1)
    {
        if ( root->right->right==NULL)
        {
            rightRotation(&(root->right));
            leftRotation(root_adr);
            

        }
        else
            leftRotation(root_adr);
    }

}

int main()
{
    Nd*root=NULL;
    insert(&root,3);
    insert(&root,2);
    insert(&root,4);
    insert(&root,5);
    delete(&root,2);
    printf("-------------------------------------------------------\n");
    display(root);
    treefree(root);
}