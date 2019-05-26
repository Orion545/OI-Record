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
int ch[25000010][2],cnt,a[25000010],first[80010],w[80010],cnte,st[80010][20],dep[80010],ufs[80010];
int rt[80010],n,m,q,back[80010];
int find(int x){
	return ((ufs[x]<0)?x:ufs[x]=find(ufs[x]));
}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	ufs[fx]+=ufs[fy];ufs[fy]=fx;
}
struct node{
	int val,pos,rk;
}rk[80010];
bool cmp1(node l,node r){
	return l.val<r.val; 
}
bool cmp2(node l,node r){
	return l.pos<r.pos;
}
void update(int x){
	a[x]=a[ch[x][0]]+a[ch[x][1]];
}
int insert(int l,int r,int pre,int pos){
	int cur=++cnt;ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];a[cur]=a[pre]+1;
//	cout<<"	insert "<<l<<' '<<r<<' '<<pre<<' '<<pos<<' '<<cur<<' '<<a[cur]<<'\n';
	if(l==r) return cur;
	int mid=(l+r)>>1;
	if(mid>=pos) ch[cur][0]=insert(l,mid,ch[pre][0],pos);
	else ch[cur][1]=insert(mid+1,r,ch[pre][1],pos);
	return cur;
}
int getk(int l,int r,int u,int v,int lca,int flca,int k){
	if(l==r) return l;
	int mid=(l+r)>>1,tmp=a[ch[u][0]]+a[ch[v][0]]-a[ch[lca][0]]-a[ch[flca][0]];
//	cout<<"	getk "<<l<<' '<<r<<' '<<tmp<<' '<<k<<'\n';
	if(tmp>=k) return getk(l,mid,ch[u][0],ch[v][0],ch[lca][0],ch[flca][0],k);
	else return getk(mid+1,r,ch[u][1],ch[v][1],ch[lca][1],ch[flca][1],k-tmp);
}
struct edge{
	int to,next;
}e[160010];
inline void add(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs1(int u,int f){
	int i,v;dep[u]=dep[f]+1;st[u][0]=f;
//	cout<<"dfs1 "<<u<<' '<<f<<'\n';
	rt[u]=insert(1,n,rt[f],w[u]);
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs1(v,u);
	}
}
int sta[80010],top;
void dfs2(int u,int f){
//	cout<<"dfs2 "<<u<<' '<<f<<'\n';
	int i,v;dep[u]=dep[f]+1;st[u][0]=f;
	rt[u]=insert(1,n,rt[f],w[u]);
	sta[++top]=u;
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs2(v,u);
	}
}
int lca(int l,int r){
//	cout<<"lca "<<l<<' '<<r<<'\n';
	if(dep[l]>dep[r]) swap(l,r);
	int i;
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
//	cout<<"finish phase 1 "<<l<<' '<<r<<'\n';
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			r=st[r][i];
			l=st[l][i];
		}
	}
//	cout<<"finish lca "<<l<<' '<<r<<' '<<st[l][0]<<'\n';
	return st[l][0];
}
int main(){
	freopen("9.in","r",stdin);
	freopen("3123.out","w",stdout);
	int T=read();T=1;
	memset(first,-1,sizeof(first));cnt=cnte=0;
	n=read();m=read();q=read();int i,j,k,t1,t2,t3,t4;char s[10];
	memset(ufs,-1,sizeof(ufs));
	for(i=1;i<=n;i++){
		t1=read();rk[i]=(node){t1,i,0};
	}
	sort(rk+1,rk+n+1,cmp1);
	for(i=1;i<=n;i++) rk[i].rk=i;
	sort(rk+1,rk+n+1,cmp2);
	for(i=1;i<=n;i++) w[i]=rk[i].rk,back[rk[i].rk]=rk[i].val;
	for(i=1;i<=m;i++){
		t1=read();t2=read();add(t1,t2);
	}
	for(i=1;i<=n;i++){
		if(!st[i][0]) dfs1(i,0);
	}
	for(j=1;j<=19;j++)
		for(i=1;i<=n;i++) 
			st[i][j]=st[st[i][j-1]][j-1];
	int ans=0;
	for(i=1;i<=q;i++){
		scanf("%s",s);
		if(s[0]=='L'){
			t1=read();t2=read();
			t1^=ans;t2^=ans;
			if(ufs[find(t1)]>ufs[find(t2)]) swap(t1,t2);
			join(t1,t2);
			top=0;
			dfs2(t2,t1);
			add(t1,t2);
			for(j=1;j<=19;j++)
				for(k=1;k<=top;k++)
					st[sta[k]][j]=st[st[sta[k]][j-1]][j-1];
		}
		else{
			t1=read();t2=read();t4=read();
			t1^=ans;t2^=ans;t4^=ans;t3=lca(t1,t2);
//			cout<<"query "<<t1<<' '<<t2<<' '<<t3<<' '<<st[t3][0]<<'\n';
			printf("%d\n",ans=back[getk(1,n,rt[t1],rt[t2],rt[t3],rt[st[t3][0]],t4)]);
		}
	}
}
