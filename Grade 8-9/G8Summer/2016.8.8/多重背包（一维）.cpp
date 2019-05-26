#include<iostream>
#include<cstdio>
using namespace std;
int c[101],w[101],m[101],f[10001];
int main(){
	int n,v;cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=v;j>=0;j--){
			for(int k=0;k<=m[i];k++){
				if(j-k*c[i]>=0) f[j]=max(f[j],f[j-k*c[i]]+k*w[i]);
			}
		}
		cout<<endl;
	}
	cout<<f[v];
}
