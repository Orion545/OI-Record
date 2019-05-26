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
const int N=50010;
int midv,ans;
namespace T{
	const int E=::N<<1;
	int to[E],bro[E],val[E],head[N],e=0;
	int f[N],lst[N],stk[N],que[N<<1];
	inline void init(int n){
		mset(head+1,-1,n);
		stk[0]=0;
	}
	inline void ae(const int u,const int v,const int w){
		to[e]=v,bro[e]=head[u],val[e]=w,head[u]=e++;
	}
	inline void add(const int u,const int v,const int w){
		ae(u,v,w),ae(v,u,w);
	}
	void dfs(int x,int fa){
		for(int i=head[x],v;~i;i=bro[i]){
			if((v=to[i])==fa)continue;
			dfs(v,x);
		}
		int ls=0,ss=0,qh=N,qt=N;
		for(int i=head[x],v;~i;i=bro[i]){
			if((v=to[i])==fa)continue;
			lst[++ls]=f[v]+val[i];
		}
		sort(lst+1,lst+ls+1);
		for(int i=1;i<=ls;i++){
			const int v=lst[i];
			if(v>=midv){
				++ans;
				continue;
			}
			for(;qh<qt&&que[qh]+v<midv;stk[++ss]=que[qh++]);
			for(;ss&&stk[ss]+v>=midv;que[--qh]=stk[ss--]);
			if(qh<qt){
				++ans,qh++;
			}else{
				que[qt++]=v;
			}
		}
		f[x]=qh<qt?que[qt-1]:stk[ss];
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	const int n=ni,m=ni;
	int l=0,r=0;
	T::init(n);
	for(int i=1;i<n;i++){
		const int u=ni,v=ni,w=ni;
		T::add(u,v,w);
		r+=w;
	}
	for(;l<r;){
		midv=((l+r)>>1)+1,ans=0;
		T::dfs(1,0);
		if(ans>=m){
			l=midv;
		}else{
			r=midv-1;
		}
	}
	printf("%d\n",l);
	return 0;
}
