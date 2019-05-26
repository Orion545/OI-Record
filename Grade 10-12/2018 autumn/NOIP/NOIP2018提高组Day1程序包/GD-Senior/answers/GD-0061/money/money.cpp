#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
#include<set>

using namespace std;

inline int read()
{
	int ch=getchar(),f=1;
	int ans=0;
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		ans=ans*10+(ch^'0');
	return f?ans:-ans;
}

const int maxn=25005;
struct edge{
	int to,w;
};
vector<edge> e[maxn];

inline void add(int u,int v,int w)
{
	e[u].push_back((edge){v,w});
}
const int inf=0x3f3f3f3f;
long long dis[maxn];
int a[105];
int n;
int mna=inf;
typedef pair<long long,int> pii;
priority_queue<pii> q;

void dij()
{
	memset(dis,0x3f,sizeof dis);
	dis[0]=0;
	q.push(pii(0,0));
	while(!q.empty())
	{
		pii t=q.top();q.pop();
		int u=t.second;
		if(dis[u]!=t.first)
			continue;
		//for(int i=0;i<e[u].size();++i)
		for(int i=1;i<=n;++i)
		{
			int v=(u+a[i])%mna;
			long long w=(u+a[i])/mna;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(pii(dis[v],v));
			}
		}
	}
}

bool cmp(int a,int b)
{
	return a/mna<b/mna;
}
bool flag[105];
int vis[maxn];
void solve()
{
	mna=inf;
	n=read();
	//for(int i=1;i<=n;++i)
	//	e[i].clear();
	for(int i=1;i<=n;++i)
		a[i]=read(),mna=min(mna,a[i]);
	//for(int i=1;i<=n;++i)
	//{
	//	s.insert(pii(a[i]%mna,a[i]/mna));
	//	s.insert(pii(a[i]%mna-mna,a[i]/mna-1));
	//}
	sort(a+1,a+n+1,cmp);
	n=unique(a+1,a+n+1)-a-1;
	//cout<<n<<'q'<<endl;
	//for(int i=1;i<=n;++i)
	//{
		//for(int j=0;j<mna)
		//add(0,a[i]%mna,a[i]/mna);
	//}	
	dij();
	int ans=1;
	for(int i=0;i<mna;++i)
	{
		//if(dis[i]!=inf)
		//	++ans;
		//printf("%d,%d\n",i,dis[i]);
	}
	memset(vis,0,sizeof vis);
	memset(flag,0,sizeof flag);
	vis[0]=1;
	for(int i=1;i<=n;++i)
	{
		//bool flag=1;
		for(int j=0;j<mna;++j)
		{
			if(vis[j]&&!vis[(j+a[i])%mna]&&(dis[j]+ (j+a[i])/mna ==dis[(j+a[i])%mna] ) )
				vis[(j+a[i])%mna]=1,flag[i]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(flag[i])ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		solve();
	}
	return 0;
}

/*


1
5
1 1 1 2 3

1
20
25 36 18 32 28 34 33 30 40 17 19 11 20 37 39 38 29 14 35 24


*/

