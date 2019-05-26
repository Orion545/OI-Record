#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define N 1001000
#define M 258
#define mo 1000000007
using namespace std;
int n,m,a[M][M],b[N],ans=0;
void dg2(int x,int y,int z)
{
	if(x==n&&y==m)
	{
		b[++b[0]]=z;
		return;
	}
	if(x>n) return;
	if(y>m) return;
	dg2(x+1,y,z*2+a[x+1][y]);
	dg2(x,y+1,z*2+a[x][y+1]);
}
bool pd()
{
	b[0]=0;
	dg2(1,1,0);
	fo(i,2,b[0]) if(b[i]<b[i-1]) return 0;
	return 1;
}
void dg(int x,int y)
{
	if(x>n)
	{
		dg(1,y+1);
		return;
	}
	if(y>m)
	{
		if(pd()) ans++;
		return;
	}
	a[x][y]=1;
	dg(x+1,y);
	a[x][y]=0;
	dg(x+1,y);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	dg(1,1);
	printf("%d\n",ans);
}
