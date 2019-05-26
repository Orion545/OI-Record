#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#include<vector>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
vector<int>a[5010];
int n,m;bool vis[5010],inc[5010],ff=0;
vector<int>ans,cir;
void dfs(int u,int f){
	int i,v;ans.push_back(u);
	for(i=0;i<a[u].size();i++){
		v=a[u][i];if(v==f||vis[v]||inc[v]) continue;
		dfs(v,u);
	}
}
void output(){
	int i;
	for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
	putchar('\n');
}
int s[5010],top,ins[5010];
void getcir(int u,int f){
//	cout<<"getcir "<<u<<' '<<f<<' '<<ins[u]<<' '<<top<<'\n';
	int i,v;
	if(ff) return;
	s[++top]=u;ins[u]=1;
	for(i=0;i<a[u].size();i++){
		v=a[u][i];
//		cout<<"	to "<<v<<'\n';
		if(v==f) continue;
//		cout<<"	to "<<v<<'\n';
		if(ins[v]){
//			cout<<"GET "<<u<<' '<<v<<'\n';
			inc[v]=1;ff=1;cir.push_back(v);
			while(s[top]!=v){
				inc[s[top]]=1;
				cir.push_back(s[top]);
				s[top--]=0;
			}
//			cout<<"final "<<cir.size()<<'\n';
			return;
		}
//		cout<<"	to "<<v<<'\n';
		getcir(v,u);
		if(ff) return;
	}
//	cout<<"finish "<<u<<' '<<ff<<'\n';
	s[top--]=0;ins[u]=0;
}
vector<int>tmp,pre;int bl,br;
void DFS(int u,int f){
	int i,v;
//	cout<<"DFS "<<u<<' '<<f<<' '<<bl<<' '<<br<<'\n';
	tmp.push_back(u);
	for(i=0;i<a[u].size();i++){
		v=a[u][i];
//		cout<<"	to "<<v<<'\n';
		if(v==f||vis[v]||(u==bl&&v==br)||(u==br&&v==bl)) continue;
		DFS(v,u);
	}
}
void check(){
	int i;
	for(i=0;i<n;i++){
		if(ans[i]==tmp[i]) continue;
		if(ans[i]<tmp[i]) return;
		else break;
	}
	ans=tmp;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	for(i=1;i<=n;i++) sort(a[i].begin(),a[i].end());
	if(m==n-1){
		dfs(1,0);
		output();
		return 0;
	}
	
	ff=0;
	getcir(1,0);
	assert(s[top]==cir[0]);
	int pos,len=cir.size()-1;
	for(i=1;i<top;i++) vis[s[i]]=1;
	for(i=1;i<top;i++) dfs(s[i],0);
	for(i=0;i<ans.size();i++) pre.push_back(ans[i]);
	while(ans.size()<n) ans.push_back(1e9);
	
	for(pos=1;pos<len;pos++){
		bl=cir[pos];br=cir[pos+1];
//		cout<<"********banning "<<bl<<' '<<br<<' '<<pos<<' '<<len<<'\n';
		tmp.clear();
		for(i=0;i<pre.size();i++) tmp.push_back(pre[i]);
		DFS(cir[0],0);
		check();
	}
	output();
}
