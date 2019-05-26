#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 200005
#define fo(i,a,b) for (int i=a;i<=b;++i)
#define fd(i,a,b) for (int i=a;i>=b;--i)

using namespace std;

int a[MAXN];
int n,ans;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0' || '9'<ch){if (ch=='-')f=-1;ch=getchar();}
	while ('0'<=ch && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int min(int x,int y)
{
	return x<y?x:y;
}
void doit(int l,int r)
{
	if (!(l<=r))return;
	int mn=1000000007,last=1;
	fo(i,l,r)mn=min(mn,a[i]);
	ans+=mn;
	if (l==r)
	{
		a[l]-=mn;
		return;
	}
	fo(i,l,r)
	{
		a[i]-=mn;
		if (a[i]==0)
		{
			doit(last,i-1);
			last=i+1;
		}
	}
	if (last<=r)doit(last,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	fo(i,1,n)a[i]=read();
	doit(1,n);
	printf("%d\n",ans);
	return 0;
}
