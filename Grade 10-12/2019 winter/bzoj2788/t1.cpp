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
int n,m1,m2,mp[610][610],a[610][610],belong[610],cntb;
int s[610],top,ins[610],dfn[610],low[610],clk,ans[610];
void tarjan(int u){
//	cout<<"tarjan "<<u<<'\n';
	int i,v,tmp;
	dfn[u]=low[u]=++clk;
	s[++top]=u;ins[u]=1;
	for(v=1;v<=n;v++){
		if(v==u||!mp[u][v]) continue;
//		cout<<"	try "<<u<<' '<<v<<' '<<dfn[v]<<' '<<ins[v]<<'\n';
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]!=low[u]) return;
	cntb++;tmp=-1;
//	cout<<"find new bcc "<<cntb<<"\n";
	while(tmp!=u){
		tmp=s[top--];
//		cout<<"	bcc ele "<<tmp<<'\n';
		belong[tmp]=cntb;
		ins[tmp]=0;
	}
}
int main(){
	n=read();m1=read();m2=read();int i,k,j,t1,t2;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) a[i][j]=1e6;
	for(i=1;i<=m1;i++){
		t1=read();t2=read();
		a[t1][t2]=min(a[t1][t2],1);
		a[t2][t1]=min(a[t2][t1],-1);
		mp[t1][t2]=mp[t2][t1]=1;
	}
	for(i=1;i<=m2;i++){
		t1=read();t2=read();
		a[t2][t1]=min(a[t2][t1],0);
		mp[t2][t1]=1;
	}
	for(i=1;i<=n;i++) a[i][i]=0;

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			if(a[i][k]==1e6) continue;
			for(j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		}
	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<a[i][j]<<' ';
//		cout<<'\n';
//	}

	for(i=1;i<=n;i++) if(a[i][i]!=0){puts("NIE");return 0;}
	for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i);

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(belong[i]==belong[j]) ans[belong[i]]=max(ans[belong[i]],a[i][j]+1);
		}
	}
	int re=0;
	for(i=1;i<=cntb;i++) re+=ans[i];
	cout<<re<<'\n';
}
