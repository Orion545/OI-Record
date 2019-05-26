#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define pb push_back
#define SZ(X) (int)X.size()
using namespace std;

const int maxn = 10100;

int n,m;
int inc[maxn],vis[maxn],t[maxn],tp;
vector<int>V[maxn];

int findc(const int x,const int las)
{
	vis[x]=1; t[++tp]=x;
	for(int i=0;i<SZ(V[x]);i++)
	{
		int y=V[x][i]; if(y==las) continue;
		if(vis[y])
		{
			inc[y]=1;
			while(t[tp]!=y) inc[t[tp--]]=1;
			return 1;
		}
		if(findc(y,x)) return 1;
	}
	tp--;
	return 0;
}

int fi[maxn],tot;
int ans[maxn],ansn;
void dfs(const int x,int mn)
{
	if(inc[x]) tot--;
	int tmpt=0;
	if(!vis[x]) 
	{
		vis[ans[++ansn]=x]=1;
		for(int j=0;j<SZ(V[x]);j++) if(inc[V[x][j]]&&!vis[V[x][j]]) tmpt++;
		tot+=tmpt;
	}
	int &i=fi[x];
	while(i<SZ(V[x]))
	{
		int y=V[x][i];	if(vis[y]) { i++;continue; }
		
		if(inc[x]&&inc[y]&&i==SZ(V[x])-1&&tot-tmpt>0&&mn<y) { i++; tot-=tmpt; break; }
		
		int nex=i+1;
		while(nex<SZ(V[x])&&vis[nex]) nex++;
		nex=nex==SZ(V[x])?mn:V[x][nex];
		dfs(y,nex);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		V[x].pb(y); V[y].pb(x);
	}
	for(int i=1;i<=n;i++) sort(V[i].begin(),V[i].end());
	if(m==n) findc(1,0);
	
	memset(vis,0,sizeof vis);
	dfs(1,n+1);
	for(int i=1;i<=ansn;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	
	return 0;
}

