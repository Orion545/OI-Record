#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{int x,y,t,next,other;}a[200010];
int q[50010];
int n,m;
int len=0;
int ans=0,tot;
int maxx=0,minn=999999999,maxxx=0;
int first[50010];
bool tf[100010],v[50010],ttff=true;

bool cmp(int x,int y)
{
	return x>y?1:0;
}

void ins(int x,int y,int t)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].t=t;
	a[len].next=first[x];first[x]=len;
	
	len++;
	a[len].x=y;a[len].y=x;a[len].t=t;
	a[len].next=first[y];first[y]=len;
	
	a[len].other=len-1;
	a[len-1].other=len;
}

void dfs(int x,int t,int d,int td)
{
//	printf("x:%d t:%d d:%d td:%d\n",x,t,d,td);
	v[x]=false;
	if(t>=d)
	{
		if(td+1>tot)tot=td+1;
		if(tot>=m)return;
		int txf=0;
		for(int i=1;i<=n && txf==0;i++)
		if(v[i]==true)txf=i;
		dfs(txf,0,d,td+1);
		return;
	}
	for(int i=first[x];i;i=a[i].next)
	if(tf[i]==true)
	{
//		printf("i.x:%d i.y:%d i.t:%d\n",a[i].x,a[i].y,a[i].t);
		int y=a[i].y;
		tf[i]=tf[a[i].other]=false;
		dfs(y,t+a[i].t,d,td);
		tf[i]=tf[a[i].other]=true;
		if(tot>=m)return;
	}
}

bool pd(int txx)
{
//	printf("txx:%d\n",txx);
	tot=0;
	for(int i=1;i<=n;i++)
	{
		memset(v,true,sizeof(v));
		memset(tf,true,sizeof(tf));
		dfs(i,0,txx,0);
//		printf("\n");
	}
	if(tot>=m)return true;
	else return false;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		q[i]=t;
		if(x!=1)ttff=false;
		maxxx+=t;
		maxx=maxx>t?maxx:t;
		minn=minn<t?minn:t;
		ins(x,y,t);
	}
	if(n-1==m)
	{
		printf("%d",minn);
		return 0;
	}
	if(ttff)
	{
		sort(q+1,q+n+1,cmp);
		int mmin=999999999;
		for(int i=1;i<=m;i++)
		mmin=mmin<(q[i]+q[m*2-i+1])?mmin:(q[i]+q[m*2-i+1]);
		printf("%d",mmin);
		return 0;
	}
	int l=minn,r=maxxx;
//	printf("l:%d r:%d\n",l,r);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(pd(mid))
		{
			ans=mid;
			l=mid+1;	
		}
		else r=mid-1;
	}
	printf("%d",ans);
}
/*
7 3
1 2 10
1 3 5
1 4 6
1 5 3
1 6 9
1 7 11
*/
