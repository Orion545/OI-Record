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
		cout<<"move_left\n"<<flush;
		cin>>tmp;
		cout<<"dist\n"<<flush;
		cin>>tmp;
		if(!tmp){
			cout<<"reach_dest\n"<<flush;
			return 0;
		}
	}
}

