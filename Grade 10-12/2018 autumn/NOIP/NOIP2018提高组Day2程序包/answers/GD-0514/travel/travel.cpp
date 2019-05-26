#include<bits/stdc++.h>
#define N 5050
#define pb push_back
#define add(u,v) to[++top]=head[u],head[u]=top,w[top]=v
#define For(x) for(int h=head[x],o=w[h];h;o=w[h=to[h]])
using namespace std;
int top=0,head[N<<1],to[N<<1],w[N<<1],ban[N<<1];
int r[N],now,vis[N];
int n,m,u[N],v[N],flag;
struct dat{
	int tot,d[N];
	bool operator <(dat b) const{
		for (int i=1;i<=n;i++){
			if (d[i]<b.d[i]) return 1;
			if (d[i]>b.d[i]) return 0;
		}
		return 1;	
	} 
}A,B;
inline void dfs(int x,int fa){
	vector<int> a;
	a.clear();
	A.tot++,A.d[A.tot]=x;
	For(x) 
		if (o!=fa&&(!ban[h])) 
			a.pb(o);
	if (a.size()==0) return;
	sort(a.begin(),a.end());
	for (int i=0;i<a.size();i++) dfs(a[i],x);
}
inline void dfs2(int x,int fa){
	For(x) if (o!=fa){
		if (o==now) r[now]=1;
		if (vis[o]) continue;
		vis[o]=1,dfs2(o,x);
	}
}
inline bool cmp(dat a,dat b){
	for (int i=1;i<=n;i++) if (a.d[i]>b.d[i]) return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]),add(u[i],v[i]),add(v[i],u[i]);
	if (m==n-1){
		dfs(1,0);
		for (int i=1;i<=n;i++) printf("%d ",A.d[i]);
		return 0;
	}
	if (m==n){
		for (int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis)),now=i;
			vis[i]=1,dfs2(i,0);
		}
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=m;i++) if (r[u[i]]&&r[v[i]]){
			ban[i*2-1]=1,ban[i*2]=1;
			dfs(1,0);
			A.tot=0;
			if (!flag){
				B=A;flag=1;
			}
			else{
				if (A<B) B=A;
			}
			ban[i*2-1]=0,ban[i*2]=0;
		}
		for (int i=1;i<=n;i++) printf("%d ",B.d[i]);
	}
}
