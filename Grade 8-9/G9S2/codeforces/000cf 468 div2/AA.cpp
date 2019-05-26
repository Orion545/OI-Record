#include<iostream>
#include<cmath>
using namespace std;
int n,a,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a,ans+=abs(a);
	cout<<ans;
} 
