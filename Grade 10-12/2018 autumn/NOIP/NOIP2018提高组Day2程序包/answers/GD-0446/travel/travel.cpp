#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5001;
int n,m,u,v,vis[N],er[N][N],cnt=0,num[N],pre[N],st,ed,mc[N],vv[N];
bool tag=0;
/*struct emm{
	int from,to;
}qwq[N];*/

int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}

/*void add(int from,int to)
{
	qwq[++cnt].from=h[from];
	qwq[cnt].to=to;
	h[from]=cnt;
}*/

/*void tarjan(int x)
{
	dfn[x]=low[x]=++timer;
	st[++tp]=x;ins[x]=1;
	for(int i=1;i<=er[x][0];i++)
	{
		int y=er[x][i];
		if(!dfn[y]){tarjan(y);low[x]=min(low[x],low[y]);}
		else if(ins[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		gp++;int y;
		do
		{
			y=st[tp--];ins[y]=0;bel[y]=gp;
		}
	}
}

void pre()
{
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
}*/

bool cmp(int a,int b){return mc[a]<mc[b];}

void del(int a,int b)
{
	int i,j;
	for(i=1;i<=er[a][0];i++)if(er[a][i]==b)break;
	for(;i<er[a][0];i++)er[a][i]=er[a][i+1];er[a][0]--;
	for(j=1;j<=er[b][0];j++)if(er[b][j]==a)break;
	for(;j<er[b][0];j++)er[b][j]=er[b][j+1];er[b][0]--;
}
void predfs(int x,int fa)
{
	/*if(x!=1)mc[fa]=min(mc[fa],x);*/vv[x]=1;pre[x]=fa;
	for(int i=1;i<=er[x][0];i++)
	{
		int y=er[x][i];
		if(!vv[y]&&!pre[y]){predfs(y,x);mc[x]=min(mc[x],min(y,mc[y]));}
		/*else if(pre[er[x][i]]&&!tag)
		{
			int t=x;st=N;ed=0;
			while(t!=er[x][i]&&t!=0)
			{
				if(t<=st&&pre[t]>=ed){st=t;ed=pre[t];}
				else if(pre[t]<=st&&t>=ed){st=pre[t];ed=t;}
				t=pre[t];
			}
			del(st,ed);tag=1;*
		}*/
	}
}

void dfs(int x,int fa)
{
	num[x]=++cnt;vis[x]=1;//pre[x]=fa;
	for(int i=1;i<=er[x][0];i++)
	{
		if(er[x][i]==fa)continue;
		if(!vis[er[x][i]])dfs(er[x][i],x);
		else if(pre[er[x][i]]&&!tag)
		{
			int t=x;st=N;ed=0;
			while(t!=er[x][i]&&t!=0)
			{
				if(t<=st&&pre[t]>=ed){st=t;ed=pre[t];}
				else if(pre[t]<=st&&t>=ed){st=pre[t];ed=t;}
				t=pre[t];
			}
			del(st,ed);tag=1;
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)mc[i]=N;
	for(int i=1;i<=m;i++)
	{
		u=read();v=read();
		er[u][++er[u][0]]=v;er[v][++er[v][0]]=u;
	}
	predfs(1,0);
	for(int i=1;i<=n;i++)sort(er[i]+1,er[i]+1+er[i][0],cmp);
	dfs(1,0); 
	if(tag)
	{
		memset(num,0,sizeof(num));
		memset(pre,0,sizeof(pre));
		memset(vis,0,sizeof(vis));
		cnt=0;
		dfs(1,0);
	}
	for(int i=1;i<=n;i++)printf("%d ",num[i]);
	return 0;
}
