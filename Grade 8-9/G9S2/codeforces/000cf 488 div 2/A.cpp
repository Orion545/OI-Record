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
int n,m,a[110],b[110],ans[110];
int main(){
	n=read();m=read();int i,j=0,t1;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=m;i++) t1=read(),b[t1]=1;
	for(i=1;i<=n;i++) if(b[a[i]]) j++,ans[j]=a[i];
	for(i=1;i<=j;i++) cout<<ans[i]<<' ';
}
