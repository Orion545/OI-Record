#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
int tot,z[5005],ans[5005],a[5005][5005],bz[5005],i,j,k,l,n,m,x,y,q;
void dfs(int x)
{
	int i;
	tot++,z[tot]=x,bz[x]=1;
	if(q==0&&z[tot]>ans[tot])
	{
		q=1;
		return;
	}
	if(q==0&&z[tot]<ans[tot])q=2;	
	if(q==2)ans[tot]=z[tot];
	for(i=1;i<=a[x][0];i++)
	{
		if(bz[a[x][i]]==1)continue;
		dfs(a[x][i]);
		if(q==1)return;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(ans,126,sizeof ans);
	if(n-1==m)
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			a[x][0]++,a[x][a[x][0]]=y;
			a[y][0]++,a[y][a[y][0]]=x;
		}
		for(i=1;i<=n;i++)sort(a[i]+1,a[i]+a[i][0]+1);
		bz[0]=1;
		dfs(1);
		for(i=1;i<=n;i++)printf("%d ",ans[i]);
	}
	if(n==m)
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			a[x][0]++,a[x][a[x][0]]=y;
			a[y][0]++,a[y][a[y][0]]=x;
		}
		for(i=1;i<=n;i++)sort(a[i]+1,a[i]+a[i][0]+1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=a[i][0];j++)
			{
				k=a[i][j];
				a[i][j]=tot=q=0;
				memset(bz,0,sizeof bz);
				bz[0]=1;
				dfs(1);
				a[i][j]=k;
			}
		}
		for(i=1;i<=n;i++)printf("%d ",ans[i]);
	}
}
