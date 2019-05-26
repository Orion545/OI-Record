#include<iostream>
using namespace std;
int a[30][30],b[30][30],n,x,y;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];b[i][j]=a[i][j];
		}
	}
	cin>>x>>y;
	
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			b[i][j]+=max(b[i-1][j],b[i-1][j-1]);
		}
	}
	for(int i=n-1;i>=x;i--){
		for(int j=y;j<=i;j++){
			b[i][j]+=max(b[i+1][j],b[i+1][j+1]);
		}
	}
	cout<<b[x][y];
} 
