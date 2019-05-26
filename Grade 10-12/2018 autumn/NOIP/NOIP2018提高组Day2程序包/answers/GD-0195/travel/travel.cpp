#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define MAXN 5100
using namespace std;
void debug()
{
	
}
int n,m;
struct node2
{
	int x,y,next;
}a[MAXN*2];int len,last[MAXN];
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
	return ;
}
struct node
{
	int x;
	node(int y)
	{
		x=y;
	}
};
bool operator < (node x,node y)
{
	return x.x>y.x;
}
priority_queue<node> b[5100];
void dfs(int x,int fr)
{
	printf("%d ",x);
	int cnt=0;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fr)
			b[x].push(node(y));
	}
	while(!b[x].empty())
	{
		node y=b[x].top();
		b[x].pop();
		dfs(y.x,x);
	}
	return ;
}
bool v[MAXN],hu[MAXN];
int pan(int x,int fr)
{
	if(v[x])return x;
	v[x]=true;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fr)
		{
			int z=pan(y,x);
		 	if(z!=-1)
			{
				hu[x]=true;
				if(z==x)return -1;
				else return z;	
			}
		}
	}
	v[x]=false;
	return -1;
}
int st[MAXN];
void myadd(int x)
{
	st[x]=1;
	printf("%d ",x);
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(st[y]==-1)st[y]=0;
		if(hu[x])hu[y]=false;
	}
	return ;
}
priority_queue<node> Q;
void mywork()
{
	memset(v,false,sizeof(v));
	memset(hu,false,sizeof(hu));
	pan(1,0);
	memset(st,-1,sizeof(st));st[1]=0;
	int num=0; 
	bool las=false;
	while(num<n)
	{
		if(num==6)
		{
			debug();
		}
		for(int j=1;j<=n;j++)
			if(st[j]==0)
			{
				num++;
				myadd(j);
				if(hu[j]&&las)
				{
					for(int k=last[j];k;k=a[k].next)
					{
						int y=a[k].y;
						if(!hu[y]&&st[y]==0)Q.push(node(y));
					}
					while(!Q.empty())
					{
						node x=Q.top();Q.pop();
						num++;
						myadd(x.x);
					}
				}
				las=hu[j];
				break;
			}
	}
	printf("\n");
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	if(m==n-1)
	{
		dfs(1,0);
		printf("\n");
	}
	else mywork();	
	return 0;
}
