#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
struct node
{
	int x,y,next;
}a[210000];int len,last[110000];
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
char st[11];
LL f[110000][2],p[110000];
int p1,p2,s1,s2;
int fa[110000];
LL tree_dp(int x,int kk)
{
	if(f[x][kk]!=f[0][0])return f[x][kk];
	if((x==p1&&kk!=s1)||(x==p2&&kk!=s2))return f[0][0];
	if(kk==0)f[x][kk]=0;
	else f[x][kk]=p[x];
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa[x])
		{
			fa[y]=x;
			if(kk==0)f[x][kk]+=tree_dp(y,1);
			else f[x][kk]+=min(tree_dp(y,0),tree_dp(y,1));
		}
	}
	return f[x][kk];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;LL sum=0;
	scanf("%d%d%s",&n,&m,st+1);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]),sum+=p[i];
	len++;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	while(m--)
	{
		scanf("%d%d",&p1,&s1);
		scanf("%d%d",&p2,&s2);
		memset(f,0x3f,sizeof(f));
		LL ans=min(tree_dp(1,0),tree_dp(1,1));
		if(ans>sum)printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
