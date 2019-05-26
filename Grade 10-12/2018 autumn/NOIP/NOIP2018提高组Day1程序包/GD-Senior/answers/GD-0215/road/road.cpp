#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100005;

int n,ftot=0,ztot=0;
int a[maxn],f[maxn];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1; i<=n; i++)
		f[i]=a[i]-a[i-1];
	
	for (int i=1; i<=n; i++)
		if (f[i]>=0) ztot+=f[i];
	
	printf("%d\n",ztot);
	
	return 0;
}
