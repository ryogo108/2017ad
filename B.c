#include<stdio.h>

const int MAX_N=1e4;
int n,k;
int a[MAX_N];

int dp[MAX_N];
int table[MAX_N][MAX_N];
int vis[MAX_N];
int max(int x,int y){return x>y? x:y;}

int val_max(int m){
	if(vis[m]==1)return dp[m];
	vis[m]=1;
	int re=a[m];
	for(int i=1;i<=m/2;i++)re=max(re,val_max(i)+val_max(m-i)-k);
	return dp[m]=re;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i+1);
	for(int i=0;i<=n;i++)dp[i]=a[i];
	for(int i=1;i<=n;i++)table[i][i]=1;
	for(int i=2;i<=n;i++){
		int t=i;
		for(int j=1;j<=i/2;j++){
			if(dp[i]<dp[j]+dp[i-j]-k){
				dp[i]=dp[j]+dp[i-j]-k;
				t=j;
			}
		}
		for(int j=0;j<n;j++)table[i][j]=table[t][j]+table[i-t][j];
	}
	printf("%d\n",dp[n]);
	for(int i=0;i<n;i++){
		if(table[n][i]){
			for(int j=0;j<table[n][i];j++)printf("%d ",i);
		}
	}
	printf("\n");
}
