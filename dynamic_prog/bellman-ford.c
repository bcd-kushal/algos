 #include<stdio.h>
 #include<stdlib.h>
 int nv=0;
 int count=0;
 void print(int dist[])
 {
 	printf("k=%d\t",++count);
 	int i;
 	for(i=0;i<nv;i++)
 	{
		printf("%d\t",dist[i]);
	}
	printf("\n");
 }
 int min(int a,int b)
 {
 	if(a<b)
 		return a;
 	else 
	 return b;
 	return a;
 }
 void bellman_ford(int cost[nv][nv])
{
	int dist[nv];
	int dist_copy[nv];
	int src;
	int i,j,k;
	printf("Enter source: ");
	scanf("%d",&src);
	src-=1;	//decrementing source value as our array index starts from zero
	for(i=0;i<nv;i++)	//this is the iteration for k=0
	{
		if(i==src)	
			continue;
		dist[i]=cost[src][i];	//copying the weights from source vertex to all other vertices having an edge
	}
	dist[src]=0;	//since distance from source to source is always zero
	dist_copy[src]=0;
	print(dist);	//printing the first iteration for k=0
	int min1=9999;
	int min2=9999;
	for(k=1;k<nv-1;k++)	//iteration continues till n-1 as per the principle
	{
		for(i=0;i<nv;i++)
		{
			if(i==src)	//this is because distance from source to source is always zero hence discarding this possibility
				continue;
			min1=dist[i];	//choosing min1 as distance from src to i in the previous iteration
			for(j=0;j<nv;j++)
			{
				if(j==i)	//to exculde the cost from i to j when i==j as cost here will be 0
					continue;
				int x=dist[j]+cost[j][i];	//finding cost from j to vertex i using the previous iteration
				if(x<=min2)	//checking if cost is less than previous cost
				{
					min2=x;
				}
			}
			int fmin=min(min1,min2);	//finding min cost
			dist_copy[i]=fmin;	//assigning min cost from source to i in the current iteration to a differrent array
			min1=9999;
			min2=9999;
		}
		for(i=0;i<nv;i++)
		{
			dist[i]=dist_copy[i];	//copying the array elements to dist to fill up costs in the current iterations
		}
		print(dist);	//printing the costs from source to all other vertices in current iteration
	}
 }
 int main()
 {
 	printf("Enter the number of vertices: ");
 	scanf("%d",&nv);
 	int i,j;
 	int cost[nv][nv];
 	for(i=0;i<nv;i++)
 	{
 		for(j=0;j<nv;j++)	
 		{
 		
 			int ch;
 			printf("Do you want an edge from %d to %d \n1.Yes\n2.No\n: ",i+1,j+1);
 			scanf("%d",&ch);
 			if(ch==1)	//creation of weighted edge
 			{
 				int w;
				printf("Enter weight: ",i+1,j+1);
 				scanf("%d",&w);
 				cost[i][j]=w;
			}
			else
				cost[i][j]=9999;//indicates no direct edge 
		}
	}
	bellman_ford(cost);
	return 0;
}
