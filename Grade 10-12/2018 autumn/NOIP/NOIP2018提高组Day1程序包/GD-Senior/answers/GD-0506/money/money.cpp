#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <bitset>

using namespace std;

const int MLn=233;
const int Max=25233;

int a[MLn];

bitset <Max>f;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int ng; scanf("%d",&ng);
	
	for ( ; ng; ng--)
	{
		int n; scanf("%d",&n);
		
		int lim=0;
		
		for (int i=0; i<n; i++)
		 scanf("%d",&a[i]),
		 lim=max(lim,a[i]);
		
		sort(a+0,a+n);
		
		int ans=0;
		
		f=1;
		
		for (int i=0; i<n; i++)
		 if (!f[a[i]])
		{
			ans++;
			
			for (int j=0; j+a[i]<=lim; j++)
			 if (f[j]) f[j+a[i]]=f[j];
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
