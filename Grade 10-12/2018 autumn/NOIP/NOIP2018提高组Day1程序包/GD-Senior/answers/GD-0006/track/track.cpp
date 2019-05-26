#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int head[50002],to[100002],s[100002],last[100002],next[100002],p;
int ans=0,f[50002],n,m;
bool b[100002];
int d[50002];
int p1[50002],p2[50002];
void add(int u,int v,int w)
{
	p++;
	last[p]=head[u];
	next[last[p]]=p;
	to[p]=v;
	s[p]=w;
	head[u]=p;
}
void dfs(int x,int y)
{
	int max1=0,max2=0;
	for(int j=head[x];j;j=last[j])
	if(to[j]!=y)
	{
		dfs(to[j],x);
		if(max1<f[to[j]]+s[j])
		{
			max2=max1;
			max1=f[to[j]]+s[j];
		}
		else
		if(max2<f[to[j]]+s[j])
		max2=f[to[j]]+s[j];
	}
	ans=max(ans,max1+max2);
	f[x]=max1;
}
void dfs1(int x,int y)
{
	f[x]=0;
	bool p=false;
	for(int j=head[x];j;j=last[j])
	if(to[j]!=y&&!b[j])
	{
		dfs1(to[j],x);
		if(f[to[j]]+s[j]>f[x])
		{
			f[x]=f[to[j]]+s[j];
			p2[x]=j;
			p=true;
		}
	}
	if(!p)
	p2[x]=-1;
}
void del(int x)
{
	if(p1[x]==-1)
	return ;
	ans+=s[p1[x]];
	b[p1[x]]=true;
	b[p1[x]^1]=true;
	del(to[p1[x]]);
}
void change(int x)
{
	p1[x]=p2[x];
	if(p2[x]==-1)
	return ;
	change(to[p2[x]]);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int t1,t2,t3,sum=0;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		d[t1]++;d[t2]++;
		sum+=t3;
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	if(m==1)
	dfs(1,0);
	else
	if(d[1]==n-1)
	{
		sort(s+1,s+p+1,cmp);
		for(int i=1;i<=min(n-1,m*2);i++)
		ans+=s[(i<<1)-1];
	}
	else
	ans=sum;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
