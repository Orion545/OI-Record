#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
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
double x[20010],y[20010],r[20010],cur;int n;
double sqr(double x){
	return x*x;
}
struct node{
	int id,sta;
	inline double gety() const{
		return y[id]-sqrt(sqr(r[id])-sqr(x[id]-cur))*(sta?(-1):1);
	}
};
inline bool operator < (const node aa,const node a){
	double my=aa.gety(),his=a.gety();
//	cout<<"comp "<<aa.id<<' '<<aa.sta<<' '<<a.id<<' '<<a.sta<<' '<<my<<' '<<his<<' '<<cur<<'\n';
	if(my>his||(my==his&&aa.sta>a.sta)) return 1;
	else return 0;
}
set<node>s;
int first[20010],cnte,dep[20010],fa[20010];
struct edge{
	int to,next;
}a[40010];
int dp[40010];
inline void add(int u,int v){
//.	cout<<"add "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
	dp[u]=0;
	if(a[first[u]].to==f&&a[first[u]].next==-1) return;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);dp[u]^=(dp[v]+1);
	}
}
struct input{
	double pos;int id;
}d[40010];
inline bool cmp(input l,input r){
	return l.pos<r.pos;
}
int main(){
	int T=read(),i;set<node>::iterator tl,tr;
	while(T--){
		memset(first,-1,sizeof(first));
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(fa,0,sizeof(fa));
		memset(d,0,sizeof(d));
		s.clear();cnte=0;
		n=read();
		for(i=1;i<=n;i++){
			x[i]=read();y[i]=read();r[i]=read();
			d[i]=(input){x[i]-r[i],i};
			d[i+n]=(input){x[i]+r[i],i+n};
		}
		sort(d+1,d+(n<<1)+1,cmp);
		for(i=1;i<=n*2;i++){
			cur=d[i].pos;
			if(d[i].id>n){
				s.erase((node){d[i].id-n,0});
				s.erase((node){d[i].id-n,1});
				continue;
			}
			tl=tr=s.insert((node){d[i].id,1}).first;
//			cout<<tl->id<<' '<<(--tl)->id<<' '<<(++tr)->id<<'\n';
//			tl++;tr--;
			if(tl==s.begin()||(++tr)==s.end()){
				add(n+1,d[i].id);dep[d[i].id]=1;fa[d[i].id]=n+1;
			}
			else{
				tl--;
				if(tl->id==tr->id) add(d[i].id,tl->id),dep[d[i].id]=dep[tl->id]+1,fa[d[i].id]=tl->id;
				else{
					if(fa[tl->id]==fa[tr->id]) add(d[i].id,fa[tl->id]),dep[d[i].id]=dep[tl->id],fa[d[i].id]=fa[tl->id];
					else{
						if(dep[tl->id]<dep[tr->id]) add(d[i].id,tl->id),dep[d[i].id]=dep[tr->id],fa[d[i].id]=tl->id;
						else add(d[i].id,tr->id),dep[d[i].id]=dep[tl->id],fa[d[i].id]=tr->id;
					}
				}
			}
			s.insert((node){d[i].id,0});
		}
		dfs(n+1,0);
		if(dp[n+1]==0) puts("Bob");
		else puts("Alice");
	}
}
