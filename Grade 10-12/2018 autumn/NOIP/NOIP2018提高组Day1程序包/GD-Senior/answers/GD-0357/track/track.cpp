#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define Min(a,b) a>b?b:a
#define MAXN 50005
using namespace std;
inline void read(int &x){
	int f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	x=0;
	while (ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
struct edge{
	int to,w;
};
vector<edge>G[MAXN];
inline void AddEdge(int u,int v,int w){
	//printf("Adding Edge : %d %d %d\n",u,v,w);
	edge temp;
	temp.to=v;
	temp.w=w;
	G[u].push_back(temp);
}
int dis[MAXN],vis[MAXN];
int maxn;
inline int bfs(int s){
	queue<int>Q;
	while (Q.size()) Q.pop();
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	Q.push(s);
	dis[s]=0,vis[s]=1;
	int max_ver;
	maxn=-0x7fffffff;
	while (Q.size()){
		int u=Q.front();
		Q.pop();
		for (register int i=0;i<(int)G[u].size();++i){
			int v=G[u][i].to;
			int w=G[u][i].w;
			if (vis[v]==1) continue;
			vis[v]=1;
			dis[v]=dis[u]+w;
			if (dis[v]>maxn){
				maxn=dis[v],max_ver=v;
			}
			Q.push(v);
		}
	}
	return max_ver;
}

inline int Special_Task1(){//m==1求树的直径 
	bfs(bfs(1));
	printf("%d\n",maxn);
	return 0;
}
vector<int>val;
int n,m;
inline int Special_Task2(){//ai==1
	int x=(n-1)-m;
	sort(val.begin(),val.end());
	int ans=0x7fffffff;
	for (register int i=0,j=2*x-1;i<=j;i++,j--){
		ans=Min(ans,val[i]+val[j]);
	}
	ans=Min(ans,val[2*x]);
	printf("%d\n",ans);
	return 0;
}
int value[MAXN];
inline bool Check(int mid){
	int cur_sum=0;
	int cnt=0;
	for (register int i=1;i<n;++i){
		cur_sum+=value[i];
		if (cur_sum>=mid){
			cnt++,cur_sum=0;
		}
	}
	return cnt>=m;
}
inline int Special_Task3(){//退化成了一条链 
	int l=0,r=0x7fffffff;
	int ans=0;
	while (l<=r){
		int mid=(l+r)>>1;
		if (Check(mid)){
			l=mid+1;
			ans=mid;
		}
		else {
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int min_ans=0x7fffffff;
	bool flag=true;
	bool is_chain=true;
	for (register int i=1;i<n;++i){
		int u,v,w;
		read(u),read(v),read(w);
		val.push_back(w);
		if (u!=1) flag=false;
		if (v!=u+1&&u!=v+1) is_chain=false;
		value[min(u,v)]=w;
		min_ans=Min(min_ans,w);
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	if (m==1){
		return Special_Task1()*19260817;
	}
	else if (m==n-1){
		printf("%d\n",min_ans);
		return 19260817*0;
	}
	else if (flag==true){
		return Special_Task2()*19260817;
	}
	else if (is_chain==true){
		return Special_Task3()*19260817;
	}
	else {
		printf("%d\n",min_ans);
		return 19260817*0;
	}
	return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
