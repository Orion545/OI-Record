#include<bits/stdc++.h>
using namespace std;
int t,a[200],n;
int main(){
    freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ans=0;
		for(int j=1;j<=n;j++)
		cin>>a[j];	
		sort(a+1,a+n+1);
		for(register int j=n-1;j>=1;j--){
			for(register int k=j+1;k<=n;k++)
			a[k]=a[k]%a[j];
		}
		for(int j=1;j<=n;j++)
		if(a[j]!=0) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
