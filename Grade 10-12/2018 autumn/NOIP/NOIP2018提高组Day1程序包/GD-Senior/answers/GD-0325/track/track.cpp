#include<iostream>
#include<cstdio>
#include<fstream>
	using namespace std;
struct edge
{
	int last;
	int end;
	int weight;
}e[100005];
	int n=0,m=0,a=0,b=0,c=0,d=0,ne=0,s[50005],note[50005];
void NewEdge(int u,int v,int w)
{
	ne++;
	e[ne].last=note[u];
	e[ne].end=v;
	e[ne].weight=w;
	note[u]=ne;
}
void dfs(int x,int fx,int y)
{
	if(y>a) a=y,b=x;
	for(int i=note[x];i;i=e[i].last)
		if(e[i].end!=fx) dfs(e[i].end,x,y+e[i].weight);
}
void gao(int x,int fx,int y)
{
	for(int i=note[x];i;i=e[i].last)
		if(e[i].end!=fx) s[y]=e[i].weight,gao(e[i].end,x,y+1);
}
int ___nong_(int x)
{
	int w=0,k=0;
	for(int i=0;i<=n-2;i++)
	{
		w+=s[i];
		if(w>=x) k++,w=0;
	}
	if(k>=m) return 1;
	return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int u=0,v=0,w=0;
		scanf("%d%d%d",&u,&v,&w);
		NewEdge(u,v,w);
		NewEdge(v,u,w);
	}
	if(m==1)
	{
		dfs(1,0,0);
		c=a,d=b,a=0,b=0;
		dfs(d,0,0);
		printf("%d",a);
	}
	else
	{
		gao(1,0,0);
		int l=0,r=6e8;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(___nong_(mid)) l=mid;
						 else r=mid;
		}
		printf("%d",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
