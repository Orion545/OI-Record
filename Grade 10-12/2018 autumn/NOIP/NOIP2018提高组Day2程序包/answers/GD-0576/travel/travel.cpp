#include <bits/stdc++.h>

using namespace std;
int n,m;
int vis[5002];
vector<int> bian[5002];

vector<vector<int> > ans;

bool ifans(vector<int> mat){
	return true;
}

void dfs(vector<int> mat,int pos,int d){
	if(mat.size()==n){
		ans.push_back(mat);
	}
	if(!bian[pos].empty()){
		for(int i=0;i<bian[pos].size();i++){
			if(vis[bian[pos][i]]==0){
				vis[bian[pos][i]]=1;
				mat.push_back(bian[pos][i]);
				dfs(mat,bian[pos][i],d+1);
				mat.pop_back();
				vis[bian[pos][i]]=0;
			}
		}
	}
	
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int in1,in2;
		scanf("%d%d",&in1,&in2);
		bian[in1].push_back(in2);
		bian[in2].push_back(in1);
	}
	vis[1]=1;
	vector<int> a;
	a.push_back(1);
	dfs(a,1,1);
	
	for(int i=0;i<ans.size();i++){
		if(ifans(ans[i])){
			for(int j=0;i<ans[j].size();j++){
				cout<<ans[i][j]<<" ";
			}
		}
	}
	return 0;
}
