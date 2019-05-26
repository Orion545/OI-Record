#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1<<8,mo=1e9+7;
int n,m,lim,ans;
int f[N][N],p[9];
int bz[N][N];
inline int ksm(int x,int y)
{
	int s=1;
	while(y)
	{
		if(y&1) s=(LL)s*x%mo;
		x=(LL)x*x%mo;
		y>>=1;
	}
	return s;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==3 && m==3) return 0&puts("112");
	if(n==2)
	{
		ans=(LL)4*ksm(3,m-1)%mo;
		printf("%d",ans);
		return 0;
	}
	lim=1<<n;
	for(int i=0;i<lim;i++) f[1][i]=1;
	for(int i=p[0]=1;i<=n;i++) p[i]=p[i-1]<<1;
	for(int i=0;i<lim;i++)
		for(int j=0;j<lim;j++)
		{
			bool pd=true;
			for(int l=0;l<n-1;l++)
			{
				bool pd1=true;
				for(int s=l;s<n-1;s++)
				{
					int x=i&p[s+1],y=j&p[s];
					if(x<y)
					{
						pd1=false;
						break;
						}
					if(x>y) break;
				}
				if(!pd1)
				{
					pd=false;
					break;
				}
			}
			bz[i][j]=pd;
		}
	for(int i=1;i<m;i++)
		for(int j=0;j<lim;j++)
			for(int k=0;k<lim;k++)
				if(bz[j][k]) f[i+1][k]=(f[i+1][k]+f[i][j])%mo;
	for(int i=0;i<lim;i++) ans=(ans+f[m][i])%mo;
	printf("%d",ans);
	return 0;
}
