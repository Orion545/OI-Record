#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int vis[10000010];int pri[1000010],cntp,minp[10000010];
void init(){
	int i,j,k,len=10000000;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,minp[i]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			minp[k]=pri[j];
			if(i%pri[j]==0) break;
		}
	}
}
int n,cntn,first[3000010],cnte=1;
struct edge{
	int to,next;
}a[30000010];
inline void add(int u,int v){
//	cout<<"add "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dfn[3000010],low[3000010],clk,val[3000010],ans;
int CNT[3000010];
void tarjan(int u,int f,int maxsiz){
	int i,v,out=maxsiz-val[u],maxs=0;vis[u]=1;
	dfn[u]=low[u]=++clk;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		if(!vis[v]){
			tarjan(v,u,maxsiz);
			low[u]=min(low[u],low[v]);
			maxs=max(maxs,val[v]);
			if(low[v]<dfn[u]) out+=val[v];
		}
		else if(vis[v]==1) low[u]=min(low[u],dfn[v]);
	}
//	cout<<"finish tarjan "<<u<<' '<<out<<' '<<maxs<<'\n';
	if(u<=n){
		if(CNT[u]==1) ans=min(ans,max(out,maxs));
		else ans=min(ans,maxsiz-1);
	}
	vis[u]=2;return;
}
void dfs(int u){
	int i,v;vis[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		dfs(v);val[u]+=val[v];
	}
}
int x[100010],id[10000010],back[3000010];
int main(){
	init();
	int T=read();
	while(T--){
		n=read();int i,j,k,tmp;
		for(i=1;i<=n;i++) x[i]=read();
		sort(x+1,x+n+1);
		int orin=n;n=0;
		for(i=1;i<=orin;i++){
			if(x[i]!=x[i-1]) x[++n]=x[i],val[n]=1,first[n]=-1,CNT[n]=1;
			else CNT[n]++,val[n]++;
		}
		if(n==0){cout<<1<<'\n';continue;}
		if(n==1){cout<<max(1,val[1]-1)<<'\n';continue;}
		cntn=n;

		for(i=1;i<=n;i++){
			int xx=x[i];static int li[110];
//			cout<<"gao "<<xx<<'\n';
			li[0]=0;
			while(xx>1){
				li[++li[0]]=tmp=minp[xx];
				k=0;
				while(xx%tmp==0) xx/=tmp,k++;
//				cout<<"get pfac "<<tmp<<' '<<k<<'\n';
				if(k>=2){
					if(!id[j=tmp*tmp]){
						id[j]=++cntn;
						first[cntn]=-1;
						CNT[cntn]=0;
						val[cntn]=0;
						back[cntn]=j;
					}
					add(i,id[j]);
				}
			}
			for(j=1;j<li[0];j++){
				for(k=j+1;k<=li[0];k++){
					if(!id[tmp=li[j]*li[k]]){
						id[tmp]=++cntn;
						first[cntn]=-1;
						CNT[cntn]=0;
						val[cntn]=0;
						back[cntn]=tmp;
					}
					add(i,id[tmp]);
				}
			}
		}
		for(i=n+1;i<=cntn;i++) id[back[i]]=0;
		static int vsiz[110];
		vsiz[0]=0;vsiz[1]=0;val[0]=0;
		memset(vis,0,sizeof(int)*(cntn+1));
		for(i=1;i<=cntn;i++){
			if(vis[i]) continue;
			dfs(i);
			if(val[i]>val[vsiz[0]]) vsiz[1]=vsiz[0],vsiz[0]=i;
			else if(val[i]>val[vsiz[1]]) vsiz[1]=i;
		}
		clk=0;ans=2e9;
//		cout<<"getval "<<vsiz[0]<<' '<<vsiz[1]<<'\n';
		memset(vis,0,sizeof(int)*(cntn+1));
		tarjan(vsiz[0],0,val[vsiz[0]]);
		cout<<max(ans,val[vsiz[1]])<<'\n';
	}
}
