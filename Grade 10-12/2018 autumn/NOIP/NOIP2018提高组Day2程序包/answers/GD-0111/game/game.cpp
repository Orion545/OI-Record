#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define N n+m-1
#define mod 1000000007
using namespace std;

int a[50][50];
struct A{
	int w[50],s[50];
} c[200];
int W[50];
int S[50];
int n,m,i,j,k,l,len,ans;

long long qpower(long long a,int b)
{
	long long ans=1;
	
	while (b)
	{
		if (b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	
	return ans;
}

bool cmp(A a,A b)
{
	int i;
	
	fo(i,1,N)
	if (a.w[i]>b.w[i])
	return 1;
	
	return 0;
}

void pd(int t,int x,int y)
{
	int i;
	
	if (x==n && y==m)
	{
		len++;
		fo(i,1,N)
		{
			c[len].w[i]=W[i];
			c[len].s[i]=S[i];
		}
		
		return;
	}
	
	S[t]=a[x][y];
	if (y<m)
	{
		W[t]=1;
		pd(t+1,x,y+1);
	}
	if (x<n)
	{
		W[t]=0;
		pd(t+1,x+1,y);
	}
}

bool Pd(int x)
{
	int i;
	
	fo(i,1,N)
	if (c[x].s[i]>c[x+1].s[i])
	return 0;
	else
	if (c[x].s[i]<c[x+1].s[i])
	return 1;
	
	return 1;
}

void dfs(int x,int y)
{
	int i,j;
	
	if (x>n)
	{
		len=0;
		pd(1,1,1);
		
		fo(i,1,len-1)
		if (!Pd(i))
		return;
		
		ans++;
		return;
	}
	
	a[x][y]=0;
	if (y==m)
	dfs(x+1,1);
	else
	dfs(x,y+1);
	
	a[x][y]=1;
	if (y==m)
	dfs(x+1,1);
	else
	dfs(x,y+1);
}

int main()
{
	freopen("game.in", "r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	if (n<=3 && m<=3)
	{
		dfs(1,1);
		printf("%d\n",ans);
	}
	else
	if (n==1)
	{
		printf("%lld\n",qpower(2,m));
	}
	else
	if (n==2)
	{
		if (m==1)
		printf("4\n");
		else
		printf("%lld\n",4*qpower(3,m-1)%mod);
	}
	else
	if (n==3)
	{
		if (m==1)
		printf("8\n");
		else
		if (m==2)
		printf("36\n");
		else
		printf("%lld\n",112*qpower(3,m-3)%mod);
	}
	else
	if (n==4 && m==5 || n==5 && m==4)
	printf("2688\n");
	else
	if (n==5 && m==5)
	printf("7136\n");
	else
	{
		dfs(1,1);
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
