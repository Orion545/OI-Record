/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define end DEEP_DARK_FANTASY
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
int n,first[100010],cnte;
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dep[100010],st[100010][20],siz[100010],dfn[100010],end[100010],clk=0;
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;st[u][0]=f;
	dfn[u]=++clk;siz[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);siz[u]+=siz[v];
	}
	end[u]=clk;
}
void ST(){
	int i,j;
	for(j=1;j<=18;j++){
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
int getlca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=18;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=18;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
int getmid(int l,int r,int &tp){
	int mid,lca=getlca(l,r),len,maxn;
	len=(dep[l]+dep[r]-dep[lca]*2+1);
	if((len>>1)<dep[l]-dep[lca]+1) mid=maxn=l,tp=1,len=(len>>1)-1;
	else mid=maxn=r,tp=2,len=len-(len>>1)-1;
	for(int i=18;i>=0;i--) 
		if(dep[maxn]-dep[st[mid][i]]<=len) 
			mid=st[mid][i];
//	cout<<"getmid "<<l<<' '<<r<<' '<<mid<<' '<<len<<' '<<maxn<<'\n';
	return mid;
}
int solve(int x,int y,int z){
	int t1,t2,xy=getmid(x,y,t1),xz=getmid(x,z,t2),top;
	top=getlca(xy,xz);
	if(t1>t2) swap(xy,xz),swap(t1,t2);
	if(t1==1&&t2==1)
		return ((dep[xy]<dep[xz])?siz[xz]:siz[xy]);
	else if(t1==1&&t2==2){
		if(top==xy) return siz[xy]-siz[xz];
		else return siz[xy];
	}
	else{
		if(dep[xy]>dep[xz]) swap(xy,xz);
		if(top==xy) return n-siz[xy];
		else return n-siz[xy]-siz[xz];
	}
}
void init(){
	memset(first,-1,sizeof(first));cnte=0;
	memset(a,0,sizeof(a));memset(st,0,sizeof(st));
}
int main(){
	int T=read();
	while(T--){
		init();
		n=read();int i,t1,t2,t3,Q;
		for(i=1;i<n;i++){
			t1=read();t2=read();
			add(t1,t2);
		}
		dfs(1,0);ST();
		Q=read();
		while(Q--){
			t1=read();t2=read();t3=read();
			printf("%d %d %d\n",solve(t1,t2,t3),solve(t2,t1,t3),solve(t3,t1,t2));
		}
	}
}

