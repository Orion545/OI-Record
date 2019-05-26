/*我相信暴力出奇迹*/
/*O(nlogn)过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=100005;
ll n,a[Size],stmin[Size][21],mpos[Size][21];
void init()
{
	n=read();
	for(int i=1; i<=n; i++)
	{
		stmin[i][0]=a[i]=read();
		mpos[i][0]=i;
	}
	for(int j=1; j<=20; j++)
	{
		for(int i=1<<j; i<=n; i++)
		{
			if(stmin[i][j-1]<stmin[i-(1<<(j-1))][j-1])
			{
				stmin[i][j]=stmin[i][j-1];
				mpos[i][j]=mpos[i][j-1];
			} else {
				stmin[i][j]=stmin[i-(1<<(j-1))][j-1];
				mpos[i][j]=mpos[i-(1<<(j-1))][j-1];
			}
		}
	}
}
int Querymin(int l,int r)
{
	int x=log2(r-l+1);
	return min(stmin[l+(1<<x)-1][x],stmin[r][x]);
}
int Querypos(int l,int r)
{
	int x=log2(r-l+1);
	if(stmin[l+(1<<x)-1][x]<stmin[r][x])
	{
		return mpos[l+(1<<x)-1][x];
	}
	return mpos[r][x];
}
ll Divide(int l,int r,ll x)
{
	if(l>r) 	return 0;
	if(l==r)    return a[l]-x;
	ll nowmin=Querymin(l,r)-x;	//当前最小值 
	ll minpos=Querypos(l,r);	//最小值位置 
	return Divide(l,minpos-1,x+nowmin)+Divide(minpos+1,r,x+nowmin)+nowmin;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	printf("%lld",Divide(1,n,0));
	return 0;
}
