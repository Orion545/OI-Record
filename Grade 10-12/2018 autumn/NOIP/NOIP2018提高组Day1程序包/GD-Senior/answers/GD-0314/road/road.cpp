#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=100100;
int n,d[N];
int las;
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)
		scanf("%d",&d[i]);
	fo(i,1,n)
	{
		int las=d[i]-d[i-1];
		while(d[i]>=d[i+1]&&i+1<=n) ++i;
		ans+=las;
	}
	printf("%d\n",ans);
	return 0;	
}







