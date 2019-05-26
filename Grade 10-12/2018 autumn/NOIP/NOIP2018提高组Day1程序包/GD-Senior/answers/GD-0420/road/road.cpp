#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[100005],an=1;
long long ans=0;

void read(){
	cin>>n;
	cin>>a[1];
	for(int i=2,x;i<=n;i++){
		cin>>x;
		if((a[an-1]<a[an]&&a[an]>x)||(a[an-1]>a[an]&&a[an]<x)) an++;
		a[an]=x;
	}
	if(a[an]<a[an-1]) an--;
}

void f(int l,int r,int h){
	if(r<l) return;
	if(l==r){
		ans+=a[l]-h;
		return;
	}
	if(l+1==r){
		ans+=max(a[l],a[r])-h;
		return;
	}
	if(l+2==r){
		ans+=a[l]+a[r]-a[l+1]-h;
		return;
	}
	int p=l;
	for(int i=l+1;i<=r;i++){
		if(a[i]<a[p]) p=i;
	}
	ans+=a[p]-h;
	f(l,p-1,a[p]); f(p+1,r,a[p]);
}

int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	read();
	f(1,an,0);
	cout<<ans;
	return 0;
}
