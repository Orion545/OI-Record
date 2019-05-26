#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cctype>
#include <algorithm>
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
const int N=5010;
int n;
int ans[N];
int p=0,tp,tpe;
bool same,ovr;
namespace T{
	const int E=::N<<1;
	int to[E],bro[E],head[N],e=0;
	bool ban[E];
	bool vis[N];
	int fa[N];
	inline void init(int n){
		mset(head+1,-1,n);
		mset(vis+1,0,n);
		fa[1]=0;
	}
	inline void ae(int u,int v){
		to[e]=v,bro[e]=head[u],ban[e]=false,head[u]=e++;
	}
	inline void add(int u,int v){
		ae(u,v),ae(v,u);
	}
	static int elst[N];
	inline bool e_cmp(int a,int b){
		return to[a]<to[b];
	}
	inline void sortedge(int x){
		int ls=0;
		for(int i=head[x];~i;i=bro[i]){
			elst[++ls]=i;
		}
		sort(elst+1,elst+ls+1,e_cmp);
		head[x]=elst[1];
		for(int i=1;i<ls;i++){
			bro[elst[i]]=elst[i+1];
		}
		bro[elst[ls]]=-1;
	}
	int con[N];
	void dfsp(int x){
		vis[x]=true;
		for(int i=head[x],v;~i;i=bro[i]){
			if((v=to[i])==fa[x])continue;
			if(vis[v]){
				if(p==0){
					p=x,tp=v,tpe=i;
				}
			}else{
				con[v]=i;
				fa[v]=x;
				dfsp(v);
			}
		}
	}
	int tim;
	void dfsans(int x,int fa){
		++tim;
		if(same&&x!=ans[tim]){
			same=false;
			ovr=x<ans[tim];
		}
		if(!same&&ovr){
			ans[tim]=x;
		}
		for(int i=head[x],v;~i;i=bro[i]){
			if(ban[i])continue;
			if((v=to[i])==fa)continue;
			dfsans(v,x);
		}
	}
}
inline void toggle(int e){
	T::ban[e]^=1;
	T::ban[e^1]^=1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=ni;
	const int m=ni;
	T::init(n);
	for(int i=1;i<=m;i++){
		T::add(ni,ni);
	}
	for(int i=1;i<=n;i++){
		T::sortedge(i);
	}
	if(m==n){
		T::dfsp(1);
		toggle(tpe);
		T::tim=0,same=false,ovr=true,T::dfsans(1,0);
		toggle(tpe);
		for(int x=p;x!=tp;x=T::fa[x]){
			toggle(T::con[x]);
			T::tim=0,same=true,ovr=false,T::dfsans(1,0);
			toggle(T::con[x]);
		}
	}else{
		T::tim=0,same=false,ovr=true,T::dfsans(1,0);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	putchar('\n');
	return 0;
}
