#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#define log DEEP_DARK_FANTASY
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
int n,q,RT,col[100010],cntc;
struct h{
	priority_queue<int>q,d;
	inline void insert(int val){
//		cout<<"				insert "<<val<<'\n';
		q.push(val);
	}
	inline int top(){
		while(!q.empty()&&!d.empty()&&q.top()==d.top()) q.pop(),d.pop();
		if(q.empty()) return -1;
		return q.top();
	}
	inline void pop(){
		while(!q.empty()&&!d.empty()&&q.top()==d.top()) q.pop(),d.top();
		if(!q.empty()) q.pop();
	}
	inline void del(int val){
//		cout<<"				del "<<val<<'\n';
		d.push(val);
	}
	inline int getdis(){
		int t1=top();
		if(t1==-1) return -1;
		pop();
		int t2=top();
		if(t2==-1){
			insert(t1);
			return -1;
		}
		int re=t1+t2;
		insert(t1);
		return re;
	}
	inline int size(){return q.size()-d.size();}
}c[100010],b[100010],all;
namespace t{
	int first[100010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next;
	}a[200010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	int in[100010],out[100010],dep[100010],lis[400010],st[400010][20],clk,log[400010];
	void dfs(int u,int f){
		int i,v;
		dep[u]=dep[f]+1;
		lis[++clk]=dep[u];
		in[u]=clk;
//		cout<<"tree dfs "<<u<<' '<<dep[u]<<' '<<f<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u);
			lis[++clk]=dep[u];
		}
		out[u]=clk;
	}
	void ST(){
		int i,j;
		log[1]=0;
		for(i=2;i<=clk;i++) log[i]=log[i>>1]+1;
		for(i=1;i<=clk;i++) st[i][0]=lis[i];
		for(j=1;j<=18;j++){
			for(i=1;i<=clk-(1<<j)+1;i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
//				cout<<i<<' '<<j<<' '<<st[i][j]<<'\n';
			}
		}
	}
	inline int getdis(int l,int r){
		int x=in[l],y=out[r];
		if(x>y) swap(x,y);
		int k=log[y-x+1];
//		cout<<"	getdis "<<l<<' '<<r<<' '<<' '<<x<<' '<<y<<' '<<k<<' '<<' '<<dep[l]+dep[r]-2*min(st[x][k],st[y-(1<<k)+1][k])<<'\n';
		return dep[l]+dep[r]-2*min(st[x][k],st[y-(1<<k)+1][k]);
	}
}
namespace g{
	int first[100010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next;
	}a[200010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	int siz[100010],root,son[100010],vis[100010],sum;
	int fa[100010];vector<int>ch[100010];
	void getroot(int u,int f){
		int i,v;
		siz[u]=1;son[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f||vis[v]) continue;
			getroot(v,u);
			siz[u]+=siz[v];
			son[u]=max(son[u],siz[v]);
		}
		son[u]=max(son[u],sum-siz[u]);
		if(son[u]<son[root]) root=u;
	}
	void build(int u,int cursum,int f){
		int i,v;vis[u]=1;
		fa[u]=f;
//		cout<<"graph build "<<u<<' '<<cursum<<' '<<f<<' '<<RT<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			root=0;sum=(siz[v]>siz[u])?cursum-siz[u]:siz[v];son[0]=n;
			getroot(v,u);
			build(root,sum,u);
		}
	}
	inline void add(int u){
		int tmp,ori=u;
//		cout<<"****************begin add "<<ori<<'\n';
		tmp=b[u].getdis();
		if(~tmp) all.del(tmp);
		
		b[u].insert(0);

		tmp=b[u].getdis();
		if(~tmp) all.insert(tmp);
		for(;u!=RT;u=fa[u]){
//			cout<<"do "<<u<<' '<<fa[u]<<'\n';
			tmp=b[fa[u]].getdis();
			if(~tmp) all.del(tmp);

			tmp=c[u].top();
			if(~tmp) b[fa[u]].del(tmp);

			c[u].insert(t::getdis(ori,fa[u]));
//			cout<<"	finish insert "<<u<<' '<<c[u].top()<<' '<<tmp<<'\n';

			tmp=c[u].top();
			if(~tmp) b[fa[u]].insert(tmp);
//			cout<<"	finish insert "<<u<<' '<<fa[u]<<' '<<b[fa[u]].size()<<' '<<b[fa[u]].getdis()<<'\n';

			tmp=b[fa[u]].getdis();
			if(~tmp){
				all.insert(tmp);
			}
		}
	}
	inline void del(int u){
		int tmp,ori=u;
//		cout<<"****************begin del "<<ori<<'\n';
		tmp=b[u].getdis();
		if(~tmp) all.del(tmp);
		
		b[u].del(0);

		tmp=b[u].getdis();
		if(~tmp) all.insert(tmp);
		for(;u!=RT;u=fa[u]){
//			cout<<"do "<<u<<'\n';
			tmp=b[fa[u]].getdis();
			if(~tmp) all.del(tmp);

			tmp=c[u].top();
			if(~tmp) b[fa[u]].del(tmp);

			c[u].del(t::getdis(ori,fa[u]));

			tmp=c[u].top();
			if(~tmp) b[fa[u]].insert(tmp);

			tmp=b[fa[u]].getdis();
			if(~tmp){
//				cout<<"					all inserted "<<tmp<<'\n';
				all.insert(tmp);
			}
		}
	}
}
int main(){
	n=read();int i,t1,t2;
	cntc=n;
	t::init();g::init();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		t::add(t1,t2);
		g::add(t1,t2);
	}
	t::dfs(1,0);t::ST();

	g::son[0]=n;g::sum=n;g::root=0;
	g::getroot(1,0);
	RT=g::root;g::build(g::root,n,0);

	for(i=1;i<=n;i++) g::add(i),col[i]=1;

	q=read();char s[10];
	while(q--){
		scanf("%s",s);
		if(s[0]=='G'){
			if(cntc==0) puts("-1");
			if(cntc==1) puts("1");
			else printf("%d\n",all.top());
		}
		else{
			t1=read();
			if(col[t1]) g::del(t1),cntc--;
			else g::add(t1),cntc++;
			col[t1]^=1;
		}
	}
}
