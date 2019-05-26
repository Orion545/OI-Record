#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
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
int n,a[100010];
int gcd(int l,int r){return (r?gcd(r,l%r):l);}
int dfs(){
	int cnt=0,rec=0,tmp,i;
	for(i=1;i<=n;i++) ((a[i]&1)?(rec=i):(cnt++));
//	cout<<"dfs "<<cnt<<' '<<rec<<'\n';
	if(cnt&1) return 1;
	if(cnt<n-1||a[rec]==1) return 0;
	tmp=a[rec]-1;a[rec]--;
	for(i=1;i<rec;i++) tmp=gcd(tmp,a[i]);
	for(i+=2;i<=n;i++) tmp=gcd(tmp,a[i]);
	for(i=1;i<=n;i++) a[i]/=tmp;
	return !dfs();
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	puts((dfs()?"First":"Second"));
}
