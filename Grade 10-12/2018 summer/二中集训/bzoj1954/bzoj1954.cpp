#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
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
int son[4200010][2],n,cnte,val[100010],first[100010],cnt;
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
		val[v]=val[u]^a[i].w;
		dfs(v,u);
	}
}
void insert(int num){
	int cur=0,i,tmp;
	for(i=30;i>=0;i--){
		tmp=((num&(1<<i))!=0);
		if(!son[cur][tmp]) son[cur][tmp]=++cnt;
		cur=son[cur][tmp];
	}
}
int query(int num){
	int cur=0,i,tmp,re=0;
	for(i=30;i>=0;i--){
		tmp=((num&(1<<i))==0);
		if(!son[cur][tmp]) cur=son[cur][tmp^1];
		else re|=(1<<i),cur=son[cur][tmp]; 
	}
	return re|num;
}
int main(){
	while(~scanf("%d",&n)){
		memset(first,-1,sizeof(first));
		memset(son,0,sizeof(son));cnte=cnt=0;
		memset(a,0,sizeof(a));memset(val,0,sizeof(val));
		int i,t1,t2,t3,ans=0;
		for(i=1;i<n;i++){
			t1=read();t2=read();t3=read();
			add(t1,t2,t3);
		}
		dfs(1,0);
//		cout<<"test segfault\n";
		for(i=1;i<=n;i++) insert(val[i]);
		for(i=1;i<=n;i++) ans=max(ans,query(val[i]));
		cout<<ans<<'\n';
	}
}
