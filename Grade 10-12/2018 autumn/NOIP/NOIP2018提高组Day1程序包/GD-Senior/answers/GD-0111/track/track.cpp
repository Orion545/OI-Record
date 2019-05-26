#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int a[100001][3];
int b[50001];
struct C{
	int x,s;
} c[50001];
int d[50001];
int ls[50001];
int f[1001][1001];
int n,m,i,j,k,l,r,mid,len,mx,mx2,ans,root,L,R,Mid;
bool BZ1,BZ2,bz;

bool cmp(C a,C b)
{
	return a.x<b.x;
}

void New(int x,int y,int z)
{
	len++;
	a[len][0]=y;
	a[len][1]=z;
	a[len][2]=ls[x];
	ls[x]=len;
}

void dfs(int fa,int t,int sum)
{
	int i;
	
	if (sum>mx)
	{
		mx=sum;
		mx2=t;
	}
	
	for (i=ls[t]; i; i=a[i][2])
	if (a[i][0]!=fa)
	dfs(t,a[i][0],sum+a[i][1]);
}

bool pd(int t)
{
	int i,sum,tot=0;
	
	sum=0;
	fo(i,1,n)
	{
		sum+=c[i].s;
		
		if (sum>=t)
		{
			sum=0;
			++tot;
			
			if (tot>=m) return 1;
		}
	}
	
	return 0;
}

void dfs(int fa,int t)
{
	int i,j,son0=0,son1=0,s0,s1;
	
	f[t][0]=0;
	
	for (i=ls[t]; i; i=a[i][2])
	if (a[i][0]!=fa)
	{
		dfs(t,a[i][0]);
		
		if (!son0)
		son0=a[i][0],s0=a[i][1];
		else
		son1=a[i][0],s1=a[i][1];
	}
	
	fo(i,0,m)
	if (f[son0][i]>=0)
	{
		fo(j,0,m-i)
		if (f[son1][j]>=0)
		{
			if (f[son0][i]+s0>=Mid && f[son1][j]+s1>=Mid)
			f[t][i+j+2]=max(f[t][i+j+2],0);
			
			if (f[son0][i]+s0>=Mid)
			f[t][i+j+1]=max(f[t][i+j+1],f[son1][j]+s1);
			if (f[son1][j]+s1>=Mid)
			f[t][i+j+1]=max(f[t][i+j+1],f[son0][i]+s0);
			
			if (f[son0][i]+s0+f[son1][j]+s1>=Mid)
			f[t][i+j]=max(f[t][i+j],0);
		}
		else
		break;
	}
	else
	break;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	BZ1=1;BZ2=1;
	
	scanf("%d%d",&n,&m);
	fo(i,2,n)
	{
		scanf("%d%d%d",&j,&k,&l);
		b[i-1]=l;
		c[i-1].x=j;
		c[i-1].s=l;
		
		++d[j];++d[k];
		
		if (j!=1) BZ1=0;
		if (k!=j+1) BZ2=0;
		
		New(j,k,l);
		New(k,j,l);
	}
	
	if (m==1)
	{
		ans=-1;
		mx=0;
		mx2=1;
		while (ans<mx)
		{
			ans=mx;
			dfs(0,mx2,0);
		}
		
		printf("%d\n",ans);
	}
	else
	if (BZ1)
	{
		ans=233333333;
		--n;
		sort(b+1,b+n+1);
		
		if (m*2>n)
		{
			j=1;
			while (m*2>n)
			{
				ans=min(ans,b[n]);
				m--;n--;
			}
		}
		else
		if (m*2<n)
		j=n-m*2+1;
		
		k=n;
		fo(i,j,n)
		{
			ans=min(ans,b[i]+b[k]);
			--k;
		}
		printf("%d\n",ans);
	}
	else
	if (BZ2)
	{
		--n;
		sort(c+1,c+n+1,cmp);
		
		l=1;
		r=500000000;
		while (l<r)
		{
			mid=(l+r)/2;
			
			if (pd(mid))
			l=mid+1;
			else
			r=mid;
		}
		if (!pd(l)) l--;
		
		printf("%d\n",l);
	}
	else
	{
		fo(root,1,n)
		if (d[root]==1)
		break;
		
		L=1;
		R=500000000;
		while (l<r)
		{
			memset(f,255,sizeof(f));
			
			Mid=(l+r)/2;
			dfs(0,root);
			
			bz=0;
			fo(i,m,n-1)
			if (f[root][i]>=0)
			{
				bz=1;
				break;
			}
			
			if (bz)
			L=Mid+1;
			else
			R=Mid;
		}
		
		memset(f,255,sizeof(f));
		Mid=L;
		dfs(0,root);
		
		bz=0;
		fo(i,m,n-1)
		if (f[root][i]>=0)
		{
			bz=1;
			break;
		}
		if (!bz) Mid--;
		
		printf("%d\n",Mid);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
