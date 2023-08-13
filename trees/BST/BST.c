#include <stdio.h>
#include <stdlib.h>

int count=0;
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *creation(int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
    count+=1;
}

struct node *insertion(struct node *ptr, int x){
    struct node *creation(int);

    if(!ptr){
        ptr = creation(x);
        return ptr;
    }
    if(x<ptr->data)
        ptr->left = insertion(ptr->left,x);
    if(x>ptr->data)
        ptr->right = insertion(ptr->right,x);
    return ptr;
}

struct node *printBST(struct node *ptr){
    if(ptr->left!=NULL)
        ptr->left = printBST(ptr->left);
    printf(" %d ",ptr->data);
    if(ptr->right!=NULL)
        ptr->right = printBST(ptr->right);
}

struct node *delete(struct node *ptr, int x){
    int findMinimum(struct node*);

    if(!ptr)
        return NULL;
    
    //traverse to the deletetion node
    if(x<ptr->data)
        ptr->left = delete(ptr->left,x);
    else if(x>ptr->data)
        ptr->right = delete(ptr->right,x);
    
    else{
        //for no child in the node
        if(ptr->left==NULL && ptr->right==NULL){
            free(ptr);
            --count;
            return NULL;
        }

        //for single child in the node
        if(ptr->left==NULL && ptr->right==NULL){
            struct node *temp;

            if(ptr->left==NULL)
                temp->right = ptr->right;
            if(ptr->right==NULL)
                temp->left = ptr->left;

            free(ptr);
            --count;
            return temp;
        
        }

        //for double children in the node
        if(ptr->left&&ptr->right){
            int min = findMinimum(ptr->right);
            ptr->data = min;
            ptr->right = delete(ptr->right,min);
        }
    }
    return ptr;
}

int findMinimum(struct node *ptr){
    if(!ptr->left)
        return ptr->data;
    return findMinimum(ptr->left);
}

int main(){
    struct node *insertion(struct node*,int);
    struct node *printBST(struct node*);
    struct node *creation(int);

    int choice;
    struct node *head = creation(30);
    while(1){
        printf("\n1. Enter data \n2. Show data \n3. Delete a node \nOther key to exit\nEnter your choice : ");
        scanf("%d",&choice);

        if(choice == 1){
            int data;
            printf("\nEnter data : ");
            scanf("%d",&data);
            head = insertion(head,data);
            continue;
        }
        if(choice == 2){
            if(!head){
                printf("\nEmpty BST.");
                continue;
            }
            printf("\nCurrent BST = [");
            printBST(head);
            printf("]\n");
            continue;
        }
        if(choice == 3){
            if(!head){
                printf("\nEmpty BST.");
                continue;
            }
            int searchElement;
            printf("\nEnter data to delete : ");
            scanf("%d",&searchElement);
            head = delete(head,searchElement);
            continue;
        }
        else{
            printf("\nExited.\nFinal BST = [");
            printBST(head);
            printf("]\n");
            break;
        }
    }

    return 0;
}