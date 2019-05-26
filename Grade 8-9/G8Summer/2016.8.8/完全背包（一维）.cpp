#include<iostream>
#include<cstdio>
using namespace std;
int c[101],w[101],f[10001];
int main(){
	int n,v;cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=v;j++){
			if(j-c[i]>=0) f[j]=max(f[j],f[j-c[i]]+w[i]);
			printf("%3d",f[j]);
		}
		cout<<endl;
	}
	cout<<f[v];
}
