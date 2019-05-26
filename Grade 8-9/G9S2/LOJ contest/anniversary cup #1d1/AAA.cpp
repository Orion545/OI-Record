#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,l,d;
int main(){
	cin>>n>>m>>l>>d;int i,tmp,flag=0;
	for(i=1;i<=l;i++){
		if(flag) cout<<"move_right"<<endl;
		else cout<<"move_left"<<endl;
		cin>>tmp;
		
		if(!flag) cout<<"move_right"<<endl;
		else cout<<"move_left"<<endl;
		cin>>tmp;
		if(tmp) i++,flag^=1;
		
		cout<<"dist"<<endl;
		cin>>tmp;
		if(!tmp) cout<<"reach_dest"<<endl;
	}
	cout<<"reach_dest"<<endl;
}
