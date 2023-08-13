#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}dLL;

dLL *head = NULL,*last = NULL;
int totalNodes = 0;

dLL *constructNode(){
    int x;
    printf("\t| Enter value to insert : ");
    scanf("%d",&x);
    dLL *temp = (dLL*)malloc(sizeof(dLL));
    temp->data = x;
    temp->next = temp->prev = NULL;
    return temp;
}
void insert_node_front(){
    if(!head){
        head = constructNode();
        ++totalNodes;
        last = head;
        printf("\t| Data entered.");
        return;
    }
    dLL *ptr = constructNode();
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    printf("\t| Data entered.");
    ++totalNodes;
}

void insert_node_end(){
    if(!head){
        head = constructNode();
        ++totalNodes;
        last = head;
        printf("\t| Data entered.");
        return;
    }
    dLL *ptr = constructNode();
    last->next = ptr;
    ptr->prev = last;
    last = ptr;
    printf("\t| Data entered.");
    ++totalNodes;
}

void insert_node_pos(int pos){
    if(pos<1 || pos>totalNodes){
        printf("\t| Position is out of limit of list size.");
        return;
    }
    if(!head){
        head = constructNode();
        ++totalNodes;
        last = head;
        printf("\t| Data entered.");
        return;
    }
    if(pos==1){
        insert_node_front();
        return;
    }
    dLL *x = head;
    while(pos!=2){
        x = x->next;
        pos-=1;
    }
    if(x->next==last){
        insert_node_end();
        return;
    }
    dLL *temp = x->next;
    dLL *ptr = constructNode();
    x->next = ptr;
    ptr->next = temp;
    ptr->prev = x;
    temp->prev = ptr;
    ++totalNodes;
    printf("\t| Data entered.");
}

void delete_node_front(){
    if(!head){
        printf("\t| Empty list, nothing to delete.");
        return;
    }
    if(!head->next){
        printf("\t| Data deleted : %d",head->data);
        free(head);
        head = last = NULL;
        --totalNodes;
        return;
    }
    dLL *nxt = head->next;
    printf("\t| Data deleted : %d",head->data);
    head->next = NULL;
    head = nxt;
    head->prev = NULL;
    --totalNodes;
}

void delete_node_end(){
    if(!head){
        printf("\t| Empty list, nothing to delete.");
        return;
    }
    if(!head->next){
        printf("\t| Data deleted : %d",head->data);
        free(head);
        head = last = NULL;
        --totalNodes;
        return;
    }
    dLL *ptr = last->prev;
    printf("\t| Data deleted : %d",last->data);
    last->prev = NULL;
    last = ptr;
    last->next = NULL;
    --totalNodes;
}

void delete_node_pos(int pos){
    if(!head){
        printf("\t| Empty list, nothing to delete.");
        return;
    }
    if(pos<1 || pos>totalNodes){
        printf("\t| Position value out of range.");
        return;
    }
    if(pos==1){
        delete_node_front();
        return;
    }
    dLL *ptr = head;
    while(pos!=2){
        pos-=1;
        ptr = ptr->next;
    }
    if(ptr->next==last){
        delete_node_end();
        return;
    }
    dLL *nxt = ptr->next;
    printf("\t| Data deleted : %d",nxt->data);
    dLL *prev_nxt = nxt->next;
    ptr->next = prev_nxt;
    nxt->next = NULL;
    nxt->prev = NULL;
    free(nxt);
    prev_nxt->prev = ptr;
    --totalNodes;
}

void printList(){
    printf("\t| Current list : [");
    if(!head){
        printf(" ---- Empty List ---- ]");
        return;
    }
    dLL *ptr = head;
    while(ptr->next){
        printf(" %d <->",ptr->data);
        ptr = ptr->next;
    }
    printf(" %d ]",ptr->data);
}

void printRevList(){
    printf("\t| Reversed list : [");
    if(!head){
        printf(" ---- Empty List ---- ]");
        return;
    }
    dLL *ptr = last;
    while(ptr->prev){
        printf(" %d ->",ptr->data);
        ptr = ptr->prev;
    }
    printf(" %d ]",ptr->data);
}

int showOptions(){
    int x;
    printf("\n-----------------------------------------");
    printf("\nInsertion : 1.Front\t2.Position\t3.End\nDeletion : 4.Front\t5.Position\t6.End\n7.Print list\t8.Print reverse list\t9.Exit\n\t\t|| Input : ");
    scanf("%d",&x);
    return x;
}

int main(){
    int choice = 0;
    int val;
    while(1){
        choice = showOptions();
        if(choice==9)
            break;
        switch(choice){
            case 1:
                insert_node_front();
                break;
            case 2:
                printf("\t| Enter position to enter (Total nodes currently present = %d) : ",totalNodes);
                scanf("%d",&val);
                insert_node_pos(val);
                break;
            case 3:
                insert_node_end();
                break;
            case 4:
                delete_node_front();
                break;
            case 5:
                printf("\t| Enter position to delete (Total nodes currently present = %d) : ",totalNodes);
                scanf("%d",&val);
                delete_node_pos(val);
                break;
            case 6:
                delete_node_end();
                break;
            case 7:
                printList();
                break;
            case 8:
                printRevList();
                break;
            default:
                printf("\t| Wrong input");
        }
    }
    printf("\t| Exited.");
    scanf("%d",&val);
    return 0;
}
