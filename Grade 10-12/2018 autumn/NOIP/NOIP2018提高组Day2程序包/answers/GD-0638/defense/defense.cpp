#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
char type[4];
int p[2005];
int head[2005],to[5000],next[5000],ie;
int f[2005][3];
void add(int x,int y)
{
	ie++;to[ie]=y;
	next[ie]=head[x];
	head[x]=ie;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d ",&n,&m);
	scanf("%s",type);
	for(int i=1;i<=n;i++)
	{scanf("%d",&p[i]);
	}
	for(int i=1,a,b;i<n;i++)
	{scanf("%d%d",&a,&b);
	add(a,b);add(b,a);
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,y,x;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(f,0,sizeof(f));
		if(type[0]='A')
		{
			for(int j=1;j<=n;j++)
			{
				if(a==j)
				{
					if(x==1)
					{f[j][1]+=min(f[j-1][1],f[j-1][0])+p[j];
					f[j][0]=99999999;}
					else if(x==0)
					{f[j][0]+=f[j-1][1];
					f[j][1]=99999999;
					}
				}
				else if(b==j)
				{
					if(y==1)
					{f[j][1]+=min(f[j-1][1],f[j-1][0])+p[j];
					f[j][0]=99999999;}
					else if(y==0)
					{f[j][0]+=f[j-1][1];
					f[j][1]=99999999;
					}
				}
				else
				{
				f[j][1]+=min(f[j-1][1],f[j-1][0])+p[j];
				f[j][0]+=f[j-1][1];
				}
			}
			int	ans=min(f[n][1],f[n][0]);
			if(ans>99999999) ans=-1;
			printf("%d\n",ans);
		}
	}
}
