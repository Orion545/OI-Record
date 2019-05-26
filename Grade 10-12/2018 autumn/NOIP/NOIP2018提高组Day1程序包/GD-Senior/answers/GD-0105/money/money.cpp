#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdlib>
using namespace std;
int bo[25002];
int s[25002];
int a[25002];
int ans = 0x7fffffff;
int T,n,ma;
void dfs(int k,int m)
{
	if(m>ans) return ;
	if(k>n)
	{
		ans = min(ans,m);
		return ;
	}	
	if(bo[a[k]]==1) dfs(k+1,m);
	else
	{
	memset(s,0,sizeof(s));
	bo[0] = 1;
	for(int i=0;i<=ma;i++)if(bo[i]==1 && s[i]==0)
		for(int j=1;i+j*a[k]<=ma;j++) 
		{
			bo[i+j*a[k]] = 1;
			s[i+j*a[k]] = 1;
		}
	dfs(k+1,m+1);
}}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans = 0x7fffffff;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ma = a[n];
		memset(bo,0,sizeof(bo));
		dfs(1,0);	
		printf("%d\n",ans);
	}
	return 0;
}
