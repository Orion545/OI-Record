#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int Maxn=100010;
const LL inf=10000000000LL;
int n,m,A,X,B,Y,ff[Maxn];
LL f[Maxn][2],p[Maxn];
struct Edge{int y,next;}e[Maxn<<1];
int last[Maxn],len=0;
void ins(int x,int y)
{
	int t=++len;
	e[t].y=y;e[t].next=last[x];last[x]=t;
}
char str[5];
bool mp[2010][2010];
void dfs(int x,int fa)
{
	ff[x]=fa;f[x][0]=0;f[x][1]=p[x];
	for(int i=last[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		dfs(y,x);
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
	}
	if(x==A)f[A][X^1]=inf;
	if(x==B)f[B][Y^1]=inf;
//	printf("%d %lld %lld\n",x,f[x][0],f[x][1]);
}
LL ans[Maxn][2][2];
void DFS(int x,int fa,LL v0,LL v1)
{
	ans[x][0][0]=inf;
	ans[x][0][1]=f[x][0]+v1;
	ans[x][1][0]=f[x][1]+v0;
	ans[x][1][1]=f[x][1]+v1;
	for(int i=last[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		DFS(y,x,ans[x][0][1]-f[y][1],min(ans[x][1][0],ans[x][1][1])-min(f[y][0],f[y][1]));
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,str);
//	printf("\n%s\n",str);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y),ins(y,x);
		if(n<=2000&&m<=2000)mp[x][y]=mp[y][x]=true;
	}
	if(n<=2000&&m<=2000)
	{
		while(m--)
		{
			scanf("%d%d%d%d",&A,&X,&B,&Y);
			if(mp[A][B]&&!X&&!Y)printf("-1\n");
			else
			{
				dfs(1,0);
				printf("%lld\n",min(f[1][0],f[1][1]));
			}
		}
		return 0;
	}
	if(str[1]=='1'||str[1]=='2')
	{
		dfs(1,0);
		if(str[1]=='1')f[1][0]=inf;
		DFS(1,0,0,0);
		while(m--)
		{
			scanf("%d%d%d%d",&A,&X,&B,&Y);
			if(ff[A]==B||ff[B]==A)
			{
				if(!X&&!Y)
				{
					printf("-1\n");
					continue;
				}
			}
			if(str[1]=='1')
			{
				if(!Y)printf("%lld\n",ans[B][Y][1]);
				else printf("%lld\n",min(ans[B][Y][0],ans[B][Y][1]));
			}
			if(str[1]=='2')
			{
				if(ff[B]==A)swap(A,B),swap(X,Y);
				printf("%lld\n",ans[A][X][Y]);
			}
		}
	}
}
