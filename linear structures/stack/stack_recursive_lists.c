#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct stack *top;
}stack;

stack *top_element = NULL;

stack *constructNode(){
    int newData;
    printf("\t| Enter data to enter : ");
    scanf("%d",&newData);
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = newData;
    temp->top = NULL;
    return temp;
}

stack *push(stack *ptr){
    if(!ptr){
        stack *x = constructNode();
        top_element = x;
        printf("\t| Data entered.");
        return x;
    }
    ptr->top = push(ptr->top);
    return ptr;
}

stack *pop(stack *ptr){
    if(!ptr){
        printf("\t| Empty Stack, nothing to pop.");
        return NULL;
    }
    if(ptr==top_element){
        printf("\t| Data popped : %d",top_element->data);
        top_element = NULL;
        return NULL;
    }
    if(ptr->top == top_element){
        printf("\t| Data popped : %d",top_element->data);
        ptr->top = NULL;
        free(top_element);
        top_element = ptr;
        return ptr;
    }
    ptr->top = pop(ptr->top);
    return ptr;
}

stack *printStack(stack *ptr){
    if(!ptr){
        printf("  [ ---- Empty stack ---- ]");
        return NULL;
    }
    if(ptr->top)
        ptr->top = printStack(ptr->top);
    printf("\n\t\t|\t%d\t|",ptr->data);
    return ptr;
}

int showOptions(){
    int x;
    printf("\n-----------------------------------------");
    printf("\n1.Push element\t\t2.Pop element\n3.Display current stack \t\t|| Input : ");
    scanf("%d",&x);
    return x;
}

int main(){
    stack *head=NULL;
    int choice=0;
    while(choice!=4){
        choice = showOptions();
        switch(choice){
            case 1:
                head=push(head);
                break;
            case 2:
                head=pop(head);
                break;
            case 3:
                printf("\t| Current stack : ");
                head=printStack(head);
                break;
            default:
                printf("\t| Exited.  ");
        }
    }
    scanf("%d",&choice);
    return 0;
}
