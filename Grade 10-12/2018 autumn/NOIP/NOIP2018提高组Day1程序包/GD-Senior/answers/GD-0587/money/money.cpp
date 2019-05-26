#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) a>b?a:b
#define N 100005
int T,n,a[N],maxn,ans;
bool vis[N]={0},flag;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		flag=0;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);ans=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			maxn=max(maxn,a[i]);
			if(a[i]==1) flag=true;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//if(i==j) continue;
		//			if(a[i]%a[j]==0||a[j]%a[i]==0)
		//			{
		//				ans--;
		//				continue;
		//			}
				for(int k=0;k*a[i]<=maxn;k++)
					for(int l=0;a[i]*k+a[j]*l<=maxn;l++)
						vis[a[i]*k+a[j]*l]=1;
			}
		}
		for(int i=1;i<=n;i++) if(vis[a[i]]) ans--;
		if(flag) puts("1");
		else if(n!=1) printf("%d\n",ans+n);
		else printf("%d\n",ans);
	}
	return 0;
}
