#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
struct edge{
	int to,next;
}e[maxn*2];
int head[maxn],cnt=0,n;
void add_edge(int s,int t){
	e[++cnt].next=head[s];e[cnt].to=t;head[s]=cnt;
}
bool book[maxn];
void dfs(int s){
	book[s]=1;
	cout<<s<<" ";
	vector<int>p;
	for(int i=head[s];i;i=e[i].next){
		if(!book[e[i].to]){
			p.push_back(e[i].to);
		}
	}
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();++i){
		if(!book[p[i]]){
			dfs(p[i]);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int s,t;
		cin>>s>>t;
		add_edge(s,t);
		add_edge(t,s);
	}
	memset(book,0,sizeof(book));
	dfs(1);
	return 0;
}
