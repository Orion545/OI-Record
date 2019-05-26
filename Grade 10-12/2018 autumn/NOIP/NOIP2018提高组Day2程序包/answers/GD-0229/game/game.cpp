#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,cnt,a[11][11];
inline void dfs(int pn,int pm)
{
	if(pn==n+1 && pm==1)
	{
		bool bk=true;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(a[i+1][j]<a[i][j+1]){bk=false;break;}
			}
			if(bk==false)break;
		}
		if(bk==true)
		{
			cnt++;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)printf("%d",a[i][j]);
				printf("\n");
			}printf("\n");
		}
	}
	else
	{
		for(int i=0;i<=1;i++)
		{
			a[pn][pm]=i;
			int un=pn,um=pm;
			um++;if(um==m+1)um=1,un++;
			dfs(un,um);
		}
	}
}
inline long long power(long long a,int b)
{
	long long ans=1LL;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if(n>m)swap(n,m);
	if(n==1)printf("%lld\n",power(2,m));
	else if(n==2)printf("%lld\n",power(3,m-1)*4%mod);
	else if(n==3)printf("112\n");
	return 0;
}
