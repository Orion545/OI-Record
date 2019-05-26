#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,m,first[100010],cnte=-1,col[100010],vis[200010];ll cnt[3],cntn,cntm;
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
bool dfs(int u,int f,int type){
	int i,v,re=1,w;col[u]=(col[f]+type+3)%3;cnt[col[u]]++;cntn++;
//	cout<<"dfs "<<u<<' '<<f<<' '<<type<<' '<<col[u]<<' '<<cntn<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;w=(i%2?1:-1);
		if(vis[i]||vis[i^1]) continue;
		else cntm++,vis[i]=vis[i^1]=1;
		if(col[v]==-1) re&=dfs(v,u,w);
		else{
//			cout<<"vis before "<<u<<' '<<f<<' '<<w<<' '<<col[u]<<' '<<col[v]<<'\n';
			if(col[v]!=(col[u]+w+3)%3) re=0,cnt[0]=cnt[1]=cnt[2]=1e9;
		}
	}
	return re;
}
int main(){
//	freopen("in.in","r",stdin);
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2;ll ans=0;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	memset(col,-1,sizeof(col));
	for(i=1;i<=n;i++){
		if(~col[i]) continue;
//		cout<<"enter "<<i<<'\n';
		memset(cnt,0,sizeof(cnt));cntn=cntm=0;
		if(dfs(i,0,1)){
			if(!cnt[0]||!cnt[1]||!cnt[2]) ans+=cntm;
			else ans+=cnt[0]*cnt[1]+cnt[1]*cnt[2]+cnt[2]*cnt[0];
		}
		else{
			if(!cnt[0]||!cnt[1]||!cnt[2]) ans+=cntm;
			else ans+=cntn*cntn;
		}
//		cout<<cntn<<' '<<cntm<<'\n';
	} 
	cout<<ans;
}
