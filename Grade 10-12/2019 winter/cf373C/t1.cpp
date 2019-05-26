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
int n,a[500010];
int main(){
	n=read();int i,j,ans=n;
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);j=n;
	for(i=n>>1;i>=1;i--){
		if(a[i]*2<=a[j]) ans--,j--;
	}
	cout<<ans<<'\n';
}
