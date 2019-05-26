#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (i=a; i<=b; i++)
using namespace std;

const int N=105, M=25e3+5;
int t0, n, m, m0, i, j, k, ans;
int a[N], bz[M];

bool cmp(int a,int b) {return a<b;}

int main()
{
	freopen("money.in","r",stdin), freopen("money.out","w",stdout);
	
	scanf("%d",&t0), bz[0]=1;
	while (t0--)
	{
		scanf("%d",&n), m=0, m0=M; int n0=0;
		fo(i,1,n) scanf("%d",&a[i]), m=max(m,a[i]), m0=min(m0,a[i]);
		if (m0==1) {printf("1\n"); continue;}
		fo(j,1,m) bz[j]=0;
		fo(i,1,n) if (!bz[k=a[i]]) bz[k]=1, a[++n0]=k;
		ans=n=n0;
		
		sort(a+1,a+n+1,cmp);
		fo(i,1,n) if (bz[k=a[i]]>1) ans--; else
		{
			fo(j,m0,m-k) bz[j+k]+=(bz[j]>0);
		}
		printf("%d\n",ans);
	}
}
