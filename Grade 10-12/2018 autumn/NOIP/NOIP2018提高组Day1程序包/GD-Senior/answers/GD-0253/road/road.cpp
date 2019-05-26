#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
int n,m,a,b;
long long ans;
void read(int &x){
	x=0;
	char c;
	int w=1;
	for (c=getchar();c<'0'||c>'9';c=getchar()) if (c=='-') w=-1;
	for (;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
	x*=w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	ans=a=b=0;
	for (int i=1;i<=n;++i){
		read(a);
		if (a>b) ans=ans+(long long)(a-b);
		b=a;
	}
	printf("%lld\n",ans);
}
