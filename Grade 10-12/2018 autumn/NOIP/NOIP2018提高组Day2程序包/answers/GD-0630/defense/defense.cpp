#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
int n,m;char lr[5];
long long zhi[200000];
struct Edge
{
	int t,nexty;
}edge[1000000];
int head[200000]={0},cnt=0;
void add(int a,int b)
{
	cnt++;
	edge[cnt].t=b;
	edge[cnt].nexty=head[a];
	head[a]=cnt;
}
int aa,bb,cc,dd;
long long f[200000][2],faa[200000],yl[200000][2];
void dfs(int node,int fa)
{
	faa[node]=fa;
	for(int i=head[node];i;i=edge[i].nexty)
	{
		if(edge[i].t==fa)continue;
		dfs(edge[i].t,node);
	}
	if(!((node==aa&&bb==1)||(node==cc&&dd==1)))
	{
		f[node][0]=0;
		for(int i=head[node];i;i=edge[i].nexty)//0
		{
			if(edge[i].t==fa)continue;
			f[node][0]=min(((long long)(2e18)),f[node][0]+f[edge[i].t][1]);
		}
	}
	if(!((node==aa&&bb==0)||(node==cc&&dd==0)))
	{
		f[node][1]=zhi[node];
		for(int i=head[node];i;i=edge[i].nexty)//1
		{
			if(edge[i].t==fa)continue;
			f[node][1]=min(((long long)(2e18)),f[node][1]+min(f[edge[i].t][0],f[edge[i].t][1]));
		}
	}
	yl[node][0]=f[node][0];
	yl[node][1]=f[node][1];
}
void gx(int node)
{
	if(node==0)return;
	f[node][0]=0;
	for(int i=head[node];i;i=edge[i].nexty)//0
	{
		if(edge[i].t==faa[node])continue;
		f[node][0]=min(((long long)(2e18)),f[node][0]+f[edge[i].t][1]);
	}
	f[node][1]=zhi[node];
	for(int i=head[node];i;i=edge[i].nexty)//1
	{
		if(edge[i].t==faa[node])continue;
		f[node][1]=min(((long long)(2e18)),f[node][1]+min(f[edge[i].t][0],f[edge[i].t][1]));
	}
	gx(faa[node]);
}
void fgx(int node)
{
	if(node==0)return;
	f[node][0]=yl[node][0];
	f[node][1]=yl[node][1];
	fgx(faa[node]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,lr);
	for(int i=1;i<=n;i++)scanf("%lld",&zhi[i]);
	int a,b;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	if(n<=2000&&m<=2000)
	{
		while(m--)
		{
			scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
			for(int i=1;i<=n;i++)f[i][0]=f[i][1]=2e18;
			dfs(1,0);
			if(f[1][0]==2e18&&f[1][1]==2e18)printf("-1\n");
			else printf("%lld\n",min(f[1][0],f[1][1]));
		}
		fclose(stdin);fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)f[i][0]=f[i][1]=2e18;
	aa=cc=0;
	dfs(1,0);
	while(m--)
	{
		scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
		f[cc][dd^1]=2e18;
		gx(faa[cc]);
		if(f[1][1]==2e18)printf("-1\n");
		else printf("%lld\n",f[1][1]);
		fgx(cc);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
