#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<queue> 
using namespace std;

inline long long read()
{
	int ch=getchar(),f=1;
	long long ans=0;
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		ans=(((ans<<2)+ans)<<1)+(ch^'0');
	return f?ans:-ans;
}

int n,m;
const int maxn=300005;
vector<int> e[maxn];

int uu[maxn],vv[maxn];
int pp[maxn];

void solve()
{
	int p=read()-1,x=read(),q=read()-1,y=read();	
	int ans=0x3f3f3f3f;
	for(int sta=0;sta<(1<<n);++sta)
	{
		if(  (1<<p)&sta  &&  !x)continue;
		if(  !(1<<p)&sta  &&  x)continue;
		if(  (1<<q)&sta  &&  !y)continue;
		if(  !(1<<q)&sta  &&  y)continue;
		int g=1;
		for(int i=1;i<n;++i)
		{
			if(!(sta&(1<<uu[i]))&&!(sta&(1<<vv[i])))
			{
				g=0;
				break;
			}
		}
		if(!g)continue;
		int sum=0;
		for(int i=0;i<n;++i)
		{
			if(sta&(1<<i))
				sum+=pp[i];
		}
		ans=min(ans,sum);
	}
	if(ans<0x3f3f3f3f)printf("%d\n",ans);
	else printf("-1\n");
}
long long f[maxn][2];
void solve_0()
{
	memset(f,0,sizeof f);
	int a=read(),x=read(),b=read(),y=read();
		for(int i=1;i<=n;++i)
		{
			if(i==a)f[i][x]=0x3f3f3f3f3f3f3f3f;
			
			if(i==b)f[i][y]=0x3f3f3f3f3f3f3f3f;
			
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][0],f[i-1][1])+pp[i];
		}
		printf("%lld\n",min(f[n][0],f[n][1]));
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	char c[30];
	scanf("%s",c);
	for(int i=0;i<n;++i)
		pp[i]=read();
	
	for(int i=1;i<n;++i)
	{
		int u=read();
		int v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		uu[i]=u-1,vv[i]=v-1;
	}
	if(n<=10)
	{
		while(m--)
			solve();
		return 0;
	}
	if(c[0]=='A')
	{
		while(m--)
			solve_0();
		return 0;
	}
	return 0;
}
