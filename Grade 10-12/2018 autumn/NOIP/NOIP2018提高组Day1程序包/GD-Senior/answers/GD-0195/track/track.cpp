#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define MAXN 51000 
using namespace std;
struct node
{
	int x,y,c,next;
}a[MAXN*2];int len,last[MAXN];
void ins(int x,int y,int z)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].c=z;
	a[len].next=last[x];last[x]=len;
	return ;
}
int n,m;
int d[MAXN];
void w1_dfs(int x)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(d[y]==-1)
		{
			d[y]=d[x]+a[k].c;
			w1_dfs(y);
		}
	}
	return ;
}
void work1()
{
	memset(d,-1,sizeof(d));d[1]=0;
	w1_dfs(1);
	int x=0,y=1;
	for(int i=1;i<=n;i++)
		if(d[i]>x)
		{
			x=d[i];
			y=i;
		}
	memset(d,-1,sizeof(d));d[y]=0;
	w1_dfs(y);
	x=0;
	for(int i=1;i<=n;i++)
		if(d[i]>x)x=d[i];
	printf("%d\n",x);
	return ;
}
int b[MAXN];
bool w2_cmp(node x,node y)
{
	return x.c>y.c;
}
void work2()
{
	sort(a+1,a+len+1,w2_cmp);
	for(int i=1;i<=len;i+=2)b[(i-1)/2+1]=a[i].c;
	if(m<=(n-1)/2)
	{
		int ans=inf;
		for(int i=1;i<=m;i++)ans=min(ans,b[i]+b[m*2-i+1]);
		printf("%d\n",ans);
	}
	else
	{
		int ans=inf,now=0;
		while( !(m-now<=(n-1)/2) )
			ans=min(ans,b[++now]);
		for(int i=1;i<=n-now;i++)b[i]=b[i+now];
		for(int i=1;i<=(n-1-now)/2;i++)ans=min(ans,b[i]+b[(n-1-now)-i+1]);
		printf("%d\n",ans);
	}
	return ;
}
struct mt
{
	int x,y;
	mt()
	{
		x=y=inf;
	}
	mt(int x,int y)
	{
		this->x=x;this->y=y;
	}
}e[MAXN][2];
void work3()
{
	sort(a+1,a+len+1,w2_cmp);
	for(int i=1;i<=len;i+=2)b[(i-1)/2+1]=a[i].c;
	/*e[0][0]=mt(0,0);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-1-i;j++)
		{
			
		}
	}*/
	int ans=inf;
	for(int i=1;i<=n-1;i++)ans=min(ans,b[i]);
	printf("%d\n",ans);
	return ;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool w2=true,w3=true;
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		ins(x,y,z);ins(y,x,z);
		if(x!=1)w2=false;
		if(y!=x+1)w3=false;
	}
	if(m==1)
	{
		work1();
		return 0;
	}
	if(w2)
	{
		work2();
		return 0;
	}
	if(w3)
	{
		work3();
		return 0;	
	}
	return 0;
}
