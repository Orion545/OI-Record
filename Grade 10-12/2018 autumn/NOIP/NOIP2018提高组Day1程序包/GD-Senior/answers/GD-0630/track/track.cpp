#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int n,m;
struct Edge
{
	int t,nexty,val;
}edge[200000];
int head[200000],cnt=0;
void add(int a,int b,int c)
{
	cnt++;
	edge[cnt].t=b;
	edge[cnt].nexty=head[a];
	edge[cnt].val=c;
	head[a]=cnt;
}
int f1[200000]={0},f2[200000]={0},fa[200000]={0},dx[200000]={0};
void dfsfa(int node)
{
	for(int i=head[node];i;i=edge[i].nexty)
	{
		if(edge[i].t==fa[node])continue;
		fa[edge[i].t]=node;
		dfsfa(edge[i].t);
		dx[node]+=dx[edge[i].t];
	}
	dx[node]++;
}
void dfsm1(int node)
{
	int maxn1=0,maxn2=0;
	for(int i=head[node];i;i=edge[i].nexty)
	{
		if(edge[i].t==fa[node])continue;
		dfsm1(edge[i].t);
		if(f2[edge[i].t]+edge[i].val>maxn1)
		{
			maxn2=maxn1;
			maxn1=f2[edge[i].t]+edge[i].val;
		}
		else
		{
			if(f2[edge[i].t]+edge[i].val>maxn2)maxn2=f2[edge[i].t]+edge[i].val;
		}
	}
	f1[node]=maxn1+maxn2;
	f2[node]=maxn1;
}
int sz[200000];
int f[200000]={0},zgs;
bool yx[200000];
void dfs(int node,int zhi)
{
	int lr=0;
	for(int i=head[node];i;i=edge[i].nexty)
	{
		if(edge[i].t==fa[node])continue;
		dfs(edge[i].t,zhi);
		sz[++lr]=f[edge[i].t]+edge[i].val;
	}
	for(int i=1;i<=lr;i++)yx[i]=false;
	sort(sz+1,sz+lr+1);
	for(int i=lr;i>=1;i--)
	{
		if(yx[i])continue;
		if(sz[i]>=zhi)
		{
			yx[i]=true;
			zgs++;
			continue;
		}
		for(int j=1;j<i;j++)
		{
			if(yx[j])continue;
			if(sz[j]+sz[i]>=zhi)
			{
				yx[i]=yx[j]=true;
				zgs++;
				break;
			}
		}
	}
	for(int i=lr;i>=1;i--)
	{
		if(!yx[i])
		{
			f[node]=sz[i];
			return;
		}
	}
	f[node]=0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a,b,c;
	bool tf1=true,tf2=true;
	int he=0;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		he+=c;
		sz[i]=c;
		if(a!=1)tf1=false;
		if(b!=a+1)tf2=false;
		add(a,b,c);add(b,a,c);
	}
	dfsfa(1);
	if(m==1)
	{
		dfsm1(1);
		int maxn=0;
		for(int i=1;i<=n;i++)maxn=max(maxn,f1[i]);
		printf("%d\n",maxn);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(tf1)
	{
		for(int i=head[1];i;i=edge[i].nexty)f1[edge[i].t-1]=edge[i].val;
		sort(f1+1,f1+n);
		int ans=2e9,yf;
		n--;
		if(m<=n/2)
		{
			for(int i=n-2*m+1;i<=n-m;i++)ans=min(ans,f1[i]+f1[2*n-i-2*m+1]);
		}
		else
		{
			yf=2*m-n;
			for(int i=n;i>=n-yf+1;i--)ans=min(ans,f1[i]);
			for(int i=1;i<=n-m;i++)ans=min(ans,f1[i]+f1[2*n-2*m-i+1]);
		}
		printf("%d\n",ans);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(tf2)
	{
		n--;
		int zuo=0,you=0,mid,js,mq;
		for(int i=1;i<=n;i++)you+=sz[i];
		while(zuo!=you)
		{
			mid=(zuo+you+1)>>1;
			js=mq=0;
			for(int i=1;i<=n;i++)
			{
				mq+=sz[i];
				if(mq>=mid)mq=0,js++;
			}
			if(js>=m)zuo=mid;
			else you=mid-1;
		}
		printf("%d\n",zuo);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	int zuo=0,you=he,mid;
	while(zuo!=you)
	{
		mid=(zuo+you+1)>>1;
		for(int i=1;i<=n;i++)f[i]=0;
		zgs=0;dfs(1,mid);
		if(zgs>=m)zuo=mid;
		else you=mid-1;
	}
	printf("%d\n",zuo);
	fclose(stdin);fclose(stdout);
	return 0;
}
