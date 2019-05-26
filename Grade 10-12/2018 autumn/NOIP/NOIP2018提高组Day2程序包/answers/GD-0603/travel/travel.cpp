#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
using namespace std;
typedef long long ll;
typedef double db;
const int N=5005;
struct rec
{
	int x,y;
	rec(int x0=0,int y0=0){x=x0,y=y0;}
}b[N][N];
int tb[N],ta[N],a[N],n,m,i,j,k,x,y,ban,pd[N];
bool operator <(rec a,rec b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
void cpy(int *X,int *Y)
{
	int i;
	fo(i,1,n) Y[i]=X[i];
}
int cmp(int *X,int *Y) // X<Y return true
{
	int i;
	fo(i,1,n) if (X[i]!=Y[i])
		return X[i]<Y[i];
	return 0;
}
void go(int x)
{
	ta[++ta[0]]=x;
	pd[x]=ban;
	int p;
	fo(p,1,tb[x])
		if (pd[b[x][p].x]!=ban&&b[x][p].y!=ban)
			go(b[x][p].x);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	fo(i,1,m)
	{
		scanf("%d %d",&x,&y);
		b[x][++tb[x]]=rec(y,i);
		b[y][++tb[y]]=rec(x,i);
	}
	fo(i,1,n) sort(b[i]+1,b[i]+1+tb[i]);
	if (m==n-1)
	{
		ban=m+1;
		ta[0]=0;
		go(1);
		cpy(ta,a);
	}else
	{
		fo(i,1,n) a[i]=n;
		fo(ban,1,m)
		{
			ta[0]=0;
			go(1);
			if (ta[0]==n&&cmp(ta,a)) 
				cpy(ta,a);
		}
	}
	fo(i,1,n) printf("%d ",a[i]);
}
