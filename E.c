#include<stdio.h>

typedef long long ll;
const int MAX_N=1e5+5;
const int MOD=1e9;
ll dp[MAX_N];

int main(){
	int n;
	scanf("%d",&n);
	dp[0]=dp[1]=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<i;j++)dp[i]=(dp[i]+dp[j-1]*dp[i-j-1])%MOD;
	}
	printf("%lld\n",dp[n]);
}
