#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int Maxn=110;
const int Maxv=25010;
int n,T,a[Maxn],nxt[Maxv];
bool f[Maxv];
int fn(int x)
{
	if(x==nxt[x])return x;
	return nxt[x]=fn(nxt[x]);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(f,false,sizeof(f));f[0]=true;
		scanf("%d",&n);
		int mx=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
		for(int i=0;i<=mx+1;i++)nxt[i]=i;
		sort(a+1,a+1+n);
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++)
		if(!f[a[i]])
		{
			ans++;
			for(int j=a[i];j<=mx;j=fn(j+1))
			{
//				printf("%d\n",j);
				if(f[j-a[i]])f[j]=true,nxt[j]=fn(j+1);
			}
		}
		printf("%d\n",ans);
	}
}
