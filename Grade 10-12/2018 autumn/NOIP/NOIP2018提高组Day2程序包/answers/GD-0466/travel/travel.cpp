#include<cstdio>
#include<algorithm>
#define MAXN 5000+10

using namespace std;

struct ee
{
	int u,v;
};

inline int read()
{
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

bool u[MAXN];
int c[MAXN][MAXN];
ee e[(MAXN)>>1];
int q[MAXN],ci[MAXN],st[MAXN];
bool circ[MAXN];
bool flg=0;
int topv=0,cntv=0,topvv=0,cntvv=0;

void dfs1(int x)
{
	for(int i=1; i<=c[x][0]; i++)
		if(!u[c[x][i]])
		{
			q[++cntv]=c[x][i];
			u[c[x][i]]=1;
			dfs1(c[x][i]);
		}
}

bool cmp(ee x,ee y)
{
	return ((x.u<y.u)||(x.u==y.u&&x.v<y.v));
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	for(int i=1; i<=m; i++)
	{
		int x=read(),y=read();
		e[++topv].u=x,e[topv].v=y;
		e[++topv].u=y,e[topv].v=x;
	}
	sort(e+1,e+topv+1,cmp);
	for(int i=1; i<=topv; i++)
		c[e[i].u][++c[e[i].u][0]]=e[i].v;
	if(m==n-1)
	{ 
		u[1]=1;
		q[++cntv]=1;
		dfs1(1);
	}
	for(int i=1; i<n; i++)
		printf("%d ",q[i]);
	printf("%d\n",q[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
