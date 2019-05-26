#pragma gcc optimize 3
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline int qpow(int a,int b){
	if(a<0) a+=MOD;	
	int re=1;
	while(b){
		if(b&1) re=1ll*re*a%MOD;
		a=1ll*a*a%MOD;b>>=1;
	}
	return re;
}
inline void add(int &a,int b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int n,a[60][60],b[60][60],pt[60];int c[60][60],d[60][60],ans[60][60],g[60],f[60],p[110],q[110],t[110];
//Gauss
int gauss(){
	int i,j,k;int num,tmp,ch=1,re=1;
	for(i=1;i<=n;i++){
		num=0;
		for(j=i;j<=n;j++) if(a[j][i]){num=j;break;}
		if(num==0) return 0;
		if(num!=i) swap(a[num],a[i]),ch=-ch;
		for(j=i+1;j<=n;j++){
			if(!a[j][i]) continue;
			tmp=1ll*a[j][i]*qpow(a[i][i],MOD-2)%MOD;
			for(k=i;k<=n;k++)
				add(a[j][k],MOD-1ll*a[i][k]*tmp%MOD);
		}
		re=1ll*re*a[i][i]%MOD;
	}
	return (re*ch+MOD)%MOD;
}
//Cayley-Hamilton quick power
void mul(int *x,int *y,int *z){
	int i,j;
	for(i=0;i<2*n;i++) t[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			add(t[i+j],1ll*x[i]*y[j]%MOD);
	for(i=2*n-2;i>=n;i--){
		for(j=n-1;j>=0;j--)
			add(t[i-n+j],MOD-1ll*t[i]*f[j]%MOD);
		t[i]=0;
	}
	for(i=0;i<n;i++) z[i]=t[i];
}
char s[10010];
int main(){
	scanf("%s",s);n=read();
	int i,j,k,l,len=strlen(s);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=read();
	memcpy(b,a,sizeof(a));
	//set lambda as 0~n, get point (i,det(a))
	for(i=0;i<=n;i++){
		for(j=1;j<=n;j++) a[j][j]-=i;
		pt[i]=gauss();
		memcpy(a,b,sizeof(b));
	}
	//do lagrange
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++) g[j]=0;
		g[0]=pt[i];
		for(j=0;j<=n;j++) if(i!=j) g[0]=1ll*g[0]*qpow(j-i,MOD-2)%MOD;
		for(j=0;j<=n;j++){
			if(i==j) continue;
			for(k=n;k>=1;k--) add(g[k],((1ll*g[k]*(j-1)%MOD-g[k-1])+MOD)%MOD);
			g[0]=1ll*g[0]*j%MOD;
		}
		for(j=0;j<=n;j++) add(f[j],g[j]);
	}
	int tinv=qpow(f[n],MOD-2);
	for(j=0;j<n;j++) f[j]=1ll*f[j]*tinv%MOD;
	p[0]=1;q[1]=1;
	for(i=len-1;i>=0;i--){
		if(s[i]=='1') mul(p,q,p);
		mul(q,q,q);
	}
	for(i=1;i<=n;i++) c[i][i]=1;
	for(i=0;i<n;i++){
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				add(ans[j][k],1ll*c[j][k]*p[i]%MOD);
		memset(d,0,sizeof(d));
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				for(l=1;l<=n;l++)
					add(d[j][k],1ll*c[j][l]*a[l][k]%MOD);
		memcpy(c,d,sizeof(d));
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) printf("%d ",ans[i][j]);
		puts("");
	}
}
