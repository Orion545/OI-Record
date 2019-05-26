#include<set>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5010;
int n,m,tot,now,head[N],nxt[N*2],to[N*2],vis[N];
priority_queue<int,vector<int>,greater<int> >q,q2;
void add_edge(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
	return;
}
void dfs(int u){
	vis[u]=1;
	printf("%d ",u);
	set<int>Set;
	for(int i=head[u];~i;i=nxt[i]){
		int v=to[i];
		if(vis[v])
			continue;
		q.push(v);
		Set.insert(v);
	}
	while(Set.count(q.top())){
		while(vis[now])
			now++;
		if(q.top()>now){
			while(!q.empty())
				q.pop();
			while(!q2.empty())
				q2.pop();
			printf("%d ",now);
			int minv=n+1;
			vis[now]=1;
			for(int j=head[now];~j;j=nxt[j])
				minv=min(minv,to[now]);
			if(minv!=n+1){
				dfs(minv);
				exit(0);
			}
		}
		dfs(q.top());
		Set.erase(q.top());
		q.pop();
		while(!q.empty()&&!q2.empty()&&q.top()==q2.top()){
			q.pop();
			q2.pop();
		}
	}
	for(set<int>::iterator iter=Set.begin();iter!=Set.end();iter++)
		q2.push(*iter);
	while(!q.empty()&&!q2.empty()&&q.top()==q2.top()){
		q.pop();
		q2.pop();
	}
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(now=1;now<=n;now++){
		if(!vis[now]){
			printf("%d ",now);
			vis[now]=1;
			int minv=n+1;
			for(int j=head[now];~j;j=nxt[j])
				if(!vis[to[j]])
					minv=min(minv,to[j]);
			if(minv==n+1)
				continue;
			dfs(minv);
		}
	}
	return 0;
}
