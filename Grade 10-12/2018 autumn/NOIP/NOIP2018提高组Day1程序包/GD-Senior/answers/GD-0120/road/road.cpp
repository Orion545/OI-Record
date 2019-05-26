#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (i=a; i<=b; i++)
using namespace std;

const int N=1e5+5, M=1e4+5;
int n, m, i, j, p, t, ans;
int a[N], lst[M], e[N];
bool bz[N];

void link(int x) {e[i]=lst[x], lst[x]=i;}

int main()
{
	freopen("road.in","r",stdin), freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]), m=max(m,a[i]), link(a[i]);
	bz[0]=bz[n+1]=1;
	fo(i,1,n+1) if (!a[i]) {bz[i]=1; if (!bz[i-1]) p++;}
	fo(i,1,m) if (lst[i])
	{
		ans+=(i-t)*p, t=i, j=lst[i];
		while (j)
		{
			if (bz[j-1] && bz[j+1]) p--; else
			if (!bz[j-1] && !bz[j+1]) p++;
			bz[j]=1, j=e[j];
		}
	}
	printf("%d",ans);
}
