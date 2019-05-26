#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
inline char gc(){
	return getchar();
	static char bb[1000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,1000000,stdin),s==t)?EOF:*s++;
}
inline int read(){
	register int x=0;register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+ch-48,ch=gc();
	return x;
}
int n,m;
typedef pair<int,int>mp;
vector<mp>road[50005];
int dep[50005],dis[50005];
int anc[50005][16];
void dfs(int x,int p){
	dep[x]=dep[p]+1;
	anc[x][0]=p;
	for(int i=1;i<16;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(size_t i=0;i<road[x].size();i++){
		if(road[x][i].first==p)continue;
		dis[road[x][i].first]=dis[x]+road[x][i].second;
		dfs(road[x][i].second,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=15;i>=0;i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=15;i>=0;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
queue<mp>temp;
bool vis[50005];
void bfs(int node){
	//sorry dis
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(temp.size())temp.pop();
	temp.push(mp(node,0));
	while(temp.size()){
		mp x=temp.front();
		temp.pop();
		vis[x.first]=1;
		dis[x.first]=x.second;
		for(size_t i=0;i<road[x.first].size();i++)
			if(!vis[road[x.first][i].first])
				temp.push(mp(road[x.first][i].first,x.second+road[x.first][i].second));
	}
}
int fmp(){int ret=1;for(int i=2;i<=n;i++)if(dis[i]>dis[ret])ret=i;return ret;}
bool check(int mid){
	//sonrry vis
	memset(vis,0,sizeof(vis));
	int cnt=0,sum=0,now=1;
	while(cnt<m){
		while(now!=n&&sum<mid)
			for(size_t i=0;i<road[now].size();i++)
				if(!vis[road[now][i].first]){
					sum+=road[now][i].second;
					vis[now]=1;
					now=road[now][i].first;
					break;
				}
		if(sum<mid)return false;
		cnt++;
		sum=0;
	}
	return true;
}
int fz(){
	bfs(1);
	bfs(fmp());
	return dis[fmp()];
}
int gdis(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
bool flagn=1,flagm=1;
vector<int>rl;
bool comp(int a,int b){return a>b;}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++){
		int a=read(),b=read(),v=read();
		flagn&=(a==1);
		flagm&=(b==a+1);
		rl.push_back(v);
		road[a].push_back(mp(b,v));
		road[b].push_back(mp(a,v));
	}
	if(m==1){
		cout<<fz();
		return 0;
	}
	if(flagn){
		sort(rl.begin(),rl.end(),comp);
		if(m<=(n-1)/2){
			int minn=0x7fffffff;
			for(int i=0;i<m;i++){
				minn=min(minn,rl[i]+rl[2*m-i-1]);
			}
			cout<<minn;
		}
		else{
			//k+(m-k)*2=n-1
			//-k+2*m=n-1
			//-k=n-2*m-1
			//k=2*m-n+1
			int k=2*m-n+1;
			int minn=rl[k-1];
			for(int i=0;i<m-k;i++)
				minn=min(minn,rl[k+i]+rl[n-i-2]);
			cout<<minn;
		}
		return 0;
	}
	if(flagm){
		int lb=0,rb=0x7fffffff,ans=0;
		while(lb<=rb){
			int mid=(lb+rb)>>1;
			if(check(mid))ans=mid,lb=mid+1;
			else rb=mid-1;
		}
		cout<<ans;
		return 0;
	}
	int minn=0x7fffffff;
	for(int i=0;i<n-1;i++)
		minn=min(minn,rl[i]);
	cout<<minn;
//	dfs(1,0);
}
