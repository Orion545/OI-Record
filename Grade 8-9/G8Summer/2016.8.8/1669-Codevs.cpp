#include<iostream>
using namespace std;
int w[1001],v[1001],g[1001],f[1001][1001],vv,gg,n;
int main(){
	 cin>>vv>>gg>>n;
	 for(int i=1;i<=n;i++){
	 	cin>>w[i]>>v[i]>>g[i];
	 }
	 for(int i=1;i<=n;i++){
	 	for(int j=vv;j>=0;j--){
	 		for(int k=gg;k>=0;k--){
	 			if(j-v[i]>=0&&k-g[i]>=0) f[j][k]=max(f[j][k],f[j-v[i]][k-g[i]]+w[i]);
			 }
		 }
	 }
	 cout<<f[vv][gg];
} 
