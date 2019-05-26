#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=110,M=25025;
int n,a[N],f[M];
int T;
int gcd(int x,int y)
{
	return(y==0)?x:(gcd(y,x%y));
}
int lcm(int x,int y)
{
	if(x*y==0) return(x^y);
	return(1ll*x/gcd(x,y)*y);
}
int mx,k;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof f);
		mx=k=0;
		scanf("%d",&n);
		fo(i,1,n)
		{
			scanf("%d",&a[i]);	
			k=gcd(k,a[i]);
			mx=max(mx,a[i]);
		}	
		sort(a+1,a+1+n);
		fo(i,1,n) a[i]/=k;mx/=k;
		int ans=0;
		f[0]=1;
		fo(i,1,n)
		if(!f[a[i]]) 
		{
			++ans;
			fo(j,0,mx) 
			if(f[j] && j+a[i]<=mx) 
				f[j+a[i]]=1;
		}
		printf("%d\n",ans);
	}
	return 0;	
}






