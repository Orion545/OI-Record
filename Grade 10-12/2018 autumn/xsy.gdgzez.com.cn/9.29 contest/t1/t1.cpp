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
int n,m,first[100010],cnte,col[100010];
ll single,binary,linked;
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dfs(int u,int c){
	if(~col[u]&&c!=col[u]) return 0;
	if(~col[u]&&c==col[u]) return 1;
	col[u]=c;
	int i,v,re=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		re&=dfs(v,c^1);
	}
	return re;
}
int main(){
	memset(first,-1,sizeof(first));memset(col,-1,sizeof(col));
	n=read();m=read();int i,t1,t2,tmp;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) if(col[i]==-1){
//		cout<<"find empty "<<i<<' '<<first[i]<<'\n';
		if(first[i]==-1){single++;continue;}
		tmp=dfs(i,0);
		if(tmp) binary++;
		else linked++;
	}
//	cout<<single<<' '<<binary<<' '<<linked<<'\n';
	printf("%lld\n",single*single+2*single*(n-single)+binary*binary*2+linked*(binary*2+linked));
}
