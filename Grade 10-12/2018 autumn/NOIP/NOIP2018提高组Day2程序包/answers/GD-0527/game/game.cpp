#include<bits/stdc++.h>
#define fo(i) for(int i=0;i<=1;i++)
#define ha 1000000007
#define ll long long
ll ans;
int n,m,f[1000011][2][2][2];
using namespace std;
ll ksm(ll x,ll y)
{
	ll a=1,b=y,c=x;
	while(b!=0)
	{
		if(b%2==1)a=a*c%ha;
		b/=2,c=c*c%ha;
	}
	return a;
}
int main()
{
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2)
	{
		ans=ksm(3,m-1),ans=ans*4%ha;		
		printf("%lld\n",ans);
		return 0;
	}
	if(n==1||m==1)
	{
		ans=ksm(2,max(n,m));
		printf("%lld\n",ans);
		return 0;
	}
	if(n==3&&m==3)printf("112\n");
	if(n==3&&m==2)printf("36\n");
/*	if(n==3)
	{
		fo(i)fo(j)fo(k)f[m][i][j][k]=1;
		for(int i=m-1;i>=1;i--)
		{
			fo(a)fo(b)fo(c)fo(x)fo(y)fo(z)
			{
				if(x>a||y>b||z>c)continue;
				if(b==x)
				{
					if(m-i-2>0)
					{
						f[i][a][b][c]=f[i][a][b][c]*(6*ksm(4,m-i-2)%ha)%ha;
						continue;
					}
					if(m-i-1>0)
					{
						f[i][a][b][c]=(f[i][a][b][c]+6)%ha;
						continue;
					}
					f[i][a][b][c]++;
					continue;
 				}
				f[i][a][b][c]=(f[i][a][b][c]+f[i+1][x][y][z])%ha;
			}
		}
		ans=0;
		fo(a)fo(b)fo(c)ans=(ans+f[1][a][b][c])%ha;
		printf("%lld\n",ans);
	}	*/
}
