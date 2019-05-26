#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001],d[100001],head=0,ans=0;

int laobi_bound(int l,int r,int k){
	int mid;
	while(r-l>1){
		mid=(l+r)/2;
		if(d[mid]<k)l=mid;
		else r=mid;
	}
	return l;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]>d[head]){
			head++;d[head]=a[i];
		}
		else if(a[i]==d[head]){
			continue;
		}
		else {
			ans+=d[head]-a[i];
			head=laobi_bound(0,head,a[i]);
			head++;d[head]=a[i];
		}
	}
	cout<<ans+d[head];
}
