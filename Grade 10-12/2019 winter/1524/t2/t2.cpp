#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct mat{
	int a00,a01,a10,a11;
	mat(){a00=a01=a10=a11=0;}
	void init(int a,int b){a00=a01=a;a10=b;a11=-1e9;}
	inline mat operator *(const mat &b){
		mat re;
		re.a00=max(a00+b.a00,a01+b.a10);
		re.a01=max(a00+b.a01,a01+b.a11);
		re.a10=max(a10+b.a00,a11+b.a10);
		re.a11=max(a10+b.a01,a11+b.a11);
		return re;
	}
};
int n;
namespace lct{
	int ch[300010][2],fa[300010],rev[300010],f[300010][2];
	mat a[300010];
	inline void update(int cur){
		a[cur].init(f[cur][0],f[cur][1]);
		if(ch[cur][0]) a[cur]=a[ch[cur][0]]*a[cur];
		if(ch[cur][1]) a[cur]=a[cur]*a[ch[cur][1]];
	}
	inline void pushrev(int cur){
		if(!cur) return;
		swap(ch[cur][0],ch[cur][1]);
		rev[cur]^=1;
	}
	inline void pushdown(int cur){
		if(!rev[cur]) return;
		pushrev(ch[cur][0]);
		pushrev(ch[cur][1]);
		rev[cur]=0;
	}
	inline bool nroot(int cur){return ch[fa[cur]][0]==cur||ch[fa[cur]][1]==cur;}
	inline void push(int cur){
		if(nroot(cur)) push(fa[cur]);
		pushdown(cur);
	}
	inline bool get(int cur){return ch[fa[cur]][1]==cur;}
	inline void rotate(int cur){
		int f=fa[cur],ff=fa[f],son=get(cur),nr=nroot(f);
		ch[f][son]=ch[cur][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=cur;ch[cur][son^1]=f;
		fa[cur]=ff;
		if(nr) ch[ff][ch[ff][1]==f]=cur;
		update(f);update(cur);
	}
	inline void splay(int x){
		push(x);
		for(int f=fa[x];nroot(x);rotate(x)){
			f=fa[x];
			if(nroot(f))
				rotate((get(x)==get(f))?f:x);
		}
	}
	inline void access(int x){
		for(int y=0;x;y=x,x=fa[x]){
			splay(x);
			if(ch[x][1]){
				f[x][0]+=max(a[ch[x][1]].a00,a[ch[x][1]].a10);
				f[x][1]+=a[ch[x][1]].a00;
			}
			ch[x][1]=y;
			if(ch[x][1]){
				f[x][0]-=max(a[ch[x][1]].a00,a[ch[x][1]].a10);
				f[x][1]-=a[ch[x][1]].a00;
			}
			update(x);
		}
	}
	inline int link(int x,int y){
//		cout<<"link "<<x<<' '<<y<<'\n';
		access(x);splay(x);
		ch[y][0]=ch[y][1]=0;fa[y]=x;
		f[y][0]=0;f[y][1]=1;rev[y]=0;
		a[y].init(0,1);
		f[x][0]++;
		update(x);
		access(1);splay(1);
		return max(a[1].a00,a[1].a10);
	}
}
int main(){
	n=read();int i,ff,type=read(),lans=0;
	n++;
	using namespace lct;
	ch[1][0]=ch[1][1]=fa[1]=rev[1]=0;
	f[1][0]=0;f[1][1]=1;
	a[1].init(0,1);
	for(i=2;i<=n;i++){
		ff=read();
		ff=ff^(type*lans);
		ff++;
		printf("%d\n",lans=link(ff,i));
	}
}
