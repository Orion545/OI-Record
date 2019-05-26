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
int s,q;ll n,m,L=0,R=n-1;
int main(){
	int i;
	n=read();m=read();s=read();q=read();
	for(i=1;i<=n;i++){
		t1=read(),t2=read();
		//if [t1,t2] located left most
		
	}
}
