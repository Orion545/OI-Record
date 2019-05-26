#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
long long n,a[100005],sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long h=0;
	for(int i=1;i<=n;i++){
		if(h<a[i]) sum+=(a[i]-h);
		h=a[i];
	}
	printf("%lld",sum);
	return 0;
}
