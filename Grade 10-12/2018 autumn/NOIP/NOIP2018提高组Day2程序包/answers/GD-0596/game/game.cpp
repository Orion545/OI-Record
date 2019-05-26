#include<map>
#include<list>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int md=1000000007;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,ans=1;
	scanf("%d%d",&n,&m);
	if(n<m)swap(n,m);
	for(int i=2;i<=m;i++)ans=(1ll*ans*i)%md;
	ans=(1ll*ans*ans)%md;
	for(int i=1;i<=m-n+1;i++)ans=(1ll*ans*(n+1))%md;
	printf("%d",ans);
}
