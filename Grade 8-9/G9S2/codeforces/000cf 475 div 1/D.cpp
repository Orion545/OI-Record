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
int n,cnt,first[200010],deg[200010],q[200010],head=0,tail=0,maxq=200000,tot=0,ans[200010];
bool vis[200010]={0},inq[200010];
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
	a[++cnt]=(edge){v,first[u]};first[u]=cnt;
	a[++cnt]=(edge){u,first[v]};first[v]=cnt;
}
int main(){
	memset(first,-1,sizeof(first));int i,t1,u,v;
	n=read();
	for(i=1;i<=n;i++){
		t1=read();if(!t1) continue;
		add(i,t1);deg[i]++;deg[t1]++;
	}
	for(i=1;i<=n;i++) if(!(deg[i]&1)) q[tail++]=i,inq[i]=1;
	while(head!=tail){
		u=q[head];head=(head+1)%maxq;
		if(deg[u]&1){inq[u]=0;continue;}
		vis[u]=1;ans[++tot]=u;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			deg[v]--;
			if(!(deg[v]&1)&&(!inq[v])) q[tail]=v,tail=(tail+1)%maxq;
		}
	}
	if(tot<n) printf("NO");
	else{
		printf("YES\n");
		for(i=1;i<=tot;i++) printf("%d\n",ans[i]);
	}
}

