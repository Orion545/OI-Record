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
int n,m;
namespace lct{
	int ch[200010][2],fa[200010],siz[200010];
	inline void update(int cur){
		siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
	}
	inline bool nroot(int cur){
		return ch[fa[cur]][0]==cur||ch[fa[cur]][1]==cur;
	}
	inline bool get(int cur){
		return ch[fa[cur]][1]==cur;
	}
	inline void rotate(int cur){
		int f=fa[cur],ff=fa[f],son=get(cur);
//		cout<<"	rotate "<<cur<<' '<<f<<' '<<ff<<'\n';
		assert(cur!=f);
		ch[f][son]=ch[cur][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=cur;ch[cur][son^1]=f;
		fa[cur]=ff;
		if(ff) ch[ff][ch[ff][1]==f]=cur;
		update(f);update(cur);
	}
	inline void splay(int cur){
//		cout<<"	splay "<<cur<<' '<<fa[cur]<<'\n';
		for(int f;nroot(cur);rotate(cur)){
			if(nroot(f=fa[cur]))
				rotate((get(cur)==get(f))?f:cur);
		}
		assert(nroot(cur)==0);
	}
	inline void access(int x){
//		cout<<"access "<<x<<' '<<fa[x]<<'\n';
		for(int y=0;x;y=x,x=fa[x]){
			splay(x);ch[x][1]=y;update(x);
		}
	}
	inline void link(int x,int y){
		access(x);splay(x);
		fa[ch[x][0]]=0;
		ch[x][0]=0;fa[x]=y;
		update(x);
	}
	inline int query(int x){
		access(x);splay(x);
		return siz[ch[x][0]];
	}
}
int main(){
	n=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++){
		t1=read()+i;if(t1>n) t1=n+1;
		lct::fa[i]=t1;lct::siz[i]=1;
	}
	m=read();
	lct::siz[n+1]=1;lct::fa[n+1]=0;
//	for(i=1;i<=n+1;i++) cout<<i<<' '<<lct::fa[i]<<'\n';
	while(m--){
		t1=read();
		if(t1==1){
			t2=read()+1;
			printf("%d\n",lct::query(t2));
		}
		else{
			t2=read()+1;t3=read();
			t3=t2+t3;if(t3>n) t3=n+1;
			lct::link(t2,t3);
		}
	}
}
