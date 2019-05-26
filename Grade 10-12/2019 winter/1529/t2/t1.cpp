#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
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
int n,m;
struct edge{
	int from,to,next;
};
namespace g{
	int first[1000010],cnte=-1;
	edge a[1000010];
	void init(){memset(first,-1,sizeof(first));}
	inline void add(int u,int v){
		a[++cnte]=(edge){u,v,first[u]};first[u]=cnte;
	}
	int dfn[1000010],low[1000010],clk,belong[1000010],cntb,s[1000010],top,ins[1000010];
	void tarjan(int u){
		int i,v,tmp=0;
		dfn[u]=low[u]=++clk;
		s[++top]=u;ins[u]=1;
//		cout<<"tarjan "<<u<<' '<<clk<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(!dfn[v]){
				tarjan(v);
				low[u]=min(low[u],low[v]);
			}
			else if(ins[v]) low[u]=min(low[u],dfn[v]);
		}
//		cout<<"finish tarjan "<<u<<' '<<dfn[u]<<' '<<low[u]<<'\n';
		if(dfn[u]!=low[u]) return;
		cntb++;
		while(tmp!=u){
			tmp=s[top--];
			belong[tmp]=cntb;
			ins[tmp]=0;
		}
	}
}
namespace t{
	int first[1000010],cnte=-1,in[1000010],pos[1000010],lis[1000010];
	void init(){memset(first,-1,sizeof(first));}
	edge a[1000010];
	inline void add(int u,int v){
		a[++cnte]=(edge){u,v,first[u]};first[u]=cnte;
		in[v]++;
	}
	queue<int>q;
	void topo(){
		int i,u,v,cnt=0;
		for(i=1;i<=g::cntb;i++) if(!in[i]) q.push(i);
		while(!q.empty()){
			u=q.front();q.pop();
			lis[++cnt]=u;pos[u]=cnt;
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;in[v]--;
				if(!in[v]) q.push(v);
			}
		}
	}
}
namespace tinv{
	int first[1000010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	edge a[1000010];
	inline void add(int u,int v){
		a[++cnte]=(edge){u,v,first[u]};first[u]=cnte;
	}
}
int sum[1000010];vector<int>ans;
int main(){
	n=read();m=read();int i,j,t1,t2;
	g::init();
	t::init();
	tinv::init();
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		g::add(t1,t2);
	}
	for(i=1;i<=n;i++) if(!g::dfn[i]) g::tarjan(i);
//	for(i=1;i<=n;i++) cout<<i<<' '<<g::belong[i]<<'\n';
	for(i=0;i<=g::cnte;i++){
		t1=g::belong[g::a[i].from];t2=g::belong[g::a[i].to];
		if(t1==t2) continue;
		t::add(t1,t2);
		tinv::add(t2,t1);
	}
	t::topo();
	for(j=1;j<=g::cntb;j++){
		t1=t::lis[j];
		t2=g::cntb+1;
		for(i=t::first[t1];~i;i=t::a[i].next) t2=min(t2,t::pos[t::a[i].to]);
		if(t2!=g::cntb+1) sum[j+1]++,sum[t2]--;
		t2=0;
		for(i=tinv::first[t1];~i;i=tinv::a[i].next) t2=max(t2,t::pos[tinv::a[i].to]);
		if(t2!=0) sum[t2+1]++,sum[j]--;
	}
	for(i=1;i<=g::cntb;i++){
		sum[i]+=sum[i-1];
	}
	for(i=1;i<=n;i++){
		if(sum[t::pos[g::belong[i]]]==0) ans.push_back(i);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
	puts("");
}
