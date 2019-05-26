#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define N 5010
using namespace std;
int n,m,las[N],nxt[N*2],to[N*2],tot=1,ans[N],bz[N],c[N],b[N][N],flag=0,s[N];
void putin(int x,int y)
{
	nxt[++tot]=las[x];las[x]=tot;to[tot]=y;
}
void dfs(int x,int fat)
{
	s[++s[0]]=x;bz[x]=1;
	for(int i=las[x];i;i=nxt[i])
	if(i!=fat)
	{
		if(flag) return;
		int y=to[i];
		if(bz[y])
		{
			flag=1;
			for(;s[s[0]+1]!=y;s[0]--) c[s[s[0]]]=1;
			return;
		}
		dfs(y,i^1);
	}
	if(flag) return;
	s[0]--;
}
void dg(int x,int fa)
{
	bz[x]=1;ans[++ans[0]]=x;
	if(c[x]==0||flag==0)
	{
		while(1)
		{
			int jy=n+1,num=0;
			for(int i=las[x];i;i=nxt[i])
			{
				int y=to[i];
				if(bz[y]) continue;
				if(y<jy) jy=y;
				num++;
			}
			if(num==0) return;
			dg(jy,x);
		}
	}
	else
	{
		int ci=n+1;
		for(int i=las[x];i;i=nxt[i])
		{
			int y=to[i];
			if(bz[y]) continue;
			if(c[y]&&ci==n+1) {ci=y;continue;}
			b[x][++b[x][0]]=y;
		}
		while(1)
		{
			int jy=n+1,num=0;
			for(int i=las[x];i;i=nxt[i])
			{
				int y=to[i];
				if(bz[y]||y==ci) continue;
				num++;
			}
			if(num==0) fo(i,0,b[fa][0]) b[x][i]=b[fa][i];
			fo(i,1,b[x][0]) if(!bz[b[x][i]]) jy=min(jy,b[x][i]);
			if(!bz[ci]) jy=min(jy,ci);
			if(num==0&&jy!=ci) {flag=0;return;}
			if(c[jy]&&jy!=ci)
			{
				fo(i,1,b[x][0]) if(b[x][i]==jy) b[x][i]=ci;
				ci=jy;
			}
			dg(jy,x);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;scanf("%d%d",&x,&y);
		putin(x,y);putin(y,x);
	}
	dfs(1,0);
	memset(bz,0,sizeof(bz));
	bz[n+1]=1;
	dg(1,0);
	fo(i,1,n) printf("%d ",ans[i]);
	printf("\n");
}
