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
int a[5010],f[5010][5010],maxn[5010][5010];
int n,q;
int main(){
	n=read();int i,t1,t2,l,r;
	for(i=1;i<=n;i++) a[i]=f[i][i]=maxn[i][i]=read();
	for(i=2;i<=n;i++){
		for(l=1;l<=n-i+1;l++){
			r=l+i-1;
			maxn[l][r]=f[l][r]=f[l][r-1]^f[l+1][r];
			maxn[l][r]=max(maxn[l][r],maxn[l][r-1]);
			maxn[l][r]=max(maxn[l][r],maxn[l+1][r]);
//			cout<<l<<ends<<r<<ends<<f[l][r]<<ends<<maxn[l][r]<<endl;
		}
	}
	q=read();
	while(q--){
		t1=read();t2=read();
		printf("%d\n",maxn[t1][t2]);
	
	}
}
