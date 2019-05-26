#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
const int mo=1e9+7;
const int N=1e5+10;
using namespace std;
int n,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,v=0,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<=v) v=x;
		else ans+=x-v,v=x;
	}
	printf("%d",ans);
	return 0;
}
