/*
完全背包二维优化-状态转移公式：
f[n][v]=max(f[n][v-c[i]]+w[i],f[n-1][v]) 
*/ 
#include<iostream>
using namespace std;
int n,v,c[101],w[101],f[101][10001];
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=v;j++){
			f[i][j]=max(f[i][j-c[i]]+w[i],f[i-1][j]);
		}
	}
	int ans=-100;
	for(int i=0;i<=v;i++){
		ans=max(ans,f[n][i]);
	}
	cout<<ans;
}
