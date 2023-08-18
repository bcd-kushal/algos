#include <stdio.h>
#include <stdlib.h>

// adj matrix:  adj_matrix[][]
// name matrix: node[]
// visited:     visited[]
// in queue:    in_q[]

int n;
int curr_q=-1,curr_v=-1;

void acceptData(int node[],int adj_matrix[][n]){

    for(int i=0;i<n;i++){
        printf("Node %d value = ",(i+1));
        scanf("%d",&node[i]);
    }

    for(int i=0;i<n;i++){
        printf("\nThe Node %d has links to (0:no link | 1:links): \n",node[i]);

        for(int j=i;j<n;j++){
            int temp = 0;
            printf("\t| %d \t: ",node[j]);
            scanf("%d",&temp);
            
            if(!(temp==1 || temp==0)){
                printf("Enter 0 or 1 only...");
                j-=1;
                continue;
            }

            adj_matrix[i][j]=temp;
            if(i!=j)
                adj_matrix[j][i]=temp;
        }
    }

}

void showRow(int x[]){
    for(int i=0;i<n;i++){
        if(i==0)
            printf("| ");
        printf("%d\t",x[i]);
    }
}

int showMatrix(int node[],int adj_matrix[][n]){
    printf("\n\nAdjacency Matrix looks like this:\n\n");
    
    printf(".\t");
    showRow(node);
    
    printf("\n");
    for(int i=0;i<8*(n+1);i++)
        printf("-");

    for(int i=0;i<n;i++){
        printf("\n%d\t",node[i]);
        showRow(adj_matrix[i]);
    }

    printf("\n\n");
}

void showQ(int x[],int n,char str[]){
    if(n==-1){
        printf("\n%s : \t[ ]",str);
        return;
    }

    printf("\n%s : \t[ %d",str,x[0]);
    for(int i=1;i<n;i++)
        printf(" , %d",x[i]);
    printf(" ]");
}

int originPoint(int node[],int *e){
    printf("What should be the starting node? ");
    int start,flag=-1;
    scanf("%d",&start);

    for(int i=0;i<n;i++)
        if(node[i]==start){
            flag=i;
            break;
        }
    
    if(flag==-1){
        printf("No such node exists...\nAgain, ");
        originPoint(node,e);    
    }

    *e = flag;
    return start;
}

//=================[BFS begins]====================

int *enqueue(int x[],int num,int type){
    int *e = (type==1)?&curr_q:&curr_v;
    *e+=1;
    x[*e]=num;
    if(type==1)
        printf("\nNode {%d} enqued.",x[*e]);
    else    printf("\nNode {%d} added to visited.",x[*e]);
    return -1;
}

int *dequeue(int x[]){
    if(curr_q==-1){
        printf("Nothing to delete...");
        return -1;
    }
    printf("\nNode {%d} dequed.",x[0]);

    if(curr_q==0){
        curr_q=-1;
        return -1;
    }

    for(int i=0;i<curr_q;i++)
        x[i]=x[i+1];
    --curr_q;

    return -1;
}

int *already_in(int x[],int num,int type){
    int *e = (type==1)?&curr_q:&curr_v;

    for(int i=0;i<=*e;i++)
        if(x[i]==num)
            return 1;

    return 0;
}

int findIndex(int a,int x[]){
    for(int i=0;i<n;i++)
        if(x[i]==a)
            return i;
    
    return -1;
}

int BFS(int x,int pos,int mat[][n],int node[],int in_q[n],int visited[n]){
    
    
    int c=0;

    printf("\n\n---[Step %d]---------------------------\n",c);
    ++c;
    
    printf("\n");
    showQ(in_q,curr_q,"Curr Queue");

    do{
        showQ(visited,curr_v,"Visited");
        
        printf("\n\n---[Step %d]---------------------------\n",c);
        ++c;

        if(already_in(visited,x,2)==0){

            if(already_in(in_q,x,1)==0)
                enqueue(in_q,x,1);
            
            for(int i=0;i<n;i++){
                if(mat[pos][i]==1 && already_in(in_q,node[i],1)==0 && already_in(visited,node[i],2)==0)
                    enqueue(in_q,node[i],1);
            }
            dequeue(in_q);
            enqueue(visited,x,2);
            
            printf("\n");
            showQ(in_q,curr_q,"Curr Queue");
        }
        x=in_q[0];
        pos=findIndex(x,node);

    }while(curr_q>-1);

    enqueue(visited,x,2);
    showQ(visited,curr_v,"-----------------------\nFinal Visited");
    printf("\nTotal Steps = %d",c);
}



int main(){

    printf("How many nodes? ");
    scanf("%d",&n);

    if(n<1){
        printf("\nNodes must be a positive term...\n");
        exit(1);
    }

    int node[n];
    int adj_matrix[n][n];
    int r=-1;


    acceptData(node,adj_matrix);
    showMatrix(node,adj_matrix);
    int start = originPoint(node,&r);

    
    int visited[n];
    int in_q[n];

    BFS(start,r,adj_matrix,node,in_q,visited);
    return 0;
}