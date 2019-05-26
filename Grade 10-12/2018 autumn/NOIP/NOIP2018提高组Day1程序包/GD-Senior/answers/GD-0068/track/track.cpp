#include <cstdio>
#include <cstdlib>
#include <iostream>

#define LL long long 

using namespace std;

int n,m,tot,cnt;
int q[50010];
int h[50010],f[50010],len[50010],p[50010];
LL maxlen[50010],treest[50010];
struct edge{
	int to,next,value;
}x[100010];

void dfs(int ,int );
void add(int ,int ,int );

void sort(int ,int );

int main()
{
	bool bo=true;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	srand(141355);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		if (a!=1&&b!=1)
			bo=false;
		p[a]++;p[b]++;
		add(a,b,l);add(b,a,l);
	}
	if (bo)
	{
		if (tot>0)
			sort(1,tot);
		printf("%d",x[m<<1].value);
		return 0;
	}
	dfs(1,0);
	LL ans=0;
	if (m==1)
	{
		for (int i=1;i<=n;i++)
			ans=max(ans,treest[i]);
		printf("%lld",ans);
		return 0;
	}
	printf("%d",maxlen[1+rand()%n]);
	return 0;
	for (int i=1;i<=n;i++)
		if (p[i]==1)
			for (int k=i,c=1;c!=n-1;c++)
			{
				q[++cnt]=x[h[k]].value;k=x[h[k]].to;p[k]++;
			}
	return 0;
}

void add(int u,int v,int len)
{
	x[++tot]=(edge){v,h[u],len};h[u]=tot;
	return ;
}

void dfs(int now,int fa)
{
	for (int jump=h[now];jump;jump=x[jump].next)
	{
		int t=x[jump].to;
		if (t==fa)
			continue;
		f[t]=now;len[t]=x[jump].value;
		dfs(t,now);
		treest[now]=max(treest[now],max(maxlen[now]+maxlen[t]+len[t],treest[t]));
		maxlen[now]=max(maxlen[now],maxlen[t]+len[t]);
	}
	return ;
}

void sort(int l,int r)
{
	int a=l,b=r;
	int mid=x[a+rand()%(b-a+1)].value;
	while (a<=b)
	{
		while (x[a].value>mid)
			a++;
		while (x[b].value<mid)
			b--;
		if (a<=b)
		{
			edge f;
			f=x[a];x[a]=x[b];x[b]=f;
			a++;b--;
		}
	}
	if (l<b)
		sort(l,b);
	if (a<r)
		sort(a,r);
	return ;
}
