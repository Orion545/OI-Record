#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,c,next;
}a[110000];int len,last[51000];
int l[51000];
bool cmp(int n1,int n2)
{
	return n1>n2;
}
void ins(int x,int y,int c)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
int fa[51000],ans=0;
int maxx[51000],cmax[51000];
void dfs(int x)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa[x])
		{
			fa[y]=x;
			dfs(y);
			if(maxx[y]+a[k].c>=maxx[x])
			{
				cmax[x]=maxx[x];
				maxx[x]=maxx[y]+a[k].c;
			}
			else if(maxx[y]+a[k].c>cmax[x])cmax[x]=maxx[y]+a[k].c;
		}
	}
	if(maxx[x]+cmax[x]>ans)ans=maxx[x]+cmax[x];
}
int s[1100],sum[1100];
int f[1100][1100];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,dd=0;
	bool bk1=false,bk2=true,bk3=true;
	scanf("%d%d",&n,&m);if(m==1)bk1=true;
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);s[y]=c;
		ins(x,y,c);ins(y,x,c);dd=max(dd,c);
		l[i]=c;
		if(x!=1)bk2=false;
		if(y!=x+1)bk3=false;
	}
	if(bk1==true)
	{
		memset(maxx,0,sizeof(maxx));
		memset(cmax,0,sizeof(cmax));
		dfs(1);
		printf("%d\n",ans);
	}
	else if(bk2==true)
	{
		sort(l+1,l+n,cmp);
		int x=m+1;
		for(int i=m;i>=1;i--)
		{
			if(x==n)break;
			l[i]+=l[x];
			x++;
		}
		int minn=l[1];
		for(int i=1;i<=m;i++)minn=min(minn,l[i]);
		printf("%d\n",minn);
	}
	else if(bk3==true)
	{
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i];
		memset(f,0,sizeof(f));f[1][0]=999999999;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=i-1;k>=1;k--)
				{
					f[i][j]=max(f[i][j],min(f[k][j-1],sum[i]-sum[k]));
				}
			}
		}
		printf("%d\n",f[n][m]);
	}
	else printf("%d\n",dd);
	return 0;
}
