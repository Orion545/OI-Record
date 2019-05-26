#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long double
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
int fa[200010],ch[200010][2],rev[200010];
long double w[200010][15],sum[200010][15],a[200010],b[200010];int tp[200010];
//tp={1,2,3} --> {ax+b,exp,sin}
void calc(int cur){
	ll A=a[cur],B=b[cur],*val=w[cur];register int i;
	switch(tp[cur]){
		case 3:
			val[0]=B;val[1]=A;
			for(i=2;i<12;i++) val[i]=0;
			break;
		case 2:
			val[0]=exp(B);
			for(i=1;i<12;i++) val[i]=val[i-1]*A;
			break;
		case 1:
			val[0]=sin(B);
			val[1]=A*cos(B);
			for(i=2;i<12;i++) val[i]=-val[i-2]*A*A;
			break;
		default:assert(0);
	}
}
void update(int cur){
	for(register int i=0;i<12;i++) sum[cur][i]=sum[ch[cur][0]][i]+sum[ch[cur][1]][i]+w[cur][i];
}
void pushrev(int cur){
	if(!cur) return;
	swap(ch[cur][0],ch[cur][1]);
	rev[cur]^=1;
}
void pushdown(int cur){
	if(!rev[cur]) return;
	pushrev(ch[cur][0]);
	pushrev(ch[cur][1]);
	rev[cur]=0;
}
bool nroot(int cur){return ch[fa[cur]][0]==cur||ch[fa[cur]][1]==cur;}
void push(int cur){
	if(nroot(cur)) push(fa[cur]);
	pushdown(cur);
}
bool get(int cur){return ch[fa[cur]][1]==cur;}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x),nr=nroot(f);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(nr) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x){
	push(x);
	for(int f;nroot(x);rotate(x)){
		f=fa[x];
		if(nroot(f)){
			rotate((get(x)==get(f))?f:x);
		}
	}
}
void access(int x){
	for(int y=0;x;y=x,x=fa[x]){
		splay(x);ch[x][1]=y;update(x);
	}
}
void mroot(int u){
	access(u);splay(u);pushrev(u);
}
void link(int u,int v){
//	cout<<"link "<<u<<' '<<v<<'\n';
	mroot(u);fa[u]=v;
}
void cut(int u,int v){
	mroot(u);access(v);splay(v);
	fa[u]=ch[v][0]=0;update(v);
}
int find(int u){
	access(u);splay(u);
	while(ch[u][0]) u=ch[u][0];
	return u;
}
long double query(int u,int v,long double x){
//	cout<<"query "<<u<<' '<<v<<' '<<x<<'\n';
	mroot(u);access(v);splay(v);
	long double re=0,tmp=1;register int i;
	for(i=0;i<12;i++){
		re+=tmp*(long double)(sum[v][i]);
		tmp/=(long double)(i+1);tmp*=x;
	}
	return re;
}
int n,m;char s[20];
int main(){
	n=read();m=read();scanf("%s",s);int i,t1,t2;double t3,t4;
	for(i=1;i<=n;i++){
		fa[i]=ch[i][0]=ch[i][1]=rev[i]=0;
		tp[i]=read();
		scanf("%lf%lf",&t3,&t4);
		a[i]=t3;b[i]=t4;
		calc(i);
	}
	while(m--){
		scanf("%s",s);
		if(s[0]=='a'){
			t1=read();t2=read();
			t1++;t2++;
			link(t1,t2);
		}
		if(s[0]=='d'){
			t1=read();t2=read();
			t1++;t2++;
			cut(t1,t2);
		}
		if(s[0]=='m'){
			t1=read();t1++;
			tp[t1]=read();
			scanf("%lf%lf",&t3,&t4);
			a[t1]=t3;b[t1]=t4;
			mroot(t1);calc(t1);update(t1);
		}
		if(s[0]=='t'){
			t1=read();t2=read();scanf("%lf",&t3);
			t1++;t2++;
			if(find(t1)!=find(t2)) puts("unreachable");
			else printf("%.10lf\n",(double)(query(t1,t2,t3)));
		}
//		cout<<"***checking***\n";
//		for(i=1;i<=n;i++) cout<<fa[i]<<' '<<ch[i][0]<<' '<<ch[i][1]<<'\n';
//		cout<<"***check finish***\n";
	}
}
