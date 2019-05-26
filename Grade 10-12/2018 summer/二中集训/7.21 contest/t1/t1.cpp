#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,a[10010];
int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
} 
int main(){
	int T=read();
	while(T--){
		n=read();int i,tmp;
		for(i=1;i<=n;i++) a[i]=read();
		tmp=a[2];
		for(i=1;i<=n;i++) if(i!=2) tmp/=gcd(tmp,a[i]);
		if(tmp==1) puts("YES");
		else puts("NO");
	}
}

