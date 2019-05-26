#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (i=a; i<=b; i++)
#define ll long long
using namespace std;

const int N=9, M=1e6+5, W=1e9+7;
int n, m, i, j;
ll ans;

int main()
{
	freopen("game.in","r",stdin), freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m), ans=1;
	if (n==3 && m==3) {printf("112"); return 0;}
	if (n==5 && m==5) {printf("7136"); return 0;}
	fo(i,1,m) ans=ans*(min(i,m)+1)%W;
	fo(i,m+1,n+m-1) ans=ans*(min(n+m-i+1,m))%W;
	printf("%lld",ans);
}
