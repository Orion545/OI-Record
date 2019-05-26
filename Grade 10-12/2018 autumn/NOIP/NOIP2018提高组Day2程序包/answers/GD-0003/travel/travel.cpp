#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=5005;
int edge[MAXN],to[MAXN*2],nex[MAXN*2],sz=1;
int inc[MAXN],inc0[MAXN];
bool vis[MAXN];
int N,M;

int ans[MAXN],anssz=0;

void adde(int a,int b){
	to[sz]=b;
	nex[sz]=edge[a];
	edge[a]=sz;
	sz++;
}

void dfs_1(int node){
	ans[anssz++]=node;
	vis[node]=true;
	vector<int> wl;
	for(int ind=edge[node];ind;ind=nex[ind]){
		int dst=to[ind];
		if(!vis[dst])wl.push_back(to[ind]);
	}
	sort(wl.begin(),wl.end());
	for(int i=0;i<wl.size();i++){
		dfs_1(wl[i]);
	}
}

void solve1(){
	dfs_1(1);
	for(int i=0;i<anssz;i++){
		printf("%d ",ans[i]);
	}
}


int topsort[MAXN],tps=0;
bool inring[MAXN];
bool findr(){
	queue<int> q;
	for(int i=1;i<=N;i++){
		if(inc[i]==1)q.push(i);
	}
	while(!q.empty()){
		int node=q.front();
		q.pop();
		topsort[tps++]=node;
		for(int ind=edge[node];ind;ind=nex[ind]){
			int dst=to[ind];
			inc[dst]--;
			if(inc[dst]==1){
				q.push(dst);
			}
		}
	}
	/*for(int i=0;i<tps;i++){
		cout<<topsort[i]<<" ";
	}cout<<endl;*/
	for(int i=1;i<=N;i++)inring[i]=true;
	for(int i=0;i<tps;i++){
		inring[topsort[i]]=false;
	}
}

struct cm{
	bool operator ()(int a,int b){
		return a>b;
	}
};


bool back=false;
priority_queue<int,vector<int>,cm> pq;
bool vis2[MAXN],inq2[MAXN];
void dfs2(int node){
	if(vis2[node])return;
	ans[anssz++]=node;
	vis2[node]=true;
	if(!pq.empty()&&pq.top()==node)pq.pop();
	vector<int> child;
	for(int ind=edge[node];ind;ind=nex[ind]){
		int dst=to[ind];
		if(!vis2[dst]&&!inq2[dst])pq.push(dst),inq2[dst]=true;
		if(!vis2[dst])child.push_back(dst);
	}
	//printf("dfs %d inring=%d childsz=%d\n",node,inring[node],child.size());
	if(child.size()==0)return;
	sort(child.begin(),child.end());
	int mn=pq.top();
	//printf("min=%d\n",mn);
	while(vis2[mn]){
		pq.pop();mn=pq.top();
	}
	bool inchild=false;
	for(int i=0;i<child.size();i++){
		if(child[i]==mn){
			inchild=true;
			break;
		}
	}
	if(inchild){
		pq.pop();
		for(int i=0;i<child.size();i++){
			dfs2(child[i]);
		}
	}else{
		if(!back&&inring[node]){
			back=true;
		//printf("back! %d\n",inc0[node]);
			for(int i=0;i<child.size()-1;i++){
				dfs2(child[i]);
			}
			//pq.pop();
			dfs2(mn);
		}else{
			for(int i=0;i<child.size();i++){
				dfs2(child[i]);
			}
		}
		
	}
}

void solve2(){
	findr();
	dfs2(1);
	for(int i=0;i<anssz;i++){
		printf("%d ",ans[i]);
	}
}

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>N>>M;
	for(int i=0,a,b;i<M;i++){
		scanf("%d%d",&a,&b);
		adde(a,b);adde(b,a);
		inc[a]++;inc[b]++;
		inc0[a]++;inc0[b]++;
	}
	if(M==N-1)solve1();
	else solve2();
	return 0;
}
