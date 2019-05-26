#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int p,y;cin>>p>>y;
	if(y%2==0) y--;
	while(y>p){
		for(int i=2;i*i<=y&&i<=p;i++) 
			if(y%i==0) goto end;
		cout<<y<<"\n";return 0;
		end:y-=2;
	}
	cout<<"-1\n";return 0;
}
