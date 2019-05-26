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
int n,m,s,first[1000010],ans[1000010],cnte,pos[1000010],cnt=0,in[1000010],is[1000010],isn[1000010];
struct edge{
	int to,next,w;
}a[8000010];
inline void add(int u,int v,int w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	in[v]++;
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
}
int q[1000010],dp[1000010];
namespace seg{
	int ch[400010][2];
	int build(int l,int r){
		int cur=++cnt;is[cur]=1;
//		cout<<"build "<<l<<' '<<r<<' '<<cur<<'\n'; 
		if(l==r){
			isn[cur]=1;
			return pos[l]=cur;
		}
		int mid=(l+r)>>1;
		ch[cur][0]=build(l,mid);
		ch[cur][1]=build(mid+1,r);
		add(ch[cur][0],cur,0);
		add(ch[cur][1],cur,0);
		return cur;
	}
	void change(int l,int r,int ql,int qr,int cur,int ori){
		if(ql>qr) return;
//		cout<<"change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<ori<<'\n';
		if(l>=ql&&r<=qr){
			add(cur,ori,1);return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,ch[cur][0],ori);
		if(mid<qr) change(mid+1,r,ql,qr,ch[cur][1],ori);
	}
}
void topo(){
	int i,u,v,head=0,tail=0,tot=0;
	for(i=1;i<=cnt;i++) if(!in[i]){
		q[tail++]=i;dp[i]=1;
	}
	while(head<tail){
		u=q[head++];tot+=isn[u];
		if(dp[u]>1e9){
			puts("NIE");return;
		}
		if((!is[u])&&(dp[u]>ans[u])){
			puts("NIE");return;
		}
		if((!is[u])&&(dp[u]<ans[u])) dp[u]=ans[u];
//		cout<<"topo "<<u<<' '<<dp[u]<<' '<<ans[u]<<' '<<is[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
//			cout<<"	to "<<v<<' '<<in[v]<<' '<<dp[v]<<' '<<' '<<dp[u]<<' '<<a[i].w<<'\n';
			if(dp[v]<dp[u]+a[i].w){
				dp[v]=dp[u]+a[i].w;
			}
			if(!(--in[v])) q[tail++]=v;
		}
	}
	if(tot<n){
		puts("NIE");return;
	}
	puts("TAK");
	for(i=1;i<=n;i++) printf("%d ",dp[pos[i]]);
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();s=read();m=read();int i,j,t1,t2,t3;
	memset(ans,63,sizeof(ans));
	int root=seg::build(1,n);
	for(i=1;i<=s;i++){
		t1=read();t2=read();
		ans[pos[t1]]=t2;is[pos[t1]]=0;
//		cout<<"*** "<<pos[t1]<<'\n';
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		cnt++;is[cnt]=1;
		for(j=1;j<=t3;j++) q[j]=read(),add(cnt,pos[q[j]],0);
		seg::change(1,n,t1,q[1]-1,root,cnt);
		seg::change(1,n,q[t3]+1,t2,root,cnt);
		for(j=1;j<t3;j++) seg::change(1,n,q[j]+1,q[j+1]-1,root,cnt);
	}
	topo();
}
