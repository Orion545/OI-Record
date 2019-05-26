#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL LINF=1ll<<50;
const int N=100010;
int n,m,type;
int w[N];
namespace T{
	int h[N],tot;
	struct Edge{
		int v,next;
	}e[N*2];
	void addEdge(int u,int v){
		e[++tot]=(Edge){v,h[u]}; h[u]=tot;
		e[++tot]=(Edge){u,h[v]}; h[v]=tot;
	}
}
int getType(char *str){
	return (str[0]-'A')*3+(str[1]-'1');
}
void readData(){
	static char typeStr[5];
	scanf("%d%d%s",&n,&m,typeStr);	
	type=getType(typeStr);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		T::addEdge(u,v);
	}
}
namespace EDP{
	int a,x,b,y;
	LL f[N][2];
	void dfs(int u,int fa){
		f[u][0]=0;
		f[u][1]=w[u];
		for(int i=T::h[u],v;i;i=T::e[i].next)
			if((v=T::e[i].v)!=fa){
				dfs(v,u);
				f[u][0]+=f[v][1];
				f[u][1]+=min(f[v][0],f[v][1]);
			}
		int req=-1;
		if(a==u) req=x;
		if(b==u) req=y;
		if(req!=-1){
			if(req==0)
				f[u][1]=LINF;
			else
				f[u][0]=LINF;
		}
	}
	void main(){
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			dfs(1,0);
			int req=-1;
			if(a==1) req=x;
			if(b==1) req=y;
			LL ans=(req==-1)?min(f[1][0],f[1][1]):f[1][req];
			printf("%lld\n",ans<LINF?ans:-1);
		}
	}
}
namespace CHAIN{
	namespace SEG{
		const int S=N*2;
		int rt,sz;
		int ch[S][2];
		LL f[S][2][2];
		void pushup(int u){
			int lc=ch[u][0],rc=ch[u][1];
			for(int l=0;l<2;l++)
				for(int r=0;r<2;r++)
					f[u][l][r]=min(LINF,min(f[lc][l][0]+f[rc][1][r],f[lc][l][1]+min(f[rc][0][r],f[rc][1][r])));
		}
		void build(int &u,int l,int r){
			u=++sz;
			if(l==r){
				f[u][0][0]=0;
				f[u][1][1]=w[l];
				f[u][0][1]=f[u][1][0]=LINF;
				return;
			}
			int mid=(l+r)>>1;
			build(ch[u][0],l,mid);
			build(ch[u][1],mid+1,r);
			pushup(u);
		}
		void extract(int u,int l,int r,int ql,int qr,int *lis){
			if(ql<=l&&r<=qr){
				lis[++lis[0]]=u;
				return;
			}
			int mid=(l+r)>>1;
			if(qr<=mid)
				extract(ch[u][0],l,mid,ql,qr,lis);
			else if(mid<ql)
				extract(ch[u][1],mid+1,r,ql,qr,lis);
			else{
				extract(ch[u][0],l,mid,ql,mid,lis);
				extract(ch[u][1],mid+1,r,mid+1,qr,lis);
			}
		}
	}
	void calc(LL ff[2][2],int l,int r){
		if(l>r)
			return;
		using SEG::f;
		static int lis[N];
		lis[0]=0;
		SEG::extract(SEG::rt,1,n,l,r,lis);
		static LL g[2],t[2];
		g[0]=f[lis[1]][0][0]; g[1]=f[lis[1]][0][1];
		for(int i=2;i<=lis[0];i++){
			int u=lis[i];
			t[0]=min(min(g[0],g[1])+f[u][1][0],g[1]+f[u][0][0]);
			t[1]=min(min(g[0],g[1])+f[u][1][1],g[1]+f[u][0][1]);
			g[0]=t[0];
			g[1]=t[1];
		}
		ff[0][0]=g[0]; ff[0][1]=g[1];
		g[0]=f[lis[1]][1][0]; g[1]=f[lis[1]][1][1];
		for(int i=2;i<=lis[0];i++){
			int u=lis[i];
			t[0]=min(min(g[0],g[1])+f[u][1][0],g[1]+f[u][0][0]);
			t[1]=min(min(g[0],g[1])+f[u][1][1],g[1]+f[u][0][1]);
			g[0]=t[0];
			g[1]=t[1];
		}
		ff[1][0]=g[0]; ff[1][1]=g[1];
	}
	void main(){
		SEG::build(SEG::rt,1,n);
		int a,x,b,y;
		static LL f1[2][2],f2[2][2],f3[2][2],f[2];
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(a>b){
				swap(a,b);
				swap(x,y);
			}
			calc(f1,1,a-1);
			calc(f2,a+1,b-1);
			calc(f3,b+1,n);
			if(a>1){
				f[0]=min(f1[0][0],f1[1][0]);
				f[1]=min(f1[0][1],f1[1][1]);
			}
			else
				f[0]=f[1]=0;
			if(!x){
				f[0]=f[1];
				f[1]=LINF;
			}
			else{
				f[1]=min(f[0],f[1])+w[a];
				f[0]=LINF;
			}
			if(a+1<b){
				static LL t[2];
				t[0]=min(min(f[0],f[1])+f2[1][0],f[1]+f2[0][0]);
				t[1]=min(min(f[0],f[1])+f2[1][1],f[1]+f2[0][1]);
				f[0]=t[0];
				f[1]=t[1];
			}
			if(!y){
				f[0]=f[1];
				f[1]=LINF;
			}
			else{
				f[1]=min(f[0],f[1])+w[b];
				f[0]=LINF;
			}
			if(b<n){
				static LL t[2];
				t[0]=min(min(f[0],f[1])+f3[1][0],f[1]+f3[0][0]);
				t[1]=min(min(f[0],f[1])+f3[1][1],f[1]+f3[0][1]);
				f[0]=t[0];
				f[1]=t[1];
			}
			LL ans=min(f[0],f[1]);
			printf("%lld\n",ans<LINF?ans:-1);
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	readData();
	if(n<=2000&&m<=2000)
		EDP::main();
	else if(type<3) // chain
		CHAIN::main();
	else
		EDP::main();
	return 0;
}
