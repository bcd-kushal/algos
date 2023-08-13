#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
}cLL;

cLL *head=NULL,*tail=NULL;
int totalNodes=0;

cLL *newNode(){
    int newData;
    printf("\t| Enter data to insert: ");
    scanf("%d",&newData);

    cLL *temp = (cLL*)malloc(sizeof(cLL));
    temp->data = newData;
    temp->next = NULL;
    return temp;
}

void insert_node_end(){
    if(!head){
        head = tail = newNode();
        printf("\t| Data entered.");
        ++totalNodes;
        tail->next = head;
        return;
    }

    cLL *temp = newNode();
    tail->next = temp;
    tail = temp;
    tail->next = head;
    printf("\t| Data entered.");
    ++totalNodes;
}

void insert_node_front(){
    if(!head){
        head = tail = newNode();
        printf("\t| Data entered.");
        tail->next = head;
        ++totalNodes;
        return;
    }
    cLL *x = newNode();
    x->next = head;
    head = x;
    tail->next = head;
    printf("\t| Data entered.");
    ++totalNodes;
}

void insert_node_pos(int pos){
    if(pos<1 || pos>totalNodes){
        printf("\t| Position is out of limit of list size.");
        return;
    }
    if(!head){
        head = tail = newNode();
        printf("\t| Data entered.");
        ++totalNodes;
        tail->next = head;
        return;
    }

    if(pos==1){
        insert_node_front();
        return;
    }

    cLL *ptr = head;

    while(pos!=2){
        pos-=1;
        ptr = ptr->next;
    }

    if(ptr->next==tail){
        insert_node_end();
        return;
    }

    cLL *next_ptr = ptr->next;
    cLL *x = newNode();
    ptr->next = x;
    x->next = next_ptr;
    printf("\t| Data entered at given position.");
    ++totalNodes;
}

void delete_node_front(){
    if(!head){
        printf("\t| Empty list, nothing to delete.");
        return;
    }
    if(!head->next){
        printf("\t| Data deleted : %d",head->data);
        --totalNodes;
        free(head);
        head = tail = NULL;
        return;
    }
    cLL *ptr = head->next;
    tail->next = ptr;
    head->next = NULL;
    printf("\t| Data deleted : %d",head->data);
    --totalNodes;
    free(head);
    head = ptr;
}

void delete_node_pos(int pos){
    if(!head){
        printf("\t| Empty list, nothing to delete.");
        return;
    }
    if(pos<1 || pos>totalNodes){
        printf("\t| Position is out of limit of list size.");
        return;
    }
    if(!head->next){
        printf("\t| Data deleted : %d",head->data);
        --totalNodes;
        free(head);
        head = tail = NULL;
        return;
    }
    if(pos==1){
        delete_node_front();
        return;
    }
    cLL *x = head;
    while(pos!=2){
        pos-=1;
        x = x->next;
    }
    if(x->next==tail){
        delete_node_end();
        return;
    }
    cLL *nxt = x->next;
    printf("\t| Data deleted : %d",nxt->data);
    --totalNodes;
    nxt = nxt->next;
    x->next = nxt;
}

void delete_node_end(){
    if(!head){
        printf("\t| Empty list, nothing to delete.");
        return;
    }
    if(head->next==head){
        printf("\t| Data deleted : %d",head->data);
        --totalNodes;
        free(head);
        head = tail = NULL;
        return;
    }
    cLL *x = head;
    while(x->next!=tail)
        x = x->next;
    x->next = head;
    printf("\t| Data deleted : %d",tail->data);
    --totalNodes;
    tail->next = NULL;
    free(tail);
    tail=x;
}

void print_list(){
    printf("\t| Current list : [");
    if(!head){
        printf(" ---- Empty List ---- ]");
        return;
    }
    cLL *ptr = head;
    while(ptr->next!=head){
        printf(" %d ->",ptr->data);
        ptr = ptr->next;
    }
    printf(" %d ]",ptr->data);
}

int showOptions(){
    int x;
    printf("\n-----------------------------------------");
    printf("\nInsertion : 1.Front\t2.Position\t3.End\nDeletion : 4.Front\t5.Position\t6.End\n7.Print list\t8. Exit\n\t\t|| Input : ");
    scanf("%d",&x);
    return x;
}

int main(){
    int choice = 0;
    int val;
    while(1){
        choice = showOptions();
        if(choice==8)
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
                print_list();
                break;
            default:
                printf("\t| Wrong input");
        }
    }
    printf("\t| Exited.");
    scanf("%d",&val);
    return 0;
}
