#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MM 5010
#define N 10010
#define ll long long
#define itn int
int xx;int ff;char ch;
inline int read(){
	ch=getchar();ff=1;xx=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=(xx<<1)+(xx<<3)+ch-'0';
		ch=getchar();
	}
	return xx*ff;
}
struct edge{
	int v,nex;
}e1[MM<<1];
int head[MM],elen=0;
inline void adde(int u,int v){
	e1[++elen].v=v;
	e1[elen].nex=head[u];
	head[u]=elen;
}
int n,m;
int mans[MM];
int ans[MM];
int vis[MM<<1];
bool visv[MM];
int fr[MM];
int cnt=1;
inline bool cans(){
	/*cerr<<endl;
	for(int i=1;i<=n;++i)cerr<<ans[i]<<" ";
	cerr<<endl;*/
	bool flag=0;
	for(int i=1;i<=n;++i){
		if(ans[i]!=mans[i]){
			if(ans[i]<mans[i]){
				flag=1;
				break;
			}else{
				break;
			}
		}
	}
	if(flag){
		//cerr<<"F"<<endl;
		memcpy(mans,ans,sizeof(ans));
	}
	return flag;
}
inline bool kans(int len){
	for(int i=1;i<=len;++i){
		if(ans[i]!=mans[i]){
			return ans[i]<mans[i];
		}
	}
	return 1;
}
inline void dfs(int u){
	//if(!vis[u])++cnt;vis[u]=1;
	//cerr<<"D"<<u<<" "<<cnt<<endl;
	if(cnt==n&&u==1){
		if(!cans()){
			return;
		}
	}else{
		if(!kans(cnt))return ;
	}
	for(int ee=head[u];ee;ee=e1[ee].nex){
		int v=e1[ee].v;
		if(vis[v])continue;
		ans[++cnt]=v;
		vis[v]=1;
		fr[v]=u;
		dfs(v);
		if(fr[u]!=0)dfs(fr[u]);
		ans[cnt]=0;
		--cnt;
		fr[v]=0;
		vis[v]=0;
	}	
	if(fr[u]!=0)dfs(fr[u]);
	
}
/*int siz[MM];
int tp[MM];int tplen;
struct node{
	int v;
	node **son;
	int sonlen;
	node(){sonlen=0;}
}ls[MM];
int len=0;

inline void dfs2(int u,int fa){
	int siz=1;
	//ls[++len].nex=0;
	//ls[len].pre=0;
	for(int ee=head[u];ee;ee=e1[ee].nex){
		int v=e1[ee].v;
		if(v==fa)continue;
		dfs2(v,u);
		++siz;
	}
	if(siz<=2){
		return;
	}
	sort(ls[)
}
inline node* dfs3(int u,int fa){
	ls[++len].v=u;
	node *p=&ls[len];
	for(int ee=head[u];ee;ee=e1[ee].nex){
		if(e1[ee].v==fa)continue;
		p->son[++(p->sonlen)]=dfs3(e1[ee].v,u);
	}
	return p;
}*/
int dep=0;
inline void dfs3(int u,int fa){
	mans[++dep]=u;vis[u]=1;
	for(int ee=head[u];ee;ee=e1[ee].nex){
		int v=e1[ee].v;
		if(v==fa||vis[v])continue;
		dfs3(v,u);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,0,sizeof(head));
	memset(fr,0,sizeof(fr));
	memset(vis,0,sizeof(vis));
	memset(mans,0,sizeof(mans));
	memset(ans,0,sizeof(ans));
	int x,y;
	n=read();m=read();
	//for(int i=1;i<=n;++i)mans[i]=n;
	for(int i=0;i<m;++i){
		x=read();y=read();
		adde(x,y);
		adde(y,x);
	}
	
	dfs3(1,1);
	memset(vis,0,sizeof(vis));
	//return 0;
	
	/*if(m==(n-1)){
		return 0;
	}*/
	vis[1]=1;
	ans[1]=1;
	
	dfs(1);
	for(int i=1;i<=n;++i)printf("%d ",mans[i]);
	printf("\n");
	//cerr<<"Q"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
