#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;


typedef long long LL;


const int N = 110;


int n;

int a[N];

vector<int> vec;

bool f[250010];


int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		vec.clear();
		memset(f, 0, sizeof(f));
		
		scanf("%d", &n);
		int maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			maxv = max(a[i], maxv);
		}
		
		sort(a + 1, a + 1 + n);
		
		for (int i = 1; i <= n; i++)
		{
			if (f[a[i]]) continue;
			f[a[i]] = 1;
			for (int j = a[i]; j <= maxv; j++)
				f[j] |= f[j - a[i]];
			vec.push_back(a[i]);
		}
		
		printf("%d\n", vec.size());
	}
	
	return 0;
}
