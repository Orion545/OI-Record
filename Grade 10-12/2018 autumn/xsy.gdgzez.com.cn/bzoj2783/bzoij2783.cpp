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
int n,m,first[100010],cnte;
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int w[100010],pre[100010],dep[100010],st[100010][20];
void dfs(int u,int f){
	int i,v;
	pre[u]=pre[f]+w[u];
	dep[u]=dep[f]+1;
	st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
void ST(){
	int i,j;
	for(j=1;j<=18;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
int get(int u){
	if(pre[u]<m) return 0;
	int i,re=m;
	for(i=19;i>=0;i--){
		if(pre[u]-pre[st[u][i]]<=re){
			re-=pre[u]-pre[st[u][i]];
			u=st[u][i];
		}
	}
	return (!re);
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,ans=0;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);ST();
	for(i=1;i<=n;i++) ans+=get(i);
	cout<<ans<<'\n';
}
