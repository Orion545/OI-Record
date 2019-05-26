#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
const int N=5010;
struct edg{int y,nex;}e[N<<1]; int len,fir[N];
void ins(int x,int y){
	e[++len].y=y,e[len].nex=fir[x],fir[x]=len;
}
int n,m,q[N],ql,fa[N],fc,mn; bool c[N],v[N],ju;
void dfs(int x){
	v[x]=1;
	for(int k=fir[x];k;k=e[k].nex){
		int y=e[k].y; if(y==fa[x]||c[y])continue;
		if(v[y]){
			int u=x;
			while(u!=y){
				c[u]=1,u=fa[u];
			}
			c[y]=1;
		}
		else {fa[y]=x; dfs(y);}
	}
}
vector<int>p[N];
void tr(int x){
	q[++ql]=x; v[x]=1; int z=0;
	p[x].clear();
	for(int k=fir[x];k;k=e[k].nex){
		int y=e[k].y; if(v[y])continue;
		p[x].push_back(y); ++z;
	}
	if(!z) return;
	sort(p[x].begin(),p[x].end());
	for(int k=0;k<z;++k) tr(p[x][k]);
}
void qwer(int x){
	if(v[x]) return;
	q[++ql]=x; v[x]=1; int z=0;
	if(c[x] && !fc) fc=x;
	for(int k=fir[x];k;k=e[k].nex){
		int y=e[k].y; if(v[y])continue;
		p[x].push_back(y); ++z;
	}
	sort(p[x].begin(),p[x].end());
	if(fc==x){
		for(int k=0;k<z;++k){
			if(k<z-1 && !ju) mn=p[x][k+1];
			qwer(p[x][k]);
		}
	}
	else if(c[x]){
		int o;
		for(int k=0;k<z-1;++k){
			if(c[p[x][k]]) ju=1;
			qwer(p[x][k]);
		}
		if(z){
			o=p[x][z-1];
			if(c[o]){
				if(o<mn || ju) qwer(o);
				else {ju=1; qwer(mn);}
			}
			else qwer(o);
		}
	}
	else{
		for(int k=0;k<z;++k)qwer(p[x][k]);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	int i,o=0; ql=0;
	memset(c,0,sizeof c);
	memset(v,0,sizeof v);
	for(i=1;i<=m;++i){
		int x=read(),y=read();
		ins(x,y),ins(y,x);
	}
	if(n==m){
		dfs(1); fc=0,ju=0,mn=n+1;
		memset(v,0,sizeof v);
		qwer(1);
	}
	else tr(1);
	for(i=1;i<n;++i) printf("%d ",q[i]);
	printf("%d\n",q[n]);
	return 0;
}
