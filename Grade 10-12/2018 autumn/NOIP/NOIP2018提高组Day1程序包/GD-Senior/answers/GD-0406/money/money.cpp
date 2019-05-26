#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int N=105;
int n,hx[N];
bool vis[25005];

inline int nxi(){
	int x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}

inline void mod(const int x){
	for(int i=0;i<x;++i){
		bool able=0;
		for(int j=i;j<N;j+=x){
			able|=vis[j];
			if(able) vis[j]=1;
		}
	}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=nxi();
	while(T--){
		memset(vis,0,sizeof(vis));
		vis[0]=1;
		n=nxi();
		for(int i=1;i<=n;++i){
			hx[i]=nxi();
		}
		std::sort(hx+1,hx+n+1);
		int ans=n;
		for(int i=1;i<=n;++i){
			if(!vis[hx[i]]) mod(hx[i]);
			else --ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
