#include<iostream>
using namespace std;
int a[101][101],m[101][101];int n;
bool v[101][101];
int search(int x,int y){
	if(x==n){
		v[x][y]=1;
		return m[x][y];
	}
	if(v[x][y]) return m[x][y];
	m[x][y]+=max(search(x+1,y),search(x+1,y+1));
	v[x][y]=1;
	return m[x][y];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>m[i][j];
		}
	}
	cout<<search(1,1);
} 
