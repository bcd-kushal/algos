#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int push(int stack[],int *top,int totalPushTimes){
    if(totalPushTimes==0)
        return 0;
    if(*top+1>=MAX){
        printf("\t| Stack has become full, cannot enter more %d elements.",totalPushTimes);
        return -1;
    }
    *top+=1;
    stack[*top]=insert();
    return push(stack,top,totalPushTimes-1);
}

int pop(int stack[],int *top,int totalPopTimes){
    if(totalPopTimes==0)
        return 0;
    if(*top==-1){
        printf("\n\t| Reached empty stack, cannot pop more %d elements.",totalPopTimes);
        return -1;
    }
    printf(" [ %d ]",stack[*top]);
    *top-=1;
    return pop(stack,top,--totalPopTimes);
}

int printStack(int stack[],int top){
    if(top==-1){
        printf("\t| [ ---- Empty Stack ---- ]");
        return -1;
    }
    printf("\n\t\t|\t%d\t|",stack[top]);
    if(top==0)
        return 0;
    return printStack(stack,top-1);
}

int showOptions(){
    int x;
    printf("\n-----------------------------------------");
    printf("\n1.Push element\t2.Pop element\n3.Display current stack \t\t|| Input : ");
    scanf("%d",&x);
    return x;
}

int main(){
    int stackArray[MAX];
    int choice=0, top=-1, totalTimes=0;
    while(choice!=4){
        choice = showOptions();
        switch(choice){
            case 1:
                printf("\t| How many times to push at once? ");
                scanf("%d",&totalTimes);
                push(stackArray,&top,totalTimes);
                break;
            case 2:
            printf("\t| How many times to pop at once? ");
                scanf("%d",&totalTimes);
                pop(stackArray,&top,totalTimes);
                break;
            case 3:
                printStack(stackArray,top);
                break;
            default:
                printf("\t| Exited.  ");
        }
    }
    scanf("%d",&choice);
    return 0;
}

