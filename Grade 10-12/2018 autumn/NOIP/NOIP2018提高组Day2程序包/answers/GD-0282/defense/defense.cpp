#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
using namespace std;

#define inf 0x3f3f3f3f3f3f3f3f
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define maxn 100050
#define maxm 100050
typedef long long ll;

ll n,m,head[maxn],total,p[maxn];
ll f[maxn][2],fa[maxn][20],depth[maxn],temp[maxn][2];
bool visit[maxn];
string type;
struct Edge
{
	ll start,end,next;
}edge[maxm<<1];

inline void insert(ll start,ll end)
{
	edge[++total].start = start;
	edge[total].end = end;
	edge[total].next = head[start];
	head[start] = total;
}

inline void input()
{
	memset(head,0,sizeof(head));
	total=1;
	scanf("%lld%lld",&n,&m);
	cin>>type;
	ll i,u,v;
	for(i=1;i<=n;++i)
		scanf("%lld",p+i);
	for(i=1;i<n;++i)
	{
		scanf("%lld%lld",&u,&v);
		insert(u,v);
		insert(v,u);
	}
}

void dfs(ll now)
{
	visit[now] = true;
	f[now][1] = p[now];
	f[now][0] = 0;
	ll i,v;
	for(i=head[now],v=edge[i].end;i;i=edge[i].next,v=edge[i].end)
		if(!visit[v])
		{
			fa[v][0] = now;
			depth[v] = depth[now]+1;
			dfs(v);
			f[now][1] += min(f[v][0],f[v][1]);
			f[now][0] += f[v][1];
		}
}

inline void calc()
{
	ll j,i;
	for(j=1;j<=19;++j)
		for(i=1;i<=n;++i)
			fa[i][j] = fa[fa[i][j-1]][j-1];
}

inline ll lca(ll a,ll b)
{
	ll i;
	for(i=19;i>=0;--i)
		if(depth[fa[a][i]] >= depth[b])
			a = fa[a][i];
	if(a == b)
		return b;
	for(i=19;i>=0;--i)
		if(fa[a][i] != fa[b][i])
			a = fa[a][i],b=fa[b][i];
	return fa[a][0];
}

inline void pushup(ll now,ll end,ll type)
{
//	cout<<type<<endl;
	if(now != end)
	{
		ll father = fa[now][0];
//		cout<<now<<' '<<father<<',';
		if(type == 1)//当前节点必须放
		{
			if(temp[father][0] == -1)
				temp[father][0] = f[father][0];
			if(temp[father][1] == -1)
				temp[father][1] = f[father][1];
			temp[father][1] -= min(f[now][0],f[now][1]);
			temp[father][1] += f[now][1];
			now = father;
			father = fa[now][0];
		}
		else if(type == 0)//
		{
			temp[father][0] = inf;
			if(temp[father][1] == -1)
				temp[father][1] = f[father][1];
			temp[father][1] -= min(f[now][0],f[now][1]);
			temp[father][1] += f[now][0];
			now = father;
			father = fa[now][0];
		}
		while(now != end)
		{
//			cout<<now<<' '<<father<<',';
			if(temp[father][0] == -1)
				temp[father][0] = f[father][0];
			if(temp[father][1] == -1)
				temp[father][1] = f[father][1];
			temp[father][1] -= min(f[now][0],f[now][1]);
			temp[father][1] += min(temp[now][0],temp[now][1]);
			temp[father][0] -= f[now][1];
			temp[father][0] += temp[now][1];
			now = father;
			father = fa[now][0];
		}
//		cout<<endl;
	}
}

inline void change(ll a,ll x,ll b,ll y)
{
	memset(temp,-1,sizeof(temp));
	if(depth[a] < depth[b])
		swap(a,b),swap(x,y);
//	cout<<a<<' '<<b<<' ';
	ll u = lca(a,b);
//	cout<<u<<endl;
	if(u == b)
	{
		pushup(a,b,x);
		pushup(b,1,y);
	}
	else
	{
		pushup(a,u,x);
		pushup(b,u,y);
		pushup(u,1,-1);
	}
}

inline void work()
{
	memset(visit,false,sizeof(visit));
	fa[1][0] = 0;
	depth[1] = 1;
	dfs(1);
	calc();
	ll i,a,b,x,y;
//	cout<<f[1][0]<<' '<<f[1][1];
	for(i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
		if(type[1] == '2' && !x && !y)
		{
			printf("-1\n");
			continue;
		}
		if((fa[a][0] == b || fa[b][0] == a) && !x && !y)
		{
			printf("-1\n");
			continue;
		}
		change(a,x,b,y);
		if((a == 1 || b==1) && x == 1)
			printf("%lld\n",temp[1][1]);
		else if((a==1 || b==1) && x == 0)
			printf("%lld\n",temp[1][0]);
		else
			printf("%lld\n",min(temp[1][0],temp[1][1]));
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	input();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
