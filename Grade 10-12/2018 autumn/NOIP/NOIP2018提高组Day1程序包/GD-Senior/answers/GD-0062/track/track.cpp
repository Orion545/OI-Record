#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
#include <iostream>
using namespace std;

int n,m,f1,f2;
int a[50000+1];
int b[50000+1];
int l[50000+1];
int hS;
int h[300000+1];
#define fa(x) ((x)>>1)
#define lc(x) ((x)<<1)
#define rc(x) (((x)<<1)|1)

int cmp1(int x,int y)
{
	return x>y;
}

void shiftup(int now)
{
	for (int i=now;fa(i)>0;)
		if (h[i]<h[fa(i)])
		{
			swap(h[i],h[fa(i)]);
			i=fa(i);
		}
		else
			break;
}

void shiftdown(int now)
{
	for (int i=now;lc(i)<=hS;)
	{
		int j=0;
		if (h[lc(i)]<h[i])
			j=lc(i);
		if (rc(i)<=hS)
		{
			if (h[rc(i)]<h[i]&&h[rc(i)]<h[lc(i)])
				j=rc(i);
		}
		if (j==0)
			break;
		swap(h[i],h[j]);
		i=j;
	}
}

void insh(int x)
{
	h[++hS]=x;
	shiftup(hS);
}

void delh(int now)
{
	if (now==hS)
		hS--;
	else
	{
		swap(h[now],h[hS]);
		hS--;
		shiftup(now);
		shiftdown(now);
	}
}

void work1()
{
	sort(&l[1],&l[n],cmp1);
	if (m*2<=n-1)
	{
		int ans=0x3f3f3f3f;
		for (int i=m,j=m+1;i>=1&&j<=2*m;i--,j++)
			ans=min(ans,l[i]+l[j]);
		printf("%d\n",ans);
	}
	else
	{
		int ans=0x3f3f3f3f;
		for (int i=m+1,j=m;i<n&&j>=1;i++,j--)
		{
			l[j]+=l[i];
			l[i]=0;
		}
		for (int i=1;i<=m;i++)
			ans=min(ans,l[i]);
		printf("%d\n",ans);
	}
}

void work2()
{
	
}

void work()
{
	f1=f2=1;
	scanf("%d %d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&l[i]);
		if (a[i]>b[i])
			swap(a[i],b[i]);
		if (a[i]!=1)
			f1=0;
		if (b[i]!=a[i]+1)
			f2=0;
	}
	//if (f1)
		work1();
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
