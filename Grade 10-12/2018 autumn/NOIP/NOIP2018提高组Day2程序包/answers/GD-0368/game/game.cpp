#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

const long long mo=1e9+7;

int b[11],n,m,q;

long long a[256][256],g[256][256],f[256],c[256],ans;

void dg(int x,int t,int y)
{	
	if(t>n)
	{
		a[x][y]++;
		return;
	}
	
	if(b[t+1])dg(x,t+1,y+(1<<(t-1)));
	
	dg(x,t+1,y);
}

void get()
{
	memset(c,0,sizeof(c));
	for(int j=0;j<q;j++)
		for(int k=0;k<q;k++)
			c[j]=(c[j]+f[k]*a[k][j])%mo;
	
	memcpy(f,c,sizeof(f));
}

void go()
{
	memset(g,0,sizeof(g));
	for(int i=0;i<q;i++)
		for(int j=0;j<q;j++)
			for(int k=0;k<q;k++)
				g[i][j]=(g[i][j]+a[i][k]*a[k][j])%mo;
	
	memcpy(a,g,sizeof(a));
}

void pow()
{
	m--;
	for(;m;m/=2)
	{
		if(m%2)get();
		
		go();
	}
}


int pd()
{
	for(int i=2;i<=n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]<a[i-1][j+1])return 0;
	
	for(int i=3;i<=n;i++)
		for(int j=2;j<m;j++)
			if((a[i-1][j-1]==a[i-2][j])&&(a[i][j]>a[i-1][j+1]))return 0;
	
	return 1;
}

void dg1(int x,int y)
{
	if(x>n)
	{
		if(pd())ans++;
		return;
	}
	
	a[x][y]=1;
	dg1(x+y/m,y%m+1);
	a[x][y]=0;
	dg1(x+y/m,y%m+1);
}


int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	if(n==2)
	{
		memset(a,0,sizeof(a));
		q=1<<n;
		for(int i=0;i<q;i++)
		{
			memset(b,0,sizeof(b));
			for(int j=i,k=1;j;k++,j/=2)
				b[k]=j%2;
			b[n+1]=1;
		
			dg(i,1,0);
		}
		
		for(int i=0;i<q;i++)
			f[i]=1;
		pow();
		
		ans=0;
		for(int i=0;i<q;i++)
			ans=(ans+f[i])%mo;
		
		printf("%lld\n",ans);
		
		return 0;
	}
	
	if(n==3)
	{	
		scanf("%d%d",&n,&m);
		
		ans=0;
		dg1(1,1);
		
		printf("%d\n",ans);
		
		return 0;
	}
}
