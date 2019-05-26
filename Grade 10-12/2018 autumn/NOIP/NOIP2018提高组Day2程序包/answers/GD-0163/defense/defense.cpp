#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define N 100010
#define M 200010
using namespace std;
int n,m,tot,p[N];
string type;
int head[N],Next[M],ver[M];
int have[N];

void addedge(int x,int y)
{
	tot++;
	ver[tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>type;
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	if(type[0]=='A')
	{
		int sum=0;
		memset(have,-1,sizeof(have));
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);	
		}
		for(int i=1;i<=m;i++)
		{
			int a,b,x,y;
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(x==0) have[a]=0;
			else if(x==1) have[a]=1;
			if(y==0) have[b]=0;
			else if(y==1) have[b]=1;
		}
		sort(p+1,p+n+1);
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(have[i]==1)
				sum+=p[++t];
		}
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				if(have[2]==1) continue;
				else
				{
					have[i]=1;
					sum+=p[++t];
				}
			}
			if(i>1 && i<n)
			{
				if(have[i-1]!=1 && have[i+1]!=1)
				{
					have[i]=1;
					sum+=p[++t];
				}
			}
			if(i==n)
			{
				if(have[i-1]==1) continue;
				else
				{
					have[i]=1;
					sum+=p[++t];
				}
			}
		}
		printf("%d\n",sum);
		return 0;
	}
	
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	return 0;
}
