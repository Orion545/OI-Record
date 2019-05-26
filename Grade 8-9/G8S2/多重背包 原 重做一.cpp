#include<iostream>
using namespace std;
int n,c[1010],w[1010],t[1010],f[1010][10010],v,ans=-1;
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++) cin>>c[i]>>w[i]>>t[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=v;j++){
			for(int k=1;k<=t[i];k++){
				if(j>=c[i]*k) f[i][j]=max(f[i-1][j],f[i-1][j-k*c[i]]+w[i]*k);
			}
		}
	}
	for(int i=0;i<=v;i++) ans=max(ans,f[n][i]);
	cout<<ans;
}
