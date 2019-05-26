#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50010
int read()
{
	int x = 0; char ch = getchar();
	for(;ch<'0'||ch>'9';ch = getchar());
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}
int ver[N<<1],ne[N<<1],val[N<<1],head[N],tot;
void add(int x,int y,int z)
{
	ver[++tot] = y; val[tot] = z; ne[tot] = head[x]; head[x] = tot;
	ver[++tot] = x; val[tot] = z; ne[tot] = head[y]; head[y] = tot;
}
int n,m;
namespace Subtask_m{
	int ans,f[N];
	void dfs(int u,int pre)
	{
		for(int i=head[u],v;i;i=ne[i])
		if((v = ver[i])!=pre)
		{
			dfs(v,u);
			ans = max(ans,f[u]+f[v]+val[i]);
			f[u] = max(f[u],f[v]+val[i]);
		}
	}
	void solve()
	{
		dfs(1,0);
		cout<<ans<<endl;
	}
}
namespace Subtask_ba{
	int a[N];
	bool check(int t)
	{
		int sum = 0,num = 0;
		for(int i=1;i<n;)
		{
			sum = 0;
			for(;sum<t&&i<n;i++) sum += a[i];
			if(sum >= t) num++;
		}
		return num>=m;
	}
	void solve()
	{
		int sum = 0,l,r;
		for(int i=1;i<n;i++)
		{
			for(int j=head[i];j;j=ne[j])
				if(ver[j]>i) a[i] = val[j];
			sum += a[i];
		}
		sum /= m;
		l = 1; r = sum+1;
		while(l+1<r)
		{
			int mid = (l+r)>>1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		cout<<l<<endl;
	}
}
struct node{
	int x,y,dis,len;
};
bool operator<(const node &A,const node &B)
{
	if(A.dis == B.dis) return A.len < B.len;
	return A.dis < B.dis;
}
namespace Subtask_n2log{
	bool iscover[N];
	int dis[N],dep[N],f[N][12],cnt;
	node q[40010];
	void dfs(int u,int pre)
	{
		f[u][0] = pre; dep[u] = dep[pre] + 1;
		for(int i=1;i<=11;i++)
			if(f[u][i-1])
				f[u][i] = f[f[u][i-1]][i-1];
		for(int i=head[u],v;i;i=ne[i])
		if((v = ver[i])!=pre)
		{
			dis[v] = dis[u] + val[i];
			dfs(v,u);
		}
	}
	int lca(int x,int y)
	{
		if(dep[x] > dep[y]) swap(x,y);
		for(int i=11;i>=0;i--)
			if(dep[f[y][i]] >= dep[x])
				y = f[y][i];
		if(x == y) return x;
		for(int i=11;i>=0;i--)
			if(f[y][i]!=f[x][i])
			{
				x = f[x][i]; y = f[y][i];
			}
		return f[x][0];
	}
	bool pd(int x,int y)
	{
		for(;x!=y;)
		{
			if(dep[x]>dep[y]) swap(x,y);
			if(iscover[y]) return false;
			y = f[y][0];
		}
		return true;
	}
	void cover(int x,int y)
	{
		for(;x!=y;)
		{
			if(dep[x]>dep[y]) swap(x,y);
			iscover[y] = true;
			y = f[y][0];
		}
	}
	bool check(int t)
	{
		int num = 0;
		memset(iscover,0,sizeof(iscover));
		for(int i=t,dis;i<=cnt&&num<m;i++)
		{
			dis = q[i].dis;
			if(pd(q[i].x,q[i].y))
			{
				num++;
				cover(q[i].x,q[i].y);
			}
		}
		return num>=m;
	}
	void solve()
	{
		dfs(1,0);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int k = lca(i,j);
				q[++cnt] = (node){i,j,dis[i]+dis[j]-(dis[k]<<1),dep[i]+dep[j]-(dep[k]<<1)};
			}
		int sum = 0;
		for(int i=1;i<=tot;i+=2) sum += val[i];
		sum /= m; sum++;
		sort(q+1,q+cnt+1);
		int l,r;
		for(l=r=1;q[r].dis<=sum&&r<=cnt;r++); r--;
		while(l+1<r)
		{
			int mid = (l+r)>>1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		cout<<q[l].dis<<endl;
	}
}
int vv[N],vvv[N>>1],ccnt;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n = read(); m = read();
	bool bo1 = true;
	for(int i=1,x,y,z;i<n;i++)
	{
		x = read(); y = read(); z = read();
		if(y!=x+1) bo1 = false;
		add(x,y,z);
	}
	if(m == 1)
	{
		Subtask_m::solve();
		return 0;
	}
	if(bo1)
	{
		Subtask_ba::solve();
		return 0;
	}
	/*if(n<=200)
	{
		Subtask_n2log::solve();
		return 0;
	}*/
	int sum = 0;
	for(int i=1;i<=tot;i+=2) vv[(i>>1)+1] += ver[i];
	sort(vv+1,vv+n);
	for(int i=1;(i<<1)<=n;i++) vvv[++ccnt] = vv[i]+vv[n-i];
	sort(vvv+1,vvv+ccnt+1);
	printf("%d\n",vvv[m]);
	return 0;
}
