#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,cnte,clk,cnt;
int rt[300010],first[300010],dep[300010],le[300010],ri[300010],dfn[300010],siz[300010];
int ch[6000010][2];
ll x[6000010];
struct edge{
	int to,next;
}a[600010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	le[u]=++clk;dfn[clk]=u;
	dep[u]=dep[f]+1;siz[u]=1;
	int i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	ri[u]=clk;
}
inline int insert(int l,int r,int pre,int val,ll w){
	x[++cnt]=x[pre]+w;ch[cnt][0]=ch[pre][0];ch[cnt][1]=ch[pre][1];
//	cout<<"insert "<<l<<' '<<r<<' '<<cnt<<' '<<pre<<' '<<val<<' '<<w<<'\n';
	if(l==r) return cnt;
	int mid=(l+r)>>1,cur=cnt;
	if(val<=mid) ch[cur][0]=insert(l,mid,ch[pre][0],val,w);
	else ch[cur][1]=insert(mid+1,r,ch[pre][1],val,w);
	return cur;
}
inline ll query(int l,int r,int ql,int qr,int num){
//	cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<'\n';
	if(l>=ql&&r<=qr) return x[num];
	int mid=(l+r)>>1;ll re=0;
	if(mid>=ql) re+=query(l,mid,ql,qr,ch[num][0]);
	if(mid<qr) re+=query(mid+1,r,ql,qr,ch[num][1]);
	return re;
}
int main(){
//	freopen("laugh5.in","r",stdin);
//	freopen("laugh.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,lim=0;ll ans;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	
	dfs(1,0);
	for(i=1;i<=n;i++) 
		rt[i]=insert(1,n,rt[i-1],dep[dfn[i]],siz[dfn[i]]-1),lim=max(lim,dep[dfn[i]]);
	
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		ans=((ll)(siz[t1]-1)*(ll)(min(dep[t1]-1,t2)));
//		cout<<"tmpans "<<ans<<'\n';
		ans+=query(1,n,min(lim,dep[t1]+1),min(lim,dep[t1]+t2),rt[ri[t1]]);
//		cout<<"tmpans "<<ans<<'\n';
		ans-=query(1,n,min(lim,dep[t1]+1),min(lim,dep[t1]+t2),rt[le[t1]]);
		printf("%lld\n",ans);
//		if(i%1000==0) cout<<i<<'\n';
	}
}
