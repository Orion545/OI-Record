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
ll n,a,a1,minn,g;
int main(){
	freopen("Lancer.in","r",stdin);
	freopen("Lancer.out","w",stdout);
	n=read();
	a1=0;minn=1e15;
	for(int i=1;i<=n;i++){
		a=read();
		if(i>1) printf(" %lld",a1+a+minn);
		else printf("%lld",a1+a);
		minn=min(minn,a);a1=a;
	}
}

