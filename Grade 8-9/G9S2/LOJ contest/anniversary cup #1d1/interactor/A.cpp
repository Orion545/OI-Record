#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,l,d;
int main(){
	cin>>n>>m>>l>>d;int i,tmp,minn=1e9;
	for(i=1;i<=l;i++){
		cout<<"move_left"<<endl;
		cin>>tmp;
		if(minn>=500&&(i%10==0)){
			cout<<"dist"<<endl;
			cin>>tmp;minn=min(minn,tmp);
			if(!tmp) cout<<"reach_dest"<<endl;
		}
		else if(minn<=500){
			cout<<"dist"<<endl;
			cin>>tmp;minn=min(minn,tmp);
			if(!tmp) cout<<"reach_dest"<<endl;
		}
	}
	cout<<"reach_dest"<<endl;
}
