#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
vector<int>a[1001];
stack<int>s;
int num,n,m;
bool vis[1001]={0},ins[1001]={0};
int dfn[1001],low[1001],index=0;;
void tarjan(int k){
	dfn[k]=++index;low[k]=index;vis[k]=1;
	s.push(k);ins[k]=1;
//	cout<<"new on "<<k<<ends<<dfn[k]<<ends<<low[k]<<endl;
	for(int i=0;i<a[k].size();i++){
		if(!vis[a[k][i]]){
			tarjan(a[k][i]);
			low[k]=min(low[k],low[a[k][i]]);
		} 
		else if(ins[a[k][i]]) low[k]=min(low[k],dfn[a[k][i]]);
	} 
//	cout<<"defined "<<k<<ends<<dfn[k]<<ends<<low[k]<<endl;
	if(dfn[k]==low[k]){
		while(1){
//			cout<<"********"<<endl;
			int tmp=s.top();
			s.pop();ins[tmp]=0;cout<<tmp<<" ";
			if(tmp==k) break;
		}
		cout<<endl;
	}
}
int main(){
	cin>>n>>m;
	int tx,ty;
	for(int i=1;i<=m;i++){
		cin>>tx>>ty;
		a[tx].push_back(ty);
	}
	for(int i=1;i<=n;i++){	
		if(!vis[i]) tarjan(i);
	}
} 
