#include <stdio.h>
#include <stdlib.h>
#define MAX 7

void push(int stack[],int *top){
    int newData;
    if(*top+1<MAX){
        *top+=1;
        printf("\t| Enter data to insert : ");
        scanf("%d",&newData);
        stack[*top]=newData;
        printf("\t| Data is entered.");
        return;
    }
    printf("\n\t| Stack is full, cannot enter more elements.");
}

void pop(int stack[],int *top){
    if(*top==-1){
        printf("\t| Empty Stack, cannot pop anymore elements.");
        return;
    }
    printf("\t| Data popped : %d",stack[*top]);
    *top-=1;
}

void printStack(int stack[],int top){
    if(top==-1){
        printf("\t| [ ---- Empty Stack ---- ]");
        return;
    }
    printf("\t| Current stack :");
    int c = top;
    while(top>=0){
        printf("\n\t\t|\t%d\t|",stack[top]);
        if(c==top)
            printf("  <---- top");
        top-=1;
    }
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
    int choice=0, top=-1;
    while(choice!=4){
        choice = showOptions();
        switch(choice){
            case 1:
                push(stackArray,&top);
                break;
            case 2:
                pop(stackArray,&top);
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

