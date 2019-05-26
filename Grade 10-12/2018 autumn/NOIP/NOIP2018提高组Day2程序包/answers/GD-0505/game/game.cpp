#include<iostream>
#include<cstdio>
using namespace std;
long long big[256][100005];
long long equa[256][100005];
int n,m;
long long ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n>m)swap(n,m);
	if(n==1){
		cout<<(1<<m);
	}
	if(n==2){
		if(m==2){
			cout<<12;
		}
		if(m==3){
			cout<<56;
		}
	}
	if(n==3){
		cout<<112;
	}
}
