#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 110
#define M 25050

int a[N],t[M],f[M];
int n,m,ans;

bool comp(int x,int y)
{
	return x<y;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&m);
	for (int ii=1;ii<=m;ii++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(f));
		sort(a+1,a+n+1,comp);
		for (int i=1;i<=n;i++)
		  t[a[i]]=1;
		ans=n;
		f[0]=1;
		for (int i=1;i<=n;i++)
		  for (int j=a[i];j<=a[n];j++)
		  {
		    f[j]=max(f[j],f[j-a[i]]);
		  	if (f[j]==1 && t[j]==1 && j!=a[i]) 
		  	{
		  		t[j]=0;
		  		ans--;
		  	}
		  }
		printf("%d\n",ans);
	}
	return 0;
}

