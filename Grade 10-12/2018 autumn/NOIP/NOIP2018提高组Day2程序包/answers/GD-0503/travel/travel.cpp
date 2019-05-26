#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
inline int read()
{
	int re=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0' && ch<='9') re=re*10+(ch^48),ch=getchar();
	return re*f;
}
const int MAXN=5010;
struct E{int x,y,next;} ed[MAXN]; int last[MAXN],len;
struct Ed{int x,y; }a[MAXN];
void ins(int x,int y) { ed[++len]=(E){x,y,last[x]}; last[x]=len; }
int ans[MAXN],cnt,anslen,n,m;
bool v[MAXN],bk,vis[MAXN];
bool cmp(Ed x,Ed y)
{
	if(x.x!=y.x) return x.x>y.x;
	return x.y>y.y;
}
void dfs1(int x)
{
	if(bk) return ;
	if(cnt==n) { bk=true; return ; } 
	for(int k=last[x];k;k=ed[k].next)
	{
		if(!vis[k]) continue;
		int y=ed[k].y;
		vis[k]=false;
		if(!v[y])
		{
			cnt++;
			v[y]=true;
			ans[++anslen]=y;
		}
		dfs1(y);
	}
}
void dfs2(int x)
{
	if(bk) return ;
	if(cnt==n) { bk=true; return ; } 
	for(int k=last[x];k;k=ed[k].next)
	{
		if(!vis[k]) continue;
		int y=ed[k].y;
		if(!v[y])
		{
			vis[k]=false;
			cnt++;
			v[y]=true;
			ans[++anslen]=y;
			dfs2(y);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i+m].x=a[i].y,a[i+m].y=a[i].x;
	sort(a+1,a+m*2+1,cmp);
	for(int i=1;i<=2*m;i++) ins(a[i].x,a[i].y);
	memset(v,false,sizeof(v)); cnt=anslen=0;
	memset(vis,true,sizeof(vis));
	bk=false;
	v[1]=true;
	ans[++anslen]=1;
	cnt++;
	if(m==n) dfs1(1);
	else dfs2(1);
	for(int i=1;i<=anslen;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
