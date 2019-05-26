#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define INF (LL)1e10
using namespace std;
	int n,m,len=0;
	struct node{int x,y,next;} a[100010];
	int last[100010],bz[100010];
	LL d[100010],f[100010][2];
	bool p[100010][2];
void ins(int x,int y)
{
	a[++len]=(node){x,y,last[x]}; last[x]=len;
}
void dfs(int x,int fa)
{
	if(bz[x]) f[x][1]=d[x]; else p[x][1]=false;
	p[x][0]=bz[x]==1?false:true;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		dfs(y,x);
		if(!bz[y]) p[x][0]=false;
	}
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		if(p[x][0]&&p[y][1]) f[x][0]+=f[y][1]; else p[x][0]=false,f[x][0]=0;
		if(p[x][1]&&bz[x])
		{
			//if(bz[y]==-1)
			{
				if(!p[y][0]&&!p[y][1]) p[x][1]=false,f[x][1]=0;
				else if(!p[y][0]) f[x][1]+=f[y][1];
				else if(!p[y][1]) f[x][1]+=f[y][0];
				else f[x][1]+=min(f[y][0],f[y][1]);
			}
			//else if(!bz[y]) f[x][1]+=f[y][0];
			//else f[x][1]+=f[y][1];
		}
	}
}
int main()
{
	char s[5];
	int x,y,xx,yy;
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		bz[i]=-1;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		ins(x,y),ins(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&x,&y,&xx,&yy);
		for(int j=1;j<=n;j++)
			f[j][0]=f[j][1]=0,p[j][0]=p[j][1]=true;
		bz[x]=y;
		bz[xx]=yy;
		dfs(1,0);
		if(!p[1][0]&&!p[1][1]) printf("-1\n");
		else if(!p[1][0]) printf("%lld\n",f[1][1]);
		else if(!p[1][1]) printf("%lld\n",f[1][0]);
		else printf("%lld\n",min(f[1][0],f[1][1]));
		bz[x]=bz[xx]=-1;
	}
	return 0;
}
