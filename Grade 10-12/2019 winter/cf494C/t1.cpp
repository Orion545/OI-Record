#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct seg{
	int l,r,num;double pos;
}q[5010];
inline bool cmp1(seg l,seg r){
	if(l.l!=r.l) return l.l<r.l;
	if(l.r!=r.r) return l.r>r.r;
	return l.num>r.num;
}
inline bool cmp2(seg l,seg r){
	return l.num<r.num;
}
int n,m,x[100010],fa[10010],first[10010],maxn[10010],cnte=-1;
double dp[5010][5010];
struct edge{
	int to,next;
}a[10010];
inline void add(int u,int v){
//	cout<<"add "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void getval(int u,int f){
	int i,v,j,prel=q[u].l-1,prer=q[u].l-1;maxn[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		getval(v,u);
		maxn[u]=max(maxn[u],maxn[v]);
		for(j=prer+1;j<q[v].l;j++) maxn[u]=max(maxn[u],x[j]);
		prel=q[v].l;prer=q[v].r;
	}
	for(j=prer+1;j<=q[u].r;j++) maxn[u]=max(maxn[u],x[j]);
//	cout<<"getval "<<u<<' '<<f<<' '<<q[u].l<<' '<<q[u].r<<' '<<maxn[u]<<'\n';
}
void dfs(int u,int f){
	int i,v,j;double t1,t2;
//	for(i=first[u];~i;i=a[i].next){
//		v=a[i].to;if(v==f) continue;
//		dfs(v,u);
//		for(j=0;j<=5000;j++){
//			if(maxn[u]-maxn[v]+j-1>=0) dp[i][j]+=q[u].pos*dp[v][min(maxn[u]-maxn[v]+j-1,5000)];
//			dp[i][j]+=(1.0-q[u].pos)*dp[v][min(5000,maxn[u]-maxn[v]+j)];
//		}
//	}
	for(i=first[u];~i;i=a[i].next) if(a[i].to!=f) dfs(a[i].to,u);
	for(j=0;j<=5000;j++){
		t1=(j!=0);t2=1;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			if(j) t1*=dp[v][min(maxn[u]-maxn[v]+j-1,5000)];
			t2*=dp[v][min(maxn[u]-maxn[v]+j,5000)];
		}
		dp[u][j]=t1*q[u].pos+t2*(1.0-q[u].pos);
//		if(j<=10) cout<<u<<' '<<j<<' '<<dp[u][j]<<' '<<t1<<' '<<t2<<'\n';
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,cur;
	for(i=1;i<=n;i++) x[i]=read();
	for(i=1;i<=m;i++){
		q[i].l=read();q[i].r=read();
		scanf("%lf",&q[i].pos);
		q[i].num=i;
	}
	m++;
	q[m].l=1;q[m].r=n;q[m].num=m;q[m].pos=0;
	sort(q+1,q+m+1,cmp1);
	cur=1;
	for(i=2;i<=m;i++){
//		cout<<i<<' '<<cur<<' '<<q[i].l<<' '<<q[i].r<<' '<<q[cur].l<<' '<<q[cur].r<<'\n';
		while(q[cur].r<q[i].l) cur=fa[cur];
		fa[i]=cur;add(q[i].num,q[cur].num);
		cur=i;
	}
	sort(q+1,q+m+1,cmp2);
	getval(m,0);
	dfs(m,0);
	double ans=(double)maxn[m]*dp[m][0];
	for(i=1;i<=5000;i++) ans+=((double)maxn[m]+i)*(dp[m][i]-dp[m][i-1]);
	printf("%.3lf\n",ans);
}
