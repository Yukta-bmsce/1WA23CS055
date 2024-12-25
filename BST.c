BST
#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;

node *create()
{
    node *temp;
    printf("input data:");
    temp=(node*)malloc(sizeof(node));
    scanf("%d",&temp->data);
    temp->right=temp->left=NULL;
    return temp;
}
 void insert(node *root,node *temp)
 {
     if(temp->data<root->data)
     {
         if(root->left!=NULL){
          insert(root->left,temp);
         }
         
     
     else
     {
     
         root->left=temp;
     }
     }
     else if(temp->data>root->data)
     {
         if(root->right!=NULL)
         {
             insert(root->right,temp);
         }
         else
         {
             root->right=temp;
         }
         
     }
 }
 
 void preorder(node *root)
 {
     if(root!=NULL)
     {
         printf("%d ",root->data);
         preorder(root->left);
         preorder(root->right);
         
     }
 }
 
 void inorder(node *root)
 {
     if(root!=NULL)
     {
         inorder(root->left);
         printf("%d ",root->data);
         inorder(root->right);
     }
 }
 void postorder(node *root)
 {
     if(root!=NULL)
     {
         postorder(root->left);
         postorder(root->right);
         printf("%d ",root->data);
     }
 }
 
 void main()
 {
     int choice;
     node *root=NULL,*temp;
     do{
         printf("\n***BST***\n");
         printf("1.create\n2.insert\n3.preorder\n4.inorder\n5.postorder\n");
         printf("6.exit\n");
         printf("enter choice:");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:root=create();
             break;
             
             case 2:temp=create();
                   if(root!=NULL)
                     insert(root,temp);
                   else
                     root=temp;
                    printf("insertion complete");
             break;
             
             case 3:preorder(root);
             break;
             
             case 4:inorder(root);
             break;
             
             case 5:postorder(root);
             break;
             
             case 6:printf("exit");
             break;
             
             default:printf("enter valid choice:");
             
             
         }
     }while(choice!=6);
     return 0;
 }