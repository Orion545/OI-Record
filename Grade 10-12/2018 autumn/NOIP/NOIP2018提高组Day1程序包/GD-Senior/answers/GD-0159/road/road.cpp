#ifdef LOCAL
#include <cstdio>
using std::printf;
using std::fflush;
#endif

#include <cstdio>
using std::fopen;
using std::fclose;
using std::scanf;
using std::printf;

#define MAXN 100005

unsigned a[MAXN];

unsigned quicksort(unsigned l, unsigned r) // [l,r)
{
	if(l + 1 == r) return a[l];
	if(l >= r) return 0;
	unsigned ans = 0, mi = a[l], mii = l;
	for(unsigned i = l ; i < r ; i++)
	{
		if(mi > a[i]) mi = a[i], mii = i;
	}
	ans += mi;
	unsigned tmp = quicksort(l, mii);
	if(tmp > 0) ans += tmp - mi;
	tmp = quicksort(mii+1, r);
	if(tmp > 0) ans += tmp - mi;
	return ans;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	unsigned N;
	scanf("%u", &N);
	for(unsigned i = 0 ; i < N ; i++)
		scanf("%u", &a[i]);
	
	printf("%u", quicksort(0,N));
	
	fclose(stdin);
	fclose(stdout);
}

