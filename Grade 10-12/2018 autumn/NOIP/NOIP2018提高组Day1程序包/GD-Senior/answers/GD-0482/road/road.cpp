#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define LL long long 
const int N =2e5+233;
using namespace std;

int a[N],s[N],n,q1[N],q2[N],h1,t2,t1;
LL ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n)	;
	rep(i,1,n) scanf("%d",&a[i]),s[i]=a[i]-a[i-1];
	for (int i=n;i>=1;--i)
	{
		if (s[i]<0) q1[++t1]=s[i];
		else 
		{
			while (h1<=t1&&s[i]>0) 
			{
				int tmp=min(s[i],-q1[h1]);
				s[i]-=tmp;
				q1[h1]+=tmp;
				ans+=tmp;
				if (q1[h1]==0) ++h1;
				
			}
			if (s[i]>0) q2[++t2]=s[i];
		}
	}
	rep(i,h1,t1) ans+=-q1[i];
	rep(i,1,t2) ans+=q2[i];
	printf("%lld",ans);
	return 0;
}
