#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,tote,cnte=-1,first[10010],dep[10010],cur[10010];
struct rsc{
	int a[10];
	rsc(){memset(a,0,sizeof(a));}
	inline bool operator<(const rsc b){
		for(int i=1;i<=m;i++) if(a[i]!=b.a[i]) return a[i]<b.a[i];
		return 0;
	}
	inline rsc operator+(const rsc b){
		rsc re;
		for(int i=1;i<=m;i++) re.a[i]=a[i]+b.a[i];
		return re;
	}
	inline rsc operator-(const rsc b){
		rsc re;
		for(int i=1;i<=m;i++) re.a[i]=a[i]-b.a[i];
		return re;
	}
	inline bool zero(){
		for(int i=1;i<=m;i++) if(a[i]!=0) return 0;
		return 1;
	}
};
rsc INF,zero;
struct edge{
	int to,next;
	rsc w;
}a[200010];
inline void add(int u,int v,rsc adde){
//	cout<<"add "<<u<<' '<<v<<' '<<adde.a[1]<<' '<<adde.a[2]<<'\n';
	cnte++;a[cnte].to=v;a[cnte].next=first[u];a[cnte].w=adde;first[u]=cnte;
	cnte++;a[cnte].to=u;a[cnte].next=first[v];a[cnte].w=zero;first[v]=cnte;
}
bool bfs(int s,int t){
	int q[10010],head=0,tail=1,i,u,v;
	memset(dep,-1,sizeof(dep));
	for(i=0;i<=n+1;i++) cur[i]=first[i];
	q[0]=s;dep[s]=0;
	while(head<tail){
		u=q[head++];
//		if(u==n+1) cout<<"bfs "<<u<<' '<<dep[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
//			if(v==n+1) cout<<"	goto "<<v<<" from "<<u<<'\n';
			if(~dep[v]||a[i].w.zero()) continue;
//			if(v==n+1) cout<<"	suc "<<a[i].w.a[1]<<' '<<a[i].w.a[2]<<' '<<a[i].w.a[3]<<'\n';
			dep[v]=dep[u]+1;q[tail++]=v;
		}
	}
	return ~dep[t];
}
rsc min(rsc l,rsc r){
	return ((l<r)?l:r);
}
rsc dfs(int u,int t,rsc lim){
	if(u==t||lim.zero()) return lim;
//	cout<<"dfs "<<u<<' '<<t<<' '<<lim.a[1]<<' '<<lim.a[2]<<' '<<lim.a[3]<<'\n';
	int i,v;rsc f,flow=zero;
	for(i=cur[u];~i;i=a[i].next){
		v=a[i].to;cur[u]=i;
		if(dep[v]!=dep[u]+1) continue;
//		cout<<"	go "<<u<<' '<<v<<' '<<a[i].w.a[1]<<' '<<a[i].w.a[2]<<' '<<a[i].w.a[3]<<'\n';
		f=dfs(v,t,min(a[i].w,lim));
		if(!f.zero()){
			a[i].w=(a[i].w-f);a[i^1].w=(a[i^1].w+f);
			flow=(flow+f);lim=(lim-f);
			if(lim.zero()) return flow;
		}
	}
	return flow;
}
rsc dinic(int s,int t){
	rsc re;
	while(bfs(s,t)) re=(re+dfs(s,t,INF));
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	cnte=-1;
	int i,j,t1,t2;
	rsc tmp,re;
	char s[10];
	n=read();tote=read();m=read();

	for(i=1;i<=m;i++) INF.a[i]=1e9;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		memset(tmp.a,0,sizeof(tmp.a));
		for(j=0;j<m;j++){
			if(s[j]=='+') tmp.a[j+1]=1;
			if(s[j]=='-') tmp.a[j+1]=-1;
		}
		if(tmp<zero){
			for(j=1;j<=m;j++) tmp.a[j]=-tmp.a[j];
			add(i,n+1,tmp);
		}
		else add(0,i,tmp),re=(re+tmp);
	}
	for(i=1;i<=tote;i++){
		t1=read();t2=read();
		add(t1,t2,INF);
	}
	tmp=dinic(0,n+1);
	for(i=1;i<=m;i++) printf("%d ",re.a[i]-tmp.a[i]+1000);
}
