#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 30011
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m;
int A[110][110],R[110][110];
//Matrix R: [ s1[1] s1[2] ... s1[n] s2[1] s2[2] ... s2[n] ]
void mul(int a[110][110],int b[110][110],int lim1,int lim2){
	int i,j,k,re[110][110]={0};
	for(i=1;i<=lim1;i++){
		for(j=1;j<=lim2;j++){
			for(k=1;k<=(n<<1);k++){
				re[i][j]=(re[i][j]+a[i][k]*b[k][j])%MOD;
			}
		}
	}
	memcpy(a,re,sizeof(re));
}
int solve(int len){
//	cout<<"solve "<<len<<'\n';
	memset(A,0,sizeof(A));memset(R,0,sizeof(R));int i;
	for(i=1;i<=n;i++){
		if(i<n) R[i+1][i]++,R[i][i+1]++;
		R[i][i]++;
		R[i][i+n]++;R[i+n][i]++;
	}
//	for(i=1;i<=(n<<1);i++){
//		for(int j=1;j<=(n<<1);j++) cout<<R[i][j]<<' ';
//		cout<<'\n';
//	}
	A[1][1]=1;len--;
	while(len){
		if(len&1) mul(A,R,1,(n<<1));
		mul(R,R,n<<1,n<<1);len>>=1;
	}
//	cout<<A[1][n]<<' '<<A[1][n<<1]<<'\n';
	return (A[1][n]+A[1][n<<1])%MOD;
}
int main(){
	n=read();m=read();
	int re1=solve(m),re2=solve(m-1);
	printf("%d\n",(re1-re2+MOD)%MOD);
}

