#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int N=50010;
int n,m;

template <class T> inline void xswp(T &x,T &y){
	if(x<y) std::swap(x,y);
}

template <class T> inline void apx(T &x,const T y){
	if(x<y) x=y;
}

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
	int cnt,fa[N],fir[N],dep1[N],dep2[N];
	struct edge{
		int to,wi,nx;
	}eg[N<<1];

	inline void add(const int a,const int b,const int v){
		eg[++cnt]=(edge){b,v,fir[a]};
		fir[a]=cnt;
	}

	void dfs1(const int x){
		for(int i=fir[x];i;i=eg[i].nx){
			const int y=eg[i].to;
			if(y!=fa[x]){
				fa[y]=x;
				dfs1(y);
				int tp=dep1[y]+eg[i].wi;
				xswp(dep1[x],tp);
				xswp(dep2[x],tp);
			}
		}
	}

	inline int get_ans(){
		int ans=0;
		for(int i=1;i<=n;++i){
			apx(ans,dep1[i]+dep2[i]);
		}
		return ans;
	}
}

namespace L{
	int dis[N];

	inline bool jdg(const int aim){
		int cnt=0,s=0;
		for(int i=2;i<=n;++i){
			if((s+=dis[i])>=aim) s=0,++cnt;
		}
		return cnt>=m;
	}

	inline int get_ans(){
		int l=1,r=1e9,mid;
		while(l!=r){
			mid=(l+r+1)>>1;
			if(jdg(mid)) l=mid;
			else r=mid-1;
		}
		return l;
	}

	inline int get_ans1(){
		std::sort(dis+2,dis+n+1);
		int tp=0,ans=1e9;
		if((m<<1)>n-1){
			tp=(m<<1)-(n-1);
			ans=dis[n-tp+1];
			m-=tp;
		}
		for(int i=1;i<=m;++i){
			apn(ans,dis[n-tp-(m<<1)+i]+dis[n-tp-i+1]);
		}
		return ans;
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=nxi(),m=nxi();
	if(m==1){
		for(int i=1;i<n;++i){
			const int a=nxi(),b=nxi(),v=nxi();
			G::add(a,b,v);
			G::add(b,a,v);
		}
		G::dfs1(1);
		printf("%d\n",G::get_ans());
	}
	else {
		bool f=0;
		for(int i=1;i<n;++i){
			const int a=nxi(),b=nxi(),v=nxi();
			if(a!=b-1) f=1;
			L::dis[b]=v;
		}
		if(f) printf("%d\n",L::get_ans1());
		else printf("%d\n",L::get_ans());
	}
	return 0;
}
