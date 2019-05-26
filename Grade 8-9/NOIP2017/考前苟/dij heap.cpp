#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=re*10+ch-'0',ch=getchar();
	return re;
}
int n,m,cnt,first[10010],dis[10010],ans,start;
bool vis[10010];
struct edge{
	int to,next,w;
}a[1000010];
void add(int u,int v,int w){
//	cout<<"add edge "<<u<<ends<<v<<ends<<w<<endl;
	a[++cnt].to=v;a[cnt].next=first[u];first[u]=cnt;a[cnt].w=w;
//	a[++cnt].to=u;a[cnt].next=first[v];first[v]=cnt;a[cnt].w=w;
}
struct node{
	int dis,id;
	inline void operator =(const node &b){
		dis=b.dis;id=b.id;
	}
	inline bool operator <(const node &b){
		return dis<b.dis;
	}
	inline bool operator >(const node &b){
		return dis>b.dis;
	}
};
inline node mp(int t1,int t2){
	node re;
	re.dis=t1;re.id=t2;
	return re;
}
inline void swap(node &a,node &b){node t=a;a=b;b=t;return;}
struct heap{
	int n;
	node a[100010];
	heap(){n=0;memset(a,0,sizeof(a));}
	inline void up(int k){
		if(k==1) return;
		if(a[k>>1]>a[k]){
			swap(a[k>>1],a[k]);
			up(k>>1);
		}
	}
	inline void down(int k){
		if((k<<1)>n) return;
		if((k<<1)==n){
			if(a[k<<1]<a[k]){
				swap(a[k],a[k<<1]);
				down(k<<1);
			}
			return;
		}
		if(a[k<<1]<a[k]){
			if(a[(k<<1)+1]<a[k<<1]){
				swap(a[k],a[(k<<1)+1]);
				down((k<<1)+1);
			}
			else{
				swap(a[k],a[k<<1]);
				down(k<<1);
			}
		}
		else if(a[(k<<1)+1]<a[k]){
			swap(a[k],a[(k<<1)+1]);
			down((k<<1)+1);
		}
	}
	inline void push(int k,int id){
		a[++n]=mp(k,id);
		up(n);
//		for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	}
	inline void pop(){
		a[1]=a[n--];
		down(1);
//		for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	}
	inline node top(){
		if(n==0) return mp(-1,-1);
		return a[1];
	}
};
void dij(int st){
	int i,j,u,v,w,num=0;
	heap H;
	for(i=1;i<=n;i++) dis[i]=inf;
	dis[st]=0;H.push(0,st);
	while(num<n&&H.n){
		u=H.top().id;H.pop();
		if(vis[u]) continue;
//		cout<<u<<ends<<dis[u]<<endl;
		vis[u]=1;num++;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
//			cout<<"	to "<<v<<ends<<dis[v]<<ends<<dis[u]+w<<endl;
			if(dis[v]>dis[u]+w){
//				cout<<"		renew"<<endl;
				dis[v]=dis[u]+w;
				H.push(dis[v],v);
			}
		}
	}
}
int main(){
	memset(first,-1,sizeof(first));
	int i,j,t1,t2,t3;
	n=read();m=read();start=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dij(start);
	for(i=1;i<=n;i++) printf("%d ",dis[i]);
}
