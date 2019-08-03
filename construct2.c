#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        struct node* left;
        struct node* right;
};
int search(int arr[], int strt, int end, int value)
{
        int i;
        for (i = strt; i <= end; i++) {
                if (arr[i] == value)
                        return i;
        }
}
struct node* newNode(int data){
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return (node);
}
struct node* buildTree(int in[], int pre[], int inStrt, int inEnd){
        static int preIndex = 0;
        if (inStrt > inEnd) return NULL;
        struct node* tNode = newNode(pre[preIndex++]);
        if (inStrt == inEnd) return tNode;
        int inIndex = search(in, inStrt, inEnd, tNode->data);
        tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
        tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
        return tNode;
}
void postorder(struct node* node){
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        printf("--%d--",node->data);
}
void inorder(struct node* root){
        if(root == NULL) return;
        inorder(root->left);
        printf("--%d--",root->data);
        inorder(root->right);
}
void preorder(struct node* root){
        if(root == NULL) return;
        printf("--%d--",root->data);
        preorder(root->left);
        preorder(root->right);
      }
      int main() {
              printf("Enter no of Nodes");
              int i,n;
              scanf("%d",&n);
              int in[n];
              int pre[n];
              printf("Enter inorder traversal");
              for(i=0;i<n;i++) scanf("%d",&in[i]);
              printf("Enter preorder traversal");
              for(i=0;i<n;i++) scanf("%d",&pre[i]);
              struct node* root = buildTree(in, pre, 0, n - 1);
              printf("\npostorder traversal of the constructed tree is \n");
              postorder(root);
              printf("\nInorder traversal of the constructed tree is \n");
              inorder(root);
              printf("\npreorder traversal of the constructed tree is \n");
              preorder(root);
      }
