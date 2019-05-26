#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
inline int read()
{
	int f=1,k=0;char c=getchar();
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
const int maxn=107,up=25000;
int a[maxn];
bitset<up+100>vis,v;
inline int min(const int a,const int b){return a<b?a:b;}
inline int max(const int a,const int b){return a>b?a:b;}
signed main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for (int T=read();T;T--)
	{
		vis.reset();vis[0]=1;
		int n=read(),ans=0,mx=0;
		for (int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
//		for (int i=1;i<=n;i++)cout << a[i]<<" ";puts("");
		for (int i=1;i<=n;i++)
		{
			if (vis[a[i]])continue;
			v.reset();
			++ans;
			for (int j=mx;~j;j--)
			if (vis[j])
			{
				int now=1; ll tmp;
				while ((tmp=1ll*a[i]*now+j)<=up&&!v[tmp])v[tmp]=vis[tmp]=1,now++,mx=max(mx,min(up,tmp));
			}
//			cout << "ok:"<<i<<" "<<mx <<endl;
		}
		printf("%d\n",ans);
	}
}
