#include<stdio.h>
#include<stdlib.h>
struct node {
  int key;
  struct node * left;
  struct node * right;
};

struct node * casea(struct node *,struct node *,struct node *);
struct node * caseb(struct node *,struct node *,struct node *);
struct node * casec(struct node *,struct node *,struct node *);

int search(struct node * tree , int key){
struct node * temp;
temp=NULL;
while(tree!=NULL){
  if(key<tree->key){
    temp=tree;
    tree=tree->left;
  }
  if(key>tree->key){
    temp=tree;
    tree=tree->right;
  }
  if(key==tree->key){
    printf("element found\n");
    printf("parent/predecessor of the given key is %d\n",temp->key);
    return key;
  }

}
return 0;
}




void minimum(struct node * tree){
  if(tree!=NULL){
    while(tree->left!=NULL){
      tree=tree->left;
    }
  }
  printf("the smallest value is %d\n",tree->key);
}




void maximum(struct node * tree){
  if(tree!=NULL){
    while(tree->right!=NULL){
      tree=tree->right;
    }
  }
  printf("the maximum value is %d",tree->key);
}




struct node * insert (struct node * root,int k){
  struct node *tmp, *parent, *current;
  current=root;
  parent=NULL;
  while(current!=NULL)
  {
    parent=current;
    if(k<current->key)
        current=current->left;
    else if(k>current->key)
        current=current->right;
    else{
      printf("duplicate key\n");
      return root;
    }
  }
  tmp=(struct node *)malloc(sizeof(struct node));
  tmp->key=k;
  tmp->left=NULL;
  tmp->right=NULL;
  if(parent==NULL)
    root=tmp;
  else if(k<parent->key)
    parent->left=tmp;
  else
    parent->right=tmp;
  return root;


}



struct node * delete(struct node * root,int k){
  struct node * parent;
  struct node * current;
  current=root;
  parent=NULL;
  while(current!=NULL){
    if(k==current->key)
    {break;}
    parent=current;
    if(k<current->key){
      current=current->left;
    }
    else{
      current=current->right;
    }
  }
  if(current==NULL){
    printf("the searched key is not present in the tree");
  }
  if(current->left==NULL && current->right==NULL)//no child case
  {
    root=casea(root,parent,current);
  }
  if(current->left!=NULL && current->right==NULL)//only left child
  {
    root=caseb(root,parent,current);
  }
  if(current->right!=NULL && current->left==NULL)//only right child
  {
    root=caseb(root,parent,current);
  }
  if(current->right!=NULL && current->left!=NULL)//both childs are present
  {
    root=casec(root,parent,current);
  }
  return root;
}
struct node * caseb(struct node * root,struct node * parent,struct node * current){
  struct node * child;
  if(current->left==NULL){
    child=current->right;
  }
  if(current->right==NULL){
    child=current->left;
  }
  if(parent==NULL){
    root=child;
  }
  if(current==parent->right){
    parent->right=child;
  }
  if(current==parent->left){
    parent->left=child;
  }
  free(current);
  return root;
}
struct node * casec(struct node * root, struct node* parent, struct node * current){
  struct node * succ;
  struct node * succpar;
  succpar=current;
  succ=current->right;
  while(succ->left!=NULL){
    succpar=succ;
    succ=succ->left;
  }
  current->key=succ->key;
  if(succ->left==NULL && succ->right==NULL){
    root=casea(root,succpar,succ);
  }
  else{
    root=caseb(root,succpar,succ);
  }
  return root;
}
struct node * casea(struct node * root, struct node * parent, struct node * current)
{
  if (parent==NULL){
    root=NULL;
  }
  if(current==parent->left){
    current->left=NULL;
  }
  if(current==parent->right){
    current->right=NULL;
  }
  free(current);
  return root;
}


void preorder(struct node * current){
  if(current==NULL){
    return;
  }
  printf("%d\n",current->key);
  preorder(current->left);
  preorder(current->right);
}

void inorder(struct node * current){
  if(current==NULL){
    return;
  }
  inorder(current->left);
  printf("%d\n",current->key);
  inorder(current->right);
}

void postorder(struct node * current){
  if(current==NULL){
    return;
  }
  postorder(current->left);
  postorder(current->right);
  printf("%d\n",current->key);
}

int height(struct node * current){
  int hl ,hr;
  if(current == NULL){
    return 0;
  }
  hl=height(current->left);
  hr=height(current->right);
  if(hl>hr){
    return hl+1;
  }
  else{
    return hr+1;
  }
}


int main(){
     struct node * root;
     root=NULL;
     int key, choice;
     while(choice!=9){
       printf("1.Insert\n");
       printf("2.Search/predecessor\n");
       printf("3.Delete\n");
       printf("4.Preorder Traversal\n");
       printf("5.Inorder Traversal\n");
       printf("6.Postorder Traversal\n");
       printf("7.Minimum\n");
       printf("8.Maximum\n");
       printf("9.Quit\n");
       printf("10.Height\n");
       printf("Enter your choice\n");
       scanf("%d",&choice);
       switch(choice) {
         case 1:
         printf("Enter the value of the key to be inserted\n");
         scanf("%d",&key);
         root=insert(root,key);
         break;

         case 2:
         printf("enter the key to be searched\n");
         scanf("%d",&key);
         search(root,key);
         break;

         case 3:
         printf("Enter the key to be deleted\n");
         scanf("%d",&key);
         root= delete(root,key);
         break;

         case 4:
         preorder(root);
         break;

         case 5:
         inorder(root);
         break;

         case 6:
         postorder(root);
         break;

         case 7:
         minimum(root);
         break;

         case 8:
         maximum(root);
         break;

         case 10:
         printf("the height of the tree is %d\n",height(root));
         break;
       }
     }
     return 0;

}
