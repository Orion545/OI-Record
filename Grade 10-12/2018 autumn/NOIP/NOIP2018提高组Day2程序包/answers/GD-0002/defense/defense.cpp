#include <cstdio>
#include <cstring>
#define maxn 300010
#define ll long long

int n,m,len=0;
char s[5];
int w[maxn];
struct node{int x,y,next;};
node e[maxn*2];
int first[maxn];
ll f[maxn][2];
ll minn(ll x,ll y){return x<y?x:y;}
void buildroad(int x,int y)
{
	len++;
	e[len].x=x;
	e[len].y=y;
	e[len].next=first[x];
	first[x]=len;
}
int a[2][2];
void dp(int x,int fa)
{
	f[x][0]=0ll;f[x][1]=(ll)w[x];
	for(int i=first[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		dp(y,x);
		if(y==a[0][0])
		{
			if(a[0][1]==0)
			{
				f[x][0]=999999999999ll;
				f[x][1]+=f[y][0];
			}
			else
			{
				f[x][0]+=f[y][1];
				f[x][1]+=f[y][1];
			}
		}
		else if(y==a[1][0])
		{
			if(a[1][1]==0)
			{
				f[x][0]=999999999999ll;
				f[x][1]+=f[y][0];
			}
			else
			{
				f[x][0]+=f[y][1];
				f[x][1]+=f[y][1];
			}
		}
		else
		{
			f[x][0]+=f[y][1];
			f[x][1]+=minn(f[y][0],f[y][1]);
		}
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		buildroad(x,y);
		buildroad(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&a[0][0],&a[0][1],&a[1][0],&a[1][1]);
		if(a[0][1]==0&&a[1][1]==0)
		{
			bool tf=true;
			for(int j=first[a[0][0]];j;j=e[j].next)
			if(e[j].y==a[1][0])
			{
				tf=false;
				break;
			}
			if(!tf)
			{
				printf("-1\n");
				continue;
			}
		}
		dp(1,0);
		printf("%lld\n",minn(f[1][0],f[1][1]));
	}
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/
