#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int bz[25001],n,m,a[101];

void working()
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	memset(bz,0,sizeof(bz));
	bz[0]=1;
	
	m=0;
	for(int i=1;i<=n;i++)
	{
		if(bz[a[i]])continue;
		
		m++;
		for(int j=a[i];j<=a[n];j++)
			bz[j]|=bz[j-a[i]];
	}
	
	printf("%d\n",m);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	
	for(;t;t--)
		working();
}
