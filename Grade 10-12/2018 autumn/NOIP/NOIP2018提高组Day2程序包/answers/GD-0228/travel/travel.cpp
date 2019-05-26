#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,x,y,mn,sl,fh,flg,top,b[5010],vis[5010],ans[5010];
vector<int> e[5010];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int init(int u,int f)
{
	int v,siz=e[u].size();vis[u]=1;
	for(int i=0;i<siz;++i)
		if((v=e[u][i])!=f)
		{
			if(vis[v]) {b[u]=b[v]=flg=1; return 1;}
			if(init(v,u))
			{
				if(!b[u]) b[u]=flg;
				else flg=0,b[u]=0;
				return 1;
			}
		}
	return 0;
}
void dfs2(int u,int f,int nxtmn,int sf)
{
	int v,k=0,ex=1,z,nw=top,siz=e[u].size();
	ans[++top]=u;vis[u]=1;
	if(sf&&siz==2) return ;
	for(int i=0;i<siz;++i)
	{
		if((v=e[u][i])!=f&&!vis[v])
		{
			if(b[v]&&v>mn)
			{
				k=1;
				if(v<nxtmn) dfs2(v,u,0,k);
				continue;
			}
			if(i<siz-1-ex) z=e[u][i+1];
			else z=0;
			dfs2(v,u,z,0);
		}
		if(v==f) ex=0;
	}
}
void dfs1(int u,int f)
{
	int v,siz=e[u].size();ans[++top]=u;vis[u]=1;
	for(int i=0;i<siz;++i)
		if((v=e[u][i])!=f&&!(vis[v]&b[v]))
		{
			if(b[v]&&!flg)
			{
				if(i<siz-1) mn=e[u][i+1];
				else mn=n+1;
				dfs2(v,u,mn,0);
				flg=1;
				continue;
			}
			dfs1(v,u);
		}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=m;++i)
	{
		x=rd(),y=rd();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;++i) sort(e[i].begin(),e[i].end());
	if(m==n) init(1,0);flg=0;
	memset(vis,0,sizeof(vis));
	dfs1(1,0);
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	puts("");
	return 0;
}
