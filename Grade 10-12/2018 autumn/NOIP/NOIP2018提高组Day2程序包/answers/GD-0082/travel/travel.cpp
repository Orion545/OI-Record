#include <cstdio>
#include <vector>
#include <algorithm>
#define PB push_back
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
const int INF=1e9;
const int N=5010;
int n,m;
namespace G{
	VI ee[N];
	void addEdge(int u,int v){
		ee[u].PB(v);
		ee[v].PB(u);
	}
	int h[N],tot;
	struct Edge{
		int v,next;
	}e[N*2];
	void addRealEdge(int u,int v){
		e[++tot]=(Edge){v,h[u]}; h[u]=tot;
	}
	void sortEdge(){
		for(int u=1;u<=n;u++){
			sort(ee[u].begin(),ee[u].end());
			for(int i=ee[u].size()-1;i>=0;i--)
				addRealEdge(u,ee[u][i]);
		}
	}
	int r[N],rcnt;
	bool onRing[N];
	void findRing(int u,int fa){
		static bool vis[N];
		static int sta[N],top=0;
		static bool inStack[N];
		vis[u]=true;
		sta[++top]=u;
		inStack[u]=true;
		for(int i=h[u],v;i;i=e[i].next){
			v=e[i].v;
			if(v!=fa){
				if(!vis[v])
					findRing(v,u);
				else if(inStack[v]){
					int x;
					do{
						x=sta[top--];
						inStack[x]=false;
						r[rcnt]=x;
						rcnt++;
						onRing[x]=true;
					}while(x!=v);
				}
			}
		}
		if(inStack[u]){
			top--;
			inStack[u]=false;
		}
	}
	int no[2]={-1,-1};
	void dfsTree(int u,int fa,VI &a){
		a.PB(u);
		for(int i=h[u],v;i;i=e[i].next){
			v=e[i].v;
			if(v!=fa){
				if(!((no[0]==u&&no[1]==v)||(no[1]==u&&no[0]==v)))
					dfsTree(v,u,a);
			}
		}
	}
	bool smaller(VI &a,VI &b){
		for(int i=0;i<n;i++)
			if(a[i]!=b[i])
				return a[i]<b[i];
		return false;
	}
	void solveRing(){
		findRing(1,0);
		VI tmp,ans=VI(n);
		for(int i=0;i<n;i++) ans[i]=INF;
		for(int i=0;i<rcnt;i++){
			no[0]=r[i];
			no[1]=r[(i+1)%rcnt];
			tmp=VI(0);
			dfsTree(1,0,tmp);
			if(smaller(tmp,ans))
				ans=tmp;
		}
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		puts("");
	}
}
void readData(){
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		G::addEdge(u,v);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	readData();
	G::sortEdge();
	if(m==n-1){
		VI ans;
		G::dfsTree(1,0,ans);
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		puts("");
	}
	else
		G::solveRing();
	return 0;
}
