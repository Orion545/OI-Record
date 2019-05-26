#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define mmst(a, b) memset(a,b,sizeof(a))
#define mmcp(a, b) memcpy(a,b,sizeof(a))

typedef long long LL;

const int N=100100;

int n,m,len,sum;
int to[N],val[N],nex[N],head[N],cnt;
int fa[N];
int f[N],g[N],a[N],st[N];

void add(int u,int v,int w)
{
	to[++cnt]=v;
	nex[cnt]=head[u];
	val[cnt]=w;
	head[u]=cnt;
}

void dfs(int x)
{
	int num=0,tp=0;
	f[x]=g[x]=0;
	
	for(int h=head[x];h;h=nex[h])
	if(to[h]!=fa[x])
	{
		fa[to[h]]=x; 
		dfs(to[h]);
	}
	
	for(int h=head[x];h;h=nex[h])
	if(to[h]!=fa[x])
	{
		f[x]+=f[to[h]];
		if(g[to[h]]+val[h]>=len)
		f[x]++;
		else
		a[++num]=g[to[h]]+val[h];
	}
	
	if(!num)
	return ;
	
	sort(a+1,a+num+1);
	int tt=num;
	for(int i=1;i<=num;i++)
	{
		while(a[i]+a[tt]>=len&&i<tt)
		{
			st[++tp]=tt;
			tt--;
		}
		
		if(tp)
		{
			tp--;
			f[x]++;
		}
		else
		g[x]=max(g[x],a[i]);
		
		if(tt==i)
		break;
	}
	f[x]+=tp/2;
	if(tp%2==1)
	g[x]=max(g[x],a[st[1]]);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		sum+=w;
	}
	
	int l=1,r=sum/m+1;
	while(l+1<r)
	{
		len=(l+r)/2;
		
		dfs(1);
		if(f[1]>=m)
		l=len;
		else
		r=len;
	}
	
	cout<<l<<endl;

	return 0;
}

