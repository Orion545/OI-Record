#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int tr[N*10],n,M,a[N*2],ans;
int cmin(int x,int y){return a[x]<a[y]?x:y;}
int query(int l,int r){
	int ans=l;
	for (l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
		if (!(l&1))ans=cmin(ans,tr[l^1]);
		if (r&1)   ans=cmin(ans,tr[r^1]);		
	}return ans;
}
void go(int l,int r,int las){
	if (l>r)return;
	int m=query(l,r);
	ans+=a[m]-las;
	go(l,m-1,a[m]);
	go(m+1,r,a[m]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (M=1;M<=n;M<<=1);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),tr[i+M]=i;
	for (int i=M-1;i;i--)tr[i]=cmin(tr[i+i],tr[i+i+1]);
	go(1,n,0);
	cout<<ans<<endl;
	return 0;
}
