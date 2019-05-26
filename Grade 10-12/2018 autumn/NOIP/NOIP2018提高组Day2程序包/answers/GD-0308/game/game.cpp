#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define bfo(i,v,u) for(int i=BB[v],u=B[i][1];i;u=B[i=B[i][0]][1])
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int read()
{
	char ch;int n=0,p=1;
	for(ch=getchar();ch<'0' || '9'<ch;ch=getchar()) if(ch=='-') p=-1;
	for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';
	return n*p;
}
const int N=10,MXS=260,mo=1e9+7;
ll qmi(ll x,ll n)
{
	ll t=1;
	for(;n;n>>=1,x=x*x%mo) if(n&1) t=t*x%mo;
	return t;
}
int n,m,S,ans,trs[MXS][MXS],A[MXS],B[MXS],tmp[MXS][MXS];
int map[10][10];
int a[20],num,b[1000000][20];
void dg(int x,int y)
{
	a[x+y-1]=map[x][y];
	if(x==n && y==m)
	{
		++num;
		fo(i,1,n+m-1) b[num][i]=a[i];
		return;
	}
	if(y<m) dg(x,y+1);
	if(x<n) dg(x+1,y);
}
void dfs(int x,int y)
{
	if(x>n)
	{
		bool q=1;
		fo(j,2,m)
			fo(i,2,n) if(!map[i][j-1] && map[i-1][j]) q=0;
		if(!q) return;
		num=0;
		dg(1,1);
		bool p=1;
		fo(i,2,num)
		{
			bool ok=1;
			fo(j,1,n+m-1)
				if(b[i-1][j]>b[i][j]) {ok=0;break;}
				else
				if(b[i-1][j]<b[i][j]) {ok=1;break;}
			if(!ok) {p=0;break;}
		}
		if(p)
		{
			++ans;
			--ans;
		}
		if(!p) return;
		ans++;
		return;
	}
	if(y>m)
	{
		dfs(x+1,1);
		return;
	}
	map[x][y]=0;
	dfs(x,y+1);
	map[x][y]=1;
	dfs(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();if(n>m) swap(n,m);
	if(n==3)
	{
		printf("%lld\n",(ll)112*qmi(3,m-n)%mo);
		return 0;
	}
	if(n==2)
	{
		S=(1<<n)-1;
	fo(i,0,S)
		fo(j,0,S)
		{
			int ok=1;
			fo(k,1,n-1)
				if(!(i & (1<<k)) && (j & (1<<(k-1)))) {ok=0;break;}
			trs[i][j]=ok;
		}
	A[S]=1;
	int ans=0;
	for(int t=m;t;t>>=1)
	{
		if(t&1)
		{
			mset(B,0);
			fo(j,0,S)
				fo(k,0,S) B[j]=(B[j]+A[k]*trs[k][j]%mo)%mo;
			fo(i,0,S) A[i]=B[i];
		}
		mset(tmp,0);
		fo(i,0,S)
			fo(j,0,S)
				fo(k,0,S) tmp[i][j]=(tmp[i][j]+1ll*trs[i][k]*trs[k][j]%mo)%mo;
		fo(i,0,S)
			fo(j,0,S) trs[i][j]=tmp[i][j];
	}
	fo(i,0,S) ans=(ans+A[i])%mo;
	printf("%d\n",ans);
	return 0;
	}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}

