#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 1000000007
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll A[4],B[4];
inline void mul1(){
	int t[4];
	t[0]=(A[0]*B[0]+A[1]*B[1])%MOD;
	t[1]=(A[0]*B[2]+A[1]*B[3])%MOD; 
	A[0]=t[0];
	A[1]=t[1];
} 
inline void mul2(){
	int t[4];
	t[0]=(B[0]*B[0]+B[2]*B[1])%MOD;
	t[1]=(B[1]*B[0]+B[3]*B[1])%MOD; 
	t[2]=(B[0]*B[2]+B[2]*B[3])%MOD;
	t[3]=(B[1]*B[2]+B[3]*B[3])%MOD;
	B[0]=t[0];
	B[1]=t[1];
	B[2]=t[2];
	B[3]=t[3];
}
void qpow(ll k){
	while(k){
		if(k&1) mul1();
		mul2();k>>=1;
	}
}
ll qqpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll n,m,k;bool a[1010][1010];
int main(){
	n=read();m=read();k=read();char s[1010];ll i,j,v=0,ud=0,lr=0,tot=0,st=0;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++) a[i][j+1]=(s[j]=='#'),v+=(s[j]=='#');
	}
	for(i=1;i<=n;i++) lr+=(a[i][1]&&a[i][m]);
	for(i=1;i<=m;i++) ud+=(a[1][i]&&a[n][i]);
	tot=qqpow(v,(k-1)%(MOD-1));
	if(lr&&ud||k==1){
		puts("1");return 0;
	} 
	if(!lr&&!ud){
		printf("%lld\n",tot);return 0;
	}
	if(lr) for(i=1;i<=n;i++) for(j=1;j<m;j++) st+=(a[i][j]&&a[i][j+1]);
	else for(i=1;i<n;i++) for(j=1;j<=m;j++) st+=(a[i+1][j]&&a[i][j]);
	if(lr) swap(lr,ud);
	
//	cout<<v<<' '<<st<<' '<<tot<<' '<<lr<<' '<<ud<<'\n';
	
	A[0]=st;A[1]=v;
	B[3]=v;B[0]=ud;B[1]=st;
	
	qpow(k-2);
	
	printf("%lld\n",(tot-A[0]+MOD)%MOD);
}
