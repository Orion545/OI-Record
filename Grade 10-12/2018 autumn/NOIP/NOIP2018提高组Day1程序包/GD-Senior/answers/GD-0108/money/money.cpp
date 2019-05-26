#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
int a[1000000],n,ans=0,t,maxx=-1;
int pd[10000000]={0};
void dfs(int now,int h)
{
	if(now==n+1) return ;
	pd[ h ]+=1;
	if(h > maxx) return ;
	for(int i=0;i <= maxx/a[now] +1;i++)
	{
		dfs( now+1 , i * a[ now ] + h );
	}
	return ;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t){
	bool pdd=0;
	memset(pd,0,sizeof(pd));
	maxx=-1;
	ans=0;
	t--;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) pdd=1;
		maxx = max( maxx , a[i] );
	}
	maxx+=10;
	if(pdd==1)
	{
		int l=1;
		printf("%d\n",l);
	}
	else {
	sort(a+1,a+n+1);
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		if( pd[ a[i] ] == n-i ) ans++;
	}
	printf("%d\n",ans);		
	}
	}
	return 0;
}
