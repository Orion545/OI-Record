// ^_^
#include<bits/stdc++.h>
using namespace std;
namespace noip{
	int readu(){
		int ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		int value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	void writeu(int a){
		if(a<10)
			putchar(a+'0');
		else{
			writeu(a/10);
			putchar(a%10+'0');
		}
	}
	vector<int> adj[5000+1];
	vector<int> result;
	int ban_first;
	int ban_second;
	void dfs(int cur, int father){
		result.push_back(cur);
		for(size_t i=0; i<adj[cur].size(); ++i){
			int to=adj[cur].at(i);
			if(to==father)
				continue;
			if(min(cur, to)==ban_first&&max(cur, to)==ban_second)
				continue;
			dfs(to, cur);
		}
	}
	bool visited[5000+1];
	vector<int> cycle;
	int dfs0(int cur, int father){
		visited[cur]=true;
		for(size_t i=0; i<adj[cur].size(); ++i){
			int to=adj[cur].at(i);
			if(to==father)
				continue;
			if(visited[to]){
				cycle.push_back(cur);
				return to;
			}
			int root=dfs0(to, cur);
			if(root!=0){
				cycle.push_back(cur);
				if(root!=cur)
					return root;
				else
					return 0;
			}
		}
		return 0;
	}
	void run(){
		freopen("travel.in", "r", stdin);
		freopen("travel.out", "w", stdout);
		int n=readu();
		int m=readu();
		for(int i=0; i<m; ++i){
			int a=readu();
			int b=readu();
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=1; i<=n; ++i)
			sort(adj[i].begin(), adj[i].end());
		if(m==n-1)
			dfs(1, -1);
		else{
			assert(m==n);
			dfs0(1, -1);
			assert(cycle.size()>=3);
			vector<int> best;
			for(size_t i=0; i<cycle.size(); ++i){
				int cur=cycle.at(i);
				int next=cycle.at((i+1)%cycle.size());
				assert(find(adj[cur].begin(), adj[cur].end(), next)!=adj[cur].end());
				assert(find(adj[next].begin(), adj[next].end(), cur)!=adj[next].end());
				ban_first=min(cur, next);
				ban_second=max(cur, next);
				dfs(1, -1);
				if(i==0||result<best)
					best=result;
				result.clear();
			}
			result=best;
		}
		assert(int(result.size())==n);
		for(int i=0; i<n; ++i){
			if(i!=0)
				putchar(' ');
			writeu(result.at(i));
		}
		putchar('\n');
	}
}
int main(){
	noip::run();
}
