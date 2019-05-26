#include<bits/stdc++.h>
#define fir first
#define sec second
#define pbk push_back
using namespace std;
typedef pair<int,int> pr;

const int maxn = 5e3 + 10;

inline int read()
{
	int x=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+(c^48);
	return x;
}

int n,m;
vector<int> e[maxn];

inline void addedge(int u,int v){e[u].pbk(v);e[v].pbk(u);}
void input()
{
	n=read();m=read();
	for(int i=0;i<m;i++) addedge(read(),read());
	for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
}

vector<pr> Vc;
int dep[maxn],low[maxn];
bool findcir(int x,int fa)
{
	int i;
	
	for(i=0;i<(int)e[x].size();i++) if(e[x][i]!=fa)
	{
		if(!~dep[e[x][i]])
		{
			low[e[x][i]]=dep[e[x][i]]=dep[x]+1;
			if(findcir(e[x][i],x)) Vc.pbk(pr(x,e[x][i]));
			low[x]=min(low[x],low[e[x][i]]);
		}
		else if(dep[e[x][i]]<dep[x])
		{
			low[x]=min(low[x],dep[e[x][i]]);
			Vc.pbk(pr(x,e[x][i]));
		}
	}
	
	return low[x]!=dep[x];
}

vector<int> ans,fans;
int fobx,foby;

void dfs(int x,int fa)
{
	int i;
	
	ans.pbk(x);
	for(i=0;i<(int)e[x].size();i++) 
	 if(e[x][i]!=fa && !((e[x][i]==fobx&&x==foby)||(e[x][i]==foby&&x==fobx)))
		dfs(e[x][i],x);
}

void solve()
{
	int i;
	if(n==m)
	{
		for(i=0;i<(int)Vc.size();i++) 
		{
			fobx=Vc[i].fir;foby=Vc[i].sec;
			//cerr<<fobx<<' '<<foby<<endl;
			dfs(1,0);
			if(!i || ans<fans) fans.swap(ans);
			ans.clear();
		}
	}
	else 
	{
		fobx=foby=-1;
		dfs(1,0);
		fans=ans;
	}
}

void output()
{
	for(int i=0;i<n;i++) printf("%d ",fans[i]);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	input();
	memset(dep,-1,sizeof(dep));dep[1]=low[1]=0;
	findcir(1,0);
	solve();
	output();
	
	return 0;
}
