#include <iostream>
#include <cstdlib>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int a[200002][2];
int ls[100002];
long long p[100002];
long long f[100002];
long long g[100002];
long long F[100002];
long long G[100002];
long long ans,F2;
int n,m,i,j,k,l,len,x1,y1,x2,y2;
char ch,t1,t2;

void New(int x,int y)
{
	len++;
	a[len][0]=y;
	a[len][1]=ls[x];
	ls[x]=len;
}

void swap(int &x,int &y)
{
	int z=x;
	x=y;
	y=z;
}

void dfs(int fa,int t)
{
	int i;
	
	f[t]=0;
	g[t]=0;
	
	for (i=ls[t]; i; i=a[i][1])
	if (a[i][0]!=fa)
	{
		dfs(t,a[i][0]);
		
		if (a[i][0]==x2)
		{
			if (!y2)
			{
				f[t]+=g[a[i][0]];
				g[t]=17179869184;
			}
			else
			{
				f[t]+=f[a[i][0]];
				g[t]+=f[a[i][0]];
			}
		}
		else
		{
			f[t]+=min(f[a[i][0]],g[a[i][0]]);
			g[t]+=f[a[i][0]];
		}
	}
	f[t]+=p[t];
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d%c%c%c",&n,&m,&ch,&t1,&t2);
	fo(i,1,n)
	scanf("%lld",&p[i]);
	fo(i,2,n)
	{
		scanf("%d%d",&j,&k);
		
		New(j,k);
		New(k,j);
	}
	
	if (t1=='A' && t2=='1')
	{
		f[1]=p[1];
		g[1]=17179869184;
		fo(i,2,n)
		{
			f[i]=min(g[i-1],f[i-1])+p[i];
			g[i]=f[i-1];
		}
		fd(i,n,2)
		{
			F[i]=min(G[i+1],F[i+1])+p[i];
			G[i]=F[i+1];
		}
		F[1]=min(G[2],F[2])+p[1];
		G[1]=17179869184;
		
		fo(i,1,m)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			
			if (!y2)
			ans=f[x2-1]+F[x2+1];
			else
			ans=min(g[x2-1],f[x2-1])+min(G[x2+1],F[x2+1])+p[x2];
			
			printf("%lld\n",ans);
		}
	}
	else
	if (t1=='A' && t2=='2')
	{
		fo(i,1,n)
		{
			f[i]=min(g[i-1],f[i-1])+p[i];
			g[i]=f[i-1];
		}
		fd(i,n,1)
		{
			F[i]=min(G[i+1],F[i+1])+p[i];
			G[i]=F[i+1];
		}
		
		fo(i,1,m)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			
			if (x1>x2)
			{
				swap(x1,x2);
				swap(y1,y2);
			}
			
			if (!y1)
			{
				if (!y2)
				ans=-1;
				else
				ans=f[x1-1]+min(G[x2+1],F[x2+1])+p[x2];
			}
			else
			{
				if (!y2)
				ans=min(g[x1-1],f[x1-1])+p[x1]+F[x2+1];
				else
				{
					F2=min(G[x2+1],F[x2+1])+p[x2];
					ans=min(g[x1-1],f[x1-1])+F2+p[x1];
				}
			}
			
			printf("%lld\n",ans);
		}
	}
	else
	{
		fo(i,1,m)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			dfs(0,x1);
			
			if (!y1)
			printf("%lld\n",(g[x1]>=17179869184)?-1:g[x1]);
			else
			printf("%lld\n",f[x1]);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
