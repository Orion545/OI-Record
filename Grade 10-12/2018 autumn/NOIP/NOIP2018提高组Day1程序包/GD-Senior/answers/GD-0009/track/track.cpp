#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 50000+200
#define inf 1e9
int n,m,ans,tot,mt,mf,tw;
int ar[N][10],aw[N],aww[N];
int last[N],pre[2*N],link[2*N],val[2*N],fa[N],cl[N],ru[20];
bool b1,b2;
void mlink(int x,int y,int z)
{
	pre[++tot]=last[x],last[x]=tot,link[tot]=y,val[tot]=z;
}
int get(int x)
{
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	int fx=get(x),fy=get(y);
	if(fx!=fy)
		fa[fx]=fy;
}
void dfs(int x)
{
	if(x>n-1)
	{
		int cnt=inf;
		
		for(int i=1;i<=m;i++)
		{
			memset(ru,0,sizeof(ru));
			for(int j=1;j<=n-1;j++)
				fa[j]=j;
			int val=0,fx;
			for(int j=1;j<=n-1;j++)
				if(cl[j]==i)
					merge(ar[j][0],ar[j][1]),fx=get(ar[j][0]),ru[ar[j][0]]++,ru[ar[j][1]]++;
			for(int j=1;j<=n-1;j++)
				if(cl[j]==i)
				{
					if(get(ar[j][0])!=fx||get(ar[j][1])!=fx||ru[ar[j][0]]>=3||ru[ar[j][1]]>=3)
						return;
					val+=ar[j][2];
				}	
			cnt=min(cnt,val);
		}
		ans=max(ans,cnt);
		return;
	}
	for(int i=0;i<=m;i++)
	{
		cl[x]=i;
		dfs(x+1);
	}
}
void find (int x,int las,int cc)
{
	if(cc>mt)
		mt=cc,mf=x;
	for(int i=last[x];i;i=pre[i])
	{
		if(link[i]==las)
			continue;
		find(link[i],x,cc+val[i]);
	}
}
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		mlink(x,y,z),mlink(y,x,z);
		if(x!=1)b1=1;
		if(y!=x+1)b2=1;
		ar[i][0]=x,ar[i][1]=y,ar[i][2]=z;
		aw[i]=z;
	}
	if(n<=15)
	{
		dfs(1);
		printf("%d\n",ans);
		return 0;
	}
	if(m==1)
	{
		find(1,0,0);
		mt=0;
		find(mf,0,0);
		printf("%d\n",mt);
		return 0;
	}
	if(!b1)
	{
		sort(aw+1,aw+n,cmp);
		ans=inf;
		for(int i=m+1;i<=min(n-1,2*m);i++)
			aww[++tw]=aw[i];
		for(int i=1;i<=tw;i++)
			ans=min(ans,aw[m-i+1]+aww[i]);
		for(int i=1;i<=m-tw;i++)
			ans=min(ans,aw[i]);
		printf("%d\n",ans);
		return 0;
	}
	
	
}

