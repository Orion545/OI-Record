#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
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
int n;
namespace sol{
	int first[1010],cnte;
	struct edge{
		int to,next;
	}a[5010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	}
	int vis[1010];
	bool dfs(int u){
		int i,v;vis[u]=1;
		if(u==n) return 1;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			if(dfs(v)) return 1;
		}
		return 0;
	}
}
int m,p,cnte=-1,sum=0,first[500010],dep[500010],cur[500010];
struct edge{
    int to,next,w;
}a[2500010];
inline void add(int u,int v,int w){
	if(u>=500000) u=500000;
	if(v>=500000) v=500000;
//	cout<<"add edge "<<u<<" "<<v<<" "<<w<<"\n";
    a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
    a[++cnte]=(edge){u,first[v],0},first[v]=cnte;
}
int q[500010];
bool bfs(int s,int t){
    int i,u,v,head=0,tail=1;
    for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
    q[0]=s;dep[s]=0;
    while(head<tail){
        u=q[head++];
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
            if(~dep[v]||!a[i].w) continue;
            dep[v]=dep[u]+1;q[tail++]=v;
        }
    }
    return ~dep[t];
}
int _min(int l,int r){return (l>r)?r:l;}
int dfs(int u,int t,int limit){
    if(u==t||!limit) return limit;
    int i,v,f,flow=0;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(dep[v]==dep[u]+1&&(f=dfs(v,t,_min(limit,a[i].w)))){
            flow+=f;limit-=f;
            a[i].w-=f;a[i^1].w+=f;
            if(!limit) return flow;
        }
    }
    return flow;
}
void dinic(int s,int t){
    while(bfs(s,t)) sum+=dfs(s,t,inf);
}
int op[10010],ed[10010],w[10010];
int main(){
     freopen("B.in","r",stdin);
     freopen("B.out","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&p)){
    	int i,ans=0;
    	
    	memset(first,-1,sizeof(first));
    	memset(sol::first,-1,sizeof(sol::first));
    	memset(a,0,sizeof(a));
    	memset(sol::a,0,sizeof(sol::a));
    	memset(sol::vis,0,sizeof(sol::vis));
    	memset(op,0,sizeof(op));
    	memset(ed,0,sizeof(ed));
    	memset(w,0,sizeof(w));
    	
    	cnte=sol::cnte=-1;
    	for(i=1;i<=m;i++){
    		op[i]=read();ed[i]=read();w[i]=read();
    		op[i]++;ed[i]++;
    		sol::add(op[i],ed[i]);
    		if(ed[i]==n) ed[i]=500000;
    	}
    	if(!p){
    		puts("0");continue;
    	}
    	if(!sol::dfs(1)){
    		puts("No solution");continue;
    	}
    	add(0,1,inf);sum=0;
    	while(++ans){
//			cout<<"new day "<<ans<<" "<<sum<<"\n";
    	    add(0,(ans-0)*n+1,inf);
    	    for(i=1;i<n;i++) add((ans-1)*n+i,(ans-0)*n+i,inf);
    	    for(i=1;i<=m;i++){
    	    	add((ans-1)*n+op[i],(ans-0)*n+ed[i],w[i]);
    	    }
    	    dinic(0,500000);
    	    if(sum>=p){
    	        printf("%d\n",ans);break;
    	    }
    	}
	}
}
/*
5 6 4
0 1 2
0 3 1
1 2 1
2 3 1
1 4 1
3 4 2
5 6 4
0 1 2
0 3 1
1 2 1
2 3 1
1 4 1
3 4 2

*/
