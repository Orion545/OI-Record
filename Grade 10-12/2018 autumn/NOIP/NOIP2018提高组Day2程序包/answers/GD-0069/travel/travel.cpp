#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 5010
using namespace std;

int n,m,i,j,x,y,du[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn],bz[maxn*2],vis[maxn],r[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}


int d[maxn],t,w;
void tropu(){
	t=w=0,r[0]=1;
	for(i=1;i<=n;i++) if (du[i]==1) d[++w]=i;
	while (t<w){
		x=d[++t],r[x]=1;
		for(i=ls[x];i;i=nx[i]) if (!bz[i]){
			if (i&1) j=i+1; else j=i-1;
			bz[i]=1;bz[j]=1;
			if (--du[e[i]]==1) d[++w]=e[i];
		}
	}
}

int a[maxn][maxn];
void dfs(int x,int p,int at){
	if (vis[x]) return;
	vis[x]=1;
	printf("%d ",x);
	if (x==at) at=1e9;
	if (!r[x]&&r[p]){
		at=0;
		for(int i=ls[x];i;i=nx[i]) if (!bz[i]&&e[i]!=p&&!r[e[i]])
			at=max(at,e[i]);
	}
	a[x][0]=0;
	for(int i=ls[x];i;i=nx[i]) if (!bz[i]&&e[i]!=p){
		if (!r[e[i]]&&e[i]>at) {
			if (i&1) j=i+1; else j=i-1;
			bz[i]=1;bz[j]=1;
			continue;
		} 
		a[x][++a[x][0]]=e[i];
	}
	sort(a[x]+1,a[x]+1+a[x][0]);
	for(int i=1;i<=a[x][0];i++) 
		dfs(a[x][i],x,at);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		insert(x,y);
		du[x]++,du[y]++;
	}
	tropu();
	memset(bz,0,sizeof(bz));
	memset(vis,0,sizeof(vis));
	dfs(1,0,1e9);
}
