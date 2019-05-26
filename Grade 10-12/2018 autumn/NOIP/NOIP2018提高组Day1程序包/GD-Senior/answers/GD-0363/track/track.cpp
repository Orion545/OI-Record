#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
const int N=50005;
int n,m;
struct qq
{
	int x,y,z,last;
}e[N*2];int num,last[N];
int dep[N];
int sum=0;
void init (int x,int y,int z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
void dfs (int x,int fa)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dep[y]=dep[x]+e[u].z;
		dfs(y,x);
	}
}
int lim,tot;
int mx[N];//我可以提供的最深深度
multiset<int> s[N];
multiset<int> :: iterator it;
void dfs1 (int x,int fa)
{
	s[x].clear();mx[x]=dep[x];
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dfs1(y,x);
		if (mx[y]-dep[x]>=lim)	tot++;
		else s[x].insert(mx[y]-dep[x]);
	}
	while (!s[x].empty())
	{
		int xx=(*s[x].begin());s[x].erase(s[x].begin());
		it=s[x].lower_bound(lim-xx);
		if (it==s[x].end()) 
		{
			mx[x]=max(mx[x],xx+dep[x]);
			continue;
		}
		else	{tot++;s[x].erase(it);}
	}
	//printf("%d %d %d\n",x,tot,mx[x]);
}
bool check (int x)
{
	lim=x;tot=0;
	dfs1(1,0);
	return tot>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<n;u++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		sum=sum+z;
		init(x,y,z);init(y,x,z);
	}
	//printf("YES\n");
	dep[1]=0;dfs(1,0);
	//printf("NO\n");
	int l=1,r=sum,ans=-1;
	//printf("%d %d\n",l,r);
	while (l<=r)
	{
		int mid=(l+r)>>1;
		//printf("%d %d %d\n",l,r,mid);
		if (check(mid))	{l=mid+1;ans=mid;}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
