#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char ch;
void read(int&n)
{
	for(ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for(n=0;'0'<=ch && ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
}
const int mo=1000000007;
int n,m,nn,mm,p;
long long f[10][260],ans;
int tot,a[10000],b[10000];
int nxt[256*256],to[256*256],lst[256*256],l,s;
void dfs(int x,int y,int s,int t)
{
	if(x>n || y>m)return;
	if(x==n && y==m)
	{
		a[++tot]=s;b[tot]=t;
		return;
	}
	dfs(x+1,y,(s<<1),(t<<1)+f[x][y]);
	dfs(x,y+1,(s<<1)+1,(t<<1)+f[x][y]);
	
}
bool check()
{
	tot=0;
	dfs(1,1,0,f[1][1]);
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=tot;j++)
			if(a[i]>a[j] && b[i]>b[j])return 0;
	return 1;
}
void ins(int x,int y)
{
	nxt[++l]=lst[x];
	to[l]=y;lst[x]=l;
}
void dg(int x,int y)
{
	if(x>n)x=1,y++;
	if(y>m)
	{
		if(check())
		{
			int s1=0,s2=0;
			for(int i=1;i<=m;i++)
				s1=(s1<<1)+f[1][i],s2=(s2<<1)+f[2][i];
			ins(s2,s1);
		}
		return;
	}
	if(x>1 && y>1 && f[x-1][y]>f[x][y-1])return;
	f[x][y]=0;
	dg(x+1,y);
	f[x][y]=1;
	dg(x+1,y);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);read(m);
	if(n==2)
	{
		for(int i=0;i<4;i++)f[0][i]=1;p=0;
		for(int i=2;i<=m;i++)
		{
			p=1^p;
			f[p][0]=(f[p^1][0]+f[p^1][1]+f[p^1][2]+f[p^1][3])%mo;
			f[p][1]=(f[p^1][0]+f[p^1][1]+f[p^1][2]+f[p^1][3])%mo;
			f[p][2]=(f[p^1][1]+f[p^1][3])%mo;
			f[p][3]=(f[p^1][1]+f[p^1][3])%mo;
		}
		ans=(f[p][0]+f[p][1]+f[p][2]+f[p][3])%mo;
	}
	else
	if(n<8 && m<8)
	{
		dg(1,1);ans=l;
	}
	else
	{
		nn=n;mm=m;
		n=2;m=n;
		dg(1,1);
		s=(1<<nn);memset(f,0,sizeof(f));
		for(int i=0;i<s;i++)f[0][i]=1;
		for(int i=2;i<=mm;i++)
		{
			p=p^1;
			memset(f[p],0,sizeof(f[p]));
			for(int j=0;j<s;j++)
				for(int k=lst[j];k;k=nxt[k])
					f[p][j]=(f[p][j]+f[p^1][to[k]]);
		}
		for(int i=0;i<s;i++)ans=(ans+f[p][i])%mo;
	}
	printf("%lld",ans%mo);
}
