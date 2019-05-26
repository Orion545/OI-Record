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
int main(){
	int n=read(),m=read(),i=0,ans=0;
	if(n>m) swap(n,m);
	while(n<m-1) n++,m--,ans+=(++i)*2;
	if(n!=m) ans+=++i;
	cout<<ans;
} 
