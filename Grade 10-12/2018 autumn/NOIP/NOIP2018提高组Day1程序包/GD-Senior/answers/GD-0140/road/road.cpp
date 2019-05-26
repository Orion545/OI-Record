#include<iostream>
#include<cstdio>
using namespace std;
int n,h,a,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	h=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a<=h){
			h=a;
		}else{
			ans+=a-h;
			h=a;
		}
	}
	cout<<ans;
	return 0;
}
