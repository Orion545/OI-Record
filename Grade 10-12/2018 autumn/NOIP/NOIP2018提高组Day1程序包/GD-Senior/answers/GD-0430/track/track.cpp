#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n,min_=1000000,max_=0;
int map[15][15];
int xu[50005];
bool f=1,ff=1;
struct node{
	int fr;
	int tto;
	int val;
}a[50005];
int min(int x,int y){
	if (x<y) return x; else return y;
}
int max(int x,int y){
	if (x>y) return x; else return y;
}
bool check(int x){
	//printf("%d\n",x);
	int num=0; int sum=0;
	for (int u=1;u<n;++u){
		if (sum+a[xu[u]].val>=x){
			sum=0;
			++num;
		}
		else{
			sum+=a[xu[u]].val;
		}
		//if (x==12) printf("%d ",sum);
	}
	if (num>=m) return 1; else return 0;
}
bool check_(int x){
	//printf("%d\n",x);
	int num=0; int sum=0;
	for (int u=1;u<n;++u){
		if (sum+a[u].val>=x){
			sum=0;
			++num;
		}
		else{
			sum+=a[u].val;
		}
	}
	if (num>=m) return 1; else return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=10;++i) for (int j=1;j<=10;++j) map[i][j]=10000000;
	for (int i=1;i<n;++i){
		scanf("%d%d%d",&a[i].fr,&a[i].tto,&a[i].val);
		map[a[i].fr][a[i].tto]=a[i].val;
		map[a[i].tto][a[i].fr]=a[i].val;
		xu[a[i].fr]=i;
		min_=min(min_,a[i].val);
		max_+=a[i].val;
		if (a[i].tto-a[i].fr!=1) f=false;
		if (a[i].fr!=1) ff=false;
	}
	if (f){
		//printf("%d %d\n",min_,max_);
		int l=min_; int r=max_; int mid=0;
		while (l<=r){
			mid=(l+r)/2;
			//printf("%d %d %d\n",l,r,mid);
			if (check(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d",r);
	}
	if (ff){
		for (int i=1;i<n-1;++i){
			for (int j=i+1;j<n;++j){
				if (a[i].val<a[j].val){
					int t=a[i].val; a[i].val=a[j].val; a[j].val=t;
				}
			}
		}
		int l=min_; int r=max_; int mid=0;
		while (l<=r){
			mid=(l+r)/2;
			if (check_(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d",r);
	}
	if (m==1){
		for (int k=1;k<=n;++k){
			for (int i=1;i<=n;++i){
				for (int j=1;j<=n;++j){
					map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				ans=max(ans,map[i][j]);
			}
		}
		printf("%d",ans);
	}
}
