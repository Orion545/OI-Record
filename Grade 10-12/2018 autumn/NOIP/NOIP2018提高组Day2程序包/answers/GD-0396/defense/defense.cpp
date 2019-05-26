#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int lon,n,m,cst[2001],chu[2001][2001],su[2001][2001],haed[2001],ant=0,u,v,ans=0;
int fa[2001];
char c,d;
struct node
{
	int beg,en;
}a[5001];
int edge(int x,int y)
{
	haed[x]++;
	ans++;
	chu[x][haed[x]]=ans;
	a[ans].beg=x;
	a[ans].en=y;
}
int buld(int x)
{
	if(haed[x]==1)
	{
		return 0;
	}
	int j=0;
	for(int i=1;i<=haed[x];++i)
	{
		j++;
		if(a[chu[x][i]].en==fa[x])
		{
			j--;
			continue;
		}
		else
		{
			fa[a[chu[x][i]].en]=x;
			su[x][j]=a[chu[x][i]].en;
			buld(a[chu[x][i]].en);
		}
	}
	return 0;
}
int chack(int x,bool x1,int y,bool y1)
{
	if(haed[x]==1)
	{
		return 0;
	}
	if(x1==0)
	{
		for(int i=1;i<haed[x];i++)
		{
			if(su[x][i]==y&&y1==0)
			{
				return -1;
			}
			ans+=cst[su[x][i]];
			chack(su[x][i],1,y,y1);
		}
	}
	else
	{
		int a1,a2,a3;
		for(int i=1;i<haed[x];i++)
		{
			for(int j=1;j<haed[su[x][i]];j++)
			{
				a1=ans;
				ans=cst[su[x][i]];
				chack(su[su[x][i]][j],0,y,y1);
				a2=ans;
				ans=cst[su[su[x][i]][j]];
				chack(su[su[x][i]][j],1,y,y1);
				a3=ans;
				ans=a1+min(a2,a3);
			}
		}
	}
	return ans;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>c>>d;
	for(int i=1;i<=n;++i)
	{
		cin>>cst[i];
	}
	for(int i=1;i<n;++i)
	{
		cin>>u>>v;
		edge(u,v);
		edge(v,u);
	}
	for(int i=1;i<=m;++i)
	{
		int x,y;
		bool x1,y1;
		cin>>x>>x1>>y>>y1;
		memset(fa,0,sizeof(fa));
		memset(su,0,sizeof(su));
		fa[x]=0;
		haed[x]++;
		buld(x);
		cout<<chack(x,x1,y,y1)<<endl;
		haed[x]--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
