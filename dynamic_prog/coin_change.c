#include<stdio.h>
#include<stdlib.h>

int n=0;

int min(int a,int b){
	if(a<=b)
		return a;
	return b;
}

void getCoins(int coin[],int amount){
	int i,j,k,m;
	int c[n][amount];
	int temp[amount];
	for(i=0;i<amount;i++)
		temp[i]=i;	
	for(i=0;i<n;i++){
		for(j=0;j<amount;j++){
			if(coin[i]>j)	
				c[i][j]=temp[j];
			else{
				m=min(temp[j],1+c[i][j-coin[i]]);
				c[i][j]=m;
			}
		}
		for(k=0;k<amount;k++)
			temp[k]=c[i][k];	
	}
	printf("Amount:\t\t");
	for(i=0;i<amount;i++)
		printf("%d\t",i);
	printf("\n");
	for(i=0;i<n;i++){
		printf("[%d]:coin %d\t",i+1,coin[i]);
		for(j=0;j<amount;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
}
int main(){
	int i,c,total;
	printf("Enter amount: ");
	scanf("%d",&total);
	printf("Enter distinct coins: ");
	scanf("%d",&n);
	int coin_arr[n];
	printf("Enter coin values\n");
	for(i=0;i<n;i++){
		scanf("%d",&c);
		coin_arr[i]=c;
	}
	getCoins(coin_arr,total+1);
	return 0;
}
