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
int n,a,b,c,tot,t[1010],ans=0;
int main(){
	n=read();a=read();b=read();c=read();tot=read();int i;
	for(i=1;i<=n;i++) t[i]=read();
	if(b>=c){
		cout<<n*a;
	}
	else{
		ans=n*a;
		for(i=1;i<=n;i++) ans+=(tot-t[i])*(c-b);
		cout<<ans;
	}
}

