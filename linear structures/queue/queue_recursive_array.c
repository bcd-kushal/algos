#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int insertion(int q[],int *rear,int front,int val){
    if(front+1>MAX){
        printf("\t| Queue is full, cannot enter more elements.");
        return -1;
    }
    if(front==-1){
        q[0]=val;
        *rear=0;
        printf("\t| Data entered.");
        return 0;
    }
    if(front<*rear)
        return insertion(q,rear,front+1,val);
    q[front+1]=val;
    *rear+=1;
    printf("\t| Data entered.");
    return 1;
}

int queue_elements(int q[],int front,int rear){
    if(front==-1){
        printf(" ---- Empty Queue ----");
        return -1;
    }
    printf(" %d ",q[front]);
    if(front+1<=rear)
        return queue_elements(q,front+1,rear);
    return 0;
}

void display_queue(int q[],int front,int rear){
    printf("\t| Current queue = [");
    queue_elements(q,front,rear);
    printf("]");
}

int delete_element(int q[],int front,int *rear,int x){
    if(front==-1){
        printf("\t| Empty queue, nothing to delete.");
        return -2;
    }
    if(x==0){
        printf("\t| Data element deleted = %d",q[front]);
        if(*rear==0){
            *rear=-1;
            return -1;
        }
        x=1;
    }
    if(front+1>*rear){
        *rear-=1;
        return 0;
    }
    q[front]=q[front+1];
    return delete_element(q,front+1,rear,x);    
}

int showOptions(){
    printf("\n--------------------------------------------------\n1. Insertion \t2. Deletion \n3. Display \tInput : ");
    int x;
    scanf("%d",&x);
    return x;
}

int main(){
    int queue[MAX];
    int *front = -1, *rear = -1;
    int choice=0,val;
    while(choice!=4){
        choice = showOptions();
        if(choice==4){
            printf("\t| Exited.");
            break;
        }
        switch(choice){
            case 1:
                printf("\t| Enter data to insert : ");
                scanf("%d",&val);
                if(insertion(queue,&rear,front,val)==0)
                    front = 0;
                break;
            case 2:     
                if(delete_element(queue,front,&rear,0)==-1)
                    front = -1;
                break;
            case 3:
                display_queue(queue,front,rear);
                break;
            default:
                printf("\t| Wrong input choice.");
        }
    }
    getchar();
    return 0;
}
