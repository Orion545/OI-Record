#include<iostream>
using namespace std;
int f[1001],a[1001];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j]<=a[i]) f[i]=max(f[i],f[j]+1);
		}
	}
	int maxx=-1;
	for(int i=1;i<=n;i++) maxx=max(maxx,f[i]);
	cout<<maxx;
} 
