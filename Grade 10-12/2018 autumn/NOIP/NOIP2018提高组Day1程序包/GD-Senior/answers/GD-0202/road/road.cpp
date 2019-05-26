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

const int maxn = 210000;

int n;
int a[maxn];
int ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int las=0;
	for(int i=1;i<=n;i++)
	{
		if(las<a[i]) ans+=a[i]-las,las=a[i];
		if(las>a[i]) las=a[i];
	}
	printf("%d\n",ans);
	
	return 0;
}

