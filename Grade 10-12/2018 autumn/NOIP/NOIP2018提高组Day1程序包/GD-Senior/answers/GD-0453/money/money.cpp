#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 105
#define MAXNUM 1000000
#define fo(i,a,b) for (int i=a;i<=b;++i)
#define fd(i,a,b) for (int i=a;i>=b;--i)

using namespace std;

int a[MAXN],b[MAXNUM],c[MAXN];
int n,T,mx,ans;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0' || '9'<ch){if (ch=='-')f=-1;ch=getchar();}
	while ('0'<=ch && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while (T--)
	{
		memset(b,0,sizeof(b));
		n=ans=read(),mx=0;
		fo(i,1,n)mx=max(mx,a[i]=read()),b[a[i]]=1;
		fo(i,1,mx*mx)
		if (b[i])
		{
			fo(j,1,n)
			if (i+a[j]<=MAXNUM)b[i+a[j]]=1;
		}
		fo(i,1,n)
		fo(j,1,n)
		if (i!=j && a[i]>a[j] && b[a[i]-a[j]])
		{
			--ans;
			break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
