#include <iostream>
#include <cstdio>
using namespace std;
int T,n;
int i,j,k,ans;
int a[200],vis[200];
inline void mergesort(int l,int r) {
	if(l==r) return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int w[101],x=l,y=mid+1,z=l;
	while(x<=mid && y<=r) 
	if(a[x]<=a[y]) w[z++]=a[x++];
	else w[z++]=a[y++];
	while(x<=mid) w[z++]=a[x++];
	while(y<=r) w[z++]=a[y++];
	for(z=l;z<=r;z++)
	a[z]=w[z];
}
void dfs(int pos,int data) {//位置 当前的值 
	int x;
	for(x=0;x<pos;x++) {
		if(!vis[x]) {
			if(data-a[x]==0) {
				vis[pos]=1;
				return;
			}
			if(vis[pos]==1) return;
			if(data>=a[x]) dfs(pos,data-a[x]);		
		}
	}
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T>0) {
		ans=1;
		cin>>n;
		for(i=1;i<n;i++) vis[i]=0;
		for(i=0;i<n;i++) cin>>a[i];
		mergesort(0,n-1);
		for(i=1;i<n;i++) {
			dfs(i,a[i]);
			if(!vis[i]) ans++;
		}
		cout<<ans<<endl;
		T--;
	}
}
