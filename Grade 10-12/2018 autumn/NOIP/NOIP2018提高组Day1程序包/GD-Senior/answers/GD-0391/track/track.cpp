#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;
vector<pair<int,int> > g[50001];
int n,m,val[50001],fa[50001];
pair<int,int> d[50001];
bool visit[50001],cho[50001];

int chekku=0;


void dfs(int u,int mid){
	visit[u]=true;int head=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].second;
		if(!visit[v]){
			val[v]=g[u][i].first;
			fa[v]=u;
			dfs(v,mid);
		}
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].second;
		if(fa[v]==u){
			head++;
			d[head].first=val[v];
			d[head].second=v;
			//cout<<val[v]<<" "<<v<<endl;
		}
	}
	sort(d+1,d+1+head);
	
//	cout<<u<<":";for(int i=1;i<=head;i++)cout<<d[i].second<<" ";cout<<endl;
	bool ooop;
	int tail=1,p=head;
	while(head>=tail){
		if(d[head].first>=mid)chekku++,cho[d[head].second]=true,head--;
		else{ooop=0;
			while(tail<head){
			//	cout<<d[tail].second<<" "<<d[head].second<<endl;
			//	cout<<d[tail].first+d[head].first<<endl;
				if(d[tail].first+d[head].first>=mid){
					chekku++;
					cho[d[head].second]=true;cho[d[tail].second]=true;
					head--;tail++;ooop=1;
					break;
				}
				tail++;
			}
			if(ooop==0)break;
		}
	}
	int mx=0;
	for(int i=1;i<=p;i++){
		if(!cho[d[i].second]&&fa[d[i].second]==u)mx=max(mx,val[d[i].second]);
	}
	val[u]+=mx;
}


int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(w,v));
		g[v].push_back(make_pair(w,u));
	}
//	dfs(1,15);cout<<chekku<<endl;
//	for(int i=1;i<=n;i++)cout<<val[i]<<" ";
	int l=0,r=500000000,mid;
	while(r-l>1){
		memset(visit,0,sizeof(visit));
		memset(cho,0,sizeof(cho));
		memset(val,0,sizeof(val));
		chekku=0;
		mid=(l+r)>>1;//cout<<l<<" "<<r<<" "<<mid<<endl;
		dfs(1,mid);
		//cout<<chekku<<endl;
		if(chekku>=m)l=mid;
		else r=mid;
	}
	cout<<l;
}
/*
3 5
1 2 2
2 3 3
*/

