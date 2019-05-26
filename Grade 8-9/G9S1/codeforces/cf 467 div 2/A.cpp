#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1010];
int main(){
	cin>>n;
	int i,j,ans=0;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		while(a[i]==a[i+1]) i++;
		if(a[i]) ans++;
	}
	cout<<ans<<"\n";
} 
