#include<bits/stdc++.h>
using namespace std;

int n,a[100001];
long long ans,tmp;

void dfs(int l,int r){
	if(l>r) return;
	int minn=INT_MAX;
	for(int i=l;i<=r;i++){
		int k=minn;
		minn=min(minn,a[i]);
		if(minn<k) tmp=i;
	} 
	ans+=minn;
	for(int i=l;i<=r;i++) a[i]-=minn;
	dfs(l,tmp-1);
	dfs(tmp+1,r);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dfs(1,n);
    printf("%d",ans);
}
