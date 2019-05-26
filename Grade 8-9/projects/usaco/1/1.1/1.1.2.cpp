/*
ID: marcoli2
PROG: ride
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	string a,b;int x=1,y=1,i;
	cin>>a>>b;
	for(i=0;i<a.length();i++) x*=((int)(a[i]-'A'+1));
	for(i=0;i<b.length();i++) y*=((int)(b[i]-'A'+1));
	if(x%47==y%47) cout<<"GO\n";
	else cout<<"STAY\n"; 
}
