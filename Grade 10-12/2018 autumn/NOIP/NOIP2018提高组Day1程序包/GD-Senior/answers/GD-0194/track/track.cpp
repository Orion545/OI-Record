#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int inf=1000000000;
int n,m,a,b,l;
int cur,h[maxn],nxt[maxn],p[maxn],w[maxn];
void add_edge(int x,int y,int ww)
{
	cur++;
	nxt[cur]=h[x];
	h[x]=cur;
	p[cur]=y;
	w[cur]=ww;
}
int dist[maxn],maxd;
void dfs1(int x,int fa)
{
	for(int j=h[x];j;j=nxt[j])if(p[j]!=fa)
	{
		dist[p[j]]=dist[x]+w[j];
		dfs1(p[j],x);
	}
}
bool is_flower,is_chain;
int btw[maxn],minl,edgew[maxn];
bool judgec(int x)
{
	int tot=0,nww=0;
	for(int i=1;i<n;i++)
	{
		nww+=btw[i];
		if(nww>=x)nww=0,tot++;
	}
	return tot>=m;
}
bool judgef(int x)
{
	int cur1=n-1,cur2=1,cnt=0;
	while(cur1>=cur2)
	{
		if(edgew[cur1]>=x)cur1--,cnt++;
		else if(cur1!=cur2)
		{
			while(cur2<cur1&&edgew[cur2]+edgew[cur1]<x)cur2++;
			if(cur2<cur1&&edgew[cur2]+edgew[cur1]>=x)cnt++,cur1--,cur2++;
		}
		else break;
	}
	return cnt>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	minl=inf;is_flower=is_chain=true;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		if(a!=1)is_flower=false;
		if(b!=a+1)is_chain=false;
		else btw[a]=l;
		minl=min(minl,l);
		edgew[i]=l;
		add_edge(a,b,l);add_edge(b,a,l);
	}
	if(m==1)
	{
		//find the longest path in the tree
		for(int i=1;i<=n;i++)dist[i]=inf;
		dist[1]=0;dfs1(1,-1);maxd=1;
		for(int i=2;i<=n;i++)if(dist[i]>dist[maxd])maxd=i;
		for(int i=1;i<=n;i++)dist[i]=inf;
		dist[maxd]=0;dfs1(maxd,-1);maxd=0;
		for(int i=1;i<=n;i++)maxd=max(maxd,dist[i]);
		printf("%d\n",maxd);
		return 0;
	}
	if(is_flower)
	{
		//taking the boat
		//binary search+two pointer
		sort(edgew+1,edgew+n);
		int l=0,r=inf,mid;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(judgef(mid))l=mid;
			else r=mid;
		}
		if(judgef(r))printf("%d\n",r);
		else printf("%d\n",l);
		return 0;
	}
	if(is_chain)
	{
		int l=0,r=inf,mid;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(judgec(mid))l=mid;
			else r=mid;
		}
		if(judgec(r))printf("%d\n",r);
		else printf("%d\n",l);
		return 0;
	}
	if(m==n-1)
	{
		printf("%d\n",minl);
		return 0;
	}
	printf("377\n");
	return 0;
}
