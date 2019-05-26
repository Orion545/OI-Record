#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxx=0x7f7f7f7f;
struct edge	{
	int v,ne;
}e[100001];
char s[3];
int p[100001];
int f[2001][2],a[2001],h[2001],px,py,px2,py2,q[100001],b[100001],dfn[100001],ppy[2001];

int dfs(int x)	{
	int w=h[x];
	b[x]=0;
//	printf("%d\n",x);
	while (w!=0)	{
		int v=e[w].v;
		if (b[v])	{
			if (dfn[v]==0) dfn[v]=dfn[x]+1;
			dfs(v);
		}
		w=e[w].ne;
	}
	int o=0;
	w=h[x];
	while (w!=0)	{
		int v=e[w].v;
		if (dfn[v]>dfn[x])	{
			q[++o]=v;
		}
		w=e[w].ne;
	}
	f[x][0]=f[x][1]=-1;
	if (o==0) {
		f[x][0]=0;
		f[x][1]=a[x];
	}
	if (o==1)	{
		if (ppy[q[o]]==2) {
			f[x][0]=-1;
			f[x][1]=f[q[o]][0]+a[x];
		}
		else {
			f[x][0]=f[q[o]][1];
			if (ppy[q[o]]==3) f[x][1]=f[q[o]][1]+a[x];
			else if (f[q[o]][1]==-1&&f[q[o]][0]==-1)   f[x][1]=-1;
			else if (f[q[o]][1]==-1||f[q[o]][0]==-1) f[x][1]=max(f[q[o]][1],f[q[o]][0])+a[x];
			else f[x][1]=min(f[q[o]][1],f[q[o]][0])+a[x];
		}
	}
	else {
		for (int i=1;i<=o;++i)
			for (int j=1;j<=o;++j)	
				if (i!=j) {
				int xx,y;
				if (ppy[q[i]]==1) x=f[q[i]][0];
				else if (ppy[q[i]]==2) xx=f[q[i]][1];
				else if (f[q[i]][1]==-1) xx=f[q[i]][0];
				else if (f[q[i]][0]==-1) xx=f[q[i]][1]; 
				else xx=min(f[q[i]][1],f[q[i]][0]);
				
				if (ppy[q[j]]==1) y=f[q[j]][0];
				else if (ppy[q[j]]==2) y=f[q[j]][1];
				else if (f[q[j]][1]==-1) y=f[q[j]][0];
				else if (f[q[j]][0]==-1) y=f[q[j]][1];
				else y=min(f[q[j]][1],f[q[j]][0]);
				
				
				if (ppy[q[i]]!=1&&ppy[q[j]]!=1) 
					if (f[x][0]==-1) f[x][0]=max(-1,f[q[i]][1]+f[q[j]][1]);
					else f[x][0]=min(f[x][0],f[q[i]][1]+f[q[j]][1]);
				if (f[x][1]==-1) f[x][1]=max(-1,xx+y+a[x]);
				else f[x][1]=min(f[x][1],xx+y+a[x]);
			}
	}
}

int main()	{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(dfn,0,sizeof(dfn));
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int top=0;
	for (int i=1;i<=n-1;++i)	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[++top].v=v;e[top].ne=h[u];h[u]=top;
		e[++top].v=u;e[top].ne=h[v];h[v]=top;	
	}
	memset(p,0,sizeof(p));
	memset(ppy,0,sizeof(ppy));
	for (int i=1;i<=m;++i)	{
		memset(b,1,sizeof(b));
		scanf("%d%d%d%d",&px,&py,&px2,&py2);
		if (py==0) ppy[px]=1;
		else ppy[px]=2;
		if (py2==0) ppy[px2]=1;
		else ppy[px2]=2;
		ppy[px]=ppy[px2]=0;
		dfs(1);
		if (max(f[1][0],f[1][1])==-1) printf("-1\n");
		else if (min(f[1][0],f[1][1])!=-1) printf("%d\n",min(f[1][0],f[1][1]));
		else printf("%d\n",max(f[1][0],f[1][1]));
	}
	return 0;
}
