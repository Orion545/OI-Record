#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
	int n,m,len=0,t=0;
	bool bz[10010];
	bool flag=false;
	int last[10010],linshi[100010],d[10010];
	struct node1{int x,y,next;} a[10010];
void ins(int x,int y)
{
	a[++len]=(node1){x,y,last[x]}; last[x]=len;
}
int u1=1;
void dfs1(int x,int fa)
{
	if(flag) return;
	if(bz[x]) return;
	if(t==n) {flag=true;return;}
	if(!bz[x]) d[++t]=x;
	bz[x]=true;
	int u2=u1;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		linshi[u2++]=y;
	}
	if(!(u2-u1)) return;
	int t=u1;
	u1=u2;
	sort(linshi+t,linshi+u2);
	for(int i=t;i<u2;i++)
		dfs1(linshi[i],x);
}
/*int fa[10010];
void dfs1(int x)
{
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa[x]) continue;
		dfs1(y);
	}
}
void dfs2(int x)
{
	if(flag) return;
	if(t==n) {flag=true;return;}
	if(!bz[x]) d[++t]=x;
	bz[x]=true;
	int u=0;
	int linshi[10];
	memset(linshi,0,sizeof(linshi));
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa[x]) continue;
		linshi[++u]=y;
	}
	if(!u) return;
	sort(linshi+1,linshi+u+1);
	for(int i=1;i<=u;i++)
		dfs2(linshi[i]);
}*/
int main()
{
	int x,y;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		ins(x,y),ins(y,x);
	}
	memset(bz,false,sizeof(bz));
	if(m==n-1) dfs1(1,0); else dfs1(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
	return 0;
}
