#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int n,a[MAXN];
bitset<25001> f;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans=0,maxn=0;
		f.reset();
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i),maxn=max(maxn,a[i]);
		sort(a+1,a+n+1);
		f[0]=1;
		//printf("%s\n",f.to_string().c_str());
		for(int i=1;i<=n;++i)
		{
			if(f[a[i]])
			{
				++ans;
			}
			else
			{
				for(int ct=1;ct<=maxn/a[i]+1;++ct)f|=f<<a[i];
				//printf("%s\n",f.to_string().c_str());
				//puts("");
			}
		}
		printf("%d\n",n-ans);
	}
}
