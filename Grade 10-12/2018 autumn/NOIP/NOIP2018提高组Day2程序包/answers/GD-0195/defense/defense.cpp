#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 110000
using namespace std;
struct node
{
	int x,y;
};
char ss[110];
int f[MAXN][2],c[MAXN];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;scanf("%d %d %s",&n,&m,ss+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
	}
	while(m--)
	{
		node x,y;scanf("%d%d%d%d",&x.x,&x.y,&y.x,&y.y);
		memset(f,63,sizeof(f));f[0][0]=0;f[0][1]=0;
		for(int i=1;i<=n;i++)
		{
			if(x.x==i)
			{
				if(x.y==0)f[i][0]=f[i-1][1];
				else f[i][1]=min(f[i-1][1],f[i-1][0])+c[i];
				continue;
			}
			if(y.x==i)
			{
				if(y.y==0)f[i][0]=f[i-1][1];
				else f[i][1]=min(f[i-1][1],f[i-1][0])+c[i];
				continue;
			}
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][0],f[i-1][1])+c[i];
		}
		int ans=min(f[n][0],f[n][1]);
		if(ans>=f[100001][0])printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;	
}
