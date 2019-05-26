#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010

int n,m,cnt,bound,edgecnt,head[MAXN],nxt[MAXN],to[MAXN],we[MAXN],deg[MAXN];
bool solved;

void addedge(int u,int v,int w)
{
	nxt[++edgecnt]=head[u];
	to[edgecnt]=v;
	we[edgecnt]=w;
	head[u]=edgecnt;
}


int orgdfs(int u,int fa)
{
	int maxn=0;
	vector<int> val;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i],w=we[i];
		if(v==fa)continue;
		int tmp=orgdfs(v,u);
		if(tmp+w>=bound)++cnt;
		else val.push_back(tmp+w);
	}
	sort(val.begin(),val.end());
	for(int i=0;i<val.size();++i)
	{
		for(int j=i+1;j<val.size();++j)
		{
			if(val[i]+val[j]>=bound)
			{
				++cnt;
				val[i]=val[j]=-1;
				break;
			}
		}
	}
	for(int i=0;i<val.size();++i)maxn=max(maxn,val[i]);
	return maxn;
}


int dfs(int u,int fa)
{
	int maxn=0;
	map<int,int> val;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i],w=we[i];
		if(v==fa)continue;
		int tmp=dfs(v,u);
		if(tmp+w>=bound)++cnt;
		else ++val[tmp+w];
	}
	for(map<int,int>::iterator it=val.begin();it!=val.end();)
	{
		map<int,int>::iterator findans=val.lower_bound(bound-it->first);
		if(findans!=val.end())
		{
			if(findans==it)
			{
				++findans;
				if(findans==val.end())
				{
					++it;
					continue;
				}
			}
			++cnt;
			map<int,int>::iterator tmp=it;
			++it;
			if(it==findans)++it;
			--(tmp->second);
			--(findans->second);
			if(!(tmp->second))val.erase(tmp);
			if(!(findans->second))val.erase(findans);
		}
		else
		{
			++it;
		}
	}
	if(val.empty())return 0;else return (--val.end())->first;
	//for(set<int>::iterator it=val.begin();it!=val.end();++it)maxn=max(maxn,*it);
	//return maxn;
}

bool check(int mid)
{
	bound=mid;
	cnt=0;
	if(solved)orgdfs(1,0);else dfs(1,0);
	return cnt>=m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	solved=true;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		++deg[u];
		++deg[v];
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=n;++i)if(deg[i]>5)solved=false;
	if(n>2000)solved=false;
	int l=1,r=500000000,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
}
