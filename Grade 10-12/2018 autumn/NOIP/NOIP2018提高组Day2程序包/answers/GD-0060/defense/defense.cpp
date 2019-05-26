#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN=100010;
const int oo=2147483647;

int n,m,i,j,k,l,p[MAXN],ans,a,x,b,y,f[MAXN][3];
char ty1,ty2;
bool retp,pd[MAXN];

vector<int>t[MAXN];

bool dfs2(int nown,int fa)
{
	int i,j;
	bool p=1;
	for(i=0;i<t[nown].size();i++)
	{
		int nextn=t[nown][i];
		bool st=0;
		if(nextn!=fa)
		{
			if(pd[nextn])st=1;
			p=dfs2(nextn,nown);
			if(!p)return 0;
		}
		if(!st&&!pd[nown]&&!pd[fa])return 0;
	}
	return 1;
}

bool check()
{
	if(p[a]!=x)return 0;
	if(p[b]!=y)return 0;
	return dfs2(1,0);
}

void dfs(int nown,int s)
{
	int i,j;
	if(nown>n)
	{
		if(check())ans=min(ans,s);
		return;
	}
	pd[nown]=1;
	dfs(nown+1,s+p[nown]);
	pd[nown]=0;
	dfs(nown+1,s);
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	ty1=getchar();ty2=getchar();
	for(i=1;i<=n;i++)scanf("%d",&p[i]);
	for(i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for(i=1;i<=m;i++)
	{
		ans=0;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		/*for(j=1;j<=n;j++)
		 for(k=0;k<3;k++)
		  f[j][k]=oo;*/
		t[0].push_back(1);
		ans=oo;
		memset(p,0,sizeof(p));
		dfs(1,0);
		if(ans==oo)printf("-1\n");
		      else printf("%d\n",ans);
	}
	return 0;
}
