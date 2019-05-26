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
int n,m,s,first[100010],cnte;
int dis[100010];
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
}
struct node{
	int pos,val;
	inline bool operator <(const node &b)const{
		return val>b.val;
	}
};
priority_queue<node>q;
void dij(){
	int i,u,v,d;node tmp;
	for(i=1;i<=n;i++) dis[i]=1e9;
	dis[s]=0;q.push((node){s,0});
	while(!q.empty()){
		tmp=q.top();q.pop();
		u=tmp.pos;d=tmp.val;
		if(d!=dis[u]) continue;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(dis[v]>d+a[i].w){
				dis[v]=d+a[i].w;
				q.push((node){v,dis[v]});
			}
		}
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();s=read();int i,t1,t2,t3;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dij();
	for(i=1;i<=n;i++) printf("%d ",dis[i]);
}
