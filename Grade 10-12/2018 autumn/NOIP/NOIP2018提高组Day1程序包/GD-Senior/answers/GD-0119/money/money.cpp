#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,a[101],b[101],ans;
int bz[25001],check;//1表示可被分解，2表示不可，0表示没走过 

int dg(int x,int now)
{
	for (int i=now;b[i]<=x && i<=m;i++)
		for (int j=x/b[i]*b[i];j>0;j-=b[i])
		{
			if (bz[x-j]==0) dg(x-j,i+1);
			if (bz[x-j]==1) return bz[x]=1;
		}
	return bz[x]=2;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d\n",&T);
	while (T--)
	{
		scanf("%d\n",&n);m=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(bz,0,sizeof(bz));
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++)
		{
			check=1;
			for (int j=1;j<=m;j++)
				if (a[i]%a[j]==0) {check=0; break;}
			if (check) b[++m]=a[i];
		}
		if (m>2) ans=2,bz[b[1]]=bz[b[2]]=1;
		else ans=m;
		for (int i=3;i<=m;i++)
		{
			dg(b[i],1);
			if (bz[b[i]]==2) ans++,bz[b[i]]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
