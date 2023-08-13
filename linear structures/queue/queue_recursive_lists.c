#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *next;
}node;

node *constructNode(){
    int x;
    printf("\nEnter data to insert: ");
    scanf("%d",&x);
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

node *insertData(node *ptr){
    if(!ptr)
        return constructNode();
    if(ptr->next)
        ptr->next = insertData(ptr->next);
    else
        ptr->next = constructNode();
    return ptr;
}

node *deleteData(node *ptr){
    if(!ptr){
        printf("\t| Empty queue, nothing to delete.");
        return NULL;
    }
    printf("\t| Data deleted = %d",ptr->data);
    if(!ptr->next)
        return NULL;
    return ptr->next;
}

node *display_queue(node *ptr){
    if(!ptr){
        printf(" ---- Empty queue ---- ");
        return NULL;
    }
    printf(" %d ",ptr->data);
    if(ptr->next)
        ptr->next = display_queue(ptr->next);
    return ptr;
}

void printQueue(node *head){
    printf("\t| Current queue = [");
    head = display_queue(head);
    printf("]");
}

int showOptions(){
    printf("\n--------------------------------------------------\n1. Insertion \t2. Deletion \n3. Display \tInput : ");
    int x;
    scanf("%d",&x);
    return x;
}

int main(){
    node *head = NULL;
    int choice=0,val;
    while(choice!=4){
        choice = showOptions();
        if(choice==4){
            printf("\t| Exited.");
            break;
        }
        switch(choice){
            case 1:
                head = insertData(head);
                printf("\t| Data entered.");
                break;
            case 2:     
                head = deleteData(head);
                break;
            case 3:
                printQueue(head);
                break;
            default:
                printf("\t| Wrong input choice.");
        }
    }
    getchar();
    return 0;
}