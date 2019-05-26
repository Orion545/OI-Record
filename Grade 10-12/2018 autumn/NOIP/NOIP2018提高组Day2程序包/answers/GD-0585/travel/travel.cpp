#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

int x,y,i,j,k,l,n,m,hh,zz,les,zou;
int map[5005][5005],fa[5005];
bool b[5005],huan[5005],z[5005],pd;

void dfs(int x)
{
	printf("%d ",x);
	b[x]=1;
	for (int i=1; i<=map[x][0]; i++)
		if (!b[map[x][i]]) dfs(map[x][i]);
}

void dfs2(int x)
{
	printf("%d ",x);
	b[x]=1;
	for (int i=1; i<=map[x][0]; i++)
	{
		//if (map[x][i]==5) printf("%d\n",used);
		if (!b[map[x][i]])
		{
			if (x==zz) z[map[zz][i]]=0;
			if (!huan[map[x][i]])
				if (zou||pd)
					dfs(map[x][i]);
				else dfs2(map[x][i]);
			else
			{
				if (map[x][i]==zz)
					z[x]=0,zou=1,dfs2(zz);
				else
				{
					bool bbb=false;
					int j;
					for (j=1; j<=map[zz][0]; j++)
						if (z[map[zz][j]])
						{
							bbb=true;
							break;
						}
					if (map[zz][j]<map[x][i]&&bbb)
					{
						pd=1;
						dfs(map[zz][j]);
						return ;
					}
					if (map[map[x][i]][0]>2)
					{
						pd=1,dfs(map[x][i]);
						continue;
					}
					else dfs2(map[x][i]);
				}
			}
		}
	}
}

void get_fa(int x)
{
	for (int i=1; i<=map[x][0]; i++)
	{
		if (pd) return ;
		if (!fa[map[x][i]])
		{
			fa[map[x][i]]=x;
			get_fa(map[x][i]);
		}
		else if (map[x][i]!=fa[x]) hh=x,zz=map[x][i],pd=1;
	}
}

void get_huan(int x)
{
	huan[x]=1;
	if (x==zz) return ;
	get_huan(fa[x]);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1; i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		map[x][++map[x][0]]=y;
		map[y][++map[y][0]]=x;
	}
	for (i=1; i<=n; i++)
	{
		k=map[i][0];
		sort(map[i]+1,map[i]+k+1);
	}
	if (m==n-1)
	{
		dfs(1);
		return 0;
	}
	fa[1]=1;
	get_fa(1);
	//printf("%d %d\n",hh,zz);
	get_huan(hh);
	pd=0;
	for (i=1; i<=map[zz][0]; i++) z[map[zz][i]]=1;
	dfs2(1);
	return 0;
}
