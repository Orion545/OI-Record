#include<iostream>
#include<cstdio>
using namespace std;
int c[101],w[101],f[101][10001];
int main(){
	int n,v;cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(j-c[i]>=0) f[i][j]=max(f[i-1][j],(f[i-1][j-c[i]]+w[i]));
			else f[i][j]=f[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			printf("%3d",f[i][j]);
		}
		cout<<endl;
	}
	int ans=-1000;
	for(int i=1;i<=v;i++){
		if(ans<=f[n][i]) ans=f[n][i];
	}
	cout<<ans;
} 
