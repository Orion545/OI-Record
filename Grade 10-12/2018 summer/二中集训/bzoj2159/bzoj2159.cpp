#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 10007
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
int n,m,first[50010],cnte,s[200][200],fac[200];
struct edge{
	int to,next;
}a[100010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void init(){
	int i,j;fac[0]=fac[1]=1;
	for(i=2;i<=m;i++) fac[i]=fac[i-1]*i%MOD;
	s[0][0]=1;
	for(i=1;i<=m;i++){
		for(j=0;j<=i;j++){
			s[i][j]=s[i-1][j-1]+s[i-1][j]*j;s[i][j]%=MOD;
		}
	}
}
int down[50010][210],up[50010][210],ans[50010];
void dfs1(int u,int f){
	int i,v,k;
	down[u][0]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		down[u][0]+=down[v][0];
		for(k=1;k<=m;k++) down[u][k]+=down[v][k]+down[v][k-1],down[u][k]%=MOD;
	}
}
void dfs2(int u,int f){
	int i,v,k;
	if(!f) goto skip;
	up[u][0]=n-down[u][0];
	for(k=1;k<=m;k++){
		up[u][k]=up[f][k]+up[f][k-1]+down[f][k]+down[f][k-1]-down[u][k]-down[u][k-1]-down[u][k-1];
		if(k>1) up[u][k]-=down[u][k-2];
		up[u][k]=(up[u][k]%MOD+MOD)%MOD;
	}
	skip:
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs2(v,u);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,A,B,Q,lim,now,tmp,k;
	lim=read();now=read();A=read();B=read();Q=read();
	for(i=1;i<n;i++){
		now=(now*A+B)%Q;
		tmp=(i<lim)?i:lim;
		add(i-now%tmp,i+1);
	}
	init();dfs1(1,0);dfs2(1,0);
	for(i=1;i<=n;i++){
		for(k=1;k<=m;k++) ans[i]+=s[m][k]*fac[k]%MOD*(up[i][k]+down[i][k])%MOD;
		printf("%d\n",ans[i]%MOD);
	}
}
