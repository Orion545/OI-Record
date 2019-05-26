#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int mod = 1e9+7;
const int maxn = 1100000;

int n,m;
int re;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if(n==2)
	{
		re=4;
		for(int i=2;i<n+m-1;i++) re=(ll)re*3%mod;
	}
	printf("%d\n",re);
	
	return 0;
}

