#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>

const int maxn=5e4+7;

using namespace std;

int f[maxn],g[maxn],ls[maxn];
int a[maxn];
int n,m,x,y,w,cnt,sum,ans,mid;

struct edge{
	int y,w,next;
}e[maxn*2];

multiset <int> t;

void add(int x,int y,int w)
{
	e[++cnt]=(edge){y,w,ls[x]};
	ls[x]=cnt;
}

void dfs(int x,int fa)
{
	for (int i=ls[x];i>0;i=e[i].next)
	{
		int y=e[i].y;
		if (y==fa) continue;
		dfs(y,x);
	}
	for (int i=ls[x];i>0;i=e[i].next)
	{
		int y=e[i].y;
		if (y==fa) continue;
		f[x]+=f[y];
		t.insert(g[y]+e[i].w);
	}
	multiset <int> ::iterator it,op,it1;
	it=t.begin();
	while (it!=t.end())
	{
		int d=*it;
		if (d>=mid)
		{
			f[x]++;
			it1=it;
			it++;
			t.erase(it1);
		}
		else
		{
			op=lower_bound(t.begin(),t.end(),max(mid-d,d+1));
		    if (op!=t.end())
			{
				if (*op<mid)
				{
					t.erase(op);
				    f[x]++;
				    it1=it;
				    it++;
				    t.erase(it1);
				}
				else it++;
			}
			else it++;
		}
	}
	if (!t.empty()) g[x]=*(--t.end());
	t.clear();
}

bool check()
{	
	for (int i=1;i<=n;i++) f[i]=0,g[i]=0;
	dfs(1,0);
	if (f[1]>=m) return true;
	return false;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
		add(y,x,w);
		sum+=w;
	}	
	int l=1,r=sum/m;
	while (l<=r)
	{
		mid=(l+r)/2;		
		if (check()) ans=mid,l=mid+1;
			    else r=mid-1;
	}
	printf("%d",ans);
}
