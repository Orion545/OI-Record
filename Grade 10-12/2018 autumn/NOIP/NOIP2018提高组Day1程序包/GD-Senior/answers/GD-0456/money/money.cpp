#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int a[N],n;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(n==2){
			int g=gcd(a[1],a[2]);
			if(g==1){
				if(a[1]*a[2]-a[1]-a[2]>=1)puts("2");
				else puts("1");
			}
			else {
				if(g<min(a[1],a[2]))puts("2");
				else puts("1");
			}
		}
		else printf("%d\n",n);
	}
	return 0;
}
