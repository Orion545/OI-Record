#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
char cch;
inline int rd(){
	int x=0,fl=1;
	cch=getchar();
	while(cch<'0'||cch>'9'){
		if(cch=='-') fl=-1;
		cch=getchar();
	}
	while(cch>='0'&&cch<='9') x=(x<<1)+(x<<3)+cch-'0',cch=getchar();
	return x*fl;
}
const int N=5003;
vector<int> vec[N];
bool vis[N],on[N],ban[N][N];
int n,p1[N],p2[N],len,tot,idx,dfn[N],low[N],st[N],top;
inline void adde(int u,int v){
	vec[u].push_back(v),vec[v].push_back(u);
}
struct abc{
	int a[N];
}a,ans;
inline void dfs(int u,int fa){
	a.a[++len]=u;
	int v,ed=vec[u].size()-1;
	rep(i,0,ed){
		v=vec[u][i];
		if(v==fa||ban[u][v]) continue;
		dfs(v,u);
	}
	return;
}
inline void ck(){
	//rep(i,1,n) printf("%d ",a.a[i]);puts("");
	rep(i,1,n){
		if(a.a[i]<ans.a[i]){
			ans=a;break;
		}
		else if(a.a[i]>ans.a[i]) break;
	} 
	len=0;
	return;
}
inline void tarjan(int x,int fa){
	dfn[x]=low[x]=++idx;
	vis[x]=on[x]=1,st[++top]=x;
	int v,ed=vec[x].size()-1;
	rep(i,0,ed){
		v=vec[x][i];
		if(v==fa) continue;
		if(!vis[v]) tarjan(v,x),low[x]=min(low[x],low[v]);
		else if(on[v]&&dfn[v]<low[x]) low[x]=dfn[v];
	}
	if(dfn[x]!=low[x]){
		int tmp=0;
		while(tmp!=x){
			tmp=st[top--];on[tmp]=0;
			p1[++tot]=st[top],p2[tot]=tmp;
		}
	}
	else top--,on[x]=0;
	return;
}
int coutt;
inline void dfs2(int u,int fa){
	++coutt;/**/if(coutt==n) printf("%d",u);else printf("%d ",u);
	int v,ed=vec[u].size()-1;
	rep(i,0,ed){
		v=vec[u][i];
		if(v==fa) continue;
		dfs2(v,u);
	}
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=rd();
	int m=rd(),u,v;
	memset(ans.a,0x3f,sizeof ans.a);
	rep(i,1,m) u=rd(),v=rd(),adde(u,v);
	rep(i,1,n) sort(vec[i].begin(),vec[i].end());
	if(m==n){
		tarjan(1,0);
		p1[++tot]=p2[1],p2[tot]=p1[tot-1];
		//rep(i,1,tot) cout<<' '<<p1[i]<<' '<<p2[i]<<endl;
		rep(i,1,tot){
			ban[p1[i]][p2[i]]=ban[p2[i]][p1[i]]=1;//cout<<p1[i]<<' '<<p2[i]<<endl;
			dfs(1,0);
			ck();
			ban[p1[i]][p2[i]]=ban[p2[i]][p1[i]]=0;
		}
		int ed=n-1;
		rep(i,1,ed) printf("%d ",ans.a[i]);/**/printf("%d",ans.a[n]);
	}
	else dfs2(1,0);
	return 0;
}
/*
8 8
1 4
4 5
1 2
2 7
7 8
1 3
3 6
3 7
*/

/*
6 5 
1 3
2 3
2 5
3 4 
4 6
*/
