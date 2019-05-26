#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,lim,cost[2000010],cnt,ans;
vector<int>a[2000010];
bool cmp(int l,int r){
	return cost[l]<cost[r];
}
void dfs(int u){
	int i,v;cost[u]+=a[u].size();
//	cout<<"dfs "<<u<<'\n';
	for(i=0;i<a[u].size();i++){
		v=a[u][i];dfs(v);
	}
	sort(a[u].begin(),a[u].end(),cmp);
	for(i=0;i<a[u].size();i++){
		v=a[u][i];
		if(cost[u]+cost[v]-1<=lim){
			cost[u]+=cost[v]-1;ans++;
		}
		else break;
	}
//	cout<<"finish dfs "<<u<<' '<<cost[u]<<' '<<ans<<'\n';
}
int main(){
	n=read();lim=read();int i,t1,t2;
	for(i=1;i<=n;i++) cost[i]=read();
	for(i=1;i<=n;i++){
		t1=read();
		while(t1--){
			t2=read();a[i].push_back(t2+1);
		}
	}
	dfs(1);
	printf("%d\n",ans);
}
