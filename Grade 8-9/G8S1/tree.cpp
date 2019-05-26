#include<iostream>
#include<vector>
using namespace std;
vector<int>node[10001];
int n;
bool vis[10001];
int depth[10001],maxson[10001],sonnum[10001],dad[10001];
int dfs(int k,int layer,int from){
	cout<<"searching "<<k<<" on "<<layer<<" from father "<<from<<endl;
	depth[k]=layer;dad[k]=from;vis[k]=1;
	int son=0,sum=0,maxn=-1;
	for(int i=0;i<node[k].size();i++){
		if(!vis[node[k][i]]){ 
			son++;
			int tmp=dfs(node[k][i],layer+1,k);
			maxn=max(maxn,tmp);
			sum+=tmp;
		}
	}
	sonnum[k]=son;maxson[k]=maxn;
	return sum+1;
}
int main(){
	cin>>n;
	int xx,yy;
	for(int i=1;i<n;i++){
		cin>>xx>>yy;
		node[xx].push_back(yy);
		node[yy].push_back(xx);
	} 
	n=dfs(1,1,0);
	for(int i=1;i<=n;i++) cout<<"depth: "<<depth[i]<<"	"<<ends<<"biggest son: "<<maxson[i]<<"	"<<ends<<"num of son: "<<sonnum[i]<<"	"<<ends<<"father: "<<dad[i]<<endl;
} 
