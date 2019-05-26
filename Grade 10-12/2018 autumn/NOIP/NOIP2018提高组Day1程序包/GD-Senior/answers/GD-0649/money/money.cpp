#include<bits/stdc++.h>

using namespace std ;

const int N=1e2+10,M=2.5e4;
int n,a[N],now[N],ans,i,j,k,l;
bool vis[M+100];

int read()
{
	int x=0;char c=getchar();
	for (;c<'0'||c>'9';c=getchar());
	for (;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x;
}

void solve()
{
	n=read(),ans=0;
	for (i=1;i<=n;i++) a[i]=read(); sort(a+1,a+1+n);
	for (i=1;i<=n;i++) now[i]=a[i];
	memset(vis,0,sizeof vis);
	vis[0]=1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<i;j++)
			for (k=now[j];k<now[j]+a[j]&&k+a[j]<=a[i];k+=8)
			{
				for (l=k  ;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
				for (l=k+1;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
				for (l=k+2;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
				for (l=k+3;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
				for (l=k+4;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
				for (l=k+5;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
				for (l=k+6;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
				for (l=k+7;l+a[j]<=a[i];l+=a[j])vis[l+a[j]]|=vis[l];
			}
		if (!vis[a[i]]) ans+=(vis[a[i]]=1);
	}
	printf("%d\n",ans);
}

int main()
{
	
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T=read();
	for (int t=0;t<T;t++)	
		solve();
	
	return 0;
}
