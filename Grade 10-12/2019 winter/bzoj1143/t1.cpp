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
int a[110][110],n,m,vis[110],match[110];
bool dfs(int u){
	int i,v;
//	cout<<"dfs "<<u<<'\n';
	for(i=1;i<=n;i++){
		v=i;
		if(!a[u][v]||vis[v]) continue;
//		cout<<"	try "<<v<<' '<<match[v]<<'\n';
		vis[v]=1;
		if(!match[v]||dfs(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}
int main(){
	n=read();m=read();int i,j,k;
	for(i=1;i<=m;i++){
		j=read();k=read();
//		cout<<"read e "<<j<<' '<<k<<'\n';
		a[j][k]=1;
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			if(!a[i][k]) continue;
			for(j=1;j<=n;j++){
				if(!a[k][j]) continue;
//				cout<<"do "<<i<<' '<<k<<' '<<j<<'\n';
				a[i][j]=1;
			}
		}
	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<a[i][j];
//		cout<<'\n';
//	}
	int ans=n;
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ans-=dfs(i);
	}
	cout<<ans<<'\n';
}
