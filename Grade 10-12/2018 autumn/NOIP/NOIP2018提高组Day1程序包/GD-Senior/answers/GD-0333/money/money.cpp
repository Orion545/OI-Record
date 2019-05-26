#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int t;
int n,ans;
int a[101];
bool vis[101];
bool viss[25001];
int maxx;
int lookfor(int x){
	int l=1,r=n;
	if(a[l]==x)return l;
	if(a[r]==x)return r;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(a[mid]==x)return mid;
		if(a[mid]>x)r=mid;
		if(a[mid]<x)l=mid;
		//cout<<l<<" "<<r<<endl;
	}
	if(a[l]==x)return l;
	if(a[r]==x)return r;
	return 0;
}
void shai(int x,int y){
	int xx=maxx/x;
	int yy=maxx/y;
	for(int i=2;i<=xx;i++){
		if(viss[i*x])break;
//		else viss[i*x]=1;
		if(viss[i*x]!=1){
		viss[i*x]=1;
		int tmp=lookfor(i*x);
		if(tmp!=0){
			//cout<<"fff"<<i*x<<" "<<tmp<<endl;
			vis[tmp]=1;
			ans--;
		}
		}
	}
	for(int i=2;i<=yy;i++){
		if(viss[i*y])break;
		//else viss[i*y]=1;
		
		if(viss[i*y]!=1){
		viss[i*y]=1;	
		int tmp=lookfor(i*y);
		if(tmp!=0){
			//cout<<"fff"<<i*x<<" "<<tmp<<endl;
			vis[tmp]=1;
			ans--;
		}
		}
	}
	for(int i=1;i<=xx;i++){
		for(int j=1;j<=yy;j++){
			if(i*x+j*y>maxx)break;
			if(viss[i*x+j*y])continue;
				else viss[i*x+j*y]=1;
			int tmp=lookfor(i*x+j*y);
			if(tmp!=0){
				//cout<<"fff"<<i*x+j*y<<" "<<tmp<<endl;
				vis[tmp]=1;
				ans--;
			}
		}
	}
}
void debug(){
	
	for(int i=1;i<=maxx;i++){
		cout<<viss[i]<<" ";
	}
	cout<<endl;
}
void solve(){
	ans=0;
	scanf("%d",&n);
	ans=n;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	memset(viss,0,sizeof(viss));
	maxx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[i]||!vis[j])
				shai(a[i],a[j]);
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int qwq=1;qwq<=t;qwq++){
		solve();
	//	debug();
	}
	fclose(stdin);
	fclose(stdout);
}
