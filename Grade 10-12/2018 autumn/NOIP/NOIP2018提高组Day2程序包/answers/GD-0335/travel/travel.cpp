#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 5010
#define INF 2147483647

inline int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-48;s=getchar();}
	return f*x;
}

struct ins
{
	int x,y;
}in[MAXN<<1];

struct node
{
	int to,next;
}edge[MAXN<<1];

bool cmp(const ins &a,const ins &b){return (a.x>b.x)||(a.x==b.x&&a.y>b.y);}


int n,m,ans[MAXN],head[MAXN],tot=0,anss[MAXN],pos=0,tott=0;
bool don=false;
bool visit[MAXN];

void adds(int from,int to)
{
	tot++;
	edge[tot].next=head[from];
	edge[tot].to=to;
	head[from]=tot;
}

bool check()
{
	for(int i=1;i<=n;i++)if(anss[i]<ans[i])return true;
	return false;
}

void dfs1(int a,int last)
{
	if(don)return; 
	visit[a]=true;
	for(int i=head[a];i;i=edge[i].next)
	{
		if(edge[i].to==a||edge[i].to==last)continue;
		if(edge[i].to>last)return ;
		if(!visit[edge[i].to]&&!don)
		{
			ans[++tott]=edge[i].to;
			if(tott==n){don=true;return;}
			if(edge[i].next!=0)dfs1(edge[i].to,edge[edge[i].next].to);
			else dfs1(edge[i].to,last);
			if(don)return;
		}
	}
}

void dfs(int a)
{
	if(don)return;
	if(pos==n&&check())
	{
		for(int i=1;i<=n;i++)ans[i]=anss[i];don=true;return ; 
	}
	for(int i=head[a];i;i=edge[i].next)
	{
		if(edge[i].to==a)continue;
		if(!visit[edge[i].to])
		{
			anss[++pos]=edge[i].to;
			visit[edge[i].to]=true;
			dfs(edge[i].to);
			if(don)return;
		}
	}
}


int main()
{
	int temp;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i)in[i].x=read(),in[i].y=read(),in[i+m].x=in[i].y,in[i+m].y=in[i].x;
	sort(in+1,in+m+m+1,cmp);
	for(int i=1;i<=m*2;++i)adds(in[i].x,in[i].y);
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			don=false;tott=0;
			ans[++tott]=i;
			memset(visit,false,sizeof(visit));
			dfs1(i,INF);
			if(don)break;
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	}	
	else if(m==n-1)
	{
		memset(ans,0x7f,sizeof(ans));
		memset(anss,0x7f,sizeof(anss));
		for(int i=1;i<=n;i++)
		{
			pos=0;
			memset(visit,false,sizeof(visit));
			don=false;
			visit[i]=true;
			anss[++pos]=i;
			dfs(i);
			if(don)break;
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	}
	return 0;
}
