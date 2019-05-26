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
int n,c[200010],a[200010],vis[200010],s[200010],top,r[200010];
int dfs(int u){
//	cout<<"dfs "<<u<<'\n';
	if(r[u]){
		while(top) r[s[top--]]=1;
		return 0;
	}
	if(vis[u]){
		int minn=1e9,i;
		for(i=top;s[i]!=u;i--) minn=min(minn,c[s[i]]);
		minn=min(minn,c[s[i]]);
		while(top) r[s[top--]]=1;
		return minn;
	}
	s[++top]=u;vis[u]=1;
	return dfs(a[u]);
}
int main(){
	n=read();int i,ans=0;
	for(i=1;i<=n;i++) c[i]=read();
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++){
		if(r[i]) continue;
		
		if(i==a[i]) ans+=c[i],r[i]=vis[i]=1;
		else ans+=dfs(i);
	}
	cout<<ans<<'\n';
}

