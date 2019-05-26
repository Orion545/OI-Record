#include<iostream>
#define no "NO"<<endl
#define yes "YES"<<endl 
using namespace std;
int hash=31333,h[31334];int n,m,a[100001],b[100001];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];b[a[i]]=1;
	}
	int x;
	for(int i=1;i<=m;i++){
		cin>>x;
		if(b[x]==0) cout<<no;
		else cout<<yes;
	}
}
