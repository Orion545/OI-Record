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
ll gcd(ll l,ll r){
	if(r==0) return l;
	return gcd(r,l%r);
}
int n,a[1010];bool l[710][710],r[710][710],g[710][710];
int main(){
	n=read();int i,j,k,len;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			g[i][j]=(gcd(a[i],a[j])!=1);
		}
	}
	for(i=1;i<=n;i++){
		if(i!=1) r[i][i]=(gcd(a[i-1],a[i])!=1);
		if(i!=n) l[i][i]=(gcd(a[i],a[i+1])!=1);
//		cout<<i<<' '<<i<<' '<<l[i][i]<<' '<<r[i][i]<<'\n';
	}
	for(len=2;len<n;len++){
		for(i=1;i<=n;i++){
			j=i+len-1;if(j>n) break;
			if(j==n) l[i][j]=0;
			else{
				l[i][j]=((g[i][j+1]&r[i+1][j])|(g[j][j+1]&l[i][j-1]));
				for(k=i+1;k<=j-1;k++){
					l[i][j]|=(g[k][j+1]&l[i][k-1]&r[k+1][j]);
					if(l[i][j]==1) break;
				}
			}
			if(i==1) r[i][j]=0;
			else{
				r[i][j]=((g[i][i-1]&r[i+1][j])|(g[j][i-1]&l[i][j-1]));
				for(k=i+1;k<=j-1;k++){
					r[i][j]|=(g[k][i-1]&l[i][k-1]&r[k+1][j]);
					if(r[i][j]==1) break;
				}
			}
//			cout<<i<<' '<<j<<' '<<l[i][j]<<' '<<r[i][j]<<'\n'; 
		}
	}
	int ans=0;
	ans|=(r[2][n]|l[1][n-1]);
	for(i=2;i<n;i++) ans|=(l[1][i-1]&&r[i+1][n]);
	if(ans) puts("Yes");
	else puts("No");
} 
