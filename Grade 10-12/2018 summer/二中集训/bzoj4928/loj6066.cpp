#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector> 
#define ll long long
#define uint unsigned long long
#define hash DEEP_DARK_FANTASY
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n;
int first[100010],dfn[100010],low[100010],dep[100010],dis[100010],dfsclk=0,cnt=0;
int bfn[100010],back[100010],bfsclk=0,q[100010],vis[100010];
vector<int>node[100010];
struct edge{
	int to,next;
}e[200010];
inline void add(int u,int v){
	e[++cnt]=(edge){v,first[u]};first[u]=cnt;
	e[++cnt]=(edge){u,first[v]};first[v]=cnt;
}
void dfs(int u,int f){
	dfn[u]=++dfsclk;dep[u]=dep[f]+1;dis[u]=0;int i,v;
	node[dep[u]].push_back(u);
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs(v,u);dis[u]=max(dis[u],dis[v]+1);
	}
	low[u]=++dfsclk;
}
void bfs(){
	int i,u,v,head=0,tail=1;q[0]=1;
	bfn[1]=back[1]=++bfsclk;vis[1]=1;
	while(head<tail){
		u=q[head++];
		for(i=first[u];~i;i=e[i].next){
			v=e[i].to;if(vis[v]) continue;
			vis[v]=1;q[tail++]=v;
			bfn[v]=++bfsclk;back[bfsclk]=v;
		}
	}
}
uint mod=19260817;
uint a[800010],hash[200010],siz[800010],tmpval;
void update(int num){
	int son=num<<1;
	siz[num]=siz[son]+siz[son+1];
	a[num]=a[son]*hash[siz[son+1]]+a[son+1];
//	cout<<"		update "<<num<<' '<<a[son]<<' '<<a[son+1]<<' '<<a[num]<<'\n'; 
}
void clear(int l,int r,int num){
	int mid=(l+r)>>1,son=num<<1;
	a[num]=0;if(l==r) return;
	clear(l,mid,son);clear(mid+1,r,son+1);
}
void insert(int l,int r,int num,int pos,int val){
	int mid=(l+r)>>1,son=num<<1;
//	cout<<"	insert "<<l<<' '<<r<<' '<<num<<' '<<pos<<' '<<val<<'\n';
	if(l==r){
		a[num]+=val;
		if(a[num]) siz[num]=1;
		else siz[num]=0;
		return;
	}
	if(mid>=pos) insert(l,mid,son,pos,val);
	else insert(mid+1,r,son+1,pos,val);
	update(num);
}
void query(int l,int r,int ql,int qr,int num){
	int mid=(l+r)>>1,son=num<<1;
//	cout<<"	query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<a[num]<<'\n'; 
	if(l==ql&&r==qr){
		tmpval=(tmpval*hash[siz[num]]+a[num]);return;
	}
	if(mid>=qr) query(l,mid,ql,qr,son);
	if(mid<ql) query(mid+1,r,ql,qr,son+1);
	if(mid>=ql&&mid<qr){
		query(l,mid,ql,mid,son);
		query(mid+1,r,mid+1,qr,son+1);
	}
}
uint s[100010];int top;
bool check(int x){
//	cout<<"check "<<x<<'\n'; 
	int i,j,num;top=0;clear(1,n<<1,1);
	for(i=n;i>=1;i--){
		if(i!=n&&dep[back[i]]!=dep[back[i+1]]){
			num=dep[back[i]]+x+1;
			for(j=0;j<node[num].size();j++){
				insert(1,n<<1,1,dfn[node[num][j]],-1);
				insert(1,n<<1,1,low[node[num][j]],-2);
			}
		} 
		num=back[i];
		insert(1,n<<1,1,dfn[num],1);
		insert(1,n<<1,1,low[num],2);
		if(dis[num]<x) continue;
		tmpval=0;query(1,n<<1,dfn[num],low[num],1);
		s[++top]=tmpval;
//		cout<<"do bfn "<<i<<", node "<<num<<", val "<<s[top]<<'\n'; 
	}
	sort(s+1,s+top+1);
	for(i=1;i<top;i++) if(s[i]==s[i+1]) return 1;
	return 0; 
}
int main(){
//	freopen("ernd7.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();int i,j,t1,t2,l,r,mid;
	memset(first,-1,sizeof(first));
	hash[0]=1;
	for(i=1;i<=n;i++){
		t1=read();hash[i]=hash[i-1]*mod;
		for(j=1;j<=t1;j++) t2=read(),add(i,t2);
	}
	dfs(1,0);bfs();
//	for(i=1;i<=n;i++) cout<<i<<' '<<dfn[i]<<' '<<low[i]<<' '<<bfn[i]<<'\n';
	l=0;r=n;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}
