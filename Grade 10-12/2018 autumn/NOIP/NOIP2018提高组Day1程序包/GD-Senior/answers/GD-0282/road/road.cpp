#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
using namespace std;

#define maxn 100050

typedef long long ll;

ll d[maxn],n,i,last=0;
ll ans=0;

inline void input()
{
	scanf("%lld",&n);
	for(i=1;i<=n;++i)
		scanf("%lld",d+i);
}

inline void work()
{
	for(i=1;i<=n;++i)
	{
		if(d[i] >= last)
			ans += (d[i]-last);
		last = d[i];
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input();
	work();
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
