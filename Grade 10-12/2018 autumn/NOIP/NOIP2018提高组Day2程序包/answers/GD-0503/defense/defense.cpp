#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
inline int read()
{
	int re=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0' && ch<='9') re=re*10+(ch^48),ch=getchar();
	return re*f;
}
const int MAXN=1e5;
int p[MAXN];
struct E{int x,y,next;} ed[MAXN]; int last[MAXN],len;
void ins(int x,int y) { ed[++len]=(E){x,y,last[x]}; last[x]=len; }
char opt[5];
bool v[MAXN];
int ans=0;
/*void dfs(int x)
{
	for(int k=last[x];k;k=ed[k].next)
	{
		int y=ed[k].y;
		if(!v[x]) v[y]=true,ans+=p[y];
		dfs(y);
	}
}*/
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	scanf("%s",opt+1);
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y); ins(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		int com1=read(),x=read(),com2=read(),y=read();
		if(x==1 && y==1)
		{
			ans+=p[com1]+p[com2];
//			dfs(com1);
			printf("%d\n",ans);
		}
		else puts("-1");
	}
	return 0;
}
