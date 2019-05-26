#include<bits/stdc++.h>
using namespace std;
int n,i,ans,j,l,k,d[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>d[i];
	}
	for(i=1;i<=n;i++){
		while(d[i]!=0){
			j=i;
			k=10001;
			while(d[j]!=0&&j<=n){
				k=min(d[j],k);
				j++;
			}
			ans+=k;
			for(l=i;l<=j-1;l++){
				d[l]-=k;
			}
		}
	}
	cout<<ans;
	return 0;
}
