#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define mmst(a, b) memset(a,b,sizeof(a))
#define mmcp(a, b) memcpy(a,b,sizeof(a))

typedef long long LL;

const int N=100100;

int n,d[N];
int ans=0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);
	
	for(int i=n+1;i>=1;i--)
	{
		d[i]=d[i]-d[i-1];
		if(d[i]>0)
		ans+=d[i];
	}
	
	cout<<ans<<endl;
	
	return 0;
}

