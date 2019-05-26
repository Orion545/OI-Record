#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int n,m,cnt=0,belong[100100],size[100100];
struct edge{
	int to,next;
};
struct topology{
	int first[100010],deg[100010],num;
	edge a[100010];
	int f[100010];
	topology(){
		num=0;
		memset(first,-1,sizeof(first));
		memset(deg,0,sizeof(deg));
	}
	void add(int u,int v){
		num++;deg[v]++;
		a[num].to=v;a[num].next=first[u];first[u]=num;
//		cout<<"added "<<u<<ends<<v<<ends<<deg[v]<<endl;
	}
	void topo(){
		queue<int>q;
		int i,u,v;
		memset(f,0,sizeof(f));f[belong[1]]=size[belong[1]];
		for(i=1;i<=cnt;i++){
//			cout<<deg[i]<<ends;
			if(!deg[i]) q.push(i);
		} 
//		cout<<endl;
		while(!q.empty()){
			u=q.front();q.pop();
//			cout<<"topo "<<u<<endl;
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;
//				cout<<"	to "<<v<<endl;
				f[v]=max(f[v],f[u]+size[belong[v]]);
				if(!(--deg[v])) q.push(v);
			}
		}
	}
};
topology pos,neg;
struct graph{
	int first[100010],num,dfn[100010],low[100010],times;
	edge a[100010];
	bool vis[100100],out[100100];
	stack<int>s;
	graph(){
		num=times=0;
		memset(first,-1,sizeof(first));
		memset(vis,0,sizeof(vis));
		memset(out,0,sizeof(out));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
	}
	void add(int u,int v){
		num++;
		a[num].to=v;a[num].next=first[u];first[u]=num;
	}
	void tarjan(int k){
//		cout<<"tarjan "<<k<<endl;
		int i,v;vis[k]=1;
		dfn[k]=low[k]=++times;
		s.push(k);
		for(i=first[k];~i;i=a[i].next){
			v=a[i].to;
			if(out[v]) continue;
//			cout<<"	goto "<<v<<endl;
			if(!vis[v]){
				tarjan(v);low[k]=min(low[k],low[v]);
			}
			else low[k]=min(low[k],dfn[v]);
		}
//		cout<<"end of "<<k<<endl;
		if(dfn[k]==low[k]){
//			cout<<"poped "<<k<<endl;
			cnt++;
			while(s.top()!=k){
				belong[s.top()]=cnt;out[s.top()]=1;
				s.pop();size[cnt]++;
			}
			belong[k]=cnt;out[k]=1;s.pop();size[cnt]++;
		}
	}
	void do_tarjan(){
		for(int i=1;i<=n;i++){
			if(!vis[i]) tarjan(i);
		}
	}
};
graph aa;
int calc(){
	int i,u,v,ans=size[belong[1]]*2;
	for(u=1;u<=n;u++){
		for(i=aa.first[u];~i;i=aa.a[i].next){
			v=aa.a[i].to;
			ans=max(ans,(pos.f[belong[v]]+neg.f[belong[u]]));
		}
	}
	return ans-size[belong[1]];
}
void renew(graph z,topology &x,topology &y){
	int i,u,v;
	for(u=1;u<=n;u++){
		for(i=z.first[u];~i;i=z.a[i].next){
			v=z.a[i].to;
			if(belong[u]==belong[v]) continue;
//			cout<<"add "<<u<<ends<<v<<endl;
			x.add(belong[u],belong[v]);
			y.add(belong[v],belong[u]);
		}
	}
}
int main(){
	int i,j,t1,t2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&t1,&t2);
		aa.add(t1,t2);
	}
	aa.do_tarjan();
//	for(i=1;i<=n;i++) cout<<belong[i]<<ends;cout<<endl;
//	for(i=1;i<=cnt;i++) cout<<size[i]<<ends;cout<<endl;
	renew(aa,pos,neg);
//	cout<<endl<<endl;
	pos.topo();
//	cout<<endl<<endl;
	neg.topo();
	printf("%d",calc());
}
