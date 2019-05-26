#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxa=25077,maxn=177;
int f[maxa],g[maxa],b[maxn],a[maxn],t,n;
int main()
{
	freopen("money.in","r",stdin); freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		memset(b,0,sizeof(b));
		int cnt=0,s=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			if(!f[x]) f[x]=1,a[++cnt]=x,s=max(x,s),g[x]=cnt;
		}
		int ans=cnt;
		for(int i=1; i<=s; i++)
		{
			if(!f[i]) continue;
			for(int j=1; j<=cnt; j++) if(!b[j])
			{
				int p=i+a[j];
				if(p>s) continue;
				if(f[p]&&g[p])
				{
					b[g[p]]=1; g[p]=0; ans--; 
				}else f[p]=1;
			}
		}
		printf("%d\n",ans);
	}
}













