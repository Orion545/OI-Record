#include<bits/stdc++.h>
using namespace std;
int Ed[5500][5500],sz[5500],vis[5500],q[5500],dfn[5500],l[5500][5500],fl;

void dfs(int u,int fa){
	sort(Ed[u]+1,Ed[u]+sz[u]+1);
	vis[u]=1;printf("%d ",u);
	for(int i=1;i<=sz[u];i++){
		int v=Ed[u][i];
		if(vis[v] || 1==l[u][v]) continue;
		else dfs(v,u);
	}
}

void wk(int st,int tl){
	int mn=q[tl],qq=mn,ml=st,mr=q[(--tl)],kn;
	int nr=mr,nl=ml,nn=mn;
	while(tl>dfn[st]){
		kn=nr;
		nr=q[(--tl)];
		nl=nn;
		nn=kn;
		if(nn<mn) mr=nr,ml=nl,mn=nn;
	}
	if(st<mn) mr=qq,ml=nn,mn=st;
	if(mr>ml) l[mr][mn]=l[mn][mr]=1;
	else l[ml][mn]=l[mn][ml]=1;
	return;
}

void dfs1(int u,int fa){
	if(fl) return;
	for(int i=1;i<=sz[u];i++){
		if(fl) return;
		int v=Ed[u][i];
		if(v==fa) continue;
		if(dfn[v]) wk(v,dfn[u]),fl=1;
		else {
			dfn[v]=dfn[u]+1;
			q[dfn[v]]=v;
			dfs1(v,u);
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		Ed[a][++sz[a]]=b;
		Ed[b][++sz[b]]=a;
	}
	if(m==n){
		q[1]=1,dfn[1]=1;
		dfs1(1,-1);
	}
	dfs(1,-1);
}
/*
6 5
1 3
2 3
2 5
3 4
4 6

6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
