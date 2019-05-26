#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
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
int n,m,sg[110],cnt[200010],k[110],out[110];
bool vis[110][200010];
vector<int>e[110];
int getsg(int u){
//	cout<<"getsg "<<u<<' '<<sg[u]<<'\n';
	if(~sg[u]) return sg[u];
	if(!out[u]) return sg[u]=0;
	for(auto v:e[u]){
		if(sg[v]==-1) sg[v]=getsg(v);
	}
	int i,j,s,v;
	memset(vis[u],0,sizeof(vis[u]));
	for(i=0;i<(1<<out[u]);i++){
		if(cnt[i]>k[u]) continue;
		if((cnt[i]&1)^(k[u]&1)) continue;
//		cout<<"	choosing "<<u<<' '<<i<<' '<<'\n';
		s=0;
		for(j=0;j<out[u];j++){
			if((1<<j)&i){
				v=e[u][j];
				s^=sg[v];
			}
		}
		vis[u][s]=1;
	}
	for(i=0;i<(1<<out[u]);i++) if(!vis[u][i]) return sg[u]=i;
}
int bitcnt(int x){
	int re=0;
	while(x){
		re++;
		x&=(x-1);
	}
	return re;
}
int main(){
	int T=read(),i,j,t1,t2,Q,cc;
	for(i=1;i<(1<<17);i++) cnt[i]=bitcnt(i);
	for(cc=1;cc<=T;cc++){
		printf("Game#%d:\n",cc);
		n=read();m=read();
		memset(out,0,sizeof(out));memset(k,0,sizeof(k));
		memset(sg,-1,sizeof(sg));
		memset(e,0,sizeof(e));
		for(i=1;i<=m;i++){
			t1=read();t2=read();t1++;t2++;
			e[t1].push_back(t2);
			out[t1]++;
		}
		for(i=1;i<=n;i++) k[i]=read();
		Q=read();
		for(j=1;j<=Q;j++){
			t2=0;
			for(i=1;i<=n;i++){
				t1=read();
				if(t1&1) t2^=getsg(i);
			}
			printf("Round#%d: ",j);
			if(t2) puts("WINNING");
			else puts("LOSING");
		}
		puts("");
	}
}
