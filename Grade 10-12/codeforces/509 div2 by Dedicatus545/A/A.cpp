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
	int n=read(),tmp,i,maxn=0,minn=2e9;
	for(i=1;i<=n;i++){
		tmp=read();
		maxn=max(maxn,tmp);
		minn=min(minn,tmp);
	}
	cout<<maxn-minn+1-n<<'\n';
}
