#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
using namespace std;

namespace Solution_zzc
{
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

long long d[100005];
int n;

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(d[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]>d[i-1])ans+=d[i]-d[i-1];
	}
	cout<<ans<<endl;
	return 0;
}

}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return Solution_zzc::main();
}
/*
6
4 3 2 5 3 5
*/
