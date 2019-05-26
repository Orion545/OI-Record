#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int lon,n,m,b[5001],chu[5001][5001],haed[5001],ant=0,u,v,ans=0;
bool t[5001];
struct node
{
	int beg,en;
}a[10001];
int edge(int x,int y)
{
	haed[x]++;
	ans++;
	chu[x][haed[x]]=ans;
	a[ans].beg=x;
	a[ans].en=y;
}
int dij(int x)
{
	cout<<x<<" ";
	ans++;
	if(ans==n)
	{
		cout<<endl;
		return 0;
	}
//	cout<<x<<endl;
	int g[5001],j=0;
	for(int i=1;i<=haed[x];i++)
	{
		if(t[a[chu[x][i]].en])
		{
			j++;
			t[a[chu[x][i]].en]=0;
			g[j]=a[chu[x][i]].en;
		}
	}
	sort(g+1,g+j+1);
	for(int i=1;i<=j;++i)
	{
		dij(g[i]);
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v;
		edge(u,v);
		edge(v,u);
	}
	memset(t,true,sizeof(t));
//	cout<<t[1]<<endl;
	ans=0;
	t[1]=0;
	dij(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
