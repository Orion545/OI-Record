#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef long long LL;

const int maxn=100010;
const LL INF=10000000010ll;
int n,m;
LL val[maxn],f[maxn][2][2];
int ok[maxn];
char sp[10];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,&sp);
	for (int i=1;i<=n;i++) scanf("%lld",&val[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
	}
	
	for (int i=1;i<=m;i++)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		for (int j=1;j<=n;j++) ok[j]=-1;
		ok[a]=x;ok[b]=y;
		
		for (int j=1;j<=n;j++)
			{f[j][0][0]=INF;f[j][0][1]=INF;f[j][1][0]=INF;f[j][1][1]=INF;}
		
		if (ok[1]!=1 && ok[2]!=0) f[2][1][0]=val[1];
		if (ok[1]!=0 && ok[2]!=1) f[2][0][1]=val[2];
		if (ok[1]!=1 && ok[2]!=1) f[2][1][1]=val[1]+val[2];
		for (int j=3;j<=n;j++)
		{
			if (a==j && x!=1 || b==j && y!=1 || (a!=j && b!=j))
			{
				f[j][0][0]=f[j-1][1][0];
				f[j][1][0]=min(f[j-1][0][1],f[j-1][1][1]);
			}
			if (a==j && x!=0 || b==j && y!=0 || (a!=j && b!=j))
			{
				f[j][0][1]=min(f[j-1][1][0],f[j-1][0][0])+val[j];
				f[j][1][1]=min(f[j-1][0][1],f[j-1][1][1])+val[j];
			}
		}
		LL ans=INF;
		ans=min(f[n][0][1],min(f[n][1][0],min(f[n][1][1],ans)));
		if (ans<INF) printf("%d\n",ans);else printf("-1\n");
	}
	
	return 0;
}
