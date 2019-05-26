#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#define N 100005
using namespace std;
int T,n,a[N],ma,bz[N],p[N*10],ans,s,z;
int max(int x,int y){return (x<y)?y:x;}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n),ma=0,ans=n;
		memset(bz,0,sizeof bz),memset(p,0,sizeof p);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),ma=max(ma,a[i]);
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++)
		{
			if (bz[a[i]])
			{
				ans--;
				continue;
			}
			p[++p[0]]=a[i],s=1;
			while (s>0)
			{
				z=p[0],s=0;
				for (int j=1;j<=z;j++)
					if (p[j]+a[i]<=ma&&!bz[p[j]+a[i]])
						bz[p[j]+a[i]]=1,p[++p[0]]=p[j]+a[i],s++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
