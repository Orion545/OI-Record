#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int d[100002],a[100002];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	a[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i]=a[i]-a[i-1];
	}
	d[n+1]=1;
	int x=d[1];
	long long ans=0;
	for(int i=2;i<=n+1;i++){
		if(d[i]>0){
			ans+=x;
			x=d[i];
		}
	}	
	printf("%lld",ans);
	return 0;
}
