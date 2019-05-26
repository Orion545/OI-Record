#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 2017
#define ll long long
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
int n,m,re[50][50],a[50][50];
void mul(int a[50][50],int b[50][50],int lim1,int lim2){
//	cout<<"enter mul \n";
	int i,j,k,r[50][50]={0};
//	for(i=1;i<=lim1;i++){
//		for(j=1;j<=n;j++) cout<<a[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=lim2;j++) cout<<b[i][j]<<' ';
//		cout<<'\n';
//	}
	for(i=1;i<=lim1;i++){
		for(j=1;j<=lim2;j++){
			for(k=1;k<=n;k++){
				r[i][j]+=a[i][k]*b[k][j]%MOD;
			}
			r[i][j]%=MOD;
		}
	}
	memcpy(a,r,sizeof(r));
}
int main(){
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		a[t1][t2]++;a[t2][t1]++;
	}
	for(i=1;i<=n;i++) a[i][i]++,a[i][n+1]++;
	n++;a[n][n]++;re[1][1]=1;
	int T=read();
	while(T){
		if(T&1) mul(re,a,1,n);
		mul(a,a,n,n);T>>=1;
	}
	int ans=0;
	for(i=1;i<=n;i++) ans=(ans+re[1][i])%MOD;
	printf("%d\n",ans); 
}

