#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct node{
	int d,point;
};
node a[N];
int n;
LL ans;
int find(int l,int r){
	int res=100100;a[res].d=inf;
	for(int i=l;i<=r;i++)if(a[i].d<a[res].d&&a[i].d!=0)res=i;
	return res;
}
void dfs(int l,int r,int div){
	int mid=find(l,r),temp;
	temp=a[mid].d-div;
	ans+=temp;
	if(l<r){
		if(l<=mid-1)dfs(l,mid-1,div+temp);
		if(mid+1<=r)dfs(mid+1,r,div+temp);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].d),a[i].point=i;
	dfs(1,n,0);
	printf("%lld\n",ans);
	return 0;
}
