#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int main(){
	int T=read(),n,m,a,b;
	while(T--){
		n=read();m=read();
		if(n==0&&m==0){puts("1");continue;}
		if(n==0||m==0||n<m){puts("0");continue;}
		a=n-m;
		b=(m+1)/2;
//		cout<<a<<' '<<b<<'\n';
		if(((b-1)&(a+b-1))==(b-1)) puts("1");
		else puts("0");
	}
}

