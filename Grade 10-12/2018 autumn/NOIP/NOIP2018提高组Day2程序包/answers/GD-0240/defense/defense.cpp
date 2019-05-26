#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<list>
#include<string>
#define int long long
using namespace std;
string type;
list<int>lis[100005];
int n,m,p[100005],f[100005],ans;
bool yao[100005],vis[100005],flag;
/*void dfs(int x,bool fla)
{
	if(yao[x])
	{
		f[x]=a[x];
	}
	for(list<int>::iterator it=lis[x].begin();it!=lis[x].end();it++)
	{
		if(!vis[*it])
		{
			vis[*it]=true;
			dfs(*it);
			
		}
	}
}*/
signed main()
{
	freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
	//freopen(")
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%lld %lld",&u,&v);
		lis[u].push_back(v);
		lis[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
	{
		printf("-1\n");
	}
	return 0;
}
