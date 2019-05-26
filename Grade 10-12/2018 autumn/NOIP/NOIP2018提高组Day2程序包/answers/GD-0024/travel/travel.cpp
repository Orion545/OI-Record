#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long int64;
typedef unsigned char uchar;

const int maxn(100000);

namespace IOManager{
	const int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;

	struct IOManager{
		FILE*fin;

		IOManager():fin(fopen("travel.in","r")){}
		~IOManager(){fclose(fin);}
		
		inline char gc()
			{return(ibuf==tbuf)&&(tbuf=(ibuf=buf)+fread(buf,1,FILESZ,fin),ibuf==tbuf)?EOF:*ibuf++;}

		template<class _Tp>
			inline operator _Tp(){
				_Tp s=0;char c=gc();
				for(;c<'0'||'9'<c;c=gc());
				for(;'0'<=c&&c<='9';c=gc())
					s=s*10+c-48;
				return s;
			}
	};
}IOManager::IOManager io;

struct Edge{
	int v;Edge*las;
	inline Edge* init(const int&to,Edge*const&ls)
		{return v=to,las=ls,this;}
}*las[maxn+1];

inline void AddEdge(){
	static Edge pool[maxn<<1],*alc=pool-1;
	const int u=io,v=io;
	las[u]=(++alc)->init(v,las[u]);
	las[v]=(++alc)->init(u,las[v]);
}

FILE*fout(fopen("travel.out","w"));

int vecpool[maxn<<1],
	*vecalc=vecpool;

namespace tree{
	void calc(const int&u,const int&f){
		fprintf(fout,"%d ",u);
		int*const s=vecalc+1;
		for(Edge*o=las[u];o;o=o->las)
			if(o->v!=f)
				*++vecalc=o->v;
		int*const t=vecalc+1;
  		std::sort(s,t);
  		for(int*i=s;i!=t;++i)
			calc(*i,u);
	}
}

namespace rbtree{
	int deg[maxn+1],
		q[maxn+1],
		r[maxn+1],
		*cr=r,
		*dell,
		*delr,
		ans[maxn+1],
		tans[maxn+1],*ca;
	uchar nr[maxn+1],
		hs[maxn+1];
		
	inline bool opt(const int&n){
		for(int i=1;i<=n;++i)
			if(ans[i]!=tans[i])
				return tans[i]<ans[i];
		return false;
	}

	void precalcr(const int&u){
		hs[*++cr=u]=1;
		for(Edge*o=las[u];o;o=o->las)
			if(!nr[o->v]&&!hs[o->v])
				return precalcr(o->v);
	}
	
	inline bool is(const int&u,const int&v)
		{return(u==*dell&&v==*delr)||(u==*delr&&v==*dell);}

	void calc(const int&u,const int&f){
		*++ca=u;
		int*const s=vecalc+1;
		for(Edge*o=las[u];o;o=o->las)
			if(o->v!=f&&!is(u,o->v))
				*++vecalc=o->v;
		int*const t=vecalc+1;
  		std::sort(s,t);
  		for(int*i=s;i!=t;++i)
			calc(*i,u);
	}

	inline void solve(const int&n){
		for(int u=1;u<=n;++u)
			for(Edge*o=las[u];o;o=o->las)
				++deg[u];

		int*ql=q,*qr=q;
		for(int u=1;u<=n;++u)
			if(deg[u]==1)
				nr[*qr++=u]=1;
		for(;ql<qr;){
			const int u=*ql++;
			for(Edge*o=las[u];o;o=o->las)
				if(!nr[o->v]&&--deg[o->v]<=1)
					nr[*qr++=o->v]=1;
		}

		for(int u=1;u<=n;++u)
			if(!nr[u]){
				precalcr(u);
				break;
			}

		memset(ans,0x3f,sizeof ans);
		for(dell=cr,delr=r+1;delr<=cr;dell=delr,++delr)
			if(ca=tans,vecalc=vecpool,calc(1,0),opt(n))
				std::copy(tans+1,tans+n+1,ans+1);

		for(int i=1;i<=n;++i)
			fprintf(fout,"%d ",ans[i]);
	}
}

int main(){
	const int n=io,m=io;
	for(int i=1;i<=m;++i)
		AddEdge();
 	if(m==n-1)
		tree::calc(1,0);
	else
		rbtree::solve(n);
	fclose(fout);
	
	return 0;
}
