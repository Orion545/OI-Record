#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10000+20
#define inf 1e9
#define re(x) memset(x,0,sizeof(x))
int T,n,mt,ti,ans;
int ar[N],f[N],at[N];
bool bz[N];
void dfs(int x)
{
	if(x>ti)
	{
		int cnt=0;
		re(f);
		for(int i=1;i<=ti;i++)
			if(bz[i])f[at[i]]=1,cnt++;
		for(int i=0;i<=mt;i++)
		{
			if(f[i])continue;
			for(int j=0;j<=i;j++)
				if(f[j]&&f[i-j])
					f[i]=1;
		}
		for(int i=1;i<=ti;i++)
			if(!f[at[i]])
				return;
		ans=min(ans,cnt);
		return;
	}
	bz[x]=0;
	dfs(x+1);
	bz[x]=1;
	dfs(x+1);
}
int cmp(int x,int y){return x>y;}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		re(bz),re(ar),ti=0,mt=0;
		ans=inf;
		for(int i=1;i<=n;i++)
			scanf("%d",&ar[i]);
		sort(ar+1,ar+n+1,cmp);
		
		for(int i=1;i<=n;i++)
		{
			bool bf=0;
			for(int j=i+1;j<=n;j++)
				if(ar[i]%ar[j]==0)
					bf=1;
			if(!bf)at[++ti]=ar[i],mt=max(mt,at[ti]);
		}
		dfs(1);
		if(ans==inf)
			printf("%d\n",ti);
		else
			printf("%d\n",ans);
	}
}
