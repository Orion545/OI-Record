#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long LL;
int a[5100][5100],len[5100];
bool map[5100][5100];
int ans[5100],dep[5100],tot;
void dfs(int x,int fa)
{
	for(int k=1;k<=len[x];k++)
	{
		int y=a[x][k];
		if(y==fa) continue;
		ans[++tot]=y;
		dfs(y,x);
	}
}
bool v[5100];int X,Y,K;
void duan(int x,int fa)
{
	if(X!=-1) return ;
	for(int k=1;k<=len[x];k++)
	{
		int y=a[x][k];
		if(y==fa) continue;
		if(v[y]==true){X=y;Y=x;return ;}
		v[y]=true;
		duan(y,x);
	}
}
int p[5100],pp[5100],cnt;
bool findhuan(int x,int fa)
{
	if(x==Y) return true;
	for(int k=1;k<=len[x];k++)
	{
		int y=a[x][k];
		if(y==fa||x==X&&Y==y) continue;
		if(findhuan(y,x)==true){v[y]=true;p[++cnt]=y;return true;}
	}
}
bool bo[5100];int n;
void gettree(int x,int fa)
{
	if(bo[x]==true) return ;
	for(int k=1;k<=len[x];k++)
	{
		int y=a[x][k];
		if(y==fa) continue;
		ans[++tot]=y;bo[y]=true;
		if(v[y]==true) continue;
		gettree(y,x);
	}
}
struct enode
{
	int x,y;
}e[5100];
struct shunx
{
	int x,fa;
	friend bool operator < (shunx n1,shunx n2){return n1.x>n2.x;}
};
priority_queue<shunx> q;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	memset(len,0,sizeof(len));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][++len[x]]=y;
		a[y][++len[y]]=x;
		e[i].x=x;e[i].y=y;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+len[i]+1);
		ans[1]=1;tot=1;dfs(1,0);
		for(int i=1;i<n;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	else
	{
		memset(v,false,sizeof(v));
		X=-1;v[1]=true;duan(1,0);
		memset(v,false,sizeof(v));
		cnt=0;findhuan(X,0);p[++cnt]=X;v[X]=true;
		int st=0,mmin=1<<30;
		for(int i=1;i<=cnt;i++) if(p[i]<mmin) mmin=p[i],st=i;
		memset(bo,false,sizeof(bo));
		tot=0;bool bk=false;
		int rt=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]==false)
			{
				rt=i;break;
			}
		}
		if(rt<mmin)
		{
			ans[++tot]=rt,gettree(rt,0);
			bo[rt]=true;
			for(int i=1;i<=cnt;i++)
			{
				if(bo[p[i]]==true)
				{
					st=i;
					for(int k=1;k<=len[p[i]];k++)
					{
						int y=a[p[i]][k];
						if(v[y]==false&&bo[y]==false) q.push((shunx){y,p[i]});
					}
				}
			}
		}
		int x=st-1,y=st+1;if(x==0) x=cnt;if(y==cnt+1) y=1;
		pp[1]=mmin;int plen=1;
		bool bx=false,by=false;
		int add=1,fx=-1;
		while(add<cnt)
		{
			if((p[x]>p[y]&&fx!=0)||fx==1)
			{
				while(q.empty()==0)
				{
					shunx tno=q.top();
					if(tno.x>p[y]) break;
					q.pop();
					gettree(tno.x,tno.fa);
				}
				ans[++tot]=p[y];
				by=true;if(bx==true) fx=1;
				for(int k=1;k<=len[p[y]];k++) if(v[a[p[y]][k]]==false) ans[++tot]=a[p[y]][k],gettree(a[p[y]][k],p[y]);
				add++;
				y++;if(y==cnt+1) y=1;
			}
			else
			{
				while(q.empty()==0)
				{
					shunx tno=q.top();
					if(tno.x>p[x]) break;
					q.pop();
					gettree(tno.x,tno.fa);
				}
				ans[++tot]=p[x];
				bx=true;if(by==true) fx=0;
				for(int k=1;k<=len[p[x]];k++)
				{
					if(v[a[p[x]][k]]==false)
					{
						ans[++tot]=a[p[x]][k];
						gettree(a[p[x]][k],p[x]);
					}
				}
				add++;
				x--;if(x==0) x=cnt;
			}
		}
		for(int i=1;i<tot;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[tot]);
	}
	return 0;
}
