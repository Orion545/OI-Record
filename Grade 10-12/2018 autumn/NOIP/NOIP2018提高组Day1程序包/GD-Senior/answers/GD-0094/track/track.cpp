#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

#define N (50000+5)

using namespace std;

int n,m,fur,gt,dist[N],nxt[N],w[N];
bool vis[N],f1,f2,f3;
struct graph{
 int l;
 int v;
}e;
vector<graph> g[N];

void dfs(int u){
	int i,v,l;
	vis[u]=1;
	if (dist[u]>gt){
		gt=dist[u];
		fur=u;
	}
	for (i=0;i<g[u].size();i++) {
		v=g[u][i].v;
		l=g[u][i].l;
		if (!vis[v]) {
			dist[v]=dist[u]+l;
			dfs(v);
		}
	}
}

void c1(){
	gt=0;
	dist[1]=0;
	dfs(1);
	memset(vis,0,sizeof vis);
	gt=0;
	dist[fur]=0;
	dfs(fur);
	printf("%d\n",dist[fur]);
}
void c2(){
	int i,ans,t;
	for (i=0;i<g[1].size();i++)
		w[i+1]=g[1][i].l;
	if (n-1>=2*m) {
		ans=0x3f3f3f3f;
		for (i=0;i<m;i++)
			ans=min(ans,w[n-1-i]+w[n-2*m+i]);
		printf("%d\n",ans);
	}
	else {
		t=2*(n-m-1);
		ans=w[t+1];
		for (i=0;i<(n-m-1);i++)
			ans=min(ans,w[1+i]+w[t-i]);
		printf("%d\n",ans);
	}
}

int check(int w){
	int ans=0,i,p=0;
	for (i=1;i<n;i++){
		p+=nxt[i];
		if (p>=w) {
			p=0;
			ans++;
		}
	}
	return ans;
}

void c3(){
	int tot=0,i,l,r,mid,t1,t2;
	for (i=1;i<n;i++)
		tot+=nxt[i];
	l=1;
	r=tot;
	while (1){
		mid=(l+r)>>1;
		t1=check(mid);
		t2=check(mid+1);
		if (t1==m+1&&t2==m) {
			printf("%d\n",mid+1);
			return;
		}
		if (t2>m)
			l=mid+1;
		else r=mid;	
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i,a,b,l;
	scanf("%d%d",&n,&m);
	if (m==1) f1=1;
	f2=1;
	f3=1;
	for (i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&l);
		if (b==a+1) nxt[a]=l;
		e.v=b;
		e.l=l;
		g[a].push_back(e);
		e.v=a;
		g[b].push_back(e);
		if (a!=1) f2=0;
		if (b!=a+1) f3=0;
	}
	if (f1) c1();
	else if (f2) c2();
		else if (f3) c3();
			else printf("%d\n",l);
	return 0;
}
