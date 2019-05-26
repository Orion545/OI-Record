#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 2000+200
const int inf=1e9;
int n,m,tot;
int val[N],last[N],pre[2*N],link[2*N],f[N][2],depth[N];
int xi,yi,xt,yt;
char s[10];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void mlink(int x,int y)
{
	pre[++tot]=last[x],last[x]=tot,link[tot]=y;
}
void dfs(int x,int las)
{
	depth[x]=depth[las]+1;
	for(int i=last[x];i;i=pre[i])
	{
		if(link[i]==las)
			continue;
		dfs(link[i],x);
	}
}
void dp(int x,int las)
{
	f[x][1]=val[x];
	for(int i=last[x];i;i=pre[i])
	{
		if(link[i]==las)
			continue;
		dp(link[i],x);
		if(x==xi)
		{
			if(xt==0)
				f[x][0]+=f[link[i]][1],f[x][1]=inf;
			else
				f[x][1]+=min(f[link[i]][0],f[link[i]][1]),f[x][0]=inf;
		}
		else
		{
			if(x==yi)
			{
				if(yt==0)
					f[x][0]+=f[link[i]][1],f[x][1]=inf;
				else
					f[x][1]+=min(f[link[i]][0],f[link[i]][1]),f[x][0]=inf;
			}
			else
			{
				f[x][0]+=f[link[i]][1];
				if(xi==link[i])
					f[x][1]+=f[link[i]][xt];
				if(yi==link[i]&&xi!=yi)
					f[x][1]+=f[link[i]][yt];
				if(link[i]!=xi&&link[i]!=yi)
					f[x][1]+=min(f[link[i]][0],f[link[i]][1]);
			}
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf(" %s",s);
	for(int i=1;i<=n;i++)
		val[i]=read();
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		mlink(x,y),mlink(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		xi=read(),xt=read(),yi=read(),yt=read();
		if((abs(depth[xi]-depth[yi])==1&&!yt&&!xt)||(xi==yi&&xt!=yt))
		{
			printf("-1\n");
			continue;
		}
		memset(f,0,sizeof(f));
		dp(1,0);
		printf("%d\n",min(f[1][0],f[1][1]));
	}
}
