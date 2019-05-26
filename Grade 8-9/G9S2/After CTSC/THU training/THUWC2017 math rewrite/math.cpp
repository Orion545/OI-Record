#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
int n,fac[15];
struct LCT{
	int fa[100010],ch[100010][2];double w[100010][15],a[100010][15];
	bool rev[100010];
	LCT(){
		memset(fa,0,sizeof(fa));
		memset(ch,0,sizeof(ch));
		memset(a,0,sizeof(a));
		memset(w,0,sizeof(w));
	}
	inline bool nroot(int pos){
//		if(!pos) return 1;
		if(fa[pos]==0) return 0;
//		cout<<"nroot "<<pos<<ends<<fa[pos]<<ends<<ch[fa[pos]][0]<<ends<<ch[fa[pos]][1]<<endl;
//		cout<<"nroot res "<<((ch[fa[pos]][0]==pos)||(ch[fa[pos]][1]==pos))<<endl;
		return ((ch[fa[pos]][0]==pos)||(ch[fa[pos]][1]==pos));
	}
	inline void pushrev(int pos){
//		if(!pos) return;
		swap(ch[pos][0],ch[pos][1]);rev[pos]^=1;
	}
	inline void pushdown(int pos){
//		if(!pos) return;
		if(rev[pos]){
			pushrev(ch[pos][0]);
			pushrev(ch[pos][1]);
			rev[pos]=0;
		} 
	}
	inline void push(int pos){
//		if(!pos) return;
		if(nroot(pos)) push(fa[pos]);
		pushdown(pos);
	}
	inline void update(int pos){
//		if(!pos) return;
//		cout<<"update "<<pos<<ends<<ch[pos][0]<<ends<<ch[pos][1]<<endl;
		int i;
		for(i=0;i<=12;i++) a[pos][i]=a[ch[pos][0]][i]+a[ch[pos][1]][i]+w[pos][i];
	}
	inline bool get(int pos){
//		if(!pos) return 0;
		return ch[fa[pos]][1]==pos;
	}
	inline void rotate(int pos){
		int f=fa[pos],ff=fa[f],son=get(pos);
//		cout<<"******rotate "<<pos<<ends<<f<<ends<<ff<<ends<<son<<ends<<ch[f][son]<<ends<<ch[pos][son^1]<<endl;
		assert(pos!=f&&pos!=ff&&f!=ff);
		assert(f);
		if(nroot(f)) ch[ff][ch[ff][1]==f]=pos;
		ch[f][son]=ch[pos][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=pos;ch[pos][son^1]=f;
		fa[pos]=ff;
		update(f);update(pos);
//		cout<<"&&&&&&finish rotate "<<fa[f]<<ends<<fa[pos]<<ends<<ch[pos][son^1]<<ends<<ch[f][son]<<endl;
	}
	inline void splay(int pos){
		if(!pos) return;
		push(pos);
//		cout<<"finish push, begin splay "<<pos<<endl;
		for(int f;nroot(pos);rotate(pos)){
			f=fa[pos];
//			cout<<"cheking "<<fa[pos]<<ends<<nroot(f)<<endl;
			if(nroot(f))
				rotate((get(f)==get(pos))?f:pos);
		}
		update(pos); 
//		cout<<"end of splay\n";
	}
	inline void access(int pos){
//		cout<<"access "<<pos<<endl;
		for(int tmp=0;pos;tmp=pos,pos=fa[pos]){
//			cout<<"	do access "<<pos<<ends<<tmp<<ends<<fa[pos]<<ends<<fa[fa[pos]]<<endl;
			splay(pos);ch[pos][1]=tmp;update(pos);
		}
//		cout<<"finish access\n";
	}
	inline void mroot(int pos){
//		cout<<"mroot "<<pos<<endl;
		access(pos);splay(pos);pushrev(pos);
	}
	inline int find(int pos){
//		cout<<"find "<<pos<<endl; 
		access(pos);splay(pos);
		while(ch[pos][0]) pos=ch[pos][0];
//		cout<<"finish find "<<pos<<endl;
		return pos;
	}
	inline void link(int l,int r){
//		cout<<"link "<<l<<ends<<r<<endl;
//		if(find(l)==find(r)) return;
		mroot(l);fa[l]=r;
	}
	inline void split(int l,int r){
		mroot(l);access(r);splay(r);
	}
	inline void cut(int l,int r){
		split(l,r);
		fa[l]=ch[r][0]=0;
		update(r);
	}
	inline void change(int pos,int type,double A,double B){
		mroot(pos);
		int i;double powa=1.0,powe=exp(B);
		if(type==1){
			for(i=0;i<=12;i++){
				if(i%4==0) w[pos][i]=sin(B)*powa;
				if(i%4==1) w[pos][i]=cos(B)*powa;
				if(i%4==2) w[pos][i]=-sin(B)*powa;
				if(i%4==3) w[pos][i]=-cos(B)*powa;
				powa*=A;
			}
		}
		if(type==2){
			w[pos][0]=powe;
			for(i=1;i<=12;i++){
				powa*=A;w[pos][i]=powe*powa;
			}
		}
		if(type==3){
			w[pos][0]=B;w[pos][1]=A;
		}
		update(pos);
	}
	inline double getans(int l,int r,double x){
		int i,pos=r;double re=0,powx=1.0;
		split(l,r);
		for(i=0;i<=12;i++){
			re+=powx*a[pos][i]/fac[i];
//			cout<<"get ans "<<pos<<ends<<powx<<ends<<re<<endl;
			powx*=x;
		}
		return re;
	}
}T; 
int main(){
	freopen("b10.in","r",stdin);
	freopen("math.out","w",stdout);
	char s[15];int i,t1,t2,Q;double t3,t4;
	scanf("%d%d",&n,&Q);scanf("%s",s);
	fac[0]=fac[1]=1;
	for(i=2;i<=12;i++) fac[i]=fac[i-1]*i;
	for(i=1;i<=n;i++){
		scanf("%d%lf%lf",&t1,&t3,&t4);
		T.change(i,t1,t3,t4);
	} 
//	cout<<"finish input stage 1\n";
	while(Q--){
		scanf("%s",s);
		if(s[0]=='a'){
			scanf("%d%d",&t1,&t2);
			t1++;t2++;
			T.link(t1,t2);
		} 
		if(s[0]=='d'){
			scanf("%d%d",&t1,&t2);
			t1++;t2++;
			T.cut(t1,t2);
		}
		if(s[0]=='m'){
			scanf("%d%d%lf%lf",&t1,&t2,&t3,&t4);
			t1++;
			T.change(t1,t2,t3,t4);
		}
		if(s[0]=='t'){
			scanf("%d%d%lf",&t1,&t2,&t3);
			t1++;t2++;
			if(T.find(t1)!=T.find(t2)) puts("unreachable");
			else printf("%.10lf\n",T.getans(t1,t2,t3));
		}
//		cout<<"finish query\n";//system("pause");
	}
}
