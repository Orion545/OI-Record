#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int a[105500];
struct node{
	int x,idx;
}t[105500];
long long ans;
int n;
bool cmp(node a,node b){
	return a.x<b.x;
}
void dfs(int l,int r,int rmb,int cnt){
	if(l>r) return;
	if(l==r){
		ans+=a[l]-rmb;
		return;
	}
	int i;
	for(i=cnt;i<=n;++i){
		if(t[i].idx>=l&&t[i].idx<=r) break;
	}
	ans+=t[i].x-rmb,rmb=t[i].x;
	dfs(l,t[i].idx-1,rmb,cnt+1);
	dfs(t[i].idx+1,r,rmb,cnt+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		t[i].x=a[i],t[i].idx=i;
	}
	sort(t+1,t+n+1,cmp);
	dfs(1,n,0,1);
	cout<<ans;
	return 0;
}
