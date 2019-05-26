#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define base ddf
#include<cassert>
using namespace std;
const double E=2.718281828;
int n,m;double fac[20];
struct LCT{
	int fa[100010],ch[100010][2];double a[100010][20],w[100010][20];
	bool rev[100010],rt[100010];
	LCT(){
		memset(fa,0,sizeof(fa));memset(ch,0,sizeof(ch));
		memset(rev,0,sizeof(rev));
		memset(a,0,sizeof(a));memset(w,0,sizeof(w));
		for(int i=1;i<=100000;i++) rt[i]=1;
	}
	inline void update(int pos){
		int i;
		if(pos==0) return;
		assert(pos);
		assert(((w[0][0]-0)==0)&&((w[0][1]-0)==0)&&((w[0][2]-0)==0));
		for(i=0;i<=12;i++) 
			w[pos][i]=a[pos][i]+w[ch[pos][0]][i]+w[ch[pos][1]][i];
	}
	inline void pushrev(int pos){
		if(!pos) return;
		swap(ch[pos][0],ch[pos][1]);rev[pos]^=1;
	}
	inline void pushdown(int pos){
		if(pos==0) return;
		if(rev[pos]){
			pushrev(ch[pos][0]);
			pushrev(ch[pos][1]);
			rev[pos]=0;
		}
	}
	inline void push(int pos){
//		cout<<"push "<<pos<<endl;
		if(pos==0) return;
		if(!rt[pos]) push(fa[pos]);
		pushdown(pos);
	}
	inline bool get(int pos){
		return ch[fa[pos]][1]==pos;
	}
	inline void rotate(int pos){
		if(pos==0) return;
		int f=fa[pos],ff=fa[f],son=get(pos);
//		cout<<"rotate "<<pos<<ends<<f<<ends<<ff<<endl;
		assert(pos!=f);
		ch[f][son]=ch[pos][son^1];
		if(ch[pos][son^1]) fa[ch[pos][son^1]]=f;
		fa[f]=pos;ch[pos][son^1]=f;
		fa[pos]=ff;
		if(rt[f]) rt[pos]=1,rt[f]=0;
		else ch[ff][ch[ff][1]==f]=pos;
		update(f);update(pos);
	}
	inline void splay(int x){
//		cout<<"splay "<<x<<endl;
//		if(rt[x]) goto jump;
		push(x);
//		cout<<"finish push in splay\n";
		for(int f;!rt[x];rotate(x)){
			if(!rt[f=fa[x]]) rotate((get(f)==get(x))?f:x);
		}
		update(x);
	}
	inline void access(int x){
//		cout<<"access "<<x<<endl;
		int y=0;
		do{
			splay(x);
			rt[ch[x][1]]=1;
			rt[ch[x][1]=y]=0;
			update(x);
			x=fa[y=x];
			update(x);
		}while(x);
	}
	inline void mroot(int pos){
		access(pos);splay(pos);pushrev(pos);
	}
	inline int find(int pos){
//		cout<<"find "<<pos<<endl; 
		access(pos);
//		cout<<"finish access in find!\n";
		splay(pos);
//		cout<<"finish access and splay in find!\n";
		while(ch[pos][0]) pos=ch[pos][0];
		splay(pos);
		return pos;
	}
	inline void link(int l,int r){
		mroot(l);fa[l]=r;
	}
	inline void cut(int l,int r){
		mroot(l);access(r);splay(r);
		fa[ch[r][0]]=fa[r];
		rt[ch[r][0]]=1;
		fa[r]=0;ch[r][0]=0;
	}
	inline int split(int l,int r){
		if(find(l)!=find(r)) return 0;
//		cout<<"split "<<l<<ends<<r<<endl;
		mroot(l);access(r);splay(r);return 1;
	}
	inline double getans(int pos,double x){
		int i;double re=0,powx=1.0;
		for(i=0;i<=12;i++){
			re+=powx/fac[i]*w[pos][i];
//			cout<<"getans "<<i<<ends<<powx<<ends<<w[pos][i]<<ends<<fac<<ends<<re<<endl;
			powx*=x;
		}
		return re;
	}
	inline void change(int pos,int type,double aa,double bb){
		mroot(pos);
		if(type==1){
			int i;double powa=1.0;
			for(i=0;i<=12;i++){
				if(i%4==0) a[pos][i]=sin(bb)*powa;
				if(i%4==1) a[pos][i]=cos(bb)*powa;
				if(i%4==2) a[pos][i]=-sin(bb)*powa;
				if(i%4==3) a[pos][i]=-cos(bb)*powa;
				powa*=aa;
			}
		}
		if(type==2){
			int i;double base=pow(E,bb),powa=1.0;
			a[pos][0]=base;
			for(i=1;i<=12;i++){
				powa*=aa;
				a[pos][i]=base*powa;
			}
		}
		if(type==3){
			a[pos][0]=bb;a[pos][1]=aa;
		}
		update(pos);
	}
}T;
int main(){
	freopen("b10.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d%d",&n,&m);char s[15];scanf("%s",s);int i,t1,t2;double t5,t3,t4;
	fac[0]=fac[1]=1;
	for(i=2;i<=16;i++) fac[i]=fac[i-1]*(double)i;
	for(i=1;i<=n;i++){
		scanf("%d%lf%lf",&t1,&t5,&t3);
		T.change(i,t1,t5,t3);
	}
	for(i=1;i<=m;i++){
		scanf("%s",s);scanf("%d%d",&t1,&t2);
		if(s[0]=='a') T.link(t1+1,t2+1);
		if(s[0]=='d') T.cut(t1+1,t2+1);
		if(s[0]=='m') scanf("%lf%lf",&t3,&t4),T.change(t1+1,t2,t3,t4);
		if(s[0]=='t'){
			scanf("%lf",&t3);
			if(T.split(t1+1,t2+1)) printf("%.13lf\n",T.getans(t2+1,t3));
			else puts("unreachable");
		}
//		cout<<"********finish do "<<i<<ends<<s<<ends<<t1<<ends<<t2<<endl;
	}
}
