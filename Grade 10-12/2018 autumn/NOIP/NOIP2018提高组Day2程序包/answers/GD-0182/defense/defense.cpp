#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{int x,y,next;}a[20010];
struct node1{int x,y,a,b;}b[100010];
int n,m;
char s[11];
int f[100010][2];
int q[100010];
int first[100010];
bool tf[100010];
bool v[100010];
int ans[100010];
int len=0,l=0,le=0;

void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=first[x];first[x]=len;
}

int dfs(int x,int t,int d)
{
	int tot=0,minf=9999999;
	for(int i=first[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(tf[y]==true)
		{
			if(q[y]==-1)
			{
				tf[y]=false;
				q[y]=1;le++;
				minf=dfs(y,1,t);
				le--;
				if(t==1)
				{
					q[y]=0;tf[y]=false;
					le++;
					int ttf=dfs(y,0,t);
					le--;
					if(ttf<minf)minf=ttf;
				}
				tot+=minf;
				tf[y]=true;
			}
			else 
			{
				tf[y]=false;
				le++;
				if(q[y]==0 && d==0)return 999999999;
				minf=dfs(y,q[y],t);
			}
		}
	}
	if(t==1)
	f[x][t]=q[x]+tot;
	else f[x][t]=tot;
	return f[x][t];
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(first,0,sizeof(first));
	memset(v,false,sizeof(v));
	memset(ans,0,sizeof(ans));
	memset(tf,true,sizeof(tf));
	scanf("%d %d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++)q[i]=-1;
	for(int i=1;i<=n;i++)
	scanf("%d",&q[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&b[i].a,&b[i].x,&b[i].b,&b[i].y);q[b[i].a]=b[i].x;q[b[i].b]=b[i].y;
		if(s[2]=='2' && b[i].x==0 && b[i].y==0)ans[i]=-1,v[i]=true,l++;
		else
		{
			tf[b[i].a]=false;
			ans[i]=dfs(b[i].a,b[i].x,2);
		}
	}
	for(int i=1;i<=m;i++)
	printf("%d\n",ans[i]);
}
