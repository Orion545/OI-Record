#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
const int N=1e5+50;
using namespace std;
int n;
int num=0;
ll ans=0;
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n); a[0]=0;
	for (int i=1;i<=n;i++){
	  scanf("%d",&a[i]);
	  num=a[i]-a[i-1];
	  if (num>0) ans+=num;
	}
	printf("%lld",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
