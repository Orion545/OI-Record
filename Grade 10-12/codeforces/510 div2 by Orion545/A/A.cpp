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
int n,m,a[110];
int main(){
	n=read();int i,minn,pos;m=read();
	for(i=1;i<=n;i++) a[i]=read();
	int maxn=0;
	for(i=1;i<=n;i++) maxn=max(maxn,a[i]);
	maxn+=m;
	while(m){
		minn=1e9;
		for(i=1;i<=n;i++){
			if(minn>a[i]) minn=a[i],pos=i;
		}
		a[pos]++;m--;
	}
	minn=0;
	for(i=1;i<=n;i++) minn=max(minn,a[i]);
	cout<<minn<<' '<<maxn<<'\n';
}
