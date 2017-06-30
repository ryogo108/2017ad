#include<stdio.h>

const int MAX_N=1e4+5;

int n,m;
int a[MAX_N],b[MAX_N];
int dp[MAX_N][MAX_N];
int table[MAX_N][MAX_N];
int max(int x,int y){return x>y?x:y;}
/*int lcs(int i,int j){
	//i,j : 1-indexed
	if(dp[i][j]!=-1)return dp[i][j];
	if(i>n||j>m)return dp[i][j]=0;
	if(a[i]==b[j])return dp[i][j]=lcs(i+1,j+1)+1;
	return dp[i][j]=max(lcs(i+1,j),lcs(i,j+1));
}*/
int dx[3]={1,0,1};
int dy[3]={0,1,1};
int main(){
	scanf("%d%d",&n,&m);
	//for(int i=0;i<n;i++)for(int j=0;j<m;j++)dp[i][j]=-1;
	for(int i=0;i<n;i++)scanf("%d",a+i+1);
	for(int i=0;i<m;i++)scanf("%d",b+i+1);
	for(int i=n;i>0;i--){
		for(int j=m;j>0;j--){
			if(a[i]==b[j]){
				dp[i][j]=dp[i+1][j+1]+1;
				table[i][j]=3;
			}
			else if(dp[i+1][j]>dp[i][j+1]){
				dp[i][j]=dp[i+1][j];
				table[i][j]=2;
			}
			else{
				dp[i][j]=dp[i][j+1];
				table[i][j]=1;
			}
		}
	}
	int now[2]={1,1};
	printf("%d\n",dp[1][1]);
	while(now[0]<=n || now[1]<=m){
		int t=table[now[0]][now[1]];
		if(t==3)printf("%d ",a[now[0]]);
		now[0]+=dy[t-1];
		now[1]+=dx[t-1];
	}
	printf("\n");
}
