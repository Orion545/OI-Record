#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=5005;
bool vis[N];
vector <int> vt[N];
int n,m,p[N],c[N],fa[N],ans[N],x,y;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	vt[u].pb(v);
	vt[v].pb(u);
}

void dfs(int x,int f)
{
	fa[x]=f,vis[x]=1;
	int sz=vt[x].size();
	rep(i,0,sz-1)
		if(vt[x][i]!=f)
		{
			if(vis[vt[x][i]])
			{
				if(!(::x)) ::x=x,y=vt[x][i];
			}
			else dfs(vt[x][i],x);
		}
}

void solve(int x,int f)
{
	c[++*c]=x,vis[x]=1;
	int sz=vt[x].size();
	rep(i,0,sz-1)
		if(vt[x][i]!=f)
			if((x!=::x || vt[x][i]!=y) && (x!=y || vt[x][i]!=::x))
				solve(vt[x][i],x);
}	

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=getint(),m=getint();
	rep(i,1,m) addedge(getint(),getint());
	rep(i,1,n) sort(vt[i].begin(),vt[i].end());
	dfs(1,0);
	if(m==n-1)
	{
		*c=0,memset(vis,0,sizeof(vis)),solve(1,0);
		rep(i,1,n) printf("%d ",c[i]);
		puts("");
	}
	else
	{
		for(int i=x; i!=fa[y]; i=fa[i]) p[++*p]=i;
		*c=0,memset(vis,0,sizeof(vis)),solve(1,0);
		rep(i,1,n) ans[i]=c[i];
		rep(i,1,*p-1)
		{
			x=p[i],y=p[i+1];
			*c=0,memset(vis,0,sizeof(vis)),solve(1,0);
			rep(j,1,n)
			{
				if(c[j]>ans[j]) break;
				if(c[j]<ans[j])
				{
					rep(k,1,n) ans[k]=c[k];
					break;
				}
			}
		}
		rep(i,1,n) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
