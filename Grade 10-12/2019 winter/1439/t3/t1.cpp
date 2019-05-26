#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
inline int gcd(int l,int r){
	if(!r) return l;
	return gcd(r,l%r);
}
int n,mat[10][10],a[10];
inline void dfs(int l,int r,int sig){
	int i;
	if(abs(a[l])<abs(a[r])) swap(l,r);
//	cout<<"dfs "<<l<<' '<<r<<' '<<' '<<a[l]<<' '<<a[r]<<' '<<sig<<'\n';
	if(a[l]==0||a[r]==0){
		if(l!=1){
			int tmp=1;
			int &x=(r==1)?r:tmp;
			swap(x,l);swap(a[x],a[l]);
			dfs(l,r,-sig);
			for(i=1;i<=n;i++){
				swap(mat[i][l],mat[i][x]);
			}
			return;
		}
		memset(mat,0,sizeof(mat));
		memcpy(mat[1]+1,a+1,n*sizeof(int));
		sig*=a[1];
		for(i=2;i<n;i++) mat[i][i]=1;
		mat[n][n]=sig;
//		cout<<"reach end\n";
//		for(i=1;i<=n;i++){
//			for(int j=1;j<=n;j++) cout<<mat[i][j]<<' ';
//			cout<<'\n';
//		}
//		for(i=1;i<=n;i++) cout<<i<<' '<<a[i]<<'\n';
		return;
	}
	int w=a[l]/a[r];
	a[l]-=w*a[r];
	dfs(l,r,sig);
	for(i=1;i<=n;i++){
		mat[i][l]+=w*mat[i][r];
	}
	return;
}
int main(){
	n=read();int i,j,l=0,r=0;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			if(gcd(a[i],a[j])==1){
				l=i,r=j;
				break;
			}
		}
		if(l) break;
	}
	dfs(l,r,1);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",mat[i][j]);
		}
		puts("");
	}
}
