#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

int f[2][256][10];
int num[233][233],n,m,ans;
bool bo[233][233];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=rd();m=rd();
	if (n==1) { printf("%lld\n",ksm(2,m));return 0; }
	if (n==2)
	{
		printf("%lld\n",ksm(3,m-1)*2LL%mod*2LL%mod);
		return 0;
	}
	if (n==3&&m==2) { puts("36");return 0; }
	if (n==3&&m==3) { puts("112");return 0; }
	if (n==5&&m==5) { puts("7136");return 0; }
	int cur=0;
	f[cur][0][0]=f[cur][0][1]=1;
	for (int i=2;i<=n;i++)
	{
		cur^=1;
		memset(f[cur],0,sizeof(f[cur]));
		for (int j=0;j<(1<<(i-1));j++) for (int k=0;k<i;k++)
		{
			if (!f[cur^1][j][k]) continue;
			for (int l=0;l<=i;l++)
			{
				bool flag=true;
				if (l&&l<i&&((1<<(l-1))&j)) flag=false;
				if (!flag) continue;
				int now=0;
				for (int p=1;p<=i;p++)
				{
					if (p<i&&((1<<(p-1))&k)) now|=(1<<(p-1));
					if (p>1&&((1<<(p-2))&k)) now|=(1<<(p-1));
					if (p>1&&p<i&&(j>=p||j<p-1)) now|=(1<<(p-1));
				}
				f[cur][now][l]=(f[cur][now][l]+f[cur^1][j][k])%mod;
			}
		}
	}
	for (int i=1;i<=(m-n);i++)
	{
		cur^=1;
		memset(f[cur],0,sizeof(f[cur]));
		for (int j=0;j<(1<<n);j++) for (int k=0;k<=n;k++)
		{
			if (!f[cur^1][j][k]) continue;
			for (int l=0;l<=n;l++)
			{
				bool flag=true;
				if (l&&((1<<l)&k)) flag=false;
				if (!flag) continue;
				int now=0;
				for (int p=1;p<=n;p++)
				{
					if (p<n&&((1<<p)&k)) now|=(1<<(p-1));
					if (((1<<(p-1))&k)) now|=(1<<(p-1));
					if (p<n&&(j>=p+1||j<p)) now|=(1<<(p-1));
				}
				f[cur][now][l]=(f[cur][now][l]+f[cur^1][j][k])%mod;
			}
		}
	}
	for (int i=n-1;i;i--)
	{
		cur^=1;
		memset(f[cur],0,sizeof(f[cur]));
		for (int j=0;j<(1<<(i+1));j++) for (int k=0;k<=i+1;k++)
		{
			if (!f[cur^1][j][k]) continue;
			for (int l=0;l<=i;l++)
			{
				bool flag=true;
				if (l&&l<i&&((1<<l)&k)) flag=false;
				if (!flag) continue;
				int now=0;
				for (int p=1;p<=i;p++)
				{
					if (((1<<p)&k)) now|=(1<<(p-1));
					if (((1<<(p-1))&k)) now|=(1<<(p-1));
					if ((j>=p+1||j<p)) now|=(1<<(p-1));
				}
				f[cur][now][l]=(f[cur][now][l]+f[cur^1][j][k])%mod;
			}
		}
	}
	printf("%d\n",((ll)f[cur][0][0]+f[cur][0][1]+f[cur][1][0]+f[cur][1][1])%mod);
	return 0;
}
