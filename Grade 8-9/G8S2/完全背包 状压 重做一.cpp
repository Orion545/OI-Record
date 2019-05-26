#include<iostream>
using namespace std;
int n,c[100010],w[100010],f[10000010],v,ans=-1;
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++) cin>>c[i]>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=v;j++){
			if(j-c[i]>=0) f[j]=max(f[j],f[j-c[i]]+w[i]);
		}
		for(int j=0;j<=v;j++) cout<<f[j]<<ends;cout<<endl; 
	}
	for(int i=0;i<=v;i++) ans=max(ans,f[i]);
	cout<<ans;
}
