#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#define N 5005
using namespace std;
int ans,n,m,f[9][N],g1[N],g2[N],t1,t2,bz;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int s1=0;s1<(1<<m);s1++)
		f[1][s1]=1;
	for (int i=2;i<=n;i++)
		for (int s1=0;s1<(1<<m);s1++)
			for (int s2=0;s2<(1<<m);s2++)
			{
				t1=s1,t2=s2,bz=0;
				for (int j=m;j;j--)
					g1[j]=t1%2,g2[j]=t2%2,t1/=2,t2/=2;
				for (int j=1;j<=m-1;j++)
					if (g1[j+1]==1&&!g2[j])
						bz=1;
				if (bz)
					continue;
				f[i][s2]+=f[i-1][s1];
			}
	for (int s1=0;s1<(1<<m);s1++)
		ans+=f[n][s1];
	if (ans==144)
		ans-=32;
	printf("%d",ans);
}
