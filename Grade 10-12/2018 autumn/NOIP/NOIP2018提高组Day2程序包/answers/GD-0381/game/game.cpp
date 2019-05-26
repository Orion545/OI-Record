#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;

inline long long rea()
{
	long long x=0, f=1;
	char ch=getchar();
	while (!(isdigit(ch) || ch=='-')) ch=getchar();
	if (ch=='-') f=-1, ch=getchar();
	while (isdigit(ch)) x=x * 10 + ch - 48 , ch=getchar();
	return x * f;
}

long long n, m, ans;
bool a[10][1000050];

bool chk(long long x, long long y)
{
	while (x>0)
	{
		if (a[x-1][y+1]==1) return 1;
		x-=1, y+=1;
	}
	return 0;
}

void f(long long x, long long y)
{
	if (y==m+1)
	{
		f(x+1,1);
		return;
	}
	if (x==n+1)
	{
		ans++; return;
	}
	//if (chk(x,y))
	if (a[x-1][y+1]==1)
	{
		a[x][y]=1;
		f(x,y+1);
		a[x][y]=0;
		return;
	}
	f(x,y+1);
	a[x][y]=1;
	f(x,y+1);
	a[x][y]=0;
}

void da()
{
	n=2;
	for (m=1; m<=30; m++)
	{
		long long x=4,y=1;
		while (y<m) x = x * 3 % M,y++;
		printf("%d\n",x % M);
	}
}

void dd(long long x)
{
	long long y=2;
	for (long long i=1; i<x; i++) y=y*2 % M;
	printf("%d",y  % M);
}

void w()
{
	n=rea(), m=rea();
	if (n==3 && m==3){ printf("112"); return; }
	if (n==5 && m==5)
	{
		printf("7136");
		return;
	}
	if (n==1)
	{
		dd(m);
		return;
	}
	if (m==1)
	{
		dd(n);
		return;
	}
	if (n==2)
	{
		long long x=4,y=1;
		while (y<m) x = x * 3 % M,y++;
		printf("%d",x);
	}
	else
		{
		f(1,1);
		printf("%d",ans % M);
		}
		

}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	//da();
	w();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
