#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
struct node{
	int ll,lr,rl,rr,num,posl,posr,lc,rc;
}x[200010],y[200010];int L;
inline bool operator <(const node p,const node o){
	if(L) return p.posl<o.posl;
	else return p.posr<o.posr;
}
void update(int pos){
    y[pos].ll=y[pos].lr=y[pos].posl;
    if(y[pos].lc) y[pos].ll=min(y[pos].ll,y[y[pos].lc].ll);
    if(y[pos].rc) y[pos].ll=min(y[pos].ll,y[y[pos].rc].ll);
    if(y[pos].lc) y[pos].lr=max(y[pos].lr,y[y[pos].lc].lr);
    if(y[pos].rc) y[pos].lr=max(y[pos].lr,y[y[pos].rc].lr);
    y[pos].rl=y[pos].rr=y[pos].posr;
    if(y[pos].lc) y[pos].rl=min(y[pos].rl,y[y[pos].lc].rl);
    if(y[pos].rc) y[pos].rl=min(y[pos].rl,y[y[pos].rc].rl);
    if(y[pos].lc) y[pos].rr=max(y[pos].rr,y[y[pos].lc].rr);
    if(y[pos].rc) y[pos].rr=max(y[pos].rr,y[y[pos].rc].rr);
}
int build(int l,int r,int now){
	int mid=(l+r)>>1;L=now;
	nth_element(x+l,x+mid,x+r+1);
//	cout<<"build "<<l<<' '<<r<<' '<<x[mid].num<<'\n';
	y[mid]=x[mid];
	if(mid>l) y[mid].lc=build(l,mid-1,now^1);
	if(mid<r) y[mid].rc=build(mid+1,r,now^1);
	update(mid);
	return mid;
}
int getd(int X,int Y,int xx,int yy){
	return (X-xx)*(X-xx)+(Y-yy)*(Y-yy);
}
int dis(int p,int X,int Y){
	int xx=0,yy=0;
	if(y[p].lr<X) xx=X-y[p].lr;
	if(y[p].ll>X) xx=y[p].ll-X;
	if(y[p].rr<Y) yy=Y-y[p].rr;
	if(y[p].rl>Y) yy=y[p].rl-Y;
//	cout<<"	getdis "<<p<<' '<<y[p].ll<<' '<<y[p].lr<<' '<<y[p].rl<<' '<<y[p].rr<<' '<<X<<' '<<Y<<' '<<xx<<' '<<yy<<'\n'; 
	return xx*xx+yy*yy;
}
int ans,pp;
void query(int X,int Y,int pos){
	int dl=1e9,dr=1e9,d=getd(X,Y,y[pos].posl,y[pos].posr);
//	cout<<"query "<<X<<' '<<Y<<' '<<pos<<' '<<y[pos].num<<' '<<d<<'\n';
	if(d&&(ans>d||(ans==d&&pp>y[pos].num))) ans=d,pp=y[pos].num;
	if(y[pos].lc) dl=dis(y[pos].lc,X,Y);
	if(y[pos].rc) dr=dis(y[pos].rc,X,Y);
	if(dl<dr){
		if(dl<=ans) query(X,Y,y[pos].lc);
		if(dr<=ans) query(X,Y,y[pos].rc);
	}
	else{
		if(dr<=ans) query(X,Y,y[pos].rc);
		if(dl<=ans) query(X,Y,y[pos].lc);
	}
}
int n,tot,px[50010],py[50010],c[50010],m[50010],first[1000010],cnte=-1,cap[50010];
struct edge{
	int to,next,w,ori;
}a[3200010];
inline void add(int u,int v,int w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnte]=(edge){v,first[u],w,w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w,w};first[v]=cnte;
}
int q[1000010],head=0,tail,dep[1000010],cur[1000010];
bool bfs(int s,int t){
	int i,u,v;head=0;tail=1;
	for(i=1;i<=tot;i++) dep[i]=-1,cur[i]=first[i];
//	cout<<"bfs "<<s<<' '<<t<<'\n';
	q[0]=s;dep[s]=0;
	while(head<tail){
		u=q[head++];
//		cout<<"	head "<<u<<'\n';
		for(i=first[u];~i;i=a[i].next){
//			cout<<"		to "<<v<<' '<<dep[v]<<' '<<a[i].w<<'\n';
			v=a[i].to;if(~dep[v]||!a[i].w) continue;
			dep[v]=dep[u]+1;
			q[tail++]=v;
		}
	}
	return ~dep[t];
}
int dfs(int u,int t,int lim){
//	cout<<"dfs "<<u<<' '<<t<<' '<<lim<<'\n';
	if(u==t||!lim) return lim;
	int i,v,f,flow=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(lim,a[i].w)))){
			a[i].w-=f;a[i^1].w+=f;
			flow+=f;lim-=f;
			if(!lim) return flow;
		}
	}
	return flow;
}
int dinic(int s,int t){
	int re=0;
	while(bfs(s,t)) re+=dfs(s,t,1e9);
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,j,t1,t2,t3,t4;
	for(i=1;i<=n;i++){
		px[i]=read();py[i]=read();c[i]=read();
		x[i].posl=px[i];x[i].posr=py[i];x[i].num=i;
		t4=read();m[i]=read();cap[i]=tot+1;
		for(j=1;j<=m[i];j++){
			t1=read();t2=read();t3=read();
			add(tot+t1,tot+t2,t3);
		}
		tot+=t4;
	}
	int root=build(1,n,1);
	for(i=1;i<=n;i++){
		ans=pp=1e9;
		query(px[i],py[i],root);
		add(cap[i],cap[pp],c[i]);
	}
	int Q=read();
	while(Q--){
		t1=read();t2=read();t3=read();t4=read();
		t1=cap[t1]+t3-1;t2=cap[t2]+t4-1;
		printf("%d\n",dinic(t1,t2));
		for(i=0;i<=cnte;i++) a[i].w=a[i].ori;
	}
} 
/*
5
-263 -180
18
5 7
3 4 20
1 3 3
2 1 4
5 3 19
3 4 1
5 4 20
3 4 16
662 -84
20
3 2
1 2 9
3 2 16
247 174
9
5 8
1 3 2
2 3 16
4 1 11
5 4 17
3 4 3
5 1 1
3 1 18
5 2 5
-401 653
12
4 5
4 1 15
2 1 19
3 1 4
2 4 17
3 2 18
-955 602
12
2 1
2 1 8
10
4 4 1 4
2 2 3 1
5 5 1 2
4 4 1 2
5 5 2 1
1 3 2 3
1 1 1 5
3 3 3 5
4 5 4 1
3 1 4 1

3
390 -17
20
2 1
1 2 3
-280 -588
3
3 2
2 1 13
3 1 15
-976 -79
13
5 5
4 3 2
2 3 12
5 4 4
1 3 20
3 4 10
9
2 2 2 3
3 3 1 5
3 3 5 2
1 1 2 1
2 1 3 2
2 1 1 2
1 3 2 3
2 2 3 2
3 1 4 2

*/
