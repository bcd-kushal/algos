#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *next;
}node;

node *front = NULL, *rear = NULL;
int totalNodes = 0;

void insertion(int newData){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = newData;
    temp->next = NULL;

    if(!front){
        front = temp;
        rear = temp;
        printf("\t| Data entered.");
        ++totalNodes;
        return;
    }

    rear->next = temp;
    rear = rear->next;
    printf("\t| Data entered.");
    ++totalNodes;
}

void delete_node(){
    if(!front){
        printf("\n\t| Empty queue, nothing to delete.");
        return;
    }
    
    if(front==rear){
        printf("\t| Data deleted. Deleted element = %d",front->data);
        free(front);
        front = rear = NULL;
        --totalNodes;
        return;
    }

    node *x = front->next;
    front->next = NULL;
    printf("\n\t| Data deleted. Deleted element = %d",front->data);
    free(front);
    front = x;
    --totalNodes;
}

void display_queue()
{
    printf("\t| Current queue : [");
    if(!front){
        printf(" ---- Empty Queue ---- ]");
        return;
    }
    node *ptr = front;
    while(ptr->next){
        printf(" %d  <- ",ptr->data);
        ptr = ptr->next;
    }
    printf(" %d ]",ptr->data);
}

void reverse_queue(){
    printf("\t| Reversed queue : [");
    if(!front){
        printf(" ---- Empty Queue ---- ]");
        return;
    }
    int queueStack[totalNodes],i=0;
    node *ptr = front;
    while(ptr){
        queueStack[i] = ptr->data;
        ++i;
        ptr = ptr->next;
    }
    i-=1;
    while(i>=0){
        printf(" %d ",queueStack[i]);
        --i;
    }
    printf("]");
}

void search_element(int searchValue){
    if(!front){
        printf("\n\t| Empty queue, no data present.");
        return;
    }
    int flag = 0, pos = 1;
    node *x = front;
    while(x){
        if(x->data==searchValue){
            if(flag==0)
                printf("\n\t| Search element found in queue. Location = ");
            printf("[ %d ] ",pos);
            ++flag;
        }
        x = x->next;
        ++pos;
    }
    if(flag==0)
        printf("\n\t| Search element %d not present in the queue.",searchValue);
    else
        printf("\n\t\t\t\t\t\t| -> Total occurences = %d",flag);
}

int showOptions(){
    printf("\n--------------------------------------------------\n1. Insertion \t2. Deletion \n3. Display \t4. Reversal \n5. Search for an element\n\tInput : ");
    int x;
    scanf("%d",&x);
    return x;
}

int main(){
    int choice=0,val;
    while(choice!=6){
        choice = showOptions();
        if(choice==6){
            printf("\n\t| Exited.");
            break;
        }
        switch(choice){
            case 1:
                printf("\t| Enter data to insert : ");
                scanf("%d",&val);
                insertion(val);
                break;
            case 2:     
                delete_node();
                break;
            case 3:
                display_queue();
                break;
            case 4:
                reverse_queue();
                break;
            case 5:
                printf("\t| Enter search data : ");
                scanf("%d",&val);
                search_element(val);
                break;
            default:
                printf("\t| Wrong input choice.");
        }
    }
    getchar();
    return 0;
}
