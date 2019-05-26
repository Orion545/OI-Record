#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL maxx=0,sum[100001];
vector<int> edges[100001],vv[100001];
bool vis[100001];
int n,m;

LL read()
{
	LL num=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}

LL dfs(int root)
{
	vis[root]=1;
	int len=edges[root].size();
	LL m1=0,m2=0;
	if(len==1) return 0;
	for(int i=0;i<len;i++)
	if(!vis[edges[root][i]])
	{
		LL t=dfs(edges[root][i])+vv[root][i];
		if(t>m2 && t<=m1) m2=t;
		if(t>m1) m1=t;
	}
	maxx=max(maxx,m1+m2);
	return m1;
}

bool check(int x)
{
	int p=0,cnt=0;
	for(int i=1;i<n;i++)
	if(sum[i]-p>=x)
	{
		cnt++;
		p=sum[i];
	}
	if(cnt>=m) return 1; else return 0;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	if(m!=1)
	{
		for(int i=1;i<n;i++)
		{
			int x=read(),y=read(),v=read();
			sum[i]=sum[i-1]+v;
		}
		int l=0,r=sum[n-1]+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(check(mid)) l=mid; else r=mid;
		}
		printf("%d",r-1);
	}
	if(m==1)
	{
		for(int i=1;i<n;i++) 
		{
			int x=read(),y=read(),v=read();
			edges[x].push_back(y);
			edges[y].push_back(x);
			vv[x].push_back(v); vv[y].push_back(v);
		}
		memset(vis,sizeof(vis),0);
		LL r=dfs(1);
		printf("%lld",maxx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
