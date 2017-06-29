#include<stdio.h>

const int MAX_N=1e6+6;

int dp[MAX_N];
int a[MAX_N];
int max(int x,int y){return x>y?x:y;}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int ans=0;
	int l=0,r=0;
	int prev=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
		if(dp[i]<0)prev=i+1;
		dp[i]=max(dp[i],0);
		if(dp[i]>ans){
			ans=dp[i];
			l=prev;
			r=i;
		}
	}
	printf("%d\n%d %d\n",ans,l,r);
}
