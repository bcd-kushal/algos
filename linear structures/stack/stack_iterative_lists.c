#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct stack *top;
}stack;

stack *head = NULL, *top = NULL;
int size = 0;

void push(int newData){
    stack *x = (stack*)malloc(sizeof(stack));
    x->data = newData;
    x->top = NULL;

    if(!head){
        head = top = x;
        printf("\t| Data entered.");
        ++size;
        return;
    }
    top->top = x;
    top = x;
    printf("\t| Data entered."); 
    ++size;   
}

void pop(){
    if(!head){
        printf("\t| Empty Stack nothing to delete.");
        return;
    }
    if(head==top){
        printf("\t| Data deleted : %d",head->data);
        free(head);
        head = top = NULL;
        --size;
        return;
    }
    stack *ptr = head;
    while(ptr->top!=top)
        ptr = ptr->top;
    ptr->top = NULL;
    printf("\t| Data deleted : %d",top->data);
    free(top);
    top = ptr;
    --size;
}

void printStack(){
    if(!head){
        printf("\t| [ ---- Empty Stack ---- ]");
        return;
    }
    printf("\t| Current stack : ");
    stack *ptr=head;
    int i=0,stack_arr[size];
    while(ptr){
        stack_arr[i] = ptr->data;
        ++i;
        ptr = ptr->top;
    }
    i-=1;
    while(i>=0){
        printf("\n\t\t|\t%d\t|",stack_arr[i]);
        --i;
    }
}

int showOptions(){
    int x;
    printf("\n-----------------------------------------");
    printf("\n1.Push element\t\t2.Pop element\n3.Display current stack \t\t|| Input : ");
    scanf("%d",&x);
    return x;
}

int main(){
    int choice=0,x;
    while(choice!=4){
        choice = showOptions();
        switch(choice){
            case 1:
                printf("\t| Enter data to enter : ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
            default:
                printf("\t| Exited.  ");
        }
    }
    scanf("%d",&choice);
    return 0;
}