#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define link deep_dark_fantasy
#define ll long long
#define MOD 1000000007
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int n;ll a[510][510],b[510][510],inv[510][510],c[510][510];
int e[510][510]={0},link[510],vis[510];
void Gauss(){
	int i,j,k,num;ll tmp;
	for(i=1;i<=n;i++){
//		cout<<"******************\n";
//		for(j=1;j<=n;j++){
//			for(k=1;k<=n;k++) cout<<a[j][k]<<' ';
//			cout<<'\n';
//		}
//		for(j=1;j<=n;j++){
//			for(k=1;k<=n;k++) cout<<inv[j][k]<<' ';
//			cout<<'\n';
//		}
//		cout<<"******************\n";
		num=i;
		for(j=i+1;j<=n;j++){
			if(abs(a[num][i])<abs(a[j][i])) num=j;
		}
		if(num!=i) for(j=1;j<=n;j++) swap(a[i][j],a[num][j]),swap(inv[i][j],inv[num][j]);
		tmp=qpow(a[i][i],MOD-2);
		for(j=1;j<=n;j++){
			a[i][j]=(a[i][j]*tmp)%MOD;
			inv[i][j]=(inv[i][j]*tmp)%MOD;
		}
		for(j=1;j<=n;j++){
			if(i!=j&&a[j][i]){
				tmp=a[j][i];
				for(k=1;k<=n;k++){
					a[j][k]=(a[j][k]-(a[i][k]*tmp%MOD))%MOD;
					inv[j][k]=(inv[j][k]-(inv[i][k]*tmp%MOD))%MOD;
				}
			}
		}
	}
//	cout<<"******************\n";
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<a[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<inv[i][j]<<' ';
//		cout<<'\n';
//	}
//	cout<<"******************\n";
}
void Mul(){
	int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				c[i][j]=(c[i][j]+b[i][k]*inv[k][j]%MOD)%MOD;
			}
//			cout<<c[i][j]<<' ';
		}
//		cout<<'\n';
	}
}
int dfs(int u,int t){
//	cout<<"dfs "<<u<<' '<<t<<'\n'; 
	for(int i=1;i<=n;i++){
		if(e[u][i]&&vis[i]!=t){
			vis[i]=t;
			if(link[i]==-1||dfs(link[i],t)){
				link[i]=u;return 1;
			}
		}
	}
	return 0;
}
int dfs2(int u,int t,int k){
	if(u==t) return 1;
	for(int i=1;i<=n;i++){
		if(e[u][i]&&vis[i]!=k){
			vis[i]=k;
			if(dfs2(link[i],t,k)){
				link[i]=u;return 1;
			}
		}
	}
	return 0;
}
int main(){
//	freopen("4.in","r",stdin);
	n=read();int i,j,k;
	for(i=1;i<=n;i++){
		inv[i][i]=1;
		for(j=1;j<=n;j++) a[i][j]=read();
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) b[i][j]=read();
	}
	Gauss();Mul();
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(c[i][j]!=0)
				e[j][i]=1;
		}
	}
	memset(link,-1,sizeof(link));int cnt=0;
	for(i=1;i<=n;i++){
		if(dfs(i,i)) cnt++;
	}
	if(cnt<n){
		puts("NIE");return 0;
	}
	puts("TAK");
//	for(i=1;i<=n;i++) cout<<link[i]<<' ';cout<<'\n';
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) e[i-1][j]=0;
		for(j=1;j<=n;j++){
			if(e[i][j]&&vis[j]!=i){
				vis[j]=i;
				if(link[j]>=i&&dfs2(link[j],i,i)){
					link[j]=i;printf("%d\n",j);
					for(k=1;k<=n;k++) e[k][j]=0;
					break;
				}
			}
		}
	}
}
/*
3
1 0 0
0 1 0
0 0 1
2 3 0
0 7 8
0 0 9

2
10 6
5 3
4 0
6 3

*/
