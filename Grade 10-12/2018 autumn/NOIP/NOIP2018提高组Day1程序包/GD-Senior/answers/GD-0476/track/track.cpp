#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#define M 100005
using namespace std;

int f[M]={0},g[M]={0};
struct edge{int u,v,next;}e[M*2]={0}; int head[M]={0},use=0;
void add(int x,int y,int z){use++;e[use].u=y;e[use].v=z;e[use].next=head[x];head[x]=use;}
int n,m,now;
multiset<int> s;
void dfs(int x,int fa){
	for(int i=head[x];i;i=e[i].next)
	if(e[i].u!=fa)
	dfs(e[i].u,x);
	for(int i=head[x];i;i=e[i].next) if(e[i].u!=fa){
		if(g[e[i].u]+e[i].v>=now) f[x]++;
		else s.insert(g[e[i].u]+e[i].v);
		f[x]+=f[e[i].u];
	}
	multiset<int>::iterator it,it2;
	while(s.size()){
		it=s.begin();
		int num=*it;
		s.erase(it);
		it=s.lower_bound(now-num);
		if(it!=s.end()){
			f[x]++;
			s.erase(it);
		}else
		g[x]=max(g[x],num);
	}
}
	

bool check(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	dfs(1,0);
	return f[1]>=m;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=0,r=0;
	for(int i=1;i<n;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
		r+=z;
	}
	while(l<r){
		int mid=(l+r+1)>>1;
		now=mid;
		if(check()) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}
