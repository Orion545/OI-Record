#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=100005;
using namespace std;
int n;
int a[INF];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	long long ans=a[1]; int pre_num=a[1];
	for (int i=2;i<=n;++i){
		if (a[i]>pre_num){
			ans+=a[i]-pre_num;
			pre_num=a[i];
		}
		if (a[i]<=pre_num){
			pre_num=a[i];
		}
	}
	printf("%lld",ans);
}
