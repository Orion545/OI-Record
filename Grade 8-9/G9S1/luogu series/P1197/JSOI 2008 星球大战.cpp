#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
} 
int	n,m,K,hit[400010],first[400010],ans[400010],f[400010];
bool vis[400010],cut[400010];
struct edge{
	int to,next;
}a[400010];
inline int find(int x){
	return ((f[x]==x)?x:(f[x]=find(f[x])));
}
void dfs(int u){
//	cout<<"dfs "<<u<<endl;
	int i,v;vis[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(vis[v]) continue;
		f[v]=u;dfs(v);
	}
}
int main(){
	int i,t1,t2,k,u,v,f1,f2;
	n=read();m=read();
	for(i=1;i<=n;i++) f[i]=i,first[i]=-1;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t1++;t2++;
		a[(i<<1)-1].to=t2;a[(i<<1)-1].next=first[t1];first[t1]=(i<<1)-1;
		a[(i<<1)].to=t1;a[(i<<1)].next=first[t2];first[t2]=(i<<1);
	}
	K=read();
	for(i=1;i<=K;i++) hit[i]=read(),hit[i]++,vis[hit[i]]=1;
	for(i=1;i<=n;i++){
		if(!vis[i]) dfs(i),ans[K+1]++;
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=K;i++) vis[hit[i]]=1;
	for(i=K;i>=1;i--){
		u=hit[i];vis[u]=0;
		ans[i]=ans[i+1]+1;
		for(k=first[u];~k;k=a[k].next){
			v=a[k].to;
			if(vis[v]) continue;
			f1=find(u);f2=find(v);
			if(f1!=f2) ans[i]--,f[f2]=f1;
		}
	}
	for(i=1;i<=K+1;i++) printf("%d\n",ans[i]);
}
