#include<bits/stdc++.h>
using namespace std;

const int inf=2e9;
int n,m,len=0;
long long w[100010];
struct edge
{
	int x,y,next;
}e[200010];
int first[100010];
bool build[100010];
char type[5];
long long f[100010][2];
int a,b,c,d;

inline long long read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if (c=='-') f=0;c=getchar();}
	while (c>='0' && c<='9') x=x*10+(c^48),c=getchar();
	return f?x:-x;
}

void ins(int x,int y)
{
	e[++len].x=x;e[len].y=y;
	e[len].next=first[x];first[x]=len;
}

long long min(long long x,long long y) {return x<y?x:y;}

void dfs(int x,int fa) //0: ²»È¡  1£ºÈ¡ 
{
	long long temp1=0,tempsum=0;bool son=false;
	for (int i=first[x];i;i=e[i].next)
	{
		int y=e[i].y;if (y==fa) continue;
		dfs(y,x);son=true;
		if (f[y][0]!=inf) tempsum+=f[y][0];
			temp1+=min(f[y][0],f[y][1]);
	}
	f[x][0]=0;f[x][1]=w[x];
	f[x][1]+=temp1;
	if (!son) f[x][0]=0;
	if (tempsum!=temp1 && son) f[x][0]+=temp1;
	if (tempsum==temp1 && son)
	{
		int tempmin=inf;
		for (int i=first[x];i;i=e[i].next)
		{
			int	y=e[i].y;if (y==fa) continue;
			if (f[y][1]!=inf && f[y][0]!=inf)
				tempmin=min(tempmin,tempsum-f[y][0]+f[y][1]);
		}
		f[x][0]=(!son)?0:f[x][0]+tempmin;
	}
	if (x==a) f[x][c^1]=inf;
	if (x==b) f[x][d^1]=inf;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();scanf("%s",type);
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1;i<n;i++)
	{
		int x,y;
		x=read(),y=read();
		ins(x,y);ins(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		a=read(),c=read(),b=read(),d=read();dfs(1,0);
			 if (f[1][0]>=1e6 && f[1][1]<1e6) printf("%lld\n",f[1][1]);
		else if (f[1][0]<1e6 && f[1][1]>=1e6) printf("%lld\n",f[1][0]);
		else if (f[1][0]>=1e6 && f[1][1]>=1e6) printf("-1\n");
		else printf("%lld\n",min(f[1][0],f[1][1]));
	}
	return 0;
}
