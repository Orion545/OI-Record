#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<queue>
#define next DEEP_DARK_FANTASY
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,s,first[100010],w[200010],next[200010],to[200010],cnte;double ave,siz;
inline void add(int u,int v,int val){
	cnte++;w[cnte]=val;to[cnte]=v;next[cnte]=first[u];first[u]=cnte;
}
deque<int>q;int dis[100010],vis[100010];
void spfa(){
	int i,u,v;
	memset(dis,127,sizeof(dis));
	q.push_back(s);dis[s]=0;siz=1;ave=0;
	while(!q.empty()){
		while((u=q.front())&&((double)dis[u]>ave)) q.pop_front(),q.push_back(u);
		q.pop_front();ave=(ave*siz-dis[u])/(siz-1);siz--;vis[u]=0;
		for(i=first[u];i;i=next[i]){
			v=to[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				if(!vis[v]){
					if(siz&&dis[v]<dis[q.front()]) q.push_front(v);
					else q.push_back(v);
					vis[v]=1;ave=(ave*siz+dis[v])/(siz+1);siz++;
				}
			}
		}
	}
}
int main(){
	n=read();m=read();s=read();int t1,t2,t3;
	while(m--){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	spfa();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
}

