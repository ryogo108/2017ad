#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

typedef vector<ll> vec;
typedef vector<vec> mat;

const int MOD=1e9+7;

//A*B
mat mul(mat &A,mat&B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++){
		for(int k=0;k<B.size();k++){
			for(int j=0;j<B[0].size();j++){
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
			}
		}
	}
	return C;
}
//A^n
mat pow(mat A,ll n){
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++){
		B[i][i]=1;
	}
	while(n>0){
		if(n&1)B=mul(B,A);
		A=mul(A,A);
		n>>=1;
	}
	return B;
}
ll data[10][10]={{1,1,1,1,1,1,1,1,0,0},
	{0,1,0,1,0,1,0,1,0,1},
	{0,0,1,1,0,0,1,1,0,1},
	{0,1,1,1,0,0,1,1,0,1},
	{0,0,0,0,1,1,1,1,0,1},
	{0,0,0,0,0,1,0,1,0,0},
	{0,0,1,1,1,0,1,1,0,1},
	{0,1,1,1,1,0,1,1,1,1},
	{0,1,0,0,1,0,0,0,1,1},
	{0,0,0,0,0,0,0,0,0,1}};

ll data2[10]={0,1,1,1,1,0,1,1,1,1};
ll v[10];
int main(){
	
	mat A(10,vec(10));
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)A[i][j]=data[i][j];
	ll n;
	scanf("%lld",&n);
	A=pow(A,n-1);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)v[i]=(v[i]+A[i][j]*data2[j])%MOD;
	}
	ll ans=0;
	for(int i=0;i<8;i++)ans=(ans+v[i])%MOD;
	printf("%lld\n",ans);
}
