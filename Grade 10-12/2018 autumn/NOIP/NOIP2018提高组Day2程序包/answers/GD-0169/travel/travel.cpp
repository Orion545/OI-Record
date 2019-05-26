#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=5e3+10;
int n,m;
int a[maxn][maxn];
int head[maxn],next[maxn],V[maxn],cnt=-1;
int tag[maxn],ans[maxn];

void add(int x,int y){
	V[++cnt]=y;
	next[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int x,int f,int cnt){
	int v=5001;
	cout<<x<<" ";
	for(register int i=1;i<=n;i++){
		if(i==f) continue;
		if(a[x][i]==1){
			dfs(i,x,cnt+1);
		}
	}
	return ;
}
int main(){
	int i,j,k;
	int x,y;
	memset(head,-1,sizeof(head));
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=m;i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	if(m==n-1) dfs(1,1,1);
	cout<<endl;
	return 0;
}
//6 5
//1 3
//2 3
//2 5
//3 4
//4 6
