#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,tot=0,mx=0;
int a[102];
bool b[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(b,false,sizeof(b));
		b[0]=true;
		scanf("%d",&n);
		tot=mx=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		mx=a[n];
		for(int i=1;i<=n;i++)
		{
			if(b[a[i]]) continue;
			tot++;
			for(int j=a[i];j<=mx;j++)
				if(b[j-a[i]]) b[j]=true;
		}
		printf("%d\n",tot);
	}
	return 0;
}
