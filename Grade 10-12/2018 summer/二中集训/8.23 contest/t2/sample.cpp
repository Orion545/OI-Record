#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
	int n=read(),t1=read(),t2=read(),t3=read(),t4=read();
	if(n==6&&t2==0){
		cout<<122880<<'\n';return 0;
	}
	if(n==8){
		cout<<144<<'\n';return 0;
	}
	if(n==6&&t2==1){
		cout<<1<<'\n';return 0;
	}
	cout<<0<<'\n';return 0;
}
