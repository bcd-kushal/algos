#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion(int queue[],int *front, int *rear, int newData){
    if(*rear<MAX){
        queue[*rear+1] = newData;
        *rear+=1;
        if(*front==-1)
            *front+=1;
        printf("\t| Data entered.");
        return;
    }
    printf("\t| Queue is full, cannot insert more elements.");
}

int deletion(int queue[],int *front, int *rear){
    if(*front==-1){
        printf("\n\t| Queue is empty, nothing to delete.");
        return 9999;
    }
    int deleted_data = queue[*front],x=*front;
    if(*rear==0){
        *front=*rear=-1;
        return deleted_data;
    }
    while(x<*rear){
        queue[x] = queue[x+1];
        x+=1;
    }
    *rear-=1;
    return deleted_data;
}

void display_queue(int queue[], int front, int rear){
    printf("\n\t| Current queue : [");
    if(front==-1){
        printf(" ---- Empty Queue ---- ]");
        return;
    }
    while(front<=rear){
        printf(" %d ",queue[front]);
        front+=1;
    }
    printf("]");
}

void reverse_queue(int queue[],int rear){
    printf("\n\t| Reversed queue : [");
    if(rear==-1){
        printf(" ---- Empty Queue ---- ]");
        return;
    }
    while(rear>=0){
        printf(" %d ",queue[rear]);
        rear-=1;
    }
    printf("]");
}

void search_element(int queue[], int front, int rear, int searchData){
    if(rear==-1){
        printf("\n\t| Empty Queue, no data here.");
        return;
    }
    int flag = 0;
    while(front<=rear){
        if(queue[front]==searchData){
            if(flag==0)
                printf("\n\t| Element found in queue. Location in queue =");
            printf(" [ %d ] ",front+1);
            flag+=1;
        }
        front+=1;
    }
    if(flag==0)
        printf("\n\t| Search element %d not present in the queue.",searchData);
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
    int queue[MAX];
    int *front = -1, *rear = -1;
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
                insertion(queue,&front,&rear,val);
                break;
            case 2:     
                val = deletion(queue,&front,&rear);
                if(val!=9999)
                    printf("\n\t| Data deletion succesful. Data deleted = %d",val);
                break;
            case 3:
                display_queue(queue,front,rear);
                break;
            case 4:
                reverse_queue(queue,rear);
                break;
            case 5:
                printf("\n\t| Enter search data : ");
                scanf("%d",&val);
                search_element(queue,front,rear,val);
                break;
            default:
                printf("\t| Wrong input choice.");
        }
    }
    getchar();
    return 0;
}
