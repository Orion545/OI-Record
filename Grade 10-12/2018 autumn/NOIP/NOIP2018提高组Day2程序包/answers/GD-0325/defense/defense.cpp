#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
	using namespace std;
struct edge
{
	int last;
	int end;
}e[200005];
	int a=0,u=0,b=0,v=0,ne=0,p[100005],note[100005];
	long long f[100005][2];
void NewEdge(int u,int v)
{
	ne++;
	e[ne].last=note[u];
	e[ne].end=v;
	note[u]=ne;
}
void gao(int x,int fx)
{
	f[x][0]=0,f[x][1]=p[x];
	for(int i=note[x];i;i=e[i].last)
		if(e[i].end!=fx) gao(e[i].end,x);
	for(int i=note[x];i;i=e[i].last)
		if(e[i].end!=fx)
		{
			f[x][0]+=f[e[i].end][1];
			f[x][1]+=min(f[e[i].end][0],f[e[i].end][1]);
		}
	if(x==a) f[x][!u]=1e6;
	if(x==b) f[x][!v]=1e6;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=0,m=0;
	char ch[10];
	scanf("%d%d",&n,&m);
	scanf("%s",ch);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u=0,v=0;
		scanf("%d%d",&u,&v);
		NewEdge(u,v);
		NewEdge(v,u);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&u,&b,&v);
		gao(1,0);
		long long ans=min(f[1][0],f[1][1]);
		if(ans>=1e6) ans=-1;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
