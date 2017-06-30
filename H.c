#include<stdio.h>

typedef long long ll;

const int MAX_H=1e3+3;
const int MOD=1e9;
ll dp[MAX_H][MAX_H];
char maze[MAX_H][MAX_H];
int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	dp[0][0]=1;
	for(int i=0;i<h;i++)scanf("%s",maze[i]);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(maze[i][j]=='.'){
				if(i)dp[i][j]+=dp[i-1][j];
				if(j)dp[i][j]+=dp[i][j-1];
				dp[i][j]%=MOD;
			}
		}
	}
	printf("%lld\n",dp[h-1][w-1]);
}
