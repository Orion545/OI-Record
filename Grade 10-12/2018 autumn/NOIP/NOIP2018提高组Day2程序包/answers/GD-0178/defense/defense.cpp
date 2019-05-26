#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
struct node
{
	int x,y,next;
}a[610000];int len,last[310000];
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
char st[11];
LL d[310000],f[310000][2];
int p[310000];
LL dfs(int x,int fa,int t)
{
	if(p[x]==(t^1)) return -1;
	bool bk=false;
	LL dd=0;
	if(t==0)
	{
		dd=0;
		for(int k=last[x];k;k=a[k].next)
		{
			int y=a[k].y;
			if(y==fa) continue;
			LL pd=dfs(y,x,t^1);
			if(pd==-1) return -1;
			dd+=pd;
			bk=true;
		}
		return dd;
	}
	else
	{
		dd=d[x];
		for(int k=last[x];k;k=a[k].next)
		{
			int y=a[k].y;
			if(y==fa) continue;
			LL p1=dfs(y,x,t),p2=dfs(y,x,t^1);
			if(p1==-1&&p2==-1) return -1;
			if(p1==-1) dd+=p2;
			else if(p2==-1) dd+=p1;
			else dd+=min(p1,p2);
			bk=true;
		}
	}
	if(bk==false)
	{
		if(t==1) return d[x];
		else if(t==0) return 0;
	}
	return dd;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;scanf("%d%d%s",&n,&m,st+1);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	memset(f,-1,sizeof(f));
	memset(p,-1,sizeof(p));
	if(n<=2000&&m<=2000)
	{
		for(int i=1;i<=m;i++)
		{
			int A,x,B,y;
			scanf("%d%d%d%d",&A,&x,&B,&y);
			p[A]=x;p[B]=y;
			LL d1=dfs(1,0,0),d2=dfs(1,0,1);p[A]=-1;p[B]=-1;
			if(d1==-1&&d2==-1) printf("-1\n");
			else if(d1==-1) printf("%lld\n",d2);
			else if(d2==-1) printf("%lld\n",d1);
			else printf("%lld\n",min(d1,d2));
		}
	}
	return 0;
}
