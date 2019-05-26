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
int tmp[12],n,vis[12];
bool ok[12]; 
int qpow(int l,int r){
	int re=1;
	while(r){
		if(r&1) re=(re*l)%n;
		l=l*l%n;r>>=1;
	}
	return re;
}
int add(int l,int r){
	return (l+r)%n;
}
void dfs(int u){
	int i;
	if(u==n){
		memset(ok,0,sizeof(ok));
		bool flag=1;
		for(i=0;i<n;i++){
			if(ok[add(tmp[i],i)]){
				flag=0;break;
			}
			else ok[add(tmp[i],i)]=1;
		}
		if(flag){
			puts("YES");
			for(i=0;i<n;i++) cout<<i<<' '<<tmp[i]<<'\n';
			exit(0);
		}
		return;
	}
	for(i=0;i<n;i++){
		if(vis[i]) continue;
		vis[i]=1;tmp[u]=i;
		dfs(u+1);
		vis[i]=0;
	}
}
int main(){
	n=read();dfs(0);
	puts("NO");
}
