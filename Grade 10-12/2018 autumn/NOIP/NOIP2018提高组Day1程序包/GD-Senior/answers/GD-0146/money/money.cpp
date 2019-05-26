#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[101],b[101],T,n,m;
bool vis[101];
bool work(int k)
{
	if(k==0)return 1;
	for(int i=1;i<=m;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(work(k%b[i]))return 1;
			vis[i]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.ans","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		m=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",a+i);
		sort(a+1,a+n+1);
		b[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(work(a[i]))continue;
			b[++m]=a[i];
		}
		printf("%d\n",m);
	}
	return 0;
}
