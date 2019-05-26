#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define _ read()
const int N=1e4+5;
struct node{ int u,v; }a[N];
struct Edge{ int to,nxt,id; }e[N<<1];
int cnt,head[N],n,m,vis[N],flag[N],ans[N],res[N],CNT; 
inline void insert( int u,int v,int id ) {
	e[cnt]=(Edge) { v,head[u],id };
	head[u]=cnt++;
}
inline void ins( int u,int v,int id ) {
	insert(u,v,id);
	insert(v,u,id);
}
inline void dfs( int x,int fa ) {
	printf("%d ",x);
	vis[x]=1;
	int b[5005],tot=0;
	for(int i=head[x];~i;i=e[i].nxt)
		if(e[i].to!=fa) b[++tot]=e[i].to;
	sort(b+1,b+tot+1);
	for(int i=1;i<=tot;i++)
		if(!vis[b[i]]) dfs(b[i],x);
}
inline void Dfs( int x,int fa ) {
	ans[++CNT]=x;
	vis[x]=1;
	int b[5005],tot=0;
	for(int i=head[x];~i;i=e[i].nxt) 
		if(e[i].to!=fa&&!flag[e[i].id]) //如果这条边没被删掉 
			b[++tot]=e[i].to;
	sort(b+1,b+tot+1);
	for(int i=1;i<=tot;i++)
		if(!vis[b[i]]) Dfs(b[i],x);
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=_; m=_;
	memset(head,-1,sizeof(head));
	if(m==n-1) {
		for(int i=1,u,v;i<=m;i++) {
			u=_; v=_;
			ins(u,v,i); 
		}
		dfs(1,0);
		return 0;
	}else {
		for(int i=1,u,v;i<=m;i++) {
			u=_; v=_;
			ins(u,v,i);
		}
		for(int i=1;i<=n;i++)
			res[i]=n+1;
		for(int i=1;i<=m;i++) { //枚举删掉哪条边 
			flag[i]=1;
			CNT=0; 
			memset(ans,0,sizeof(ans));
			memset(vis,0,sizeof(vis));
			Dfs(1,0);
			if(CNT!=n) { flag[i]=0; continue;}
			bool qwq=true;
			for(int j=1;j<=n;j++)
				if(ans[j]==res[j]) continue;
				else if(ans[j]<res[j]) { qwq=false; break; }
				else break;
			if(!qwq) for(int j=1;j<=n;j++) res[j]=ans[j];
			flag[i]=0;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",res[i]);
		return 0;
	}
}
