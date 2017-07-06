#include<stdio.h>

#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

const int MOD=1e9+7;
const int MS=10;
ll data[10][10]={
	{1,1,1,1,1,1,1,1,0,0},
	{0,1,0,1,0,1,0,1,0,1},
	{0,0,1,1,0,0,1,1,0,1},
	{0,1,1,1,0,0,1,1,0,1},
	{0,0,0,0,1,1,1,1,0,1},
	{0,0,0,0,0,1,0,1,0,0},
	{0,0,1,1,1,0,1,1,0,1},
	{0,1,1,1,1,0,1,1,1,1},
	{0,1,0,0,1,0,0,0,1,1},
	{0,0,0,0,0,0,0,0,0,1}};
ll v0[10]={0,1,1,1,1,0,1,1,1,1};
ll v[10];
// A=A*B
void mul(ll A[MS][MS],ll B[MS][MS]){
	ll C[MS][MS]; 
	rep(i,MS)rep(j,MS)C[i][j]=0;
	rep(i,MS)rep(k,MS)rep(j,MS)C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
	rep(i,MS)rep(j,MS)A[i][j]=C[i][j];
}
// re=A^n
void pow_m(ll A[MS][MS],ll re[MS][MS],ll n){
	rep(i,MS)re[i][i]=1;
	ll C[MS][MS];
	rep(i,MS)rep(j,MS)C[i][j]=A[i][j];
	while(n>0){
		if(n&1)mul(re,C);
		mul(C,C);
		n>>=1;
	}
}


ll A_n[10][10];

int main(){
	ll n;
	scanf("%lld",&n);
	pow_m(data,A_n,n-1);
	rep(i,MS)rep(j,MS)v[i]=(v[i]+A_n[i][j]*v0[j])%MOD;
	ll ans=0;
	rep(i,8)ans=(ans+v[i])%MOD;
	printf("%lld\n",ans);
}
