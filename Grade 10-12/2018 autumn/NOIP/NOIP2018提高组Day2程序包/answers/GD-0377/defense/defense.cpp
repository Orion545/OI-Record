#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1200000
#define INF 0x7ffff
using namespace std;
struct node{
	int to;
	int nxt;
}edge[N*2];
char ch[2];
int n,m,cnt,head[N],x,y,a,b;
long long f[N][2],v[N];
bool vi[N];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

void dp(int u)
{
	vi[u]=1;	bool fl=1;		long long tmp1=0;	long long tmp2=0;
	for (int i=head[u];i;i=edge[i].nxt)
	{
		if (vi[edge[i].to]==1)	continue;fl=0;
		dp(edge[i].to);
	
		tmp1+=min(f[edge[i].to][1],f[edge[i].to][0]);
		tmp2+=f[edge[i].to][1];
	}
	f[u][1]=min(tmp1,f[u][1]);
	f[u][0]=min(tmp2,f[u][0]);
	if (fl)	f[u][1]=v[u],	f[u][0]=0;
	if (u==a)
	{
		if (x==0)	f[u][1]=INF;
		if (x==1)	f[u][0]=INF;
	}
	else if (u==b)
	{
		if (y==0)	f[u][1]=INF;
		if (y==1)	f[u][0]=INF;
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>ch;
	for (int i=1;i<=n;i++)	cin>>v[i];
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);	add(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(f,0x4f,sizeof(f));
		dp(a);
		if (f[a][0]>=INF&&f[a][1]>=INF)	cout<<-1<<endl;
		else printf("%lld\n",min(f[a][0],f[a][1]));
	}
	fclose(stdin);	fclose(stdout);
	return 0;
}
