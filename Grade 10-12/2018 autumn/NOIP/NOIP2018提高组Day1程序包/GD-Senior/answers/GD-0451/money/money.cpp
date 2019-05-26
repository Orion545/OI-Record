#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define fo(i,x,y) for(i=x;i<=y;i++)
#define N 105
#define M 50005
using namespace std;
int n,m,i,j,k,x,y,t,T,ii,r,ans,xx,yy,mx;
int a[N];
bool bz[M],f[M];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	fo(ii,1,T)
	{
		scanf("%d",&n);
		memset(bz,0,sizeof(bz));
		fo(i,1,n)
		{
			scanf("%d",&a[i]);
			bz[a[i]]=true;
			mx=max(mx,a[i]);
		}
		sort(a+1,a+n+1);
		memset(f,0,sizeof(f));
		fo(i,1,n)
			fo(j,1,mx)
			{
				if (j-a[i]<0 || f[j]) continue;
				if (f[j-a[i]] || bz[j-a[i]]) f[j]=1;
			}
		ans=0;
		fo(i,1,n)
			if (!f[a[i]]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
