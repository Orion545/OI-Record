#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#define inf 100005
using namespace std;

int n;
int a[inf];
int cnt[inf];

int add[inf*4];

void pushdown(int u){
	if (add[u]){
		add[u*2+1]+=add[u];
		add[u*2]+=add[u];
		add[u]=0;
	}
	return;
}

void ST_add(int u,int l,int r,int L,int R,int v){
	if (L<=l && r<=R){
		add[u]+=v;
		return;
	}
	pushdown(u);
	int mid=(l+r)/2;
	if (L<=mid){
		ST_add(u*2,l,mid,L,R,v);
	}
	if (R>mid){
		ST_add(u*2+1,mid+1,r,L,R,v);
	}
	return;
}

void ST_query(int u,int l,int r){
	if (l==r){
		cnt[l]=add[u];
		return;
	}
	pushdown(u);
	int mid=(l+r)/2;
	ST_query(u*2,l,mid);
	ST_query(u*2+1,mid+1,r);
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int maxv=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxv=max(maxv,a[i]);
	}
	for (int i=1;i<=n;i++){
		if (a[i]>a[i-1]){
			ST_add(1,1,maxv,a[i-1]+1,a[i],1);
		}
	}
	ST_query(1,1,maxv);
	int ans=0;
	for (int i=1;i<=maxv;i++){
		ans+=cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}
/*
6
4 3 2 5 3 5

*/
