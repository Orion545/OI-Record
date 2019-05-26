#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
inline char _getc(){
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int scan(){
	int x=0,f=1; char ch=0;
	while(ch<48) ch=='-'&&(f=-1),ch=_getc();
	while(ch>=48) x=x*10+ch-48,ch=_getc();
	return x*f;
}
const int N=5005;
int n,m,res[N],cc; 
bool vis[N],del[N][N];
vector<int> to[N];
void dfs(int u){
	res[++cc]=u; vis[u]=1;
	for(int i=0;i<(int)to[u].size();i++){
		int v=to[u][i];
		if(!vis[v]) dfs(v); 
	}
}
struct node{
	int x,y; node(int a=0,int b=0):x(a),y(b){}
}tmp[N]; int cn;
int dep[N],mindep=N;
bool getcyc(int u,int fa){
	vis[u]=1; dep[u]=dep[fa]+1;
	for(int i=0;i<(int)to[u].size();i++){
		int v=to[u][i];
		if(v==fa) continue;
		if(vis[v]) mindep=dep[v];
		if(vis[v]||getcyc(v,u)){
			tmp[++cn]=node(u,v);
			if(dep[u]!=mindep) return 1;
			else return 0;
		} 
	}
	return 0;
}
bool fir,err;
void dfs_cyc(int u){
//	printf("%d %d\n",u,c);
	if(err) return;
	if(!fir&&res[cc]>0&&(res[cc]<u)){
//		printf("%d--%d\n",u,res[c]);
		err=1; return;
	}
	if((res[cc]==0||res[cc]>u)||fir){res[cc]=u; fir=1;}
	vis[u]=1;
	for(int i=0;i<(int)to[u].size();i++){
		int v=to[u][i];
		if(del[u][v]) continue;
		if(!vis[v]) cc++,dfs_cyc(v); 
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=scan(); m=scan();
	for(int i=1;i<=m;i++){
		int a,b; a=scan(); b=scan();
		to[a].push_back(b); to[b].push_back(a);
	}
	for(int i=1;i<=n;i++) sort(to[i].begin(),to[i].end());
	if(m==n-1) dfs(1);
	else{
		getcyc(1,0);
		for(int i=1;i<=cn;i++){
//			printf("%d %d\n",tmp[i].x,tmp[i].y);
			memset(vis,0,sizeof(vis));
			int a=tmp[i].x,b=tmp[i].y;
			del[a][b]=del[b][a]=1; err=fir=0;
			cc=1; dfs_cyc(1);
			del[a][b]=del[b][a]=0;
		}
		cc=n;
	}
	for(int i=1;i<=cc;i++) printf("%d ",res[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
