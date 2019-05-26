#include<iostream>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	bool a[101][101][101];int m[101][101];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>m[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		a[n][i][m[n][i]%k]=1;
	}
	for(int x=n-1;x>=1;x--){
		for(int y=1;y<=x;y++){
			for(int z=0;z<k;z++){
				if(a[x+1][y][z]) a[x][y][(z+m[x][y])%k]=1;
				if(a[x+1][y+1][z]) a[x][y][(z+m[x][y])%k]=1;
			}
		}
	}
	for(int i=k-1;i>=0;i--){
		if(a[1][1][i]){
			cout<<i;return 0;
		}
	}
} 
