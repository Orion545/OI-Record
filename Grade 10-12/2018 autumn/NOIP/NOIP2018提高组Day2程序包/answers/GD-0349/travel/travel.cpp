#include<bits/stdc++.h>
using namespace std;
int n,m,i,u,v,fa[6000],bl[6000],lb[6000],ss[6000][6000],k[6000],t;
bool f[6000];
vector <int> s[6000];
queue <int> q;
void bfs(int a){
	q.push(a);
	f[a]=true;
	while (!q.empty()) {
		int x=q.front();
		for (int i=0;i<s[x].size();i++) {
			int y=s[x][i];
			if (fa[x]!=y) {
				if (f[y]) bl[x]++;
				else {
					fa[y]=x;
					q.push(y);
					f[y]=true;	
				}
			}
		}
		q.pop();
	}
}
void dfss(int x){
	for (int i=0;i<s[x].size();i++) if (fa[s[x][i]]==x) {
		dfss(s[x][i]);
		if (bl[s[x][i]]==2) {
			bl[x]=max(bl[x],bl[s[x][i]]);
			lb[x]++;
		}
	}
}
void dfs2(int x){
	if (t==10000) {
		for (int i=0;i<s[x].size();i++) if (fa[x]!=s[x][i]) {
			int y=s[x][i];
			if (bl[y]==2) {
				if (lb[y]==2) for (int j=1;j<s[y].size();j++) if (bl[s[y][j-1]]==2) {
					if (fa[y]!=s[y][j-1]) {
						t=s[y][j];
						f[s[y][j-1]]=true;	
					}	
				} else dfs2(y);
			}
		}
	}
}
void dfs1(int x){
	printf("%d ",x);
	for (int i=0;i<s[x].size();i++) if (fa[s[x][i]]==x) dfs1(s[x][i]);
}
void dfs3(int x){
	for (int i=0;i<s[x].size();i++) if (fa[x]!=s[x][i]&&f[s[x][i]]==false) {
		fa[s[x][i]]=x;
		dfs3(s[x][i]);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		s[u].push_back(v);
		s[v].push_back(u);
	}
	bfs(1);
	if (m==n) {
		memset(f,false,sizeof(f));
		for (i=1;i<=n;i++) bl[i]++;
		dfss(1);	
		for (i=1;i<=n;i++) {
			for (int j=0;j<s[i].size();j++) k[j+1]=s[i][j];
			sort(k+1,k+s[i].size());
			for (int j=0;j<s[i].size();j++) ss[i][j]=k[j+1];
		}
		memset(f,false,sizeof(f));
		t=10000;
		dfs2(1);
		dfs3(t);
		dfs1(1);
	} else {
		for (i=1;i<=n;i++) {
			for (int j=0;j<s[i].size();j++) k[j+1]=s[i][j];
			sort(k+1,k+s[i].size());
			for (int j=0;j<s[i].size();j++) ss[i][j]=k[j+1];
		}
		dfs1(1);
	}
}
