#include<stdio.h>

const int MAX_N=1e5+5;
int a[MAX_N],b[MAX_N],w[MAX_N];
int dp[MAX_N];
int n;
int max(int x,int y){return x>y?x:y;}
int bin(int x){
//a[t]>=xとなる最小のtを求める
	int l=0,r=n;
	while(r-l>0){
		int m=(l+r)/2;
		if(a[m]>=x)r=m;
		else l=m+1;
	}
	return r;
}
int solve(int k){
//k番目の仕事を始める時刻以降の最大収益を求める
	if(dp[k]>0)return dp[k];
	if(k==n)return 0;
	int t=k+1;
	t=bin(b[k]);
	return dp[k]=max(solve(k+1),solve(t)+w[k]);
	//k番目の仕事をする or しない<=>k+1番目以降の仕事で頑張る.
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d%d",a+i,b+i,w+i);
	dp[n]=0;
	for(int i=n-1;i>=0;i--){
		dp[i]=max(dp[i+1],dp[bin(b[i])]+w[i]);
	}
	printf("%d\n",dp[0]);
}
