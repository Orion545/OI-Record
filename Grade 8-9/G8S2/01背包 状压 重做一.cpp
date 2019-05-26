#include<iostream>
using namespace std;
int n,c[100010],w[100010],f[10000010],totv,ans=-1;
int main(){
	cin>>n>>totv;
	for(int i=1;i<=n;i++) cin>>c[i]>>w[i];
	for(int i=1;i<=n;i++){
		for(int v=totv;v>=0;v--){
			if(v-c[i]>=0) f[v]=max(f[v],f[v-c[i]]+w[i]);
		}
		for(int j=1;j<=totv;j++) cout<<f[j]<<ends;cout<<endl;
	}
	for(int i=1;i<=totv;i++) ans=max(ans,f[i]);
	cout<<ans;
}
//f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}
