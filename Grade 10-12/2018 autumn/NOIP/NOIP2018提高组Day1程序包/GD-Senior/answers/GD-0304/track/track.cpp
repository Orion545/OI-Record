#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 50001
using namespace std;
void read(int &x){
	char c;int f=1;x=0;c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c>=48&&c<=57){x=x*10+c-48;c=getchar();}
	x*=f;
}
struct Edge{
	int nxt,to,val;
}e[N*2];
int head[N],siz[N];
int n,m,cnt=0;
void add(int u,int v,int w){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	e[cnt].val=w;
	head[u]=cnt;
}
void dfs1(int u,int fa){
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to,w=e[i].val;
		if(v!=fa){
			siz[v]=siz[u]+w;
			dfs1(v,u);
		}
	}
}
int solve1(){
	//一条赛道，用两遍dfs找直径 
	//有20分 
	for(int i=1;i<n;i++){
		int a,b,len;
		read(a);read(b);read(len);
		add(a,b,len);add(b,a,len);
	}
	siz[1]=0;dfs1(1,0);
	int maxn=-1,x;
	for(int i=1;i<=n;i++){
		if(siz[i]>maxn){
			maxn=siz[i];
			x=i;
		}
	}
	//cout<<x<<endl;
	siz[x]=0;dfs1(x,0);
	maxn=-1;
	for(int i=1;i<=n;i++)
		if(siz[i]>maxn)maxn=siz[i];
	return maxn;
}

priority_queue<int, vector<int>, greater<int> > q;
int dis[N];
int solve2(){
	//扫把
	//15分 
	int tot=0;
	for(int i=head[1];i;i=e[i].nxt){
		int v=e[i].to,w=e[i].val;
		dis[++tot]=w;
	}
	sort(dis+1,dis+tot+1);
	for(int i=tot-m+1;i<=tot;i++){
		//cout<<dis[i]<<endl;
		q.push(dis[i]);
	}
	for(int i=tot-m;i>=1;i--){
		int x=q.top();q.pop();
		q.push(x+dis[i]);
	}
	int ans=q.top();
	//cout<<q.top()<<endl;
	return ans;
}
int f[N],dp[1001][1001],suf[N];
int solve3(){
	int sum=n-1;
	suf[0]=0;
	for(int i=1;i<=sum;i++)suf[i]=suf[i-1]+f[i];
	//cout<<suf[4]<<endl;
	memset(dp,0x3f,sizeof(dp));
	//cout<<dp[0][0]<<endl;
	//dp[0][0]=0;
	for(int i=1;i<=sum;i++){
		for(int j=i;j>=1;j--){
			for(int k=0;k<j;k++){
				if(dp[i][k+1]>=99999999)
					dp[i][k+1]=min(dp[j-1][k],suf[i]-suf[j-1]);
				dp[i][k+1]=max(dp[i][k+1],min(dp[j-1][k],suf[i]-suf[j-1]));
				//cout<<i<<" "<<k+1<<":"<<dp[i][k+1]<<endl;
			}
		}
	}
	//cout<<dp[sum][m]<<endl;
	return dp[sum][m];
}
int main(){
	//!!!
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n);read(m);
	if(m==1){//check!
		printf("%d\n",solve1());
		return 0;
	}
	bool flag1=0;
	bool flag2=0;
	for(int i=1;i<n;i++){
		int a,b,len;
		read(a);read(b);read(len);
		add(a,b,len);add(b,a,len);	
		f[a]=len;
		if(a!=1)flag1=1;
		if(b!=a+1)flag2=1;
	}
	if(!flag1){//check!!
		printf("%d\n",solve2());
		return 0;
	}
	if(!flag2){
		printf("%d\n",solve3());
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
10 4
1 2 5
2 3 2
3 4 3
4 5 7
5 6 9
6 7 6
7 8 4
8 9 8
9 10 10
*/
