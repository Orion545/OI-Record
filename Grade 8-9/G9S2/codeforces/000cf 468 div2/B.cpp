#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
int n,l,r,ans=0;
int main(){
	n=read();l=read();r=read();
	if(l>r) swap(l,r);
	while((n>2)&&(!((l==r-1)&&(l%2)))){
		ans++;n/=2;
		l=(l+l%2)/2;r=(r+r%2)/2;
	}
	if(n==2) cout<<"Final!\n";
	else cout<<ans+1;
}
