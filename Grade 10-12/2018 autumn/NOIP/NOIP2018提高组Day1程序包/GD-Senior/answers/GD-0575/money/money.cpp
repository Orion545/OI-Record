#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m[1005];
int cant1[1005];
bool can1[1005];
void dfs(int x,int now)
{
	if (can1[x]==true||x>1005) return;
	if (now!=1) can1[x]=true;
	for (int i=1;i<=n;i++) dfs(x+m[i],now+1);
}
int main()
{
	int q;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&q);
	while (q--)
	{
		bool happy=false;
		scanf("%d",&n);
		int ans=n;
		memset(can1,false,sizeof(can1));
		memset(cant1,0,sizeof(cant1));
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&m[i]);
			if (m[i]==1) happy=true;
		}
		if (n==1||happy==true)
		{
			printf("1\n");
			continue;
		}
		for (int i=1;i<=n;i++) dfs(m[i],1);
		for (int i=1;i<=n;i++)
			if (can1[m[i]]==true)
				ans--;
		printf("%d\n",ans);
	}
	return 0;
}
