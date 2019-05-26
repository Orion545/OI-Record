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
int a[200010],b[200010];
int main(){
	int n=read();int i,j,ans=1e9,tmp;
	for(i=1;i<=n;i++) a[i]=read(),a[i]-=i-1,a[i]=max(a[i],0);
	for(i=1;i<=n;i++){
		b[i]=(a[i]/n)+(a[i]%n>0);
		if(b[i]<ans) ans=b[i],tmp=i;
	}
	cout<<tmp;
}
