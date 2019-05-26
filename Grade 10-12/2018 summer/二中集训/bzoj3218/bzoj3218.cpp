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
int n,first[200010],cnte=-1,dep[200010],cur[200010];
struct edge{
	int to,next;ll w;
}a[1500010];
void add(int u,int v,ll w){
//	cout<<"	add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],0};first[v]=cnte; 
}
bool bfs(int s,int t){
	int i,u,v,q[200010],head=0,tail=1;
	for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
	dep[s]=0;q[0]=s;
//	cout<<"bfs "<<s<<' '<<t<<'\n';
	while(head<tail){
		u=q[head++];
//		cout<<"	enter "<<u<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(~dep[v]||!a[i].w) continue;
//			cout<<"		to "<<v<<'\n';
			dep[v]=dep[u]+1;q[tail++]=v;
		}
	}
	return ~dep[t];
}
int dfs(int u,int t,ll lim){
	if(u==t||!lim) return lim;
	int i,v,f,flow=0;
	for(i=cur[u];~i;i=a[i].next){
		v=a[i].to;cur[u]=i;
		if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(a[i].w,lim)))){
			flow+=f;lim-=f;
			a[i].w-=f;a[i^1].w+=f;
			if(!lim) return flow;
		}
	}
	if(lim) dep[u]=-1;
	return flow;
}
ll dinic(int s,int t){
	ll re=0;
	while(bfs(s,t)) re+=dfs(s,t,1e12);
	return re;
}
struct chairmantree{
	int ch[1000010][2],cnt,root[5010];
	int insert(int l,int r,int pos,int pre,int u){
//		cout<<"insert "<<l<<' '<<r<<' '<<pos<<' '<<pre<<'\n';
		int cur=++cnt;
		ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
		add(u,cur,1e12);
		if(l==r){
			if(pre) add(pre,cur,1e12);
			return cur;
		} 
		int mid=(l+r)>>1;
		if(mid>=pos){
			ch[cur][0]=insert(l,mid,pos,ch[pre][0],u);
			if(pre) add(pre,cur,1e12);
		}
		else{
			ch[cur][1]=insert(mid+1,r,pos,ch[pre][1],u);
			if(pre) add(pre,cur,1e12); 
		}
		return cur;
	}
	void check(int l,int r,int ql,int qr,int cur,int u){
		if(!cur) return;
		int mid=(l+r)>>1;
//		cout<<"check "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<'\n';
		if(l>=ql&&r<=qr){
			add(cur,u,1e12);
			return;
		}
		if(mid>=ql) check(l,mid,ql,qr,ch[cur][0],u);
		if(mid<qr) check(mid+1,r,ql,qr,ch[cur][1],u);  
	}
}T;
int main(){
//	freopen("10.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();int i,val,b,w,l,r,p;ll sum=0;
	int s=0,t=200000;T.cnt=n<<1;
	for(i=1;i<=n;i++){
		val=read();b=read();w=read();l=read();r=read();p=read();
		sum+=(ll)b+w;
		add(s,i,w);add(i,t,b);add(i+n,i,p);
		T.root[i]=T.insert(0,1e9,val,T.root[i-1],i);
		T.check(0,1e9,l,r,T.root[i-1],i+n);
	}
	printf("%lld\n",sum-dinic(s,t));
}
/*
10
0 1 7 3 9 2
7 4 0 9 10 5
1 0 4 2 10 2
7 9 1 5 7 2
6 3 5 3 6 2
6 6 4 1 8 1
6 1 6 0 6 5
2 2 5 0 9 3
5 1 3 0 2 5
5 6 7 1 1 2

*/
