#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct edge{
	int to,next,w;
	edge(int _to=0,int _next=0,int _w=0):to(_to),next(_next),w(_w){}
}e[MAXN<<1];

int n,m,lim;
int g[MAXN],nume;
int f[MAXN],h[MAXN];

void addEdge(int u,int v,int w){
	e[nume]=edge(v,g[u],w);
	g[u]=nume++;
}

void dfs(int x,int p){
	f[x]=0;
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p){
			dfs(e[i].to,x);
			f[x]+=f[e[i].to];
		}
	static int a[MAXN<<1];
	int nc=0;
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p)
			a[++nc]=h[e[i].to]+e[i].w;
	sort(a+1,a+nc+1);
	for(int i=1;i<=nc;i++){
		a[i+nc]=a[i];
		a[i]=0;
	}
	nc*=2;
	int temp=0;
	for(int i=nc,j=1;i>j;){
		if(a[i]+a[j]<lim) j++;
		else{
			i--;j++;
			temp++;
		}
	}
	f[x]+=temp;
	h[x]=a[nc-temp*2];
	for(int i=1;i<=temp;i++){
		if(a[nc-temp*2+i-1]+a[nc-i+1]<lim) return;
		h[x]=a[nc-temp*2+i];
	}
	for(int i=temp;i>=1;i--){
		if(a[nc-temp*2+i-1]+a[nc-i]<lim) return;
		h[x]=a[nc-i+1];
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(g,-1,sizeof g);
	int l=0,r=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addEdge(u,v,w);
		addEdge(v,u,w);
		r+=w;
	}
	while(l<r){
		int mid=(l+r+1)>>1;
		lim=mid;
		dfs(1,0);
		if(f[1]>=m) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
