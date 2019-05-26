#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int n;
struct node
{
	long long x,d;
}a[100010];
long long dep[100010];
long long read()
{
	char C;int ret=1;
	C=getchar();
	while(C<'0'||C>'9')
	{
	  if(C=='-') ret=-1;
	  C=getchar();
	}
	long long num=0;
	while(C>='0'&&C<='9') num=num*10+C-48,C=getchar();
	return num*ret;
}
bool cmp(node x,node y)
{
	return x.d<y.d||x.d==y.d&&x.x<y.x;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) dep[i]=read();
	int Max=dep[1],Min=0;dep[0]=1<<29,dep[n+1]=1<<29;
	long long ans=0;
	for(int i=1; i<=n+1; i++)
	{
		if(dep[i]<dep[i-1]) continue;
		ans+=Max-Min;
		Min=dep[i-1];
		Max=dep[i];
	}
	printf("%lld",ans);
	return 0;
}

