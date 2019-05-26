#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 120000
using namespace std;
int a[N],n;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	}
	printf("%lld\n",ans);
	return 0;
}
