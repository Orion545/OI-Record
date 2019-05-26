#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,ans,S[maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	S[0]=-1;
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if (S[m]<x) S[++m]=x; else
		if (S[m]>x)
		{
			while (S[m-1]>=x) ans+=S[m]-S[m-1],m--;
			ans+=S[m]-x;
			S[m]=x;
		}
	}
	printf("%d\n",ans+S[m]);
	return 0;
}
