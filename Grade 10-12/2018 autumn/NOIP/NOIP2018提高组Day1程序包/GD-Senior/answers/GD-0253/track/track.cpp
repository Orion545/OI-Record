#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#define N 600008
using namespace std;
int n,m,head[N],nxt[N],to[N],val[N],ans,num,up[N][31],dis[N],deep[N];
void read(int &x){
	x=0;
	char c;
	int w=1;
	for (c=getchar();c<'0'||c>'9';c=getchar()) if (c=='-') w=-1;
	for (;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
	x*=w;
}
void add(int u,int v,int w){
	num++;
	nxt[num]=head[u];
	head[u]=num;
	to[num]=v;
	val[num]=w;
	num++;
	nxt[num]=head[v];
	head[v]=num;
	to[num]=u;
	val[num]=w;
}
void DFS(int x,int fa){
	deep[x]=deep[fa]+1;
	up[x][0]=fa;
	for (int i=1;i<=30;++i)
		up[x][i]=up[up[x][i-1]][i-1];
	for (int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if (v!=fa){
			dis[v]=dis[x]+val[i];
			DFS(v,x);
		}
	}
	//cout<<"QAQ"<<endl;
}
int lca(int u,int v){
	int d1=deep[u],d2=deep[v];
	if (d1<d2) swap(u,v);
	for (int i=30;i>=0;--i)
		if (deep[up[u][i]]<=deep[v]) u=up[u][i];
	if (up[u][0]==up[v][0]) return up[u][0];
	for (int i=30;i>=1;--i)
		if (up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	return up[u][0];
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n);
	read(m);
	for (int u,v,w,i=1;i<n;++i){
		read(u);
		read(v);
		read(w);
		add(u,v,w);
	}
	dis[1]=0;
	deep[1]=0;
	DFS(1,0);
	for (int i=1;i<n;++i)
		for (int j=i+1;j<=n;++j)
			ans=max(ans,dis[i]+dis[j]-2*dis[lca(i,j)]);
	printf("%d\n",ans);
	return 0;
}
