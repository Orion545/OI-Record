#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

struct node
{
	int x,y,next;
}e[11000],u[11000];int elen,elast[5100],ulen,ulast[5100];
void eins(int x,int y)
{
	elen++;
	e[elen].x=x;e[elen].y=y;
	e[elen].next=elast[x];elast[x]=elen;
}
void uins(int x,int y)
{
	ulen++;
	u[ulen].x=x;u[ulen].y=y;
	u[ulen].next=ulast[x];ulast[x]=ulen;
}

//-------------------------init----------------------------------------------------------------------------

int len,a[5100],b[51000],dx,dy;
bool check(int x,int y){return ((x==dx&&y==dy)||(y==dx&&x==dy));}
void dfs(int x,int fr)
{
	a[++len]=x;
	for(int k=ulast[x];k;k=u[k].next)
	{
		int y=u[k].y;
		if(y!=fr&&!check(x,y))
		dfs(y,x);
	}
}
int L,R,fr[51000];bool v[51000];
bool gofind(int x)
{
	for(int k=ulast[x];k;k=u[k].next)
	{
		int y=u[k].y;
		if(y!=fr[x])
		{
			if(v[y]==true)
			{
				L=y;
				R=x;
				return true;
			}
			else
			{
				v[y]=true;fr[y]=x;
				if(gofind(y))return true;
			}
		}
	}
	return false;
}

//--------------------findans-----------------------------------------------------------------

int z,p[5100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	elen=0;memset(elast,0,sizeof(elast));
	ulen=0;memset(ulast,0,sizeof(ulast));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		eins(x,y),eins(y,x);
	}
	for(x=1;x<=n;x++)
	{
		z=0;
		for(int k=elast[x];k;k=e[k].next)p[++z]=e[k].y;
		sort(p+1,p+z+1);
		for(int i=z;i>=1;i--)uins(x,p[i]);
	}
	
	if(m==n-1)
	{
		dx=0,dy=0;
		len=0;dfs(1,0);
		for(int i=1;i<n;i++)printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	else
	{
		fr[1]=0;
		memset(v,false,sizeof(v));
		gofind(1);
		
		memset(b,63,sizeof(b));
		for(dx=R,dy=fr[dx];dx!=L;dx=dy,dy=fr[dx])
		{
			len=0;dfs(1,0);
			bool flag=false;
			for(int i=1;i<=n;i++)
				if(a[i]<b[i]){flag=true;break;}
				else if(a[i]>b[i]){break;}
			if(flag==true)
			{
				for(int i=1;i<=n;i++)b[i]=a[i];
			}
		}

		for(int i=1;i<n;i++)printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
}
