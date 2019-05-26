#include <stdio.h>
#include <string.h>
#define min(a,b) ((a<b)?a:b)
	int stat[11111],ct[11111],ans,n,m,x[11111],y[11111];
	char chp[454];
	int mp[1111][1111],lst[11111],lm[11111];
void dfs(int add,int cost)
{
	int i,j;
	if(add>n)
		{
			int flg=1;
			for(i=1;i<n;++i)
				if(lst[x[i]]==0 && lst[y[i]]==0)
					{
						flg=0;
						break;
					}
				if(flg) ans=min(ans,cost);
			return ;
		}
		if(lm[add]==-1)
			{
				lst[add]=0;
				dfs(add+1,cost);
				lst[add]=1;
				dfs(add+1,cost+ct[add]);
			}
		else lst[add]=lm[add],dfs(add+1,cost+ct[add]*lm[add]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i,j;
	scanf("%d%d%s",&n,&m,chp);
	for(i=1;i<=n;++i) scanf("%d",&ct[i]);
	for(i=1;i<n;++i)
		{
			
			scanf("%d%d",&x[i],&y[i]);
		}
		int a,b,c,d;
	for(i=1;i<=m;++i)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
				for(j=1;j<=n;++j)
					lm[j]=-1;
				lm[a]=b;lm[c]=d;
				ans=1<<27;
				dfs(1,0);
				if(ans==1<<27) printf("-1\n");
						else printf("%d\n",ans);
		}
	return 0;
}
