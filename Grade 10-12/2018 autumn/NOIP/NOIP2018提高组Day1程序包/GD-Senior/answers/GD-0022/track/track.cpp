#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
#define maxn 100005
int n,m;
int tot;
int head[maxn];
struct node{
	int to;
	int nxt;
	int w;
}b[maxn<<1];
void into(int x,int y,int w){
	b[++tot].to=y;
	b[tot].nxt=head[x];
	b[tot].w=w;
	head[x]=tot;
}
long long dp[maxn];
long long ans=0;
long long sum=0;
long long gs=0;
bool vis[maxn];
int val[maxn];
void dfs(int root){
	vis[root]=true;
	for(int i=head[root];i;i=b[i].nxt){
		int y=b[i].to;
		if(vis[y])continue;
		dfs(y);
		ans=max(ans,dp[root]+dp[y]+b[i].w);
		dp[root]=max(dp[root],dp[y]+b[i].w);
	}
}
bool check(long long val){
	memset(vis,false,sizeof(vis));
	int temp=0;
//	for(int )
}
void dfs1(int root,long long val){
	vis[root]=true;
	for(int i=head[root];i;i=b[i].nxt){
//		cout<<root<<" "<<b[i].to<<endl;
		int y=b[i].to;
		if(vis[y])continue;		
		if(sum+b[i].w>val){
			gs++;
			sum=b[i].w;
		}
		else{
			sum+=b[i].w;
		}

		dfs1(y,val);
	}
}
bool check1(long long val){
	memset(vis,false,sizeof(vis));
	gs=0;
	sum=0;
	dfs1(1,val);
//	cout<<val<<" "<<gs<<endl;
	if(gs>m)return true;
	else return false;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool mark=true;
	bool mark1=true;
	int x,y,z;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		val[i]=z;
		if(x!=1)mark=false;
		if(y!=x+1)mark1=false;
		into(x,y,z);
		into(y,x,z);
	}
	if(m==1){
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}else if(mark){
		sort(val+1,val+n);
		int temp=0;
/*		for(int i=n-1;i>=1;i-=2){
			if(temp==m-1){
				cout<<val[i]+val[i-1]<<endl;
				break;
			}
			else{
				temp++;
			}
		}*/
		long long lx=0,rx=10000000000;
		while(lx<rx){
			long long mid=(lx+rx)>>1;
			if(check(mid)){
				lx=mid+1;
			}
			else{
				rx=mid;
			}
		}
		cout<<lx<<endl;
		return 0;
	}
	else if(mark1){
		long long lx=0,rx=10000000000;
		while(lx<rx){
			long long mid=(lx+rx)>>1;
			if(check1(mid)){
				lx=mid+1;
			}
			else{
				rx=mid;
			}
		}
		cout<<lx<<endl;	
		return 0;	
	}
}
