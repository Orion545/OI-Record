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
int n,m,cnt,first[5010],dis[5010],ans;
bool vis[5010];
struct edge{
	int to,next,w;
}a[400010];
void add(int u,int v,int w){
//	cout<<"add edge "<<u<<ends<<v<<ends<<w<<endl;
	a[++cnt].to=v;a[cnt].next=first[u];first[u]=cnt;a[cnt].w=w;
	a[++cnt].to=u;a[cnt].next=first[v];first[v]=cnt;a[cnt].w=w;
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
void prim(){
//	cout<<"begin prim"<<endl;
	memset(vis,0,sizeof(vis));
	int num=0,i,u,v,w;
	heap H;
	for(i=1;i<=n;i++) dis[i]=inf;
	H.push(0,1);dis[1]=0;
	while(num<n&&H.top().id>=0){
		int u=H.top().id;H.pop();
//		cout<<"in node "<<u<<ends<<dis[u]<<ends<<H.n<<endl;
		if(vis[u]) continue;
		vis[u]=1;num++;ans+=dis[u];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
//			cout<<"	to "<<v<<ends<<w<<ends<<dis[v]<<endl;
			if(dis[v]>w){
//				cout<<"		renew"<<endl;
				dis[v]=w;
				H.push(dis[v],v);
			}
		}
	}
}
void dfs(int k){
//	cout<<"dfs "<<k<<ends<<first[k]<<endl;
	int i,v;vis[k]=1;
	for(i=first[k];~i;i=a[i].next){
		v=a[i].to;
//		cout<<"	to "<<v<<", next "<<a[i].next<<ends<<a[a[i].next].to<<endl;
		if(!vis[v]) dfs(v);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	int i,t1,t2,t3;
	n=read();m=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	} 
	dfs(1);
//	cout<<"666"<<endl;
	for(i=1;i<=n;i++){
//		cout<<i<<endl;
		if(!vis[i]){
			printf("orz");return 0;
		}
	}
//	cout<<"666666"<<endl;
	prim();
	printf("%d",ans);
}
