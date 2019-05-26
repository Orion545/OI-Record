#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long int64;
typedef unsigned char uchar;

const int maxn(100000);
const int64 inf(1e12);

template<class _Tp>
	inline _Tp Min(const _Tp&x,const _Tp&y)
		{return x<y?x:y;}

namespace IOManager{
	const int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;

	struct IOManager{
		FILE*fin;

		IOManager():fin(fopen("defense.in","r")){}
		~IOManager(){fclose(fin);}

		inline char gc()
			{return(ibuf==tbuf)&&(tbuf=(ibuf=buf)+fread(buf,1,FILESZ,fin),ibuf==tbuf)?EOF:*ibuf++;}

		inline int gt(){
			char c=gc();
			for(;c!='A'&&c!='B'&&c!='C';c=gc());
			return(c-'A')*3+gc()-48;
		}

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

int p[maxn+1];

namespace task1{
	int64 dp[maxn+1][2];

	void calc(const int&u,const int&f){
		for(Edge*o=las[u];o;o=o->las)
			if(o->v!=f)
				calc(o->v,u),
				dp[u][0]+=dp[o->v][1],
				dp[u][1]+=Min(dp[o->v][0],dp[o->v][1]);
	}

	void solve(const int&n,int m){
		FILE*fout(fopen("defense.out","w"));
		for(;m;--m){
			const int a=io,x=io,b=io,y=io;
			if(!x&&!y){
				uchar flg=0;
				for(Edge*o=las[a];o;o=o->las)
					if(o->v==b)
						{flg=1;break;}
				if(flg){
					fputs("-1\n",fout);
					continue;
				}
			}

			for(int i=1;i<=n;++i)
				dp[i][0]=0,dp[i][1]=p[i];
			dp[a][!x]=dp[b][!y]=inf;

			calc(1,0);
			fprintf(fout,"%lld\n",Min(dp[1][0],dp[1][1]));
		}fclose(fout);
	}
}

namespace taskA{
	int qv;int64 del;uchar qd;
	struct Node{
		Node *ls,*rs;
		int64 v[2][2];

		static inline Node* newnode();

		inline void update(){
			v[0][0]=Min(Min(ls->v[0][0]+rs->v[1][0],ls->v[0][1]+rs->v[0][0]),ls->v[0][1]+rs->v[1][0]);
			v[0][1]=Min(Min(ls->v[0][0]+rs->v[1][1],ls->v[0][1]+rs->v[0][1]),ls->v[0][1]+rs->v[1][1]);
			v[1][0]=Min(Min(ls->v[1][0]+rs->v[1][0],ls->v[1][1]+rs->v[0][0]),ls->v[1][1]+rs->v[1][0]);
			v[1][1]=Min(Min(ls->v[1][0]+rs->v[1][1],ls->v[1][1]+rs->v[0][1]),ls->v[1][1]+rs->v[1][1]);
		}

		void setup(const int&l,const int&r){
			if(l==r)
				return(void)(v[0][0]=0,v[0][1]=v[1][0]=inf,v[1][1]=p[l]);
			int m=(l+r)>>1;
			ls=newnode();ls->setup(l,m);
			rs=newnode();rs->setup(m+1,r);
			update();
		}

		void update(const int&l,const int&r){
			if(l==r)
				return(void)(v[qd][qd]=del);
			int m=(l+r)>>1;
			if(qv<=m)
				ls->update(l,m);
			else rs->update(m+1,r);
			update();
		}
	};
	Node pool[maxn<<1],*alc=pool-1;
	inline Node* Node::newnode()
		{return++alc;}

	void solve(const int&n,int m){
		Node*rt=Node::newnode();
		FILE*fout(fopen("defense.out","w"));
		for(rt->setup(1,n);m;--m){
			const int a=io,x=io,b=io,y=io;
			del=inf;
			qv=a;qd=1-x;rt->update(1,n);
			qv=b;qd=1-y;rt->update(1,n);

			int64 t=Min(Min(rt->v[0][0],rt->v[0][1]),Min(rt->v[1][0],rt->v[1][1]));
			fprintf(fout,"%lld\n",inf<=t?-1:t);

			qv=a;qd=1-x;del=qd?p[a]:0;rt->update(1,n);
			qv=b;qd=1-y;del=qd?p[b]:0;rt->update(1,n);
		}fclose(fout);
	}
}

namespace taskB1{
	using task1::dp;
	int Fa[maxn+1];
	int64 t[maxn+1][2];

	void calc(const int&u){
		dp[u][1]=p[u];
		for(Edge*o=las[u];o;o=o->las)
			if(o->v!=Fa[u])
				Fa[o->v]=u,
				calc(o->v),
				dp[u][0]+=dp[o->v][1],
				dp[u][1]+=Min(dp[o->v][0],dp[o->v][1]);
	}

	void update(const int&u,const int&f){
		dp[u][0]+=dp[f][1]-t[f][1];
		dp[u][1]+=Min(dp[f][0],dp[f][1])-Min(t[f][0],t[f][1]);
		if(u!=1)
			update(Fa[u],u);
	}

	void redo(const int&u){
		dp[u][0]=t[u][0];
		dp[u][1]=t[u][1];
		if(u!=1)
			redo(Fa[u]);
	}

	void solve(const int&n,int m){
		FILE*fout(fopen("defense.out","w"));

		calc(1);
		for(int i=1;i<=n;++i)
			t[i][0]=dp[i][0],
			t[i][1]=dp[i][1];

		for(;m;--m){
			const int a=io,x=io,b=io,y=io;
			dp[b][!y]=inf;
			update(Fa[b],b);

			fprintf(fout,"%lld\n",inf<=dp[1][1]?-1:dp[1][1]);

			redo(b);
		}fclose(fout);
	}
}

int main(){
	const int n=io,m=io,tp=io.gt();
	for(int i=1;i<=n;++i)
		p[i]=io;
	for(int i=1;i<n;++i)
		AddEdge();

	if(n<=2000&&m<=2000)
		task1::solve(n,m);
	else if(tp<=3)
		taskA::solve(n,m);
	else if(tp<=6)
		taskB1::solve(n,m);

	return 0;
}
