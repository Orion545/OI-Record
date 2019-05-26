#include<bits/stdc++.h>
using namespace std;
const int N=9,MOD=1e9+7;
int f[2][(1<<N)];
int a[N];
int n,m,ans;
inline int read()
{
	char ch=getchar();int x=0,f=0;
	for(; ch<'0'||ch>'9' ;ch=getchar())	if(ch=='-')	f=1;
	for(;'0'<=ch&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	return f?-x:x;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(); m=read();
	for(int i=0;i<(1<<n);i++)	f[0][i]=1;
	int which=0;
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<(1<<n);j++)	f[which^1][j]=0;
		for(int j=0;j<(1<<n);j++)
		{
			int cnt=0;
			for(int k=1;k<n;k++)
				if(j&(1<<k))		a[cnt++]=k-1;
			a[cnt++]=n-1;
			for(int l=0;l<(1<<cnt);l++)
			{
				int now=0;
				for(int k=0;k<cnt;k++)	
					if(l&(1<<k)) now+=(1<<a[k]);
				(f[which^1][now]+=f[which][j])%=MOD;
			}	
		} 
		which^=1;
	}
	ans=0;
	for(int i=0;i<(1<<n);i++)	(ans+=f[which][i])%=MOD;
	cout<<ans<<endl;
	return 0;
}
