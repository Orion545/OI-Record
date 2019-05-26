#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,l,d;
int main(){
	cin>>n>>m>>l>>d;int i,tmp;
	for(i=1;i<=l;i++){
		cout<<"move_right"<<endl;
		cin>>tmp;
		cout<<"dist"<<endl;
		cin>>tmp;
		if(!tmp) cout<<"reach_dest"<<endl;
	}
	cout<<"reach_dest"<<endl;
}
