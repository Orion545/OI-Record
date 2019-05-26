#include<cctype>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=110;
int n,t,a[maxn],c[maxn],ans,f[maxn];
bool b[maxn];

int rd()
{
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-1:1,c=getchar();
	while (isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

bool ch(int x)
{
	
}

int exgcd(int a,int b,int &x,int &y)
{
	if (!b)
	{
		x=1;
		y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int z=x;
	x=y;
	y=z-a/b*y;
	return d;
}

int fnd(int x)
{
	if (f[x]!=x)
		f[x]=fnd(f[x]);
	return f[x];
}

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int i,j;
	t=rd();
	while (t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		n=rd();
		for (i=1;i<=n;i++)
			f[i]=i;
		for (i=1;i<=n;i++)
			a[i]=rd();
		ans=0;
		for (i=1;i<=n;i++)
			for (j=i+1;j<=n;j++)
				if (gcd(a[i],a[j])!=1)
				{
					int ta=fnd(i),tb=fnd(j);
					if (ta!=tb)
						f[ta]=tb;
				}
		for (i=1;i<=n;i++)
		{
			f[i]=fnd(i);
			b[f[i]]++;
		}
		for (i=1;i<=n;i++)
			if (b[i])
				ans++;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
