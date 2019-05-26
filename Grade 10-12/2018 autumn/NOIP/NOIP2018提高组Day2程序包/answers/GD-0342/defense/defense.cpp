#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct data{
	int from,to;
}e[100010];
int n,m,ecnt,des,p[1000010],fu,head[100010],ans=0x7fffffff,vis[100010];
char str[10];
void adde(int u,int v)
{
	e[++ecnt].to=v;
	e[ecnt].from=head[u];
	head[u]=ecnt;
}
void dfs(int noww,int fa,int hua,int cou)
{
	if(fu==1) return;
	if(cou==n-1)
	{
		ans=min(ans,hua);
		return;
	}
	int flag=0;
	if(vis[fa]==1) flag=1;
	for(int i=head[noww];i!=0;i=e[i].from)
	{
		des=e[i].to;
		if(des!=fa)
		{
			cou++;
			if(vis[noww]!=1&&vis[des]==-1)
			{
				fu=1;return;
			}
			if(vis[noww]!=1)
			{
				vis[des]=1;
				dfs(des,noww,hua+p[des],cou);
			}
			else
			{
				if(vis[noww]==1&&vis[des]==0)
				{
					vis[des]=1;
					dfs(des,noww,hua+p[des],cou);
					vis[des]=-1;
					dfs(des,noww,hua,cou);
				}
				else
				{
					if(vis[noww]==1&&vis[des]==-1)
					{
						dfs(des,noww,hua,cou);
					}
					if(vis[noww]==1&&vis[des]==1)
					{
						dfs(des,noww,hua+p[des],cou);
					}
				}
				
			}
			cou--;
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	int tor1,tor2,tor3,tor4;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&tor1,&tor2);
		adde(tor1,tor2);adde(tor2,tor1);
	}
	if(n<=10&&m<=10)
	{
		for(int i=1;i<=n;i++) vis[i]=-1;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&tor1,&tor2,&tor3,&tor4);
			ans=0x7fffffff;
			memset(vis,0,sizeof(vis));
			vis[tor1]=tor2;vis[tor3]=tor4;
			if(tor1!=1&&tor3!=1)
			{
				vis[0]=1;vis[1]=1;
				dfs(1,0,p[1],0);
				vis[1]=0;
				dfs(1,0,0,0);
			}
			else
			{
				if(vis[1]==1) dfs(1,0,p[1],0);
				else dfs(1,0,0,0);
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
