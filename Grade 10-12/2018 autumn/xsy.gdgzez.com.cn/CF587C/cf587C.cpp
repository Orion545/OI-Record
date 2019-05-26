/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
struct node{
	int a[12];
	node(){memset(a,127,sizeof(a));}
	inline node operator +(const node &b){
		node re;int cur=0,l=1,r=1;
		while(cur<10){
			if(a[l]<b.a[r]) re.a[++cur]=a[l],l++;
			else re.a[++cur]=b.a[r],r++;
		}
		return re;
	}
}rk[100010][18];
int n,m,q,first[100010],cnte,st[100010][18],dep[100010];
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
	dep[u]=dep[f]+1;
	st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
void ST(){
	int j,i;
	for(j=1;j<18;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
			rk[i][j]=rk[i][j-1]+rk[st[i][j-1]][j-1];
//			cout<<"st "<<i<<' '<<j<<' '<<rk[i][j].a[1]<<'\n';
		}
	}
}
node lca(int l,int r){
	int i;node re;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=17;i>=0;i--){
		if(dep[st[r][i]]>=dep[l]){
			re=re+rk[r][i];
			r=st[r][i];
		}
	}
	if(l==r) return re+rk[l][0];
//	cout<<"lca first phase finish "<<l<<' '<<r<<' '<<re.a[1]<<'\n';
	for(i=17;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			re=(re+rk[r][i])+rk[l][i];
			r=st[r][i];
			l=st[l][i];
		}
	}
//	cout<<"lca second phase finish "<<l<<' '<<r<<' '<<re.a[1]<<' '<<rk[l][1].a[1]<<' '<<rk[r][0].a[1]<<'\n';
	return (re+rk[l][1])+rk[r][0];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();q=read();int i,t1,t2,t3,j;node re;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=m;i++){
		t1=read();j=1;
		while(rk[t1][0].a[j]<1e9) j++;
		if(j>10) continue;
		rk[t1][0].a[j]=i;
	}
	dfs(1,0);ST();
	while(q--){
		t1=read();t2=read();t3=read();
		re=lca(t1,t2);
		for(i=1;i<=min(10,t3);i++) if(re.a[i]>1e9) break;
		i--;
		printf("%d",i);
		for(j=1;j<=i;j++) printf(" %d",re.a[j]);
		puts("");
	}
}
