#include<bits/stdc++.h>

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))

using namespace std;

typedef long long ll;

const int N=100050;

int n,d;
ll sum;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n); int las=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&d); int lc=d-las;
		if(lc>0) sum+=lc;
		las=d;
	}
	printf("%lld\n",sum);
	return 0;
}
