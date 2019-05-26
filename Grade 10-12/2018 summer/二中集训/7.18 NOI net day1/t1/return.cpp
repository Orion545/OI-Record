#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
int n,m,Q,S,K,first[200010],cnte,dis[200010],vis[200010];
struct edge{
	int from,to,next,w,h;
}a[800010];
inline void add(int u,int v,int w,int h){
//	cout<<"add edge "<<u<<' '<<v<<' '<<w<<' '<<h<<'\n';
	a[++cnte]=(edge){u,v,first[u],w,h};first[u]=cnte;
	a[++cnte]=(edge){v,u,first[v],w,h};first[v]=cnte; 
}
void spfa(){
	deque<int>q;int i,u,v;
	for(i=1;i<=n;i++) dis[i]=2e9+1;
	q.push_front(1);dis[1]=0;vis[1]=1;
	while(!q.empty()){
		u=q.front();q.pop_front();vis[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(dis[v]>dis[u]+a[i].w){
				dis[v]=dis[u]+a[i].w;
				if(!vis[v]){
					vis[v]=1;
					if(!q.empty()&&dis[v]<dis[q.front()]) q.push_front(v);
					else q.push_back(v);
				}
			}
		}
	}
}
void init(){
	memset(first,-1,sizeof(first));memset(a,0,sizeof(a));cnte=0;
}
namespace offline{
	int ufs[200010];
	int find(int x){assert(x);return ((ufs[x]==x)?x:ufs[x]=find(ufs[x]));}
	void join(int x,int y){
		ufs[y]=ufs[x];
	}
	struct segtree{
		int ch[4000010][2],siz[4000010],a[4000010],cnt,rt[400010];
		segtree(){cnt=0;}
		void clear(){
			cnt=0;memset(ch,0,sizeof(ch));memset(siz,0,sizeof(siz));memset(a,0,sizeof(a));
			memset(rt,0,sizeof(rt));
		}
		void update(int pos){
			a[pos]=1e9;
			if(ch[pos][0]) a[pos]=min(a[pos],a[ch[pos][0]]);
			if(ch[pos][1]) a[pos]=min(a[pos],a[ch[pos][1]]);
			siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]];
		}
		int insert(int l,int r,int pos,int val){
			int cur=++cnt,mid=(l+r)>>1;
			ch[cur][0]=ch[cur][1]=0;siz[cur]=1;a[cur]=val;
			if(l==r) return cur;
			if(mid>=pos) ch[cur][0]=insert(l,mid,pos,val);
			else ch[cur][1]=insert(mid+1,r,pos,val);
			return cur;
		}
		int merge(int pre,int cur){
			if(!pre) return cur;
			if(!cur) return pre;
			assert(cur&&pre);
			ch[cur][0]=merge(ch[pre][0],ch[cur][0]);
			ch[cur][1]=merge(ch[pre][1],ch[cur][1]);
			update(cur);return cur;
		}
		int query(int cur){return a[cur];}
		void jointree(int l,int r){
			int fl=find(l),fr=find(r);if(fl==fr) return;
			if(siz[rt[fl]]<siz[fr]) swap(l,r);
			join(fl,fr);merge(rt[fr],rt[fl]);
		}
	}T;
	bool cmp(edge l,edge r){
		return l.h>r.h;
	}
	struct query{
		int pos,h,ans,num;
	}q[100010];
	bool cmpq(query l,query r){
		return l.h>r.h;
	}
	bool cmpans(query l,query r){
		return l.num<r.num;
	}
	void solve(){
		int i,j;
		for(i=1;i<=n;i++) ufs[i]=i;
		T.clear();spfa();
		for(i=1;i<=n;i++) T.rt[i]=T.insert(1,n,i,dis[i]);
		sort(a+1,a+cnte+1,cmp);
//		for(i=1;i<=cnte;i++) cout<<"check edge "<<a[i].from<<' '<<a[i].to<<' '<<a[i].w<<'\n';
		for(i=1;i<=Q;i++) q[i].pos=read(),q[i].h=read(),q[i].num=i;
		sort(q+1,q+Q+1,cmpq);
		j=0;
		for(i=1;i<=Q;i++){
			while(a[j+1].h>q[i].h) j++,T.jointree(a[j].from,a[j].to);
//			cout<<"deal with query "<<q[i].pos<<' '<<q[i].h<<'\n';
			q[i].ans=T.query(T.rt[find(q[i].pos)]);
		}
		sort(q+1,q+Q+1,cmpans);
		for(i=1;i<=Q;i++){
			printf("%d\n",q[i].ans);
		}
	}
}
namespace brute{
	int ufs[200010];
	int find(int x){assert(x);return ((ufs[x]==x)?x:ufs[x]=find(ufs[x]));}
	void join(int x,int y){
		int fx=find(x),fy=find(y);
		ufs[fy]=ufs[fx];
//		cout<<"	ufs join "<<fx<<' '<<fy<<'\n';
	}
	void solve(){
		int i,lastans=0,t1,t2;spfa();
		while(Q--){
			t1=read();t2=read();
//			cout<<t1<<' '<<t2<<'\n';
			t1=(t1+lastans-1)%n+1;
			t2=(t2+lastans)%(S+1);
//			cout<<t1<<' '<<t2<<'\n';
			for(i=1;i<=n;i++) ufs[i]=i;
			for(i=1;i<=cnte;i++){
				if(a[i].h>t2) join(a[i].from,a[i].to);
			}
			int fx=find(t1),re=2e9+1;
			for(i=1;i<=n;i++) if(fx==find(i)) re=min(re,dis[i]);
			printf("%d\n",lastans=re);
		}
	}
}
int main(){
	freopen("return5.in","r",stdin);
	freopen("return.out","w",stdout);
	int T=read();int i,t1,t2,t3,t4;
	while(T--){
		init();
		n=read();m=read();
		for(i=1;i<=m;i++){
			t1=read();t2=read();t3=read();t4=read();
			add(t1,t2,t3,t4);
		}
		Q=read();K=read();S=read();
		if(!K) offline::solve();
		else brute::solve();
	}
	
}
/*
1
4 3
1 2 50 1
2 3 100 2
3 4 50 1
5 0 2
3 0
2 1
4 1
3 1
3 2

*/
