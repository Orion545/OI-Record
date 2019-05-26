#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define maxn 5005
using namespace std;
int n,m;
bool vis[maxn]={0},visx[maxn]={0},bj=0;
int tot=0,t[maxn],nt[maxn],head[maxn],d[maxn];
int ans[maxn];
int cj[maxn];

int build(int a,int b)
{
	tot++;
	t[tot]=b;	
	d[a]++;
	nt[tot]=head[a];
	head[a]=tot;
}			

int dfs(int a,int tot)
{
	ans[tot]=a;
	int nowtot=tot+1;
	int tmptot;
	//cout<<nowtot;
	int tt=d[1];
	d[1]=2;
	if(d[a]==1)
	{
		return nowtot;
		//cout<<"t";
	}
	d[1]=tt;
	int maxd=0;
	for(int j=1;j<=d[a];j++)
	{
		int last=maxd;
		maxd=0x7f7f7f7f;
		bj=0;
		for(int i=head[a];i;i=nt[i])
	    {
	    	//cout<<t[i]<<"_";
		 	if(t[i]<=last)
		 	{
		 		continue;
		 	}
		 	if(t[i]<maxd && vis[t[i]]==0)
		 	{
		 		maxd=t[i];
		 		bj=1;
		 		//cout<<"bj";
		 	}
		 	
	    }
	    if(bj==1)
	    {
	    	vis[maxd]=1;
	    	tmptot=dfs(maxd,nowtot);
	    	nowtot=tmptot;
	    }
	}
	return nowtot;
}

//int tot1=1;
//void bcj()
//{
//	for(int j=2;j<=n;j++)
//	{
//		for(int i=2;i<=n;i++)
//		{
//			if(vis[i]==1)
//			continue;
//			for(int k=head[i];k;k=nt[k])
//			{
//				if(vis[t[k]]==1)
//				{
//					tot1++;
//					vis[i]=1;
//					ans[tot1]=i;
//					bj=1;
//					break;
//				}
//			}
//			if(bj==1)
//			{
//				bj=0;
//				break;
//			}
//		}
//	}
//}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(int a,b,i=1;i<=m;i++)
	{
		scanf("%d %d", &a, &b);
		build(a,b);
		build(b,a);
	}
	//vis[1]=1;
	//ans[1]=1;
	//bcj();
	vis[1]=1;
	int j=dfs(1,1);
	//cout<<ans[1]<<"!";
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		{
			printf("%d", ans[i]);
			break;
		}
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
