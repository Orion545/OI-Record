#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll f[1050][1050],n,m;//dp[i][j]:subtree(i),black leaf j,maximum value 
ll bl[1050][20],wh[1050][20],tmp[20];
void dfs(ll u,ll dep){
	ll i,j,lim=min(m,(1ll<<(dep-1)));
//	cout<<"dfs "<<u<<' '<<dep<<'\n';
	memset(f[u],0,sizeof(f[u]));
	if(dep==0){
		for(i=1;i<n;i++){
//			cout<<"	end "<<i<<' '<<tmp[i]<<' '<<bl[u][i]<<' '<<wh[u][i]<<'\n';
			if(tmp[i]) f[u][1]+=bl[u][i];
			else f[u][0]+=wh[u][i];
		}
//		cout<<"	val of end "<<u<<' '<<f[u][0]<<' '<<f[u][1]<<'\n';
		return;
	}
	tmp[dep]=1;dfs(u<<1,dep-1);dfs((u<<1)|1,dep-1);
	for(i=0;i<=lim;i++){
		for(j=0;j<=lim;j++){
			if(i+j>m) break;
			f[u][i+j]=max(f[u][i+j],f[u<<1][i]+f[(u<<1)|1][j]);
		}
	}
	
	tmp[dep]=0;dfs(u<<1,dep-1);dfs((u<<1)|1,dep-1);
	for(i=0;i<=lim;i++){
		for(j=0;j<=lim;j++){
			if(i+j>m) break;
			f[u][i+j]=max(f[u][i+j],f[u<<1][i]+f[(u<<1)|1][j]);
		}
	}
}
int main(){
	n=read();m=read();ll i,j;
	for(i=1;i<=(1<<(n-1));i++){
		for(j=1;j<n;j++) bl[(1<<(n-1))+i-1][j]=read();
	}
	for(i=1;i<=(1<<(n-1));i++){
		for(j=1;j<n;j++) wh[(1<<(n-1))+i-1][j]=read();
	}
	dfs(1,n-1);
	ll ans=0;
	for(i=0;i<=m;i++) ans=max(ans,f[1][i]);
	printf("%lld\n",ans);
}

