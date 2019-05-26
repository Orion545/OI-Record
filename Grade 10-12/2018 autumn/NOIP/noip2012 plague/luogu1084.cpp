/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
int n,m,first[100010],cnte=1;
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
int dep[100010],st[100010][20];
void dfs(int u,int f,int w){
	int i,v;
	dep[u]=dep[f]+w;
	st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u,a[i].w);
	}
}
void ST(){
	int i,j;
	for(j=1;j<=17;j++){
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
int lck[100010],mk[100010];
void lock(int u,int f){
	int i,v;
//	cout<<"	lock "<<u<<' '<<f<<' '<<mk[u]<<'\n';
	if(mk[u]){lck[u]=1;return;}
	lck[u]=((a[first[u]].to==f&&a[first[u]].next==-1)?0:1);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		lock(v,u);if(!lck[v]) lck[u]=0;
	}
//	cout<<"	finish lck "<<u<<' '<<lck[u]<<'\n';
}
int arm[100010];
struct node{
	int pos,re;
}mv[100010],op[100010];
inline bool cmp(node l,node r){
	return l.re>r.re;
}
int minn[100010],pos[100010],use[100010],cntm,cnto;
//armies able to move;
//sons of capital that are still open;
int check(int len){
	int i,j,u,tmp;
	memset(lck,0,sizeof(lck));
	memset(mk,0,sizeof(mk));
	memset(minn,127,sizeof(minn));
	memset(pos,0,sizeof(pos));
	memset(use,0,sizeof(use));
	cntm=0;cnto=0;
	for(j=1;j<=m;j++){
		u=arm[j];
		for(i=17;i>=0;i--) 
			if(dep[arm[j]]-dep[st[u][i]]<=len&&dep[st[u][i]]>1) u=st[u][i];
//		cout<<"	up "<<arm[j]<<' '<<u<<' '<<st[u][0]<<' '<<dep[st[u][0]]<<' '<<len-(dep[arm[j]]-dep[u])-dep[u]+1<<'\n';
		if(st[u][0]==1&&dep[arm[j]]-dep[u]<len){
			tmp=len-(dep[arm[j]]-dep[u])-dep[u]+1;
			mv[++cntm]=(node){j,tmp};
			if(minn[u]>tmp){
				minn[u]=tmp;
				pos[u]=j;
			}
		}
		else mk[u]=1;
	}
	
	lock(1,0);
	if(lck[1]) return 1;
	for(i=2;i<=n;i++){
		if(st[i][0]==1&&!lck[i]) op[++cnto]=(node){i,dep[i]-1};
	}
	sort(mv+1,mv+cntm+1,cmp);
	sort(op+1,op+cnto+1,cmp);
	
	j=1;use[0]=1;
	for(i=1;i<=cnto;i++){
//		cout<<"	check "<<op[i].pos<<' '<<op[i].re<<' '<<pos[op[i].pos]<<'\n';
//		cout<<'	'<<j<<' '<<mv[j].pos<<' '<<mv[j].re<<' '<<use[mv[j].pos]<<'\n';
		if(!use[pos[op[i].pos]]){
			use[pos[op[i].pos]]=1;
			continue;
		}
		while(j<=cntm&&(use[mv[j].pos]||mv[j].re<op[i].re)) j++;
//		cout<<"	gg "<<j<<' '<<cntm<<'\n';
		if(j>cntm) return 0;
		use[mv[j].pos]=1;
	}
	return 1;
}
int main(){
	freopen("in.in","r",stdin);
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2,t3,ans=-1;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0,1);ST();
	m=read();
	for(i=1;i<=m;i++) arm[i]=read();
	int l=0,r=1000000,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
//		cout<<"binary "<<l<<' '<<r<<'\n';
	}
	printf("%d\n",ans);
}
