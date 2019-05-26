#include<map>
#include<list>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int>a[100005];
int f[100005][2];
int b[100005];
bool c[100005];
int n,m,x_,y_,a_,b_;
char s[10];
void dfs(int u,int fa)
{
	f[u][0]=0;
	f[u][1]=b[u];
	for(int i=0;i<a[u].size();i++)if(a[u][i]^fa)
	{
		dfs(a[u][i],u);
		f[u][0]+=f[a[u][i]][1];
		f[u][1]+=min(f[a[u][i]][0],f[a[u][i]][1]);
	}
	if(u==x_)f[u][a_^1]=0x3f3f3f3f;
	if(u==y_)f[u][b_^1]=0x3f3f3f3f;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x_,&a_,&y_,&b_);
		dfs(1,0);
		int tmp=min(f[1][0],f[1][1]);
		tmp<0x3f3f3f3f?printf("%d\n",tmp):printf("-1\n");
	}
}
