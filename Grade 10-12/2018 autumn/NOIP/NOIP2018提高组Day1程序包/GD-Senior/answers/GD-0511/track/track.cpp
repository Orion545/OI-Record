#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 100005
#define maxt 1005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

int n,m;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn<<1];
int sz=0;
int head[maxn];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

namespace solve1{
	vector<long long>route;
	int mark[maxt][maxt];
	void dfs(int x,int fa,int start,long long d){
		route.push_back(d);
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa&&!mark[start][y]){
				mark[start][y]=mark[y][start]=1;
				dfs(y,x,start,d+E[i].len);
			}
		}
	}
	void work(){
		for(int i=1;i<=n;i++){
			dfs(i,0,i,0);
		}
		sort(route.begin(),route.end());
		int sz=route.size();
		printf("%lld\n",route[sz-m]);
	}
}

namespace solve2{
	long long maxd=0;
	int begin;
	void dfs(int x,int fa,int start,long long d){
		if(d>maxd){
			begin=x;
			maxd=d;
		}
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa){
				dfs(y,x,start,d+E[i].len);
			}
		}
	}
	void work(){
		dfs(1,0,1,0);
		maxd=0;
		dfs(begin,0,begin,0);
		printf("%lld\n",maxd);
	}
}

namespace solve3{
	int v[maxn];
	vector<long long>pv;
	vector<int>pid;
	vector<long long>ans;
	void work(){
		int cnt=0;
		long long sum=0;
		for(int i=2;i<=sz;i+=2){
			v[i/2]=E[i].len;
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n-1;j++){
				pv.push_back(v[i]+v[j]);
				pid.push_back((1<<i)+(1<<j));
			}
		}
		ans.clear();
		for(int i=0;i<(1<<(n-1));i++){
			cnt=0;
			sum=0;
			for(int j=0;j<n-1;j++){
				if(i&(1<<j)){
					cnt++;
					if(cnt>m*2) break;
					sum+=v[j+1];
				}
			}
			if(cnt==m*2){
				ans.push_back(sum);
			}
		}
		sort(ans.begin(),ans.end());
		printf("%lld\n",ans[ans.size()-m]);
	}

}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int u,v,w;
	n=qread();
	m=qread();
	bool all_1=true;
	for(int i=1;i<n;i++){
		u=qread();
		v=qread();
		w=qread();
		add_edge(u,v,w);
		add_edge(v,u,w);
		if(u!=1) all_1=false;
	}
	if(m==1){//Ö±¾¶ 
		solve2::work();
	}else if(all_1){//È«1 
		solve3::work();
	}else{
		solve1::work();
	}
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7

9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4

7 2
1 2 1
1 3 1
1 4 1
1 5 1
1 6 1
1 7 100
*/
