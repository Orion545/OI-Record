#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int N=10010;
inline int read(){
	int x=0;
	char ch=getchar();
	while (ch<48||ch>57) ch=getchar();
	while (ch>=48&&ch<=57) x=(x*10)+(ch^48),ch=getchar();
	return x;
}
struct Edge{
	int to,next;
}edges[N];
int h[N],tot=0;
void AddEdge(int from,int to){
	edges[++tot]=(Edge){to,h[from]};
	h[from]=tot;
}
int n,m,v[N],ans[N],t;
void dfs(int x){
	vector<int>q;
	ans[++t]=x;
	v[x]=1;
	for (int i=h[x];i;i=edges[i].next){
		int e=edges[i].to;
		if (!v[e]) q.push_back(e);
	}	
	sort(q.begin(),q.end());
	for (int i=0;i<q.size();i++) dfs(q[i]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
		dfs(1);
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		return 0;
}
