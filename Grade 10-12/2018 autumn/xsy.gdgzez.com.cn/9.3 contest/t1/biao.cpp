#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int main(){
	ll T=read(),x,y;
	while(T--){
		x=read();y=read();
		if(x==1ll){
			if(y%2ll) puts("YES");
			else puts("NO");
		}
		if(x==2ll){
			if(y==1ll||y==2ll) puts("YES");
			else puts("NO");
		}
		if(x==3ll){
			if(y==1||y==2||y==3||y==4||y==6) puts("YES");
			else puts("NO");
		}
	}
}
