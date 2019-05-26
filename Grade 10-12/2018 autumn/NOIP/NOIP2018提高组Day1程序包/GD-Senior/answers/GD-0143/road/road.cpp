#include<cstdio>
using namespace std;
typedef long long ll;
int road[100010];

inline int qr ()
{
	int num = 0;
	char ch = getchar();
	bool neg = 0;
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') neg = 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		num = (num<<1) + (num<<3) + ch - '0';
		ch = getchar();
	}
	return neg ? -num : num;
}

int main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n = qr();
	ll ans = 0l;
	for(int i = 1; i <= n; i++)
	{
		road[i] = qr();
		if(road[i] > road[i-1]) ans += road[i] - road[i-1];
	}
	printf("%lld\n",ans);
	return 0;
}
