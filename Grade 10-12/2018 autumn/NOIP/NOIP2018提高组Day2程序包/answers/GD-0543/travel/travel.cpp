#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define maxn 5005
#define INF 0x7f7f7f7f
using namespace std;
vector<int>M[maxn];
void read(int &x){
	int f=1;x=0;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
bool vis[maxn];
vector<int>ans,ss;
int mins[maxn],mint[maxn];
int Fa[maxn];
bool isfind;
int n,m;
void dfs(int th,int fa,bool ins){
	if(!ins) Fa[th]=fa;
	if(!ins) ans.push_back(th);
	if(isfind||ans.size()==n){
		if(ss.empty()) ss=ans;
		isfind=1;
		return;
	}
	bool flag=0;
	for(vector<int>::iterator i=M[th].begin();i!=M[th].end();i++){
		if(!flag&&mins[fa]<*i){
			int siz=ans.size();
			flag=1;
			dfs(mint[fa],Fa[mint[fa]],1);
			while(ans.size()>siz) ans.pop_back();
		}
		if(vis[*i]) continue;
		vis[*i]=1;
		if(i+1!=M[th].end()&&*(i+1)<mins[fa]) mins[th]=*(i+1),mint[th]=th;
		else mins[th]=mins[fa],mint[th]=mint[fa];
		dfs(*i,th,0);
		vis[*i]=0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++){
		int a,b;
		read(a),read(b);
		M[a].push_back(b);
		M[b].push_back(a);
	}
	for(int i=1;i<=n;i++) sort(M[i].begin(),M[i].end());
	mins[0]=INF;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,0,0);
		vis[i]=0;
		if(isfind) break;
	}
	for(vector<int>::iterator i=ss.begin();i!=ss.end();i++) printf("%d ",*i);
}
/*
6 5
1 3
2 3
2 5
3 4
4 6
*/
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
