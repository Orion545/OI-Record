#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
int fa[100010],n,ccnt,first[100010],dep[100010],cnt[100010];
struct edge{
	int to,next;
}a[100010];
inline void add(int u,int v){
	a[++ccnt]=(edge){v,first[u]};first[u]=ccnt;
}
void dfs(int u){
	int i,v;dep[u]=dep[fa[u]]+1;cnt[dep[u]]++;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==fa[u]) continue;
		dfs(v);
	}
}
int main(){
	int i,ans=0;memset(first,-1,sizeof(first));
	n=read();
	for(i=2;i<=n;i++) fa[i]=read(),add(fa[i],i);
	dfs(1);
	for(i=1;i<=n;i++) ans+=cnt[i]%2;
	cout<<ans<<"\n";
}
