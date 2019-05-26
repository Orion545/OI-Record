#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long lint;
#define cout cerr
#define ni (next_num<int>())
template<class T>inline T next_num(){
	T i=0;char c;
	for(;!isdigit(c=getchar())&&c!='-';);
	bool neg=c=='-';
	neg?c=getchar():0;
	for(;i=i*10-'0'+c,isdigit(c=getchar()););
	return neg?-i:i;
}
template<class A,class B>inline void apmax(A &a,const B &b){if(a<b)a=b;}
template<class A,class B>inline void apmin(A &a,const B &b){if(b<a)a=b;}
template<class T>inline void mset(T a[],int v,int n){memset(a,v,n*sizeof(T));}
template<class T>inline void mcpy(T a[],T b[],int n){memcpy(a,b,n*sizeof(T));}
const int N=100010;
const lint LINF=0x7f7f7f7f7fll;
int pval[N],stat[N];
namespace T{
	const int E=::N<<1;
	int to[E],bro[E],head[N],e=0;
	inline void init(int n){
		mset(head+1,-1,n);
	}
	inline void ae(int u,int v){
		to[e]=v,bro[e]=head[u],head[u]=e++;
	}
	inline void add(int u,int v){
		ae(u,v),ae(v,u);
	}
	lint f[N],g[N];
	void dfs(int x,int fa){
		f[x]=pval[x],g[x]=0;
		for(int i=head[x],v;~i;i=bro[i]){
			if((v=to[i])==fa)continue;
			dfs(v,x);
			f[x]+=g[v];
			g[x]+=f[v];
		}
		if(stat[x]==1){
			g[x]=LINF;
		}else if(stat[x]==-1){
			f[x]=LINF;
		}
		apmin(g[x],f[x]);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	const int n=ni;
	int tot=ni;
	{
		char s[10];
		scanf("%s",s);
	}
	for(int i=1;i<=n;i++){
		pval[i]=ni;
		stat[i]=0;
	}
	T::init(n);
	for(int i=1;i<n;i++){
		T::add(ni,ni);
	}
	for(;tot--;){
		const int a=ni;
		stat[a]=ni?1:-1;
		const int b=ni;
		stat[b]=ni?1:-1;
		T::dfs(1,0);
		stat[a]=stat[b]=0;
		const lint ans=T::g[1];
		printf("%lld\n",ans<LINF?ans:-1);
	}
	return 0;
}
