#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
const int INF=1e9+10;
int n,m;
int h[N],tot;
struct Edge{
	int v,w,next;
}e[N*2];
bool cut[N];
int size[N],curRt_who,curRt_val;
int d[N*2],dcnt;
struct Data{
	int u,sub,mn,mx;
}a[N];
int acnt;
inline int max(int x,int y){
	return x>y?x:y;
}
inline int min(int x,int y){
	return x<y?x:y;
}
bool cmpByMax(const Data &a,const Data &b){
	return a.mx<b.mx;
}
void addEdge(int u,int v,int w){
	e[++tot]=(Edge){v,w,h[u]}; h[u]=tot;
	e[++tot]=(Edge){u,w,h[v]}; h[v]=tot;
}
void readData(){
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		addEdge(u,v,w);
	}
}
void findRoot_dfs(int u,int fa,int sz){
	int maxSub=0;
	size[u]=1;
	for(int i=h[u],v;i;i=e[i].next)
		if((v=e[i].v)!=fa&&!cut[v]){
			findRoot_dfs(v,u,sz);
			size[u]+=size[v];
			maxSub=max(maxSub,size[v]);
		}
	maxSub=max(maxSub,sz-size[u]);
	if(maxSub<curRt_val){
		curRt_val=maxSub;
		curRt_who=u;
	}
}
int findRoot(int enterNode,int curSize){
	curRt_who=-1; curRt_val=INF;
	findRoot_dfs(enterNode,0,curSize);
	return curRt_who;
}
void getInfo(int u,int fa,int mins,int maxs,int sub){
	if(mins!=-1&&maxs!=-1){
		if(maxs-mins<=m)
			a[++acnt]=(Data){u,sub,mins,maxs};
		else return;
	}
	if(mins==-1||maxs==-1)
		mins=INF, maxs=-INF;
	for(int i=h[u],v;i;i=e[i].next)
		if((v=e[i].v)!=fa&&!cut[v])
			getInfo(v,u,min(mins,e[i].w),max(maxs,e[i].w),(fa==0)?v:sub);
}
void Diz(){
	dcnt=0;
	for(int i=1;i<=acnt;i++){
		d[++dcnt]=a[i].mn;
		d[++dcnt]=a[i].mx;
	}
	sort(d+1,d+1+dcnt);
	dcnt=unique(d+1,d+1+dcnt)-d-1;
	for(int i=1;i<=acnt;i++){
		a[i].mn=lower_bound(d+1,d+1+dcnt,a[i].mn)-d;
		a[i].mx=lower_bound(d+1,d+1+dcnt,a[i].mx)-d;
	}
	sort(a+1,a+1+acnt,cmpByMax);
}
namespace BIT{
	int n,a[N];
	void setRange(int _n){
		n=_n;
	}
	void reset(){
		for(int i=1;i<=n;i++)
			a[i]=0;
	}
	void add(int u,int x){
		for(;u&&u<=n;u+=u&-u)
			a[u]+=x;
	}
	int que(int u){
		int res=0;
		for(;u;u-=u&-u)
			res+=a[u];
		return res;
	}
	int query(int l,int r){
		return que(r)-que(l-1);
	}
}
int getPos(int x){ // return the min pos that >= x
	return lower_bound(d+1,d+1+dcnt,x)-d;
}
ll calc(int u,bool flag){
	ll res=0;
	int sum=0;
	BIT::setRange(dcnt);
	for(int i=1;i<=acnt;i++)
		if(!flag||(flag&&a[i].sub==u)){
			sum++;
			int pos=getPos(d[a[i].mx]-m);
			res+=BIT::query(pos,a[i].mx);
			BIT::add(a[i].mn,1);
		}
	BIT::reset();
	return res+(!flag?sum:0);
}
ll solve(int enterNode,int curSize){
	int u=findRoot(enterNode,curSize);
	cut[u]=true;
	acnt=0;
	getInfo(u,0,-1,-1,-1);
	Diz();
	ll res=calc(u,false);
	for(int i=h[u],v;i;i=e[i].next)
		if(!cut[v=e[i].v])
			res-=calc(v,true);
	for(int i=h[u],v;i;i=e[i].next)
		if(!cut[v=e[i].v])
			res+=solve(v,size[u]>size[v]?size[v]:curSize-size[u]);
	return res;
}
int main(){
	readData();
	printf("%lld\n",solve(1,n));
	return 0;
}
