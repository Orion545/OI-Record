#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int dep[N],n,m;
struct hs{
	int nxt,to;
}e[10020];
int a,b;
inline int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=f*10+(ch-'0');ch=getchar();}
	return f*w;
}
int cnt=0,head[N],in[N];
inline void bd(int x,int y){
	e[++cnt].nxt=head[x];head[x]=cnt;
	e[cnt].to=y;
}
int cnt1=0;
bool vis[N];
int vi[N],dfn[N],low[N],sta[N],dfn_index=0,scc[N],size[N],scc_index=0,st=0;
bool ons[N];
int ans[N],st1=0;
bool li[N];
priority_queue<int,vector<int>,greater<int> >q;
int zz[N],no=0;
inline void dfs(int d){
	int len=no;
	li[d]=true;ans[++st1]=d;bool fl=true;
	for(int i=head[d];i;i=e[i].nxt){
		if(!li[e[i].to]){
			zz[++no]=e[i].to;
		    fl=false;
		}
	}
	if(!fl){
		sort(zz+1+len,zz+1+no);
		for(int i=len+1;i<=no;i++)if(!li[zz[i]])dfs(zz[i]);
	}
}

int dis[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=rd();m=rd();
	memset(ons,false,sizeof(ons));
	memset(vis,true,sizeof(vis));
	memset(vi,0,sizeof(vi));
	memset(li,false,sizeof(li));
	memset(size,0,sizeof(size));
	for(int i=1;i<=m;i++){
		a=rd();b=rd();
		bd(a,b);bd(b,a);
		in[a]++;in[b]++;
	}
    for(int i=1;i<=n;i++)if(in[i]==3&&size[scc[i]])vis[i]=false;
    for(int i=1;i<=n;i++){
	    if(vis[i]){
	    	dfs(i);
	    	break;
	    }
    }
    for(int i=1;i<=st1;i++)printf("%d ",ans[i]);
}

