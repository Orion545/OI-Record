#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
vector<int > a[6000];
void addline(int u,int v){
	a[u].push_back(v);
	return;
}
int st1[10000],stn1=0;
void dfs1(int now,int father){
	st1[++stn1]=now;
	int v;
	for(int i=0;i<a[now].size();i++){
		v=a[now][i];
		if(v==father)continue;
		dfs1(v,now);
	}
	return;
}
void solve1(){
	dfs1(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",st1[i]);
	printf("\n");
	return;
}

int du[60000];
bool vis[60000];
bool tag[60000];
queue<int > q;
bool f_vis=1;
int st2[10000],stn2=0;
void dfs2(int now,int father){
	tag[now]=1;
	st2[++stn2]=now;
	if((!vis[now])&&f_vis){
		f_vis=0;
		int v,c[5],cn=0;
		for(int i=0;i<a[now].size();i++){
			v=a[now][i];
			if(v==father)continue;
			if(!vis[v])c[++cn]=v;
		}
		for(int i=0;i<a[c[1]].size();i++){
			v=a[c[1]][i];
			if(v==now)continue;
			if(!vis[v]){
				c[++cn]=v;
				break;
			}
		}
		if(c[3]<=c[2]){
			for(int i=0;i<a[now].size();i++){
				v=a[now][i];
				if(v==father||tag[v]==1)continue;
				dfs2(v,now);
			}
		}
		else{
			int j;
			for(int i=0;i<a[now].size();i++){
				v=a[now][i];
				if(v==father||tag[v]==1)continue;
				if(v==c[1]){
					j=i+1;
					break;
				}
				dfs2(v,now);
			}
			tag[c[1]]=1;
			st2[++stn2]=c[1];
			for(int i=0;i<a[c[1]].size();i++){
				v=a[c[1]][i];
				if(v==now||v==c[3])continue;
				dfs2(v,c[1]);
			}
			for(int i=j;i<a[now].size();i++){
				v=a[now][i];
				if(v==father||tag[v])continue;
				dfs2(v,now);
			}
		}
	}
	else{
		int v;
		for(int i=0;i<a[now].size();i++){
			v=a[now][i];
			if(v==father||tag[v])continue;
			dfs2(v,now);
		}
	}
	return;
}
void solve2(){
	memset(vis,0,sizeof(vis));
	memset(tag,0,sizeof(tag));
	for(int i=1;i<=n;i++)
		if(du[i]==1)q.push(i);
	int u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();
		vis[u]=1;
		for(int i=0;i<a[u].size();i++){
			v=a[u][i];
			if(vis[v])continue;
			du[v]--;
			if(du[v]==1)q.push(v);
		}
	}
//	for(int i=1;i<=n;i++)
//		if(!vis[i])cout<<i<<" ";
//	cout<<endl;
	dfs2(1,0);
	for(int i=1;i<=stn2;i++)
		printf("%d ",st2[i]);
	printf("\n");
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(du,0,sizeof(du));
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		addline(u,v);
		addline(v,u);
		du[u]++;
		du[v]++;
	}
	for(int i=1;i<=n;i++)
		sort(a[i].begin(),a[i].end());
	if(m==n-1)
		solve1();
	else 
		solve2();
	return 0;
}
