#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,a[105],n;
bool f[25005],g[105];
int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
void DO()
{
	long long Min=625050000LL;
	int x,y;
	for (int i=1;i<=n;i++) g[i]=false;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (gcd(a[i],a[j])==1)
			{
				if ((long long)(a[i]*a[j]-a[i]-a[j])<Min)
				{
					Min=(long long)(a[i]*a[j]-a[i]-a[j]);
					x=i;y=j;
				}
			}
	for (int i=1;i<=n;i++)
		if (i!=x&&i!=y&&a[i]>Min) g[i]=true;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int ans=n;
		for (int i=1;i<=n;i++) 
			scanf("%d",&a[i]);
		DO();
		f[0]=true;
		for (int i=1;i<=n;i++)
			if (g[i]) ans--; else
			{
				for (int j=1;j<=a[i];j++) f[j]=false;
				for (int j=1;j<=n;j++)
				{
					if (i==j) continue;
					for (int k=a[j];k<=a[i];k++)
						f[k]=(f[k]||f[k-a[j]]);
					if (f[a[i]]) {
						ans--;break;
					}
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
