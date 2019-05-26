#include<iostream>
using namespace std;
int f[10001];
int main(){
	int n,m,num[101],a[101][1001][2],V;cin>>n>>m>>V;
	for(int i=1;i<=m;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			cin>>a[i][j][0]>>a[i][j][1];
		} 
	}
	for(int k=1;k<=m;k++){
		for(int v=V;v>=0;v--){
			for(int i=1;i<=num[k];i++){
				if(v-a[k][i][0]>=0) f[v]=max(f[v],f[v-a[k][i][0]]+a[k][i][1]);
			}
		}
	}
	cout<<f[V];
} 
