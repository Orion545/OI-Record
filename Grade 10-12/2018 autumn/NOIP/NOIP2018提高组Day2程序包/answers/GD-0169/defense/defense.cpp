#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int maxn=2e5+10;
string type;
int e[maxn],n,m;
int head[maxn],next[maxn],V[maxn],cnt=-1;
int state[maxn],minn;
void add(int x,int y){
	V[++cnt]=y;
	next[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int i,int ans){
	if(i==n+1){
		minn=min(minn,ans);
		return ;
	}
	if(state[i-1]==0){
		if(state[i]==0) return ;
		if(state[i]==-1){
			state[i]=1;
			dfs(i+1,ans+e[i]);
			state[i]=-1;
		}
		if(state[i]==1)
			dfs(i+1,ans+e[i]);
	}
	if(state[i-1]==1){
		if(state[i]==-1){
			state[i]=1;
			dfs(i+1,ans+e[i]);
			state[i]=0;
			dfs(i+1,ans);
			state[i]=-1;
		}
		else dfs(i+1,ans+e[i]*state[i]);
	}
}
void workA3(){
	int i,a,x,b,y;
	while(m--){
		int ans=999999;
		memset(state,-1,sizeof(state));
		cin>>a>>x>>b>>y;
		if((x==0&&y==0)&&((a==b+1)||(b==a+1))){
			cout<<"-1"<<endl;
			continue;
		}
		else{
			state[a]=x;state[b]=y;
		}
		
		if(state[1]==-1){
			minn=99999;state[1]=0;
			dfs(2,0);
			state[1]=-1;
			ans=min(minn,ans);
			minn=99999;state[1]=1;
			dfs(2,e[1]);
			state[1]=-1;
			ans=min(minn,ans);
			cout<<ans<<endl;
		}
		
		if(state[1]==1){
			minn=99999;
			dfs(2,e[1]);
			cout<<minn<<endl;
		}
		
		if(state[1]==0){
			minn=99999;
			dfs(2,0);
			cout<<minn<<endl;
		}
	}
}
int main(){
	int i,j,k;
	int x,y;
	memset(head,-1,sizeof(head));
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for(i=1;i<=n;i++)
	  cin>>e[i];
	for(i=1;i<n;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	memset(state,-1,sizeof(state));
	if(type=="A3") workA3();
}
