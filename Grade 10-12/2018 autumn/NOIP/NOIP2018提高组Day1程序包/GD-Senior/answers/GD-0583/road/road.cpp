#include<iostream>
#include<cstdio>
using namespace std;
long long  n,ans=0,last=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		long long x;
		scanf("%lld",&x);
		if(x>last)ans+=(x-last);
		last=x;
	}
	printf("%lld",ans);
	return 0;
}
