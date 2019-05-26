#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,L,R,first[200010],cnte,siz[200010],son[200010],sum,root;
struct edge{
	int to,next,w;
}a[400010];int col[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
bool vis[200010];
void getroot(int u,int f){
	int i,v;
	siz[u]=1;son[u]=0;
//	cout<<"getroot "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
int maxn[200010],colm[200010],sec[200010],sz;
int q[200010],qcol[200010],qsum[2000010],qfrom[200010],qdep[200010],head,tail;
int tmaxn[200010],tsiz;
int tmp[200010],tmppos[200010],tl,tr;
int ans=-2e9;
void bfs(int u,int st){
//	cout<<"begin "<<u<<' '<<st<<' '<<sz<<'\n';
	head=0;tail=1;int i,v,pre,cur=0,curdis,predis,curcol,precol,tmpdep;
	q[0]=u;qsum[0]=col[st];qcol[0]=st;qfrom[0]=0;qdep[0]=1;
	tl=tr=0;tsiz=0;
	for(i=R-1;i>=L-1;i--){
		if(i>sz) continue;
		if(st!=colm[i]||(st==colm[i]&&maxn[i]-col[st]>=sec[i])) tmp[tr]=maxn[i]-(st==colm[i])*col[st];
		else tmp[tr]=sec[i];
		tmppos[tr++]=i;
		while(tr>tl&&tmp[tr-1]>tmp[tr-2]) tmp[tr-2]=tmp[tr-1],tmppos[tr-2]=tmppos[tr-1],tmp[--tr]=-2e9;
	}
	while(head<tail){
		u=q[head];
		predis=qsum[head];
		pre=qfrom[head];
		tmpdep=qdep[head];
		precol=qcol[head++];
//		cout<<"	bfs "<<u<<' '<<predis<<' '<<pre<<' '<<tmpdep<<' '<<precol<<'\n';
		if(tmpdep>cur){
			cur++;
			tmaxn[tmpdep]=-2e9;
			if(L-tmpdep>sz) goto jump;
//			cout<<"		dandiao "<<tl<<' '<<tr<<' '<<cur<<' '<<L<<' '<<cur<<' '<<R<<' '<<maxn[L-cur]<<' '<<sec[L-cur]<<'\n';
			if(R-cur<0) return;
			while(tmppos[tl]>(R-cur)) tmppos[tl]=0,tmp[tl]=-2e9,tl++;
			if(st!=colm[L-cur]||(st==colm[L-cur]&&maxn[L-cur]-col[st]>=sec[L-cur])) tmp[tr]=maxn[L-cur]-(st==colm[L-cur])*col[st];
			else tmp[tr]=sec[L-cur];
			tmppos[tr++]=L-cur;
			while(tr>tl&&tmp[tr-1]>tmp[tr-2]) tmp[tr-2]=tmp[tr-1],tmppos[tr-2]=tmppos[tr-1],tmp[--tr]=-2e9;
		}
//		cout<<"	cur head "<<tmp[tl]<<' '<<tmppos[tl]<<'\n';
		ans=max(ans,predis+tmp[tl]);
		jump:
		tmaxn[tmpdep]=max(tmaxn[tmpdep],predis);tsiz=max(tsiz,tmpdep);
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==pre||vis[v]) continue;
			curcol=a[i].w;
			curdis=predis+(precol!=curcol)*col[curcol];
			q[tail]=v;
			qsum[tail]=curdis;
			qfrom[tail]=u;
			qdep[tail]=tmpdep+1;
			qcol[tail++]=curcol;
		}
	}
}
int maxdep[200010],curdep[200010];
void getdep(int u,int f){
	int i,v;curdep[u]=curdep[f]+1;
	maxdep[u]=curdep[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getdep(v,u);maxdep[u]=max(maxdep[u],maxdep[v]);
	}
}
void dfs(int u){
//	cout<<"dfs "<<u<<' '<<sum<<'\n';
	int i,v,j,tmpss=sum;vis[u]=1;sz=0;
	curdep[u]=0;
	getdep(u,0);
	for(i=0;i<=maxdep[u];i++) maxn[i]=sec[i]=-2e9,colm[i]=0;
//	cout<<"begin1\n";
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		bfs(v,a[i].w);
		while(tl<tr) tmp[tl]=-2e9,tmppos[tl++]=0;
		sz=max(sz,tsiz);
		for(j=1;j<=tsiz;j++){
//			cout<<"	renew ori "<<j<<' '<<tmaxn[j]<<'\n';
			if(tmaxn[j]>=maxn[j]){
				if(a[i].w==colm[j]) maxn[j]=tmaxn[j];
				else sec[j]=maxn[j],maxn[j]=tmaxn[j],colm[j]=a[i].w;
			}
			else if(tmaxn[j]>=sec[j]&&a[i].w!=colm[j]) sec[j]=tmaxn[j];
		}
	}
//	cout<<"begin2\n";
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=((siz[v]>siz[u])?(tmpss-siz[u]):siz[v]);
		root=0;son[0]=sum;
		getroot(v,0);
		dfs(root);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();L=read();R=read();
	int i,t1,t2,t3;
	for(i=0;i<=n;i++) tmp[i]=-2e9;
	for(i=1;i<=m;i++) col[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	sum=n;root=0;son[0]=n;
	getroot(1,0);
	dfs(root);
	printf("%d\n",ans);
}
