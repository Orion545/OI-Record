#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
	ll n=read(),ans=0,tmp=1;n--;
	while(n){
		ans+=(n+1)/2*tmp;n-=(n+1)/2;
		tmp=tmp<<1;
	}
	cout<<ans;
}
