#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int first[100010],cnte,dep[100010],ans=0,n,k;
struct edge{
	int to,next;
}a[100010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
int dfs(int u,int f){
//	cout<<"dfs "<<u<<' '<<f<<'\n';
	dep[u]=dep[f]+1;
	int i,v,maxdis=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;maxdis=max(maxdis,dfs(v,u));
	}
	if(u!=1) assert(maxdis<=k);
//	cout<<"maxdis "<<u<<' '<<maxdis<<'\n';
	if(maxdis==k&&u!=1&&f!=1){
		ans++;return 0;
	}
	return maxdis+1;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();k=read();int i,t1;
	for(i=1;i<=n;i++){
		t1=read();
		if(i!=1) add(t1,i);
		if(i==1&&t1!=1) ans++;
	}
	dfs(1,0);
	printf("%d\n",ans);
}
