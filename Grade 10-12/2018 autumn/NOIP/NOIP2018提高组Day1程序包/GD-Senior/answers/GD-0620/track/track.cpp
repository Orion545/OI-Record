#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n,m;
int i,j,a,b,l,r,h;
long long cnt,sum,ans;
int head[1001],vis[2001];//vis record edge exist?
struct edge{
	int to,next;
	long long w;
};
edge e[2001];
stack <int> s;
void add_edge(int x,int y,long long z) {
	cnt++;
	e[cnt].to=y;
	e[cnt].w=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int dfs(int x,int now) {
	if(now>=x) {
		h++;
		return 1;
	}
	while(!s.empty()) {
		int t=s.top();
		s.pop();
		for(int k=head[t];k;k=e[k].next) {
			if(!vis[k] && now<x) {
				vis[k]=1;
				if(e[k+1].to==t) vis[k+1]=1;
				else vis[k-1]=1;
				s.push(e[k].to);
				if(dfs(x,now+e[k].w)) 
				return 1;
				vis[k]=0;
				if(e[k+1].to==t) vis[k+1]=0;
				else vis[k-1]=0;
			}
		}
		return 0;
	}
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n-1;i++) {
		cin>>a>>b>>l;
		add_edge(a,b,l);
		add_edge(b,a,l);
		sum+=l;
	}
	l=0;r=sum;
	ans=0x7fffffff;
	while(l<r) {
		int mid=l+(r-l)/2;
		h=0;
		for(i=1;i<=2000;i++) vis[i]=0;
		for(j=1;j<=n;j++) {
			s.push(j);
			dfs(mid,0);
		}
		if(h<m) r=mid;
		else l=mid+1;
	}
	cout<<l-1;
	return 0;
}
