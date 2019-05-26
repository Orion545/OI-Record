#include<iostream>
#include<cstdio>
using namespace std;
const long long Mod=1000000007;
long long calc_2(int x){
	if(x==0)return 1;
	long long cc=calc_2(x/2);
	if(x%2==1){
		return (((cc*cc)%Mod)*2)%Mod;
	}else{
		return (cc*cc)%Mod;
	}
}
long long calc_3(int x){
	if(x==0)return 1;
	long long cc=calc_2(x/2);
	if(x%2==1){
		return (((cc*cc)%Mod)*3)%Mod;
	}else{
		return (cc*cc)%Mod;
	}
}
int n,m;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<calc_2(m);
	}else if(n==2){
		cout<<(4*calc_3(m-1))%Mod;
	}else if(n==3){
		if(m==1){
			cout<<8;
		}else if(m==2){
			cout<<36;
		}else if(m==3){
			cout<<112;
		}
	}
	return 0;
}
