#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cstring>
#define maxn 100005
#define inf 10000000
#define cin fin
#define cout fout
using namespace std;
ifstream fin("travel.in");
ofstream fout("travel.out");
int n,m;
struct edge{
	int from,to,next;
};struct edge e[maxn];int cnt_e=0;
int head[maxn],vis[maxn],ans[maxn];int cnt_ans=0;
void adde(int start,int end){
	cnt_e++;
	e[cnt_e].from=start,e[cnt_e].to=end,e[cnt_e].next=head[start];
	head[start]=cnt_e;
}
void dfs1(int now,int fa){
	cnt_ans++;
	ans[cnt_ans]=now;
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=head[now];i;i=e[i].next){
		int to=e[i].to;
		if(to==fa) continue;
		q.push(to);
	}
	while(q.empty()!=true){
		int t=q.top();
		q.pop();
		dfs1(t,now);
	}
}
priority_queue<int,vector<int>,greater<int> > pq;
int num_use=0;
void dfs2(int now,int fa){
	vis[now]=true;
	priority_queue<int,vector<int>,greater<int> > q;
	cnt_ans++;
	ans[cnt_ans]=now;
	for(int i=head[now];i;i=e[i].next){
		int to=e[i].to;
//		cout<<"to="<<to<<endl;	
		if(vis[to]==true||to==fa) continue;
		pq.push(to);
		q.push(to);
	//	vis[to]=true;
	}
//	cout<<"now_use="<<num_use<<endl;
	if(num_use<1){
		while(pq.empty()!=true){
			int t=pq.top();
			bool flag=false;
			for(int i=head[now];i;i=e[i].next){
				int to=e[i].to;
				if(to==fa) continue;
				if(to==t){
					flag=true;
					q.pop();
					break;
				}
			}
			if(flag==false) num_use++;
			pq.pop();
			dfs2(t,now);
		}
	}
	else{
		while(pq.empty()!=true){
			int t=pq.top();vis[t]=false;
			pq.pop();
		}
		while(q.empty()!=true){
			int t=q.top();
		//	vis[t]=true;
			q.pop();
			dfs2(t,now);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	memset(vis,false,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int start,end;
		cin>>start>>end;
		adde(start,end);
		adde(end,start);
	}
	if(m==n-1){
		vis[1]=true;
		dfs1(1,0);
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	else{
		vis[1]=true;
		dfs2(1,0);
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
}













/*

int fa[maxn],deep[maxn],top[maxn],hson[maxn],siz[to],id[to];
int cnt_id=0;
void dfs1(int x,int fath,int dep){
	fa[x]=fath,deep[x]=dep,hson[x]=-1,siz[x]=1;int maxson=-1;
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(to==fath) continue;
		dfs1(to,x,dep+1);
		siz[x]+=siz[to];
		if(siz[to]>maxson){
			maxson=siz[to];
			hson[x]=to;
		}
	}
}
void dfs2(int x,int topf){
	cnt_id++;
	id[x]=cnt_id;top[x]=topf;
	if(hson[x]==-1) continue;
	dfs2(hson[x],topf);;
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(to==fa[x]||to==hson[x]) continue;
		dfs2(to,to);
	}
}
int query(int x,int y){
	int res=0;
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		res+=deep[top[x]]-deep[x]+1;
		x=fa[top[x]];
	}
	if(x>y) swap(x,y);
	res+=deep[y]-deep[x];
	return res;
}
*/
