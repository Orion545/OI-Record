#include<cstdio>
#include<algorithm>

typedef long long int64;
typedef unsigned char uchar;

const int maxn(50000);

namespace IOManager{
	const int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;
	
	struct IOManager{
		FILE*fin;
		
		IOManager():fin(fopen("track.in","r")){}
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
	int v,w;Edge*las;
	inline Edge* init(const int&to,const int&val,Edge*const&ls)
		{return v=to,w=val,las=ls,this;}
}*las[maxn+1];

inline int AddEdge(){
	static Edge pool[maxn<<1],*alc=pool-1;
	const int u=io,v=io,w=io;
	las[u]=(++alc)->init(v,w,las[u]);
	las[v]=(++alc)->init(u,w,las[v]);
	return w;
}

int vecpool[maxn<<1],
	*vecalc=vecpool,
	*vec[maxn+1];
uchar vispool[maxn<<1],
	*visalc=vispool,
	*vis[maxn+1];

void precalc(const int&u,const int&f){
	int s=0;
	for(Edge*o=las[u];o;o=o->las)
		if(o->v!=f)
			precalc(o->v,u),++s;
	vec[u]=vecalc;vecalc+=s;
	vis[u]=visalc;visalc+=s;
}

int lim,cnt;

int calc(const int&u,const int&f){
	int *r=vec[u],t;
	uchar *vr=vis[u];
	for(Edge*o=las[u];o;o=o->las)
		if(o->v!=f){
			if(lim<=(t=calc(o->v,u)+o->w))
				++cnt;
			else*++r=t,*++vr=0;
		}

	if(vec[u]+1<r)
		std::sort(vec[u]+1,r+1);
	else return vec[u]==r?0:*r;

	int *l=vec[u]+1;
	uchar *vl=vis[u]+1;
	for(;l<r;){
		for(;l<r&&*l+*r<lim;++l,++vl);
		if(l<r&&lim<=*l+*r)
			*vl=*vr=1,++cnt,
			++l,++vl,--r,--vr;
	}

	for(;vec[u]<r;--r,--vr)
		if(!*vr)
			return*r;
	return 0;
}

int main(){
	const int n=io,m=io;
	int l=0,r=0;
	for(int i=n-1;i;--i)
		r+=AddEdge();

	for(precalc(1,0);l<r;cnt=0)
		lim=(l+r+1)>>1,calc(1,0),
		m<=cnt?(l=lim):(r=lim-1);

	FILE*fout=fopen("track.out","w");
	fprintf(fout,"%d",l);
	fclose(fout);

	return 0;
}

