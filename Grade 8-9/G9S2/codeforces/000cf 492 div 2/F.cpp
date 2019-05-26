#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int main(){
	ll n=read();
	int ans=0;
	while(n>=100) n-=100,ans++;
	while(n>=20) n-=20,ans++;
	while(n>=10) n-=10,ans++;
	while(n>=5) n-=5,ans++;
	while(n>=1) n-=1,ans++;
	cout<<ans;
}
