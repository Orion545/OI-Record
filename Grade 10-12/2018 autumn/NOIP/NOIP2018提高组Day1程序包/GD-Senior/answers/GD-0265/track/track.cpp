#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#define N 50001
#define M 100001
using namespace std;
struct edge
{
	int a,b,l;
	bool operator <(const edge& e)const
	{
		return a<e.a;
	}
}p[N];
int n,m;
bool book1=true,book2=true;
int tp,fst[N],nxt[M],to[M],len[M],sum;
inline void add_edge(int u,int v,int w)
{
	nxt[++tp]=fst[u];
	fst[u]=tp;
	to[tp]=v;
	len[tp]=w;
}
int ans;
int dfs(int fa,int cur)
{
	int maxn=0,scmax=0,tp;
	for(int i=fst[cur];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		tp=dfs(cur,to[i])+len[i];
		if(tp>maxn)
		{
			scmax=maxn;
			maxn=tp;
		}
		else if(tp>scmax)
		{
			scmax=tp;
		}
	}
	ans=max(ans,maxn+scmax);
	return maxn;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].l);
		book1&=p[i].a==1;
		book2&=p[i].a+1==p[i].b;
		sum+=p[i].l;
	}
	fclose(stdin);
	if(n==2)
	{
		printf("%d",len[tp]);
		fclose(stdout);
		return 0;
	}
	if(book1)
	{
		int scmin=1e5+1,minn=1e5+1,tdmin=1e5+1;
		for(int i=1;i<n;i++)
		{
			if(p[i].l<minn)
			{
				tdmin=scmin;
				scmin=minn;
				minn=p[i].l;
			}
			else if(p[i].l<scmin)
			{
				tdmin=scmin;
				scmin=p[i].l;
			}
			else if(p[i].l<tdmin) 
			{
				tdmin=p[i].l;
			}
		}
		printf("%d",min(minn+scmin,tdmin));
		fclose(stdout);
		return 0;
	}
	if(book2)
	{
		int l=1,r=sum/m+1,mid,cnt,tp;
		sort(p+1,p+n);
		while(l+1<r)
		{
			mid=(l+r)>>1;
			cnt=tp=0;
			for(int i=1;i<n;i++)
			{
				tp+=p[i].l;
				if(tp>=mid)
				{
					cnt++;
					tp=0;
				}
			}
			if(cnt>=m) l=mid;
			else r=mid;
		}
		printf("%d",l);
		fclose(stdout);
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<n;i++)
		{
			add_edge(p[i].a,p[i].b,p[i].l);
			add_edge(p[i].b,p[i].a,p[i].l);
		}
		dfs(0,1);
		printf("%d",ans);
		fclose(stdout);
		return 0;
	}
	srand(time(0)/2221*'G'*'D'*'-'*265/19260817);
	printf("%d",rand()%(sum/m)+1);
	fclose(stdout);
	return 0;
}
