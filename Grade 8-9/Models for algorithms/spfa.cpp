#include<iostream>
#include<vector>
#define inf 0x7fffffff
using namespace std;
vector<int>a[1001];
vector<int>b[1001];
int n,m,op,ed;
int ans[1001],link[1000001];
bool vis[1001]={0};
void spfa(){
	int head=0,tail=1;
	link[1]=op;ans[op]=0;
	while(head<tail){
		head++;vis[link[head]]=1;
		for(int i=0;i<a[link[head]].size();i++){
			ans[a[link[head]][i]]=min(ans[a[link[head]][i]],ans[link[head]]+b[link[head]][i]);
			if(!vis[a[link[head]][i]]){
				tail++;link[tail]=a[link[head]][i];
			}
		}
	}
}
int main(){
	for(int i=0;i<=1000;i++) ans[i]=inf;
	cin>>n>>m;int xx,yy,zz;
	for(int i=1;i<=m;i++){
		cin>>xx>>yy>>zz;
		a[xx].push_back(yy);b[xx].push_back(zz);
	}
	cin>>op>>ed;
	spfa();
	cout<<ans[ed];
} 
