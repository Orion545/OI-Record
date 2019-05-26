#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define PB push_back
using namespace std;
typedef vector<int> VI;
const int INF=1e9;
const int N=50010;
int n,m;
namespace T{
	int h[N],tot;
	struct Edge{
		int v,w,next;
	}e[N*2];
	void addEdge(int u,int v,int w){
		e[++tot]=(Edge){v,w,h[u]}; h[u]=tot;
		e[++tot]=(Edge){u,w,h[v]}; h[v]=tot;
	}
	int match;
	int dfs(int u,int fa,int len){
		VI a(0,0);
		int sz=0;
		for(int i=h[u],v;i;i=e[i].next)
			if((v=e[i].v)!=fa){
				int val=dfs(v,u,len)+e[i].w;
				if(val<len){
					sz++;
					a.PB(val);
				}
				else
					match++;
			}
		sort(a.begin(),a.end());
		static multiset<int> s;
		multiset<int>::iterator it;
		s.clear();
		for(int i=0;i<sz;i++){
			it=s.lower_bound(len-a[i]);
			if(it!=s.end()){
				match++;
				s.erase(it);
			}
			else
				s.insert(a[i]);
		}
		if(s.empty())
			return 0;
		it=s.end();
		it--;
		return *it;
	}
	bool judge(int len){
		match=0;
		dfs(1,0,len);
		return match>=m;
	}
}
void readData(){
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		T::addEdge(u,v,w);
	}
}
void solve(){
	int l=1,r=INF,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(T::judge(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",r);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	readData();
	solve();
	return 0;
}
