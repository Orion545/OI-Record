#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(f=='-') f=-f; ch=getchar(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f; +
}
#define _ read()
const int N=5e4+5;
struct node { int u,v,w; } a[N];
bool cmp1(node a,node b) { return a.w>b.w; }
struct Edge{ int to,nxt,w; }e[N<<1];
int head[N],cnt,n,m,vis[N],b[N];
ll dis[N];
inline void insert(int u,int v,int w) { //连单向边 
	e[cnt]=(Edge) { v,head[u],w };
	head[u]=cnt++;
}
inline void ins(int u,int v,int w) { //连双向边 
	insert(u,v,w);
	insert(v,u,w);
} 
inline int bfs(int x) { //BFS两遍找树的直径 
	queue<int> q;
	for(int i=0;i<N;i++)
		vis[i]=dis[i]=0;
	q.push(x); vis[x]=1;
	while(!q.empty()) {
		int now=q.front(); q.pop();
		for(int i=head[now];~i;i=e[i].nxt) {
			if(!vis[e[i].to]) {
				dis[e[i].to]=dis[now]+e[i].w;
				q.push(e[i].to);
			}
			vis[e[i].to]=1;
		}
	}
	int qwq=0;
	for(int i=1;i<=n;i++) 
		if(dis[i]>dis[qwq]) qwq=i;
	return qwq;
}
inline bool check(int x) { //二分最小值。 
	int sum=0,cnt=1;
	for(int i=1;i<n;i++) {
		if(sum>=x) sum=0,cnt++; 
		sum+=b[i];
	}
	if(sum>=x) sum=0,cnt++; 
	return cnt>=m;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=_; m=_;
	memset(head,-1,sizeof(head));
	bool flag1=1,flag2=1;
	for(int i=1;i<n;i++) {
		a[i].u=_; a[i].v=_; a[i].w=_;
		if(a[i].u!=1) flag1=0;
		if(a[i].v!=a[i].u+1) flag2=0;
		ins(a[i].u,a[i].v,a[i].w);
	}
	if(m==1) { //20pts 如果m=1 直接找树的直径 
		int ed=bfs(1);
		int res=bfs(ed);
		printf("%lld\n",dis[res]);
	}else 
	if(flag1) { //20pts 2~n都是1的孩子 直接按边权从大到小，找第m大的边权 
		sort(a+1,a+n,cmp1);
		printf("%d\n",a[m].w);
	}else
	if(flag2) { //20pts 如果是一条链，当成一条n-1个元素的序列来处理， 
		int l=2e9,r=0,ans=0;
		for(int i=1;i<n;i++) {
			b[i]=a[i].w; r+=b[i]; l=min(l,b[i]); //初始化l,r的范围 
		}
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1,ans=mid;//如果最小值最大为mid时可以分成x段，则答案可能在[mid+1,r]; 
			else r=mid-1;//如果最小值最大为mid时无法分成k段，则[r..inf]都不可以，答案可能在[l..mid-1]; 
		}
		printf("%d\n",ans);
	}
	return 0; 
}
