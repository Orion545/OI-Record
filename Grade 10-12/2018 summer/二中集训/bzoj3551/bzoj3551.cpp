#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
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
int n,m,q,val[200010],ufs[200010];
bool cmp(int l,int r){
	return val[l]<val[r];
}
int find(int x){
	return ((ufs[x]==x)?x:ufs[x]=find(ufs[x]));
}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	ufs[fx]=fy;
}

struct Edge{int from,to,w;}e[500010];
bool cmpe(Edge l,Edge r){return l.w<r.w;}

int ch[7000010][2],siz[7000010],cnt,rt[200010];
int insert(int l,int r,int pre,int pos){
//	cout<<"	insert "<<l<<' '<<r<<' '<<pre<<' '<<pos<<'\n';
	int mid=(l+r)>>1,cur=++cnt;
	siz[cur]=siz[pre]+1;ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
	if(l==r) return cur;
	if(mid>=pos) ch[cur][0]=insert(l,mid,ch[pre][0],pos);
	else ch[cur][1]=insert(mid+1,r,ch[pre][1],pos);
	return cur;
}
int query(int l,int r,int cur,int pre,int k){
//	cout<<"	query "<<l<<' '<<r<<' '<<cur<<' '<<k<<' '<<siz[cur]<<' '<<siz[ch[cur][1]]<<'\n';
	int mid=(l+r)>>1,tmp=siz[ch[cur][1]]-siz[ch[pre][1]];
	if(l==r) return l;
	if(tmp>=k) return query(mid+1,r,ch[cur][1],ch[pre][1],k);
	else return query(l,mid,ch[cur][0],ch[pre][0],k-tmp);
}

int first[200010],w[200010],st[200010][19],dfn[200010],out[200010],seq[200010];
int cnte,cntp,root,clk;
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
//	cout<<"add edge "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;st[u][0]=f;seq[dfn[u]=++clk]=val[u];
//	if(clk%1000==0) cout<<"dfs "<<clk<<' '<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
	out[u]=clk;
}
void ST(){
	for(int j=1;j<=18;j++) for(int i=1;i<=cntp;i++) st[i][j]=st[st[i][j-1]][j-1];
}
void getp(int &u,int lim){
	for(int i=18;i>=0;i--) if(w[st[u][i]]<=lim) u=st[u][i];
}
int main(){
//	freopen("4.in","r",stdin);
//	freopen("bzoj3551.out","w",stdout);
	n=read();m=read();q=read();int i,t1,t2,t3,fx,fy,tans=0;
	w[0]=0x7fffffff;
	for(i=1;i<=n;i++) val[i]=read(),w[i]=0,ufs[i]=i;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		e[i]=(Edge){t1,t2,t3};
	}
	sort(e+1,e+m+1,cmpe);cntp=n;
	memset(first,-1,sizeof(first));
	for(i=1;i<=m;i++){
		if((fx=find(e[i].from))!=(fy=find(e[i].to))){
			root=++cntp;w[cntp]=e[i].w;
			ufs[cntp]=cntp;
			ufs[fx]=ufs[fy]=cntp;
			add(fx,cntp);add(fy,cntp);
		}
	}
//	cout<<"finish build tree\n";
	dfs(root,0);ST();
//	cout<<"finish dfs\n";
	for(i=1;i<=cntp;i++) rt[i]=insert(0,1e9,rt[i-1],seq[i]);
//	cout<<"finish merge\n";
	for(i=1;i<=q;i++){
		t1=read();t2=read();t3=read();
		if(~tans) t1^=tans,t2^=tans,t3^=tans;
		getp(t1,t2);
//		cout<<"finish getp "<<t1<<'\n';
		int re=query(0,1e9,rt[out[t1]],rt[dfn[t1]-1],t3);
		if(re) printf("%d\n",re),tans=re;
		else puts("-1"),tans=-1;
	}
}
