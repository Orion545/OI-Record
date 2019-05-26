#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,m,i,j,k,ans;
long long p[2005];
long long f[2005][2][2];
long long a,x,b,y;
char str[1005];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",str+1);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
	}
	for (i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&x,&y);
	}
	for (k=1;k<=m;k++)
	{
		scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
		memset(f,100,sizeof(f));
		f[0][0][0]=0;
		f[0][0][1]=0;
		for (i=0;i<=n-1;i++)
		{
			f[i+1][0][0]=f[i][0][1];
			f[i+1][1][0]=min(f[i][0][0]+p[i+1],f[i][0][1]+p[i+1]);
			f[i+1][0][1]=min(f[i][1][0],f[i][1][1]);
			f[i+1][1][1]=min(f[i][1][0]+p[i+1],f[i][1][1]+p[i+1]);
			if (i+1==a)
			{
				if (x==1)
				f[i+1][0][1]=f[i+1][0][0]=999999999999;
				else
				f[i+1][1][0]=f[i+1][1][1]=999999999999;
			}
			if (i+1==b)
			{
				if (y==1)
				f[i+1][0][1]=f[i+1][0][0]=999999999999;
				else
				f[i+1][1][0]=f[i+1][1][1]=999999999999;
			}
		}
		ans=min(min(f[n][1][0],f[n][0][1]),f[n][1][1]);
		if (ans>=999999999999) printf("-1\n");
		else
		printf("%lld\n",ans);
	}
}
