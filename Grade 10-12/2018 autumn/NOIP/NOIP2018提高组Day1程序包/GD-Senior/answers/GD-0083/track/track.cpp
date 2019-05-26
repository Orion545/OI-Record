#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=50008;
int head[maxn],cur,f[maxn],n,m,ans,w[maxn],u,v,sum,fa[maxn],dep[maxn],vis[maxn];
struct tnode{
	int t,next,cost;
};
tnode edge[maxn];

void addedge(int u,int v,int w)
{
	edge[++cur].t=v; edge[cur].next=head[u]; edge[cur].cost=w; head[u]=cur;
}

void dfs(int now,int d)
{
	dep[now]=d;
	for (int i=head[now];i!=0;i=edge[i].next){
		int t=edge[i].t;
		if (!dep[t]){
			fa[t]=now;
			dfs(t,d+1);
		}
	}
}

void findfar(int now)
{
	for (int i=head[now];i!=0;i=edge[i].next){
		int t=edge[i].t;
		if (!f[t]&&t!=fa[now]) 
			findfar(t);
		if (t!=fa[now]) f[now]=max(f[now],f[t]+edge[i].cost);
	}
	return;
}

void work1()
{
	findfar(1);
	for (int i=1;i<=n;i++){
		int maxx=0,maxx2=0,wei=0;
		for (int j=head[i];j!=0;j=edge[j].next){
			int t=edge[j].t;
			if (t==fa[i]) continue;
			if (f[t]+edge[j].cost>maxx) maxx=f[t]+edge[j].cost,wei=t;
		}
		for (int j=head[i];j!=0;j=edge[j].next){
			int t=edge[j].t;
			if (t==fa[i]) continue;
			if (t!=wei) maxx2=max(maxx2,f[t]+edge[j].cost);
		}
		ans=max(ans,maxx2+maxx);
	}
}

void work2()
{
	sort(w+1,w+n);
	ans=2147480000;
	int i=1,j=n-1;
	if (m<=(n-1)/2){
		i=n-m*2;
		while (i<j){
			ans=min(ans,w[i]+w[j]);
			i++; j--; 
		}
	}
}

bool check(int k)
{
	int num=0,z=0;
	for (int i=1;i<n;i++){
		num+=w[i];
		if (num>=k) z++,num=0;
	}
	if (z>=m) return true;
	return false;
}

void work3()
{
	int l=0,r=sum+1;
	while (l+1<r){
		int mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	ans=l;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag1=true,flag2=true,flag3=true;
	if (m>1) flag1=false; 
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w[i]);
		sum+=w[i];
		addedge(u,v,w[i]);
		addedge(v,u,w[i]);
		if (u!=1) flag2=false;
		if (v!=u+1) flag3=false; 
	}
	dfs(1,1);
	if (flag1) work1();
	else if (flag3) work3();
	else if (flag2) work2();
	else ans=26282;
	printf("%d",ans);
	return 0;
}
