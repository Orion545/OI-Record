#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,m,k[100],a[100][100],b[233333][100],s,sum[100][100];
long long ans;
void work(int x,int y)
{
	if(x>n)return;
	if(y>m)return;
	k[x+y-1]=a[x][y];
	if(x==n&&y==m)
	{
		s++;
		for(int i=1;i<=n+m-1;i++)b[s][i]=k[i];
		return;
	}
	work(x,y+1);
	work(x+1,y);
}
bool check()
{
	s=0;
	work(1,1);for(int j=1;j<s;j++)
	for(int i=1;i<=n+m-1;i++)
		
			if(b[j][i]>b[j+1][i])
			{
				return false;
			}else
			if(b[j][i]<b[j+1][i])break;
				
	return true;
}
bool check2()
{
	for(int i=2;i<=n;i++)
		for(int j=1;j<m;j++)
			if(a[i-1][j+1]>a[i][j])return false;
	return true;
}
void finds(int x,int y)
{
	if(x>n)
	{
//	if(check2())
		if(check())
		
		{
			ans++;
		}
		return;
	}
	if(y>m)finds(x+1,1);else
	{
		a[x][y]=0;
		finds(x,y+1);
		a[x][y]=1;
		finds(x,y+1);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int mm;
	scanf("%d%d",&n,&mm);if(n>mm)swap(n,mm);m=n;
	finds(1,1);
	if(n>1)
	for(int i=m+1;i<=mm;i++)ans=(ans*3)%mod;else
	{
		ans=1;
		for(int i=1;i<=mm;i++)ans=(ans*2)%mod;
	}
	printf("%d",ans);
	return 0;
}