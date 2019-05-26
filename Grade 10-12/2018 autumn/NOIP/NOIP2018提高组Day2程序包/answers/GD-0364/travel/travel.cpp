#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,a[5010],b[5010],st[5010],en[5010],tot,cnt;
bool f[5010],fff[5010][5010],cuttt[5010][5010];

struct node{
	int u,v;
}bian[20010];

int cmp(node x,node y)
{
	return (x.u<y.u||(x.u==y.u&&x.v<y.v));
}

void dfs(int x)
{
	f[x]=true;a[++cnt]=x;
	for (int i=st[x];i<=en[x];i++){
		if (f[bian[i].v]||cuttt[bian[i].u][bian[i].v]) continue;
		dfs(bian[i].v);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	tot=0;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		node z;
		z.u=x,z.v=y;bian[++tot]=z;
		z.u=y,z.v=x;bian[++tot]=z;
	}
	sort(bian+1,bian+2*m+1,cmp);
	for (int i=1;i<=n;i++) st[i]=en[i]=0;
	for (int i=1;i<=2*m;i++){
		if (st[bian[i].u]==0) st[bian[i].u]=i;
		en[bian[i].u]=i;
	}
	if (m==n-1){	
		dfs(1);
		for (int i=1;i<=n;i++)
			printf("%d ",a[i]);
	}
	else{
		for (int i=1;i<=n;i++) b[i]=n+1;
		for (int i=1;i<=2*m;i++){
			if (fff[bian[i].u][bian[i].v]) continue;
			fff[bian[i].u][bian[i].v]=fff[bian[i].v][bian[i].u]=true;
			cuttt[bian[i].u][bian[i].v]=cuttt[bian[i].v][bian[i].u]=true;
			cnt=0;
			for (int j=1;j<=n;j++) f[j]=false;
			dfs(1);
			cuttt[bian[i].u][bian[i].v]=cuttt[bian[i].v][bian[i].u]=false;
			if (cnt<n) continue;
			for (int j=1;j<=n;j++)
				if (a[j]<b[j]){
					for (int k=j;k<=n;k++)
						b[k]=a[k];
					break;
				}
				else if (a[j]>b[j]) break;
			//for (int j=1;j<=n;j++) printf("%d ",a[j]);printf("\n");
		}
		for (int i=1;i<=n;i++)
			printf("%d ",b[i]);
	}
	return 0;
}
