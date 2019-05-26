#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<vector>
#define mp make_pair
#define rank DEEP_DARK_FANTASY
#define next VAN_YOU_SEE
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
//KDTREE
struct node{/*{{{*/
	int ll,lr,rl,rr,num,posl,posr,lc,rc;
}x[200010],kdtr[200010];int L;
inline bool operator <(const node p,const node o){
	if(L) return p.posl<o.posl;
	else return p.posr<o.posr;
}
void update(int pos){
    kdtr[pos].ll=kdtr[pos].lr=kdtr[pos].posl;
    if(kdtr[pos].lc) kdtr[pos].ll=min(kdtr[pos].ll,kdtr[kdtr[pos].lc].ll);
    if(kdtr[pos].rc) kdtr[pos].ll=min(kdtr[pos].ll,kdtr[kdtr[pos].rc].ll);
    if(kdtr[pos].lc) kdtr[pos].lr=max(kdtr[pos].lr,kdtr[kdtr[pos].lc].lr);
    if(kdtr[pos].rc) kdtr[pos].lr=max(kdtr[pos].lr,kdtr[kdtr[pos].rc].lr);
    kdtr[pos].rl=kdtr[pos].rr=kdtr[pos].posr;
    if(kdtr[pos].lc) kdtr[pos].rl=min(kdtr[pos].rl,kdtr[kdtr[pos].lc].rl);
    if(kdtr[pos].rc) kdtr[pos].rl=min(kdtr[pos].rl,kdtr[kdtr[pos].rc].rl);
    if(kdtr[pos].lc) kdtr[pos].rr=max(kdtr[pos].rr,kdtr[kdtr[pos].lc].rr);
    if(kdtr[pos].rc) kdtr[pos].rr=max(kdtr[pos].rr,kdtr[kdtr[pos].rc].rr);
}
int build(int l,int r,int now){
	int mid=(l+r)>>1;L=now;
	nth_element(x+l,x+mid,x+r+1);
//	cout<<"build "<<l<<' '<<r<<' '<<x[mid].num<<'\n';
	kdtr[mid]=x[mid];
	if(mid>l) kdtr[mid].lc=build(l,mid-1,now^1);
	if(mid<r) kdtr[mid].rc=build(mid+1,r,now^1);
	update(mid);
	return mid;
}
int getd(int XX,int YY,int xx,int yy){
	return (XX-xx)*(XX-xx)+(YY-yy)*(YY-yy);
}
int dis(int p,int X,int Y){
	int xx=0,yy=0;
	if(kdtr[p].lr<X) xx=X-kdtr[p].lr;
	if(kdtr[p].ll>X) xx=kdtr[p].ll-X;
	if(kdtr[p].rr<Y) yy=Y-kdtr[p].rr;
	if(kdtr[p].rl>Y) yy=kdtr[p].rl-Y;
//	cout<<"	getdis "<<p<<' '<<kdtr[p].ll<<' '<<kdtr[p].lr<<' '<<kdtr[p].rl<<' '<<kdtr[p].rr<<' '<<X<<' '<<Y<<' '<<xx<<' '<<yy<<'\n'; 
	return xx*xx+yy*yy;
}
int ans,pp,curnum;
void query(int X,int Y,int pos){
	int dl=1e9,dr=1e9,d=getd(X,Y,kdtr[pos].posl,kdtr[pos].posr);
//	cout<<"query "<<X<<' '<<Y<<' '<<pos<<' '<<kdtr[pos].num<<' '<<d<<'\n';
	if((kdtr[pos].num!=curnum)&&(ans>d||(ans==d&&pp>kdtr[pos].num))) ans=d,pp=kdtr[pos].num;
	if(kdtr[pos].lc) dl=dis(kdtr[pos].lc,X,Y);
	if(kdtr[pos].rc) dr=dis(kdtr[pos].rc,X,Y);
	if(dl<dr){
		if(dl<=ans) query(X,Y,kdtr[pos].lc);
		if(dr<=ans) query(X,Y,kdtr[pos].rc);
	}
	else{
		if(dr<=ans) query(X,Y,kdtr[pos].rc);
		if(dl<=ans) query(X,Y,kdtr[pos].lc);
	}
}/*}}}*/

//MIN CUT TREE
int tot,cap[50010];
namespace orig{/*{{{*/
	vector<pair<int,int> >e[100010];
	int dep[100010],st[100010][20],minn[100010][20],dis[100010];
	void dfs(int u,int f,int w){
		dep[u]=dep[f]+1;st[u][0]=f;minn[u][0]=w;
		if(f!=0) dis[u]=min(dis[f],w);
		else dis[u]=1e9;
//		cout<<"dfs "<<u<<' '<<f<<' '<<w<<' '<<dis[u]<<'\n';
		assert(dis[u]>0);
		for(auto v:e[u]){
			if(v.first==f) continue;
			dfs(v.first,u,v.second);
		}
	}
	void ST(){
		int i,j;
		for(j=1;j<=17;j++) 
			for(i=1;i<=tot;i++)
				st[i][j]=st[st[i][j-1]][j-1];
		for(j=1;j<=17;j++)
			for(i=1;i<=tot;i++){
				if(dep[i]>(1<<j))
					minn[i][j]=min(minn[i][j-1],minn[st[i][j-1]][j-1]);
			}
	}
	int query(int l,int r){
		int i,re=1e9;
		if(dep[l]>dep[r]) swap(l,r);
		assert(dep[0]==0);
		for(i=17;i>=0;i--){
			if(dep[st[r][i]]>=dep[l]){
				re=min(re,minn[r][i]);
				r=st[r][i];
			}
		}
		if(l==r) return re;
		for(i=17;i>=0;i--){
			if(st[l][i]!=st[r][i]){
				re=min(re,min(minn[l][i],minn[r][i]));
				r=st[r][i];l=st[l][i];
			}
		}
		assert(re>0);
		return min(re,min(minn[r][0],minn[l][0]));
	}
}/*}}}*/
namespace bigg{/*{{{*/
	vector<pair<int,int> >e[100010];
	int dep[100010],st[100010][20],minn[100010][20],n;
	int numcnt=0,belong[100010];
	void dfs(int u,int f,int w){
		dep[u]=dep[f]+1;st[u][0]=f;minn[u][0]=w;
		belong[u]=numcnt;
//		cout<<"bigg dfs "<<u<<' '<<f<<' '<<w<<' '<<dep[u]<<'\n';
		for(auto v:e[u]){
			if(v.first==f) continue;
			dfs(v.first,u,v.second);
		}
	}
	void ST(){
		int i,j;
		for(j=1;j<=17;j++) 
			for(i=1;i<=n;i++)
				st[i][j]=st[st[i][j-1]][j-1];
		for(j=1;j<=17;j++)
			for(i=1;i<=n;i++){
				if(dep[i]>(1<<j))
					minn[i][j]=min(minn[i][j-1],minn[st[i][j-1]][j-1]);
//				cout<<"bigg "<<i<<' '<<j<<' '<<st[i][j]<<' '<<minn[i][j]<<'\n';
			}
	}
	int query(int l,int r){
		int i,re=1e9;
		if(belong[l]!=belong[r]){return 0;}
		if(dep[l]>dep[r]) swap(l,r);
//		cout<<"query bigg "<<l<<' '<<r<<' '<<dep[l]<<' '<<dep[r]<<'\n';
		for(i=17;i>=0;i--){
			if(dep[st[r][i]]>=dep[l]){
				re=min(re,minn[r][i]);
				r=st[r][i];
//				cout<<"	pre r "<<i<<' '<<r<<' '<<re<<'\n';
			}
		}
		if(l==r) return re;
		for(i=17;i>=0;i--){
			if(st[l][i]!=st[r][i]){
				re=min(re,min(minn[l][i],minn[r][i]));
				r=st[r][i];l=st[l][i];
			}
		}
		assert(re>0);
		return min(re,min(minn[r][0],minn[l][0]));
	}
}/*}}}*/
namespace NETW{/*{{{*/
	int n=0,first[50010],cnte,dep[50010],cur[50010];
	bool vis[50010];int node[50010];
	struct edge{
		int to,next,w,ori;
	}a[120010];
	inline void add(int u,int v,int w){
//		cout<<"****add "<<u<<' '<<v<<' '<<w<<'\n';
		a[++cnte]=(edge){v,first[u],w,w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],w,w};first[v]=cnte;
	}
	void renew(int num){
		n=num;
		for(int i=1;i<=n;i++) node[i]=i;
	}
	void clear(){
		int i;
		for(i=1;i<=n;i++) first[i]=-1;
		cnte=-1;
	}
	int q[50010],head=0,tail;
	bool bfs(int s,int t){
		int i,u,v;head=0;tail=1;
		for(i=1;i<=n;i++) dep[i]=-1,cur[i]=first[i];
//		cout<<"	bfs "<<s<<' '<<t<<'\n';
		q[0]=s;dep[s]=0;
		while(head<tail){
			u=q[head++];
//			cout<<"		head "<<u<<'\n';
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;
//				cout<<"			to "<<v<<' '<<dep[v]<<' '<<a[i].w<<'\n';
				if(~dep[v]||!a[i].w) continue;
				dep[v]=dep[u]+1;
				q[tail++]=v;
			}
		}
		return ~dep[t];
	}
	int dfs(int u,int t,int lem){
//		cout<<"	dfs "<<u<<' '<<t<<' '<<lem<<'\n';
		if(u==t||!lem) return lem;
		int i,v,f,flow=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(lem,a[i].w)))){
				a[i].w-=f;a[i^1].w+=f;
				flow+=f;lem-=f;
				if(!lem) return flow;
			}
		}
		return flow;
	}
	int dinic(int s,int t){
		int re=0;
		while(bfs(s,t)) re+=dfs(s,t,1e9);
//		cout<<"*****************dinic "<<s<<' '<<t<<' '<<re<<'\n';
		return re;
	}
	int bl[50010],br[50010],tl,tr;
	void cut(int u){
		int i,v;vis[u]=1;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(a[i].w&&!vis[v]) cut(v);
		}
	}
	void solve(int l,int r){
//		cout<<"solve "<<l<<' '<<r<<' '<<node[l]<<' '<<node[r]<<'\n';
		int i,tmp,ttl,S=node[l],T=node[r];
//		for(i=1;i<=n;i++) cout<<"^^^ "<<i<<' '<<node[i]<<'\n';
		if(l==r) return;
		tl=tr=0;
		for(i=0;i<=cnte;i++) a[i].w=a[i].ori;
		tmp=dinic(S,T);

		memset(vis,0,sizeof(vis));
		cut(S);
		
		for(i=l;i<=r;i++){
			if(!vis[node[i]]) bl[++tl]=node[i];
			else br[++tr]=node[i];
		}

		for(i=1;i<=tl;i++) node[l+i-1]=bl[i];
		for(i=1;i<=tr;i++) node[l+tl-1+i]=br[i];
		ttl=tl;
//		cout<<"**** going into subtask "<<ttl<<' '<<ttr<<'\n';
		solve(l,l+ttl-1);
//		cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& get mid! "<<l<<' '<<r<<'\n';
		solve(l+ttl,r);
//		cout<<"**** finishing subtask "<<l<<' '<<r<<'\n';
		orig::e[tot+S].push_back(mp(tot+T,tmp));
		orig::e[tot+T].push_back(mp(tot+S,tmp));
//		cout<<"return "<<l<<' '<<r<<'\n';
		return ;
	}
}/*}}}*/
int mate[50010];
int n,px[50010],py[50010],c[50010],m[50010];
int main(){
	n=read();int i,j,t1,t2,t3,t4;bigg::n=n;
	memset(orig::minn,127,sizeof(orig::minn));
	memset(bigg::minn,127,sizeof(bigg::minn));

	for(i=1;i<=n;i++){

		px[i]=read();
		py[i]=read();
		c[i]=read();

		x[i].posl=px[i];
		x[i].posr=py[i];
		x[i].num=i;

		t4=read();
		m[i]=read();
		cap[i]=tot;
		NETW::renew(t4);NETW::clear();
		for(j=1;j<=m[i];j++){
			t1=read();t2=read();t3=read();
			NETW::add(t1,t2,t3);
		}
		NETW::solve(1,t4);
		orig::dfs(tot+1,0,0);
		tot+=t4;
	}

	int root=build(1,n,1);
	NETW::renew(n);NETW::clear();
	for(i=1;i<=n;i++){
		ans=pp=1e9;curnum=i;
		query(px[i],py[i],root);
//		cout<<"KDTREE FIND "<<i<<' '<<ans<<' '<<pp<<'\n';
		mate[i]=pp;
	}
	for(i=1;i<=n;i++){
		if(mate[i]==-1) continue;
		if(mate[mate[i]]==i){
			bigg::e[i].push_back(mp(mate[i],c[i]+c[mate[i]]));
			bigg::e[mate[i]].push_back(mp(i,c[i]+c[mate[i]]));
			mate[mate[i]]=-1;
		}
		else{
			bigg::e[i].push_back(mp(mate[i],c[i]));
			bigg::e[mate[i]].push_back(mp(i,c[i]));
		}
	}

	orig::ST();
	
	for(i=1;i<=n;i++) if(!bigg::dep[i]) bigg::numcnt++,bigg::dfs(i,0,0);
	bigg::ST();

	int Q=read();
	while(Q--){
		t1=read();t2=read();t3=read();t4=read();
//		cout<<"query entered "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
		if(t1==t2) printf("%d\n",orig::query(cap[t1]+t3,cap[t1]+t4));
		else printf("%d\n",min(bigg::query(t1,t2),min(orig::dis[cap[t1]+t3],orig::dis[cap[t2]+t4])));
	}
} 
