#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define id(i,j) (i-1)*m+j
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
int n,m,first[30010],dep[30010],cur[30010],cnte=-1,tot;
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],0};first[v]=cnte;
}
bool bfs(int s,int t){
//	cout<<"bfs "<<s<<' '<<t<<'\n';
	int i,q[30010],head=0,tail=1,u,v;
	for(i=1;i<=tot;i++) dep[i]=-1,cur[i]=first[i];
	q[0]=s;dep[s]=0;
	while(head<tail){
		u=q[head++];
//			cout<<"start "<<u<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(~dep[v]||!a[i].w) continue;
//			cout<<"		from "<<u<<" to "<<v<<' '<<a[i].w<<'\n';
			dep[v]=dep[u]+1;q[tail++]=v;
		}
	}
	return ~dep[t];
}
int dfs(int u,int t,int lim){
	if(u==t||!lim) return lim;
	int i,v,f,flow=0;
	for(i=cur[u];~i;i=a[i].next){
		v=a[i].to;cur[u]=i;
		if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(lim,a[i].w)))){
			flow+=f;lim-=f;
			a[i].w-=f;a[i^1].w+=f;
			if(!lim) return flow;
		}
	}
	return flow;
}
void dinic(int s,int t){
	int ans=0;
	while(bfs(s,t)) ans+=dfs(s,t,1e9);
	if(ans<=n*m) printf("%d\n",ans);
	else puts("-1");
}
int x[110][110],S,T;
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();char s[110];int i,j;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			if(s[j]=='.') continue;
			x[i][j+1]=1;
			if(s[j]=='S') S=id(i,j+1); 
			if(s[j]=='T') T=id(i,j+1);
		}
	}
	tot=n*m*2;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!x[i][j]) continue;
			add(n*m+id(i,j),tot+i,1e9);
			add(n*m+id(i,j),tot+n+j,1e9);
			add(tot+i,id(i,j),1e9);
			add(tot+n+j,id(i,j),1e9);
			if(id(i,j)!=S&&id(i,j)!=T) add(id(i,j),n*m+id(i,j),1);
		}
	}
	tot=n*m*2+n+m;
	dinic(n*m+S,T);
}

