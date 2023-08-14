#include <stdio.h>
#define MAX_SIZE 32

typedef struct node{
	int data;
	struct node *left,*right;
};

struct node *root=NULL;
int totalNodes = 0;

struct node *createNode(int x){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = x;
	ptr->left = NULL;
	ptr->right = NULL;
	totalNodes+=1;
	return ptr;
}

void createTree(int x){
	int choice=0;
	if(!root){
		root = createNode(x);
		printf("\nData entered at root.\n");
		return;
	}
	struct node *ptr = root;
	while(ptr){
		printf("(0:left 1:right) | Current node: %d",ptr->data);
		scanf("%d",&choice);
		if(choice==0 || choice==1){
			if(choice==0 && ptr->left)   ptr=ptr->left;
			else if(choice==1 && ptr->right)   ptr=ptr->right;
			else    break;
		}
		else{
			printf("Invalid choice\n");
			continue;
		}
	}
	struct node *new_ptr = createNode(x);
	if(choice==0)   ptr->left = new_ptr;
	else            ptr->right= new_ptr;
	printf("\nData entered.\n");
}

void BFS_showTree(){
	int i=0;
	struct node *q[totalNodes],*bfs[totalNodes];
	if(!root){
		printf("[]");
		return;
	}
	struct node *ptr = root;

	//BFS begin
	while(i<totalNodes){
//		en_q(q,ptr);
//		if(ptr->left && alreadyExists(visited,ptr->left)==0)
//			en_q(q,ptr->left->data);
//			ptr=ptr->left;
//		de_q(q);
		i+=1;
	}
}

void enQ(struct node q[totalNodes],struct node *val){
	q_ptr+=1;
	q[q_ptr]=val;
}
void deQ(struct node q[totalNodes]){
	
}

int main(){
	int choice=0,x=0;
	while(choice==0){
		printf("\nNode value: ");
		scanf("%d",&x);
		createTree(x);
		printf("\n[0:continue | 1:exit system]");
		scanf("%d",&choice);
	}
	struct node *q[totalNodes];
	struct node *ptr = root;
	int i=0;
	while(){
		
	}
	return 0;
}
