#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct LCT{
	int ch[200010][2],fa[200010],rev[200010],ufs[200010],sum[200010],w[200010];
	LCT(){
		for(int i=1;i<=200000;i++) ufs[i]=i;
		memset(ch,0,sizeof(ch));
		memset(fa,0,sizeof(fa));
		memset(rev,0,sizeof(rev));
		memset(sum,0,sizeof(sum));
		memset(w,0,sizeof(w));
	}
	void update(int pos){
		sum[pos]=sum[ch[pos][0]]+sum[ch[pos][1]]+w[pos];
//		cout<<"			update "<<pos<<' '<<ch[pos][0]<<' '<<ch[pos][1]<<' '<<w[pos]<<' '<<sum[pos]<<'\n';
	}
	bool get(int pos){return ch[fa[pos]][1]==pos;}
	bool nroot(int pos){return ((ch[fa[pos]][0]==pos)||(ch[fa[pos]][1]==pos));}
	void rotate(int pos){
		int f=fa[pos],ff=fa[f],son=get(pos),nr=nroot(f);
//		cout<<"		rotate "<<pos<<' '<<f<<' '<<ff<<'\n';
		ch[f][son]=ch[pos][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=pos;ch[pos][son^1]=f;
		fa[pos]=ff;
		if(nr) ch[ff][ch[ff][1]==f]=pos;
		update(f);update(pos);
	}
	int find(int pos){
//		cout<<"		find "<<pos<<' '<<ufs[pos]<<'\n';
		return ((pos==ufs[pos])?pos:(ufs[pos]=find(ufs[pos])));
	}
	void ufs_merge(int f1,int f2){
		f1=find(f1),f2=find(f2);
//		cout<<"+++++++++++++ ufs merge "<<f1<<' '<<f2<<'\n';
		ufs[f1]=f2;
	}
	void pushrev(int pos){
		if(!pos) return;
//		cout<<"pushrev "<<pos<<'\n';
		swap(ch[pos][0],ch[pos][1]);
		rev[pos]^=1;
	}
	void pushdown(int pos){
		if(!pos) return;
		if(rev[pos]){
			pushrev(ch[pos][0]);pushrev(ch[pos][1]);
			rev[pos]=0;
		}
	}
	int sta[200010]; 
	void splay(int pos){
		if(!pos) return;
		int p=find(pos);
//		cout<<"	splay "<<pos<<' '<<p<<'\n';
		int top=0;sta[++top]=p;fa[p]=find(fa[p]);
		while(nroot(p)){
			fa[p]=find(fa[p]);
			sta[++top]=fa[p];
			fa[fa[p]]=find(fa[fa[p]]);
			p=fa[p]; 
		}
		while(top) pushdown(sta[top]),top--;
//		cout<<"	finish pushdown "<<pos<<' '<<ch[pos][0]<<' '<<ch[pos][1]<<' '<<fa[pos]<<' '<<ufs[fa[pos]]<<'\n';
		for(int f;nroot(pos);rotate(pos)){
			f=fa[pos];
			if(nroot(f))
				rotate((get(f)==get(pos))?f:pos);
		}
//		cout<<"	finish splay\n";
	}
	void access(int pos){
//		cout<<"access "<<pos<<'\n';
		for(int y=0;pos;y=pos,pos=fa[pos]){
			pos=find(pos);
			splay(pos);
//			cout<<"*****************check\n";
			ch[pos][1]=y;
//			cout<<"*****************check\n";
			update(pos);
		}
//		cout<<"finish access "<<ch[10][0]<<' '<<ch[10][1]<<' '<<fa[10]<<' '<<fa[5]<<'\n';
	}
	void mroot(int pos){
		access(pos);splay(pos);pushrev(pos);
	}
	void link(int x,int y){
		x=find(x);y=find(y);
//		cout<<"link "<<x<<' '<<y<<' '<<fa[x]<<' '<<fa[y]<<'\n';
		mroot(x);fa[x]=y;
	}
	bool judge(int x,int y){
		fa[x]=find(fa[x]);fa[y]=find(fa[y]); 
		while(fa[x]) x=fa[x],fa[x]=find(fa[x]);
		while(fa[y]) y=fa[y],fa[y]=find(fa[y]);
		return x!=y;
	}
	int getans(int x,int y){
//		cout<<"getans "<<x<<' '<<y<<'\n'; 
		x=find(x);y=find(y);
//		cout<<"finish find "<<x<<' '<<fa[x]<<' '<<y<<' '<<fa[y]<<' '<<fa[5]<<' '<<ch[10][0]<<' '<<ch[10][1]<<'\n';
		if(judge(x,y)) return -1;
		mroot(x);access(y);splay(y);
		return sum[y];
	}
	void dfs(int u,int f){
		if(!u) return;
//		cout<<"------------------- dfs "<<u<<' '<<f<<'\n';
//		pushdown(u);
		dfs(ch[u][0],f);dfs(ch[u][1],f);
		ufs_merge(u,f);
		w[u]=sum[u]=ch[u][0]=ch[u][1]=fa[u]=0;
	}
	void merge(int x,int y){
//		cout<<"merge "<<x<<' '<<y<<' '<<find(x)<<' '<<find(y)<<'\n';
		x=find(x);y=find(y);
		mroot(x);access(y);splay(y);int ttmp=sum[y];
//		cout<<"finish op "<<x<<' '<<fa[x]<<' '<<y<<' '<<ch[y][0]<<' '<<ch[y][1]<<' '<<fa[5]<<'\n';
		dfs(y,x);
		w[x]=sum[x]=ttmp;fa[x]=0;
	}
	void add(int pos,int val){
//		cout<<"begin add "<<fa[5]<<' '<<ch[10][0]<<' '<<ch[10][1]<<'\n';
		pos=find(pos);mroot(pos);
		w[pos]+=val;update(pos);
//		cout<<"finish add "<<pos<<' '<<val<<'\n';
	}
}T;
int n,m,val[200010];
int main(){
//	freopen("1.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();m=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++) val[i]=T.w[i]=read();
	while(m--){
		t1=read();t2=read();t3=read();
		if(t1==1){
			if(T.judge(T.find(t2),T.find(t3))) T.link(t2,t3);
			else T.merge(t2,t3);
		}
		if(t1==2){
			T.add(t2,t3-val[t2]);
			val[t2]=t3;
		}
		if(t1==3){
			printf("%d\n",T.getans(t2,t3));
		}
	}
}
