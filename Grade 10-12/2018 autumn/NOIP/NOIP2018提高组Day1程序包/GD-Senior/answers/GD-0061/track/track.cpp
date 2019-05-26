#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
#include<set>

using namespace std;

inline long long read()
{
	int ch=getchar(),f=1;
	long long ans=0;
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		ans=ans*10+(ch^'0');
	return f?ans:-ans;
}

int n,m;
const int maxn=50005;
struct edge{
	int to,w;
};
vector<edge> e[maxn];

inline void add(int u,int v,int w)
{
	e[u].push_back((edge){v,w});
}
const int inf=0x3f3f3f3f;
namespace t1{
	int dis[maxn];
	bool vis[maxn];
	queue<int> q;
	void dfs(int u,int fa,int dep)
	{
		//if(vis[u])return dis[u];
		dis[u]=dep,vis[u]=1;
		for(int i=0;i<e[u].size();++i)
		{
			int v=e[u][i].to;
			int w=e[u][i].w;
			if(v==fa)continue;
			dfs(v,u,dep+w);
		}
		//return dis[u];
	}
	/*
	void spfa(int s)
	{
		memset(dis,-inf,sizeof dis);
		dis[s]=0;
		q.push(s);
		inq[s]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=0;i<e[u].size();++i)
			{
				int v=e[u][i].to;
				int w=e[u][i].w;
				if(dis[v]<dis[u]+w)
				{
					dis[v]=dis[u]+w;
					if(!inq[v])
					{
						q.push(v);
					}
				}
			}
		}
	}
	*/
	void solve()
	{
		int mx=0,mxi;
		dfs(1,0,0);
		for(int i=1;i<=n;++i)
			if(dis[i]>mx)
			{
				mx=dis[i];
				mxi=i;
			}
		dfs(mxi,-1,0);
		mx=0;
		for(int i=1;i<=n;++i)
			if(dis[i]>mx)
			{
				mx=dis[i];
				mxi=i;
			}
		printf("%d\n",mx);
	}
};

namespace t2{
	int check(int k)
	{
		int now=0;
		int cnt=0;
		for(int i=2;i<=n;++i)
		{
			int w=e[i][0].w;
			if(now+w>=k)
			{
				now=0;
				cnt++;
			}
			else
			{
				now+=w;
			}
		}
		return cnt;
	}
	void solve()
	{
		int l=0,r=1e9;
		//r=12;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(mid)>=m)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		printf("%d\n",l);
	}
};

namespace t3{
	vector<int> w;
	bool b[maxn];
	int check(int k)
	{
		int cnt=0;
		memset(b,0,sizeof b);
		for(int i=0;i<w.size();++i)
		{
			if(b[i])continue;
			if(w[i]>=k)
			{
				b[i]=1;
				++cnt;
				continue;
			}
			//int t33=w[i];
			int pos=upper_bound(w.begin(),w.end(),k-w[i]-1)-w.begin();
			if(pos==i)pos++;
			//int t32=w[pos];
			if(!b[pos]&&pos<w.size())
			{
				b[i]=1;
				b[pos]=1;
				cnt++;
			}
		}
		return cnt;
	}
	void solve()
	{
		for(int i=0;i<e[1].size();++i)
		{
			w.push_back(e[1][i].w);
		}
		sort(w.begin(),w.end());
		int l=0,r=1e9;
		r=12;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(mid)>=m)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		printf("%d\n",l);
	}
};
int check(int k)
{
	return 1;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	bool t2flag=1;
	bool t3flag=1;
	for(int i=2;i<=n;++i)
	{
		int u=read(),v=read(),w=read();
		if(v!=u+1)t2flag=0;
		if(u!=1)t3flag=0;
		add(u,v,w);
		add(v,u,w);		
	}
	if(m==1)
	{
		t1::solve();
		return 0;
	}
	if(t2flag)
	{
		t2::solve();
		return 0;
	}
	if(t3flag)
	{
		t3::solve();
		return 0;
	}
	int l=0,r=1e9;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d\n",l);
	return 0;
	printf("hehehehehehehe");
	printf("hehehehehehehe");
	printf("hehehehehehehe");
	printf("hehehehehehehe");
}

/*


9 1
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4


5 3
1 2 8
2 3 3
3 4 5
4 5 10


5 3
1 2 8
1 3 3
1 4 5
1 5 10


5 3
1 2 8
1 3 3
1 4 5
1 5 10


*/
