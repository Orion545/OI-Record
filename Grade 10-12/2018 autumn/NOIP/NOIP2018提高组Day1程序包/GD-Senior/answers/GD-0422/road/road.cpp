#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
int n,x,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&ans);
	int last=ans;
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>last)ans+=(x-last);
		last=x;
	}
	printf("%d",ans);
}

