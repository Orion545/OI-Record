#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 50005
#define MAXN 100010
using namespace std;
int n,m,cnt;
int a[MAXN],link[MAXN],head[maxn],len[MAXN];
int eg[maxn];
inline bool cmp(int x,int y){
	return x>y;
}
void addlink(int x,int y,int z){
	a[++cnt]=y;
	len[cnt]=z;
	link[cnt]=head[x];
	head[x]=cnt;
	return ;
}
int dfs(int now,int father){
	int ans=0;
	for(register int l=head[now];l!=-1;l=link[l]){
		if(a[l]!=father){
			ans=max(ans,dfs(a[l],now)+len[l]);
		} 
	}
	return ans;
}
void read1(){
	int ans=0;
	for(register int i=1,x,y,z;i<n;i++){
		cin>>x>>y>>z;
		addlink(x,y,z);
		addlink(y,x,z);
	}
	for(register int i=1;i<=n;i++)
		ans=max(ans,dfs(i,0));
	cout<<ans;
	return ;
}
void read2(){
	int ans;
	bool k=1;
	for(register int i=1,x,y,z;i<n;i++){
		cin>>x>>y>>z;
		if(x!=1) k=0;
		eg[i]=z;
		addlink(x,y,z);
		addlink(y,x,z);
	}
	if(k){
		ans=214721476;
		sort(eg+1,eg+n,cmp);
		for(register int i=1;i<=m;i++) ans=min(ans,eg[i]+eg[2*m-i+1]);
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	memset(link,-1,sizeof(link));
	if(m==1) read1();
	else read2();
	return 0;
}
