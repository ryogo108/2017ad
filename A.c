#include<stdio.h>

const int MAX_N=1e3;
const int INF=1e9;
int dp[MAX_N][MAX_N];
int a[MAX_N];
int n;
int min(int x,int y){
	return x>y? y:x;
}
int opt_mul(int i,int j){
	if(j-i==1)return dp[i][j]=0;
	if(dp[i][j]!=0)return dp[i][j];
	int re=INF;
	for(int k=i+1;k<j;k++)re=min(re,opt_mul(i,k)+opt_mul(k,j)+a[i]*a[j]*a[k]);
	return dp[i][j]=re;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)scanf("%d",a+i);
	printf("%d\n",opt_mul(0,n));
}
