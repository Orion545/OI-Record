#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,a,b,cnt=0,ans[5008],ev[5008];
bool p[5008];
vector <int> v[5008];
void build_tree_1(int x){
	p[x]=true;
	ans[++cnt]=x;
	int sz_x=v[x].size();
	for(int i=0;i<sz_x;i++){
		ev[i]=v[x][i];
	}
	sort(ev,ev+sz_x);
	for(int i=0;i<sz_x;i++){
		v[x][i]=ev[i];
	}
	for(int i=0;i<sz_x;i++){
		if(!p[v[x][i]]){
			build_tree_1(v[x][i]);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	if(m==n-1){
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			p[i]=false;
		}
		build_tree_1(1);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
