#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct list *next;
}list;

list *head = NULL;
int total_Nodes = 0;

void insert_data_front(){
    
}

void insert_data_end(){
    int newData;
    printf("\t| Enter data to enter : ");
    scanf("%d",&newData);

    list *temp = (list*)malloc(sizeof(list));
    temp->data = newData;
    temp->next = NULL;

    if(!head){
        head = temp;
        printf("\t| Data entered.");
        return;
    }

    list *ptr = head;
    while(ptr->next)
        ptr = ptr->next;
    
    ptr->next = temp;
    printf("\t| Data entered.");
    ++total_Nodes;
}

void delete_node_end(){
    if(!head){
        printf("\t| Empty List, nothing to delete.");
        return;
    }
    if(!head->next){
        printf("\t| Data deleted : %d",head->data);
        --total_Nodes;
        head = NULL;
        return;
    }
    list *ptr = head->next;
    list *prev_ptr = head;
    while(ptr->next){
        ptr=ptr->next;
        prev_ptr = prev_ptr->next;
    }
    prev_ptr->next = NULL;
    printf("\t| Data deleted : %d",ptr->data);
    free(ptr);
    --total_Nodes;
}

void printList(){
    if(!head){
        printf("[ ---- Empty List ---- ]");
        return;
    }
    printf("\t| Current list : ");
    list *ptr = head;
    while(ptr->next){
        printf("[ %d ] -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("[ %d ]\n\t\t\t| Total nodes = %d",ptr->data,total_Nodes);
}

