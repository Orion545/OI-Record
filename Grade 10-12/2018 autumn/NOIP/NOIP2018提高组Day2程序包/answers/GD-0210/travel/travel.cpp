#include<bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef pair<int,int> pii;
const int N=5005;
int n,m,cnt,getcir,ind,cn;
int ins[N],b[N],ans[N];
stack<int>s;
vector<int>e[N];
pii a[N];

int read()
{
	int ret=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c^48),c=getchar();
	return ret;
}

void dfs1(int x,int fa)
{
	//cerr<<x<<" "<<fa<<endl;
	if(getcir) return;
	s.push(x);ins[x]=1; int sz=e[x].size();
	//cerr<<"push:"<<x<<endl;
	for(int i=0;i<sz;++i)
	{
		int v=e[x][i];
		if(v==fa) continue;
		if(getcir) return;
		if(ins[v])
		{
			int u,las=x;s.pop();
			a[++cnt]=mkp(x,v);
			while((u=s.top())^v)
			{
				a[++cnt]=mkp(u,las),las=u,s.pop();
			}
			a[++cnt]=mkp(las,v);
			getcir=1;return;
		}
		dfs1(v,x);
	}
	if(getcir) return;
	ins[x]=0;s.pop();
	//cerr<<"pop:"<<x<<endl;
}

void dfs2(int x,int fa)
{
	int sz=e[x].size();b[++ind]=x;
	for(int i=0;i<sz;++i)
	{
		int v=e[x][i];
		if(v==fa) continue;
		if((x==a[cn].fi && v==a[cn].se) || (x==a[cn].se && v==a[cn].fi)) continue;
		dfs2(v,x);
	}
}

void check()
{
	//for(int i=1;i<=n;++i) printf("%d ",b[i]);puts("");
	bool flag=0;
	for(int i=1;i<=n;++i) 
	{
		if(b[i]>ans[i]) break;
 		if(b[i]<ans[i]) {flag=1;break;}
	}
	if(flag) for(int i=1;i<=n;++i) ans[i]=b[i];
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		e[u].pb(v);e[v].pb(u);
	}
	for(int i=1;i<=n;++i) sort(e[i].begin(),e[i].end());
	dfs1(1,0);
	for(int i=1;i<=n;++i) ans[i]=n+1;
	//for(int i=1;i<=cnt;++i) printf("%d %d\n",a[i].fi,a[i].se);
	if(!cnt) dfs2(1,0),check();
	else
	{
		for(int i=1;i<=cnt;++i) 
		{
			ind=0;cn=i;
			dfs2(1,0);check();
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	
	return 0;
}
