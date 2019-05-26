#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
int n,m;
int sum=0;
struct edge{
	int u,v,nxt,dis;
	friend bool operator <(edge a,edge b){
		return a.dis>b.dis;
	}
}e[233333],e2[233333];
int h[233333],tot;
void add_edge(int u,int v,int dis){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].dis=dis;
	e[tot].nxt=h[u];
	h[u]=tot;
}
bool check(int tar){
	int s=0,cnt=0;;
	for(int i=1;i<n;++i){
		s+=e2[i].dis;
		if(s>=tar)cnt++,s=0;
	}
	return cnt>=m;
}
bool flag=1;
signed main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
		sum+=c;
		if(a!=b-1)flag=0;
		e2[i]=(edge){a,b,0,c};
	}
    if(flag){
		int ans,mid,l=1,r=1e9;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans;
	}
	else {
		sort(e2+1,e2+n);
		cout<<e2[1].dis+e2[2].dis;
	}
}
