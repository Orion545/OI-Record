#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <vector>
const int inf=1e9;
const int mo=1e9+7;
const int N=5e3+10;
using namespace std;
int n,m,an[N][N],num,go[N][N],a[N][2],v[N];
bool bz[N][N],vis[N];
void dg(int x,int fa)
{
	vis[x]=true;
	an[num][++an[num][0]]=x;
	for(int i=1;i<=v[x];i++)
	{
		int j=go[x][i];
		if(bz[x][j]) continue;
		if(vis[j] && j!=fa)
		{
			an[num][0]=-1;
			return;
		}
		if(vis[j]) continue;
		dg(j,x);
		if(an[num][0]==-1) return;
	}
}
bool cmp(int x,int y)
{
	if(an[x][0]!=n) return true;
	if(an[y][0]!=n) return false;
	for(int i=1;i<=n;i++)
		if(an[x][i]>an[y][i]) return true;
		else
		if(an[x][i]<an[y][i]) return false;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),a[i][0]=x,a[i][1]=y,go[x][++v[x]]=y,go[y][++v[y]]=x;
	for(int i=1;i<=n;i++) sort(go[i]+1,go[i]+1+v[i]);
	if(m==n-1)
	{
		num=1;
		dg(1,0);
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			memset(vis,0,sizeof(vis));
			num++;
			bz[a[i][0]][a[i][1]]=bz[a[i][1]][a[i][0]]=true;
			dg(1,0);
			bz[a[i][0]][a[i][1]]=bz[a[i][1]][a[i][0]]=false;
		}
		for(int i=2;i<=n;i++)
			if(cmp(1,i)) swap(an[1],an[i]);
	}
	for(int i=1;i<n;i++) printf("%d ",an[1][i]);
	printf("%d",an[1][n]);
}
