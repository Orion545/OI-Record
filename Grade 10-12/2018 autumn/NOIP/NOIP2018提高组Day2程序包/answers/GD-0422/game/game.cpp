#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int Maxn=9;
const int Maxm=100010;
const int mod=1000000007;
int Pow(int x,int y)
{
	if(!y)return 1;
	if(y==1)return x;
	int t=Pow(x,y>>1),re=(LL)t*t%mod;
	if(y&1)re=(LL)re*x%mod;
	return re;
}
void upd(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int n,m,a[Maxn][9],ans=0;
struct Node
{
	int b[20],c[20];
}p[Maxm];int lp;
int bb[Maxm],cc[Maxm];
void dfs1(int x,int y,int z)
{
	bb[z]=a[x][y];
	if(x==n&&y==m)
	{
		lp++;
		for(int i=1;i<=n+m-1;i++)p[lp].b[i]=bb[i];
		for(int i=1;i<=n+m;i++)p[lp].c[i]=cc[i];
		return;
	}
	if(y<m)
	{
		cc[z]=1;
		dfs1(x,y+1,z+1);
	}
	if(x<n)
	{
		cc[z]=0;
		dfs1(x+1,y,z+1);
	}
}
bool pd(Node x,Node y)
{
	bool is=false;
	for(int i=1;i<=n+m-2;i++)
	if(x.c[i]!=y.c[i])
	{
		is=(x.c[i]>y.c[i]);
		break;
	}
	if(!is)return false;
	is=false;
	for(int i=1;i<=n+m-1;i++)
	if(x.b[i]!=y.b[i])
	{
		is=(x.b[i]>y.b[i]);
		break;
	}
	return is;
}
bool check()
{
	lp=0;
	dfs1(1,1,1);
	for(int i=1;i<=lp;i++)
	for(int j=1;j<=lp;j++)
	if(i!=j&&pd(p[i],p[j]))return false;
	return true;
}
void dfs(int x,int y)
{
	if(x==n+1)
	{
		if(check())ans++;
		return;
	}
	a[x][y]=1;
	if(y==m)dfs(x+1,1);
	else dfs(x,y+1);
	a[x][y]=0;
	if(y==m)dfs(x+1,1);
	else dfs(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	if(n==1){printf("%d",Pow(2,m));return 0;}
	if(n==2){printf("%d",(LL)Pow(3,m-1)*4LL%mod);return 0;}
	if(n<=3&&m<=3)
	{
		dfs(1,1);
		printf("%d",ans);
		return 0;
	}
	printf("0");
	/*memset(f,0,sizeof(f));//0 tong
	f[0][0][1]=6;f[0][1][1]=2;f[1][0][1]=2;f[1][1][1]=1;
	for(int i=2;i<=m-2;i++)
	{
		upd(f[0][0][i],(f[0][0][i-1]+f[1][0][i-1])%mod);
	}*/
}
