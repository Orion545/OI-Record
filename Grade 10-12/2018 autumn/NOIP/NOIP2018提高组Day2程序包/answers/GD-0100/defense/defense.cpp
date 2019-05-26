#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL inf=1LL<<60;
struct node{
	int y,next;
}a[200010];int len=0,last[100010];
int n,m,p[100010];
char s[10];
void ins(int x,int y)
{
	a[++len].y=y;
	a[len].next=last[x];last[x]=len;
}
int A,X,B,Y;
LL f[100010][2];
void dfs(int x,int fa)
{
	f[x][0]=0;f[x][1]=p[x];
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		dfs(y,x);
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
		f[x][0]=min(f[x][0],inf);
		f[x][1]=min(f[x][1],inf);
	}
	if(x==A) f[x][X^1]=inf;
	if(x==B) f[x][Y^1]=inf;
	//printf("%d:%lld %lld\n",x,f[x][0],f[x][1]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d %d",&x,&y);
		ins(x,y);ins(y,x);
		//printf("%d %d\n",x,y);
	}
	while(m--)
	{
		scanf("%d %d %d %d",&A,&X,&B,&Y);
		dfs(1,0);
		LL ans=min(f[1][0],f[1][1]);
		if(ans>=inf) printf("-1\n");
		else printf("%lld\n",ans);
	}
}
