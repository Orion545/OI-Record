#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define id(i,j) (i-1)*46+j
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
int n,m,cnt=-1,first[200010],dep[200010],cur[200010];
int pri[210],cntp,vis[210],fac[210][10];
struct edge{
	int to,next,w;
}a[2000010];
inline void add(int u,int v,int w){
	a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],0};first[v]=cnt;
}
void init(){
	int i,j,k,tmp;
	for(i=2;i<=200;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];
			if(k>200) break;
			vis[k]=1;
			if(i%pri[j]==0) break;
		}
	}
//	cout<<cntp<<'\n';
	for(k=2;k<=200;k++){
		tmp=k;i=1;
		while(tmp>1){
			j=pri[i];
			if(tmp%j==0){
				fac[k][++fac[k][0]]=i;
				while(tmp%j==0) tmp/=j;
			}
			i++;
		}
	}
}
int q[200010];
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
int dfs(int u,int t,int limit){
	if(u==t||!limit) return limit;
	int i,v,f,flow=0;
	for(i=cur[u];~i;i=a[i].next){
		v=a[i].to;cur[u]=i;
		if((dep[v]==dep[u]+1)&&(f=dfs(v,t,min(a[i].w,limit)))){
			flow+=f;limit-=f;
			a[i].w-=f;a[i^1].w+=f;
			if(!limit) return flow;
		}
	}
	return flow;
}
#define inf 1e9
int dinic(int s,int t){
	int re=0;
	while(bfs(s,t)) re+=dfs(s,t,inf);
	return re;
}
int S=0,T;
int main(){
//	freopen("20.in","r",stdin); 
	memset(first,-1,sizeof(first));
	init();
	n=read();m=read();int i,j,k,t1,t2,t3;
	T=n+m+46*46*3+1;
	for(i=1;i<=n;i++){
		t1=read();t2=read();t3=read();
		add(S,i,1);
		for(j=1;j<=fac[t1][0];j++)
			for(k=1;k<=fac[t2][0];k++)
				add(i,n+id(fac[t1][j],fac[t2][k]),1);
		for(j=1;j<=fac[t1][0];j++)
			for(k=1;k<=fac[t3][0];k++)
				add(i,n+id(fac[t1][j],fac[t3][k])+46*46,1);
		for(j=1;j<=fac[t2][0];j++)
			for(k=1;k<=fac[t3][0];k++)
				add(i,n+id(fac[t2][j],fac[t3][k])+46*46*2,1);
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(i+46*46*3+n,T,1);
		for(j=1;j<=fac[t1][0];j++)
			for(k=1;k<=fac[t2][0];k++)
				add(n+id(fac[t1][j],fac[t2][k]),i+46*46*3+n,1);
		for(j=1;j<=fac[t1][0];j++)
			for(k=1;k<=fac[t3][0];k++)
				add(n+id(fac[t1][j],fac[t3][k])+46*46,i+46*46*3+n,1);
		for(j=1;j<=fac[t2][0];j++)
			for(k=1;k<=fac[t3][0];k++)
				add(n+id(fac[t2][j],fac[t3][k])+46*46*2,i+46*46*3+n,1);
	}
//	cout<<"begin dinic\n";
	printf("%d\n",dinic(S,T));
}
