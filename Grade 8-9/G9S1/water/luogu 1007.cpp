#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 0x7fffffff
using namespace std;
int l,n,a[5010];
int main(){
	int ans1=0,ans2=0;
	scanf("%d%d",&l,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans1=max(ans1,min(a[i],l-a[i]+1));
		ans2=max(ans2,max(a[i],l-a[i]+1));
	}
	printf("%d %d",ans1,ans2);
}
