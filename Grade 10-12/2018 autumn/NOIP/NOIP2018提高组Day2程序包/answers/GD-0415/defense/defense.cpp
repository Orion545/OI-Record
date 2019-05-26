#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<stdlib.h>
#include<queue>
using namespace std;
const int N=100005;

int n,m;
string st;
long long val[N];
int vis[N];
struct Defense{
	int x,y;
}a[N];
bool cmp(Defense i,Defense j)
{
	if(val[i.x]==val[j.x])
	return val[i.y]<val[j.y];
	return val[i.x]<val[j.x];
}
void read();
void work();
int main()
{
	read();
	for(int i=1;i<=m;i++)
	  work();
	return 0;
}

void work()
{
	int t,tt,d,dd;
	long long ans=0;
	scanf("%d%d%d%d",&t,&tt,&d,&dd);
	memset(vis,0,sizeof(vis));
	if(tt==1) 
	  vis[t]=1,ans+=val[t];
	else   
	  vis[t]=-1;
	if(dd==1) 
	  vis[d]=1,ans+=val[d];
	else   
	  vis[d]=-1;
	for(int i=1;i<n;i++)
	{
		int nx=a[i].x,ny=a[i].y;
		//cout<<nx<<' '<<ny<<endl;
		if(vis[nx]==-1 && vis[ny]==-1)
		{
			printf("-1\n");
			return ;
		}
		if(vis[nx]==1 || vis[ny]==1)
		  continue;
		if(vis[nx]==-1)
		{
			ans+=val[ny];
			vis[ny]=1;
		}
		if(vis[ny]==-1)
		{
			ans+=val[ny];
			vis[ny]=1;
		}
		if(!vis[nx] && !vis[ny])
		{
			if(val[nx]>val[ny])
			{
				ans+=val[ny];
				vis[ny]=1;
			}
			else
			{
				ans+=val[nx];
				vis[nx]=1;
			}
		}
	}
	printf("%lld\n",ans);
	return ;
}

void read()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);cin>>st;
	for(int i=1;i<=n;i++)
	  scanf("%lld",&val[i]);
	for(int i=1;i<n;i++)
	  scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n,cmp);
}

