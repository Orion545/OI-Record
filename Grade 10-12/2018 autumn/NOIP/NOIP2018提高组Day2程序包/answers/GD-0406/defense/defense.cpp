#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long lint;
const int N=1e5+5;
int n,m,hx[N],req[N];
lint dp[N][2];
char ch[5];

template <class T> inline void apn(T &x,const T y){
	if(x>y) x=y;
}

inline int nxi(){
	int x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}

namespace G{
	int cnt,fa[N],fir[N];
	struct edge{
		int to,nx;
	}eg[N<<1];

	inline void add(const int a,const int b){
		eg[++cnt]=(edge){b,fir[a]};
		fir[a]=cnt;
	}

	inline bool linked(const int a,const int b){
		for(int i=fir[a];i;i=eg[i].nx){
			if(eg[i].to==b) return 1;
		}
		return 0;
	}

	void dfs(const int x){
		dp[x][1]=hx[x];
		dp[x][0]=0;
		for(int i=fir[x];i;i=eg[i].nx){
			const int y=eg[i].to;
			if(y!=fa[x]){
				fa[y]=x;
				dfs(y);
				apn(dp[x][1]+=std::min(dp[y][1],dp[y][0]),(lint)1e16);
				apn(dp[x][0]+=dp[y][1],(lint)1e16);
			}
		}
		if(~req[x]) dp[x][req[x]^1]=1e16;
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(req,-1,sizeof(req));
	n=nxi(),m=nxi();
	scanf("%s",ch);
	for(int i=1;i<=n;++i){
		hx[i]=nxi();
	}
	for(int i=1;i<n;++i){
		const int a=nxi(),b=nxi();
		G::add(a,b);
		G::add(b,a);
	}
	for(int i=1;i<=m;++i){
		const int a=nxi(),x=nxi(),b=nxi(),y=nxi();
		if(!(x||y)&&G::linked(a,b)) puts("-1");
		else{
			req[a]=x,req[b]=y;
			G::dfs(1);
			printf("%lld\n",std::min(dp[1][0],dp[1][1]));
			req[a]=-1,req[b]=-1;
		}
	}
	return 0;
}
