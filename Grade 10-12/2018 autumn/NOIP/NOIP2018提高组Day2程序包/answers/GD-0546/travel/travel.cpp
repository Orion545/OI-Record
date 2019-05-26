#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
const int N=5010;
typedef pair<int,int> pii;
namespace graph
{
	int h[N];
	int v[2*N];
	int w[2*N];
	int t[2*N];
	int cnt;
	void add(int x,int y,int z)
	{
		cnt++;
		v[cnt]=y;
		w[cnt]=z;
		t[cnt]=h[x];
		h[x]=cnt;
	}
}
vector<pii> g[N];
int n,m;
int ans[N];
int t;
int s[N];
int ban;
int vis[N];
//void dfs(int x)
//{
//	vis[x]=1;
//	s[++t]=x;
//	for(int i=graph::h[x];i;i=graph::t[i])
//		if(graph::w[i]!=ban&&!vis[graph::v[i]])
//			dfs(graph::v[i]);
//}
int s1[N],s2[N];
int top;
void dfs(int x)
{
	top=1;
	vis[x]=1;
	s[++t]=x;
	s1[top]=x;
	s2[top]=graph::h[x];
	while(top)
	{
		while(s2[top]&&(graph::w[s2[top]]==ban||vis[graph::v[s2[top]]]))
			s2[top]=graph::t[s2[top]];
		if(s2[top])
		{
			s1[top+1]=graph::v[s2[top]];
			s2[top+1]=graph::h[s1[top+1]];
			s2[top]=graph::t[s2[top]];
			top++;
			s[++t]=s1[top];
			vis[s1[top]]=1;
		}
		else
			top--;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(pii(y,i));
		g[y].push_back(pii(x,i));
	}
	for(int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end(),greater<pii>());
	for(int i=1;i<=n;i++)
	{
		int sz=g[i].size();
		for(int j=0;j<sz;j++)
			graph::add(i,g[i][j].first,g[i][j].second);
	}
	if(m==n-1)
	{
		ban=0;
		dfs(1);
		for(int i=1;i<=n;i++)
			printf("%d ",s[i]);
	}
	else
	{
		for(int i=1;i<=n;i++)
			ans[i]=0x7fffffff;
		for(int i=1;i<=m;i++)
		{
			ban=i;
			t=0;
			for(int i=1;i<=n;i++)
				vis[i]=0;
			dfs(1);
			int flag=0;
			if(t==n)
				for(int j=1;j<=n;j++)
					if(s[j]<ans[j])
					{
						flag=1;
						break;
					}
					else if(s[j]>ans[j])
						break;
			if(flag)
				for(int j=1;j<=n;j++)
					ans[j]=s[j];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}
