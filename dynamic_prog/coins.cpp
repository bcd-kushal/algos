#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX INT_MAX

int coins[3] = {1,4,6};

int coinChange(int n,int total){
	int dp[total+1];
	for(int i=0;i<=total;i++)
		dp[i]=MAX;
	dp[0]=0;
	for(int i=0;i<=total;i++){
		for(int j=0;j<n;j++){
			if(i-coins[j]>=0 && dp[i-coins[j]]!=MAX)
				dp[i]=min(dp[i],1+dp[i-coins[j]]);
		}
	}
	return dp[total];
}

int main(){
	int ans = coinChange(3,8);
	if(ans==MAX)    cout << -1;
	else                cout << ans;
	return 0;
}
