#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insertNewNode(int num){
    struct node *x = (struct node*)malloc(sizeof(struct node)); 
    x->data = num;
    x->right=NULL;
    x->left=NULL;

    struct node *curr = root;
    struct node *prev = NULL;

    while (curr != NULL) {
        prev = curr;
        if (num < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (prev == NULL) {
        prev = x;
        root = prev;
    }
    else if (num < prev->data)
        prev->left = x;
    else
        prev->right = x;
}

struct node *preorder(struct node *ptr){
    if(!ptr)
        return NULL;
    printf(" %d ",ptr->data);
    ptr->left = preorder(ptr->left);
    ptr->right = preorder(ptr->right);
    return ptr;
}

struct node *inorder(struct node *ptr){
    if(!ptr)
        return NULL;
    ptr->left = preorder(ptr->left);
    printf(" %d ",ptr->data);
    ptr->right = preorder(ptr->right);
    return ptr;
}

struct node *postorder(struct node *ptr){
    if(!ptr)
        return NULL;
    ptr->left = preorder(ptr->left);
    ptr->right = preorder(ptr->right);
    printf(" %d ",ptr->data);
    return ptr;
}

int showOptions(){
    printf("\n1.Insert Node\n2.Preorder traversal\n3.Inorder Traversal\n3.Postorder Traversal\n4.Exit\nEnter choice: ");
    int x;
    scanf("%d",&x);
    return x;
}

int main(){
    int ch=0,x;

    while(ch!=4){
        ch=showOptions();
        if(ch==4)
            break;
        switch(ch){
            case 1:
            printf("\nEnter data to insert: ");
            scanf("%d",&x);
            insertNewNode(x);
            break;
            case 2:
            printf("\nCurrent tree: [ ");
            root = preorder(root);
            printf(" ]");
            break;
            case 3:
            printf("\nCurrent tree: [ ");
            root = inorder(root);
            printf(" ]");
            break;
            case 4:
            printf("\nCurrent tree: [ ");
            root = postorder(root);
            printf(" ]");
            break;
        }
    }
    printf("\nExited.");
    scanf("%d",&x);
    return 0;
}
