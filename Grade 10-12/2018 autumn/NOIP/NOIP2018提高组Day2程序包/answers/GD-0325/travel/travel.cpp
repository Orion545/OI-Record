#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
	using namespace std;
struct edge
{
	int last;
	int end;
}e[11005];
struct shujv
{
	int u;
	int v;
}d[11005];
bool cmp(shujv x,shujv y)
{
	if(x.u==y.u) return x.v>y.v;
	return x.u<y.u;
}
	int n=0,m=0,h=0,k=0,s=0,ne=0;
	int t[5005],sta[5005],ans[5005],note[5005];
	bool c=false,a[5005],b[5005];
void NewEdge(int u,int v)
{
	ne++;
	e[ne].last=note[u];
	e[ne].end=v;
	note[u]=ne;
}
void gao(int x,int fx)
{
	if(c) return;
	if(a[x])
	{
		while(d[sta[k+1]].u!=x) b[sta[k--]]=true;
		c=true;
		return;
	}	
	a[x]=true;
	for(int i=note[x];i;i=e[i].last)
		if(e[i].end!=fx)
		{
			sta[++k]=i;
			gao(e[i].end,x),k--;
		}
}
void dfs(int x,int fx)
{
	t[++h]=x;
	for(int i=note[x];i;i=e[i].last)
	{
		if(e[i].end==fx||(x==d[s].u&&e[i].end==d[s].v)||(x==d[s].v&&e[i].end==d[s].u)) continue;
		dfs(e[i].end,x);
	}
}
void __nong_()
{
	for(int i=1;i<=n;i++)
		if(t[i]<ans[i])
		{
			for(int j=1;j<=n;j++) ans[j]=t[j];
			return;
		}
		else if(t[i]>ans[i]) return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		a[i]=false,b[i]=false;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&d[i].u,&d[i].v);
		d[i+m].u=d[i].v;
		d[i+m].v=d[i].u;
	}
	sort(d+1,d+m+m+1,cmp);
	for(int i=1;i<=m+m;i++) NewEdge(d[i].u,d[i].v);
	gao(1,0);
	ans[1]=1e9;
	for(int i=1;i<=m+m;i++)
		if(b[i]) s=i,h=0,dfs(1,0),__nong_();
	if(ans[1]==1e9) s=0,h=0,dfs(1,0),__nong_();
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
