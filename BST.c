#include<stdio.h>
#include<stdlib.h>

struct BST
{
    /* data */
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST node;

node *root=NULL;

node* insert(node *root ,int data){
    // creating new node 
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    // place the node in proper position 
    if(root==NULL){
        root=newNode;
    }
    else if (root->data>data)
    {
        /* code */
        insert(root->left,data);
    }else
    {
        insert(root->right,data);
    }
    
    
}
int search(node *root ,int searchingElemet){
    if(root==NULL)
    return 0;
    else
    {
        if(root->data==searchingElemet){
            return 1;
        }
        else if(root->data>searchingElemet){
            search(root->left,searchingElemet);
        }
        else
        {
            search(root->right,searchingElemet);
        }
        
    }
    
}
int main(){
    int data;
    char ch;
    do
    {
        /* code */
        printf("Enter the data :");
        fflush(stdin);
        scanf("%d",&data);
        root=insert(root,data);
        printf("do you want to continue [y/n]");
        fflush(stdin);
        scanf("%c",&ch);
    } while (ch!='n');
    
    int searchinelement;
    printf("Enter the searching Element :");
    scanf("%d",&searchinelement);
    if(search(root,searchinelement))
    printf("Search Successful");
    else
    {
        printf("Search Unsuccessful");
    }
    
    return 0;
}