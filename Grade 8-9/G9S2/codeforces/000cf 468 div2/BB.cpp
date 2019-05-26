#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a,b,c,d,A,B;
int main(){
	cin>>a>>b;
	while(a&&b&&(a>=2*b||b>=2*a)){
		if(a>=b) a%=2*b;
		else b%=2*a;
	}
	cout<<a<<" "<<b<<endl;
}
