#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,M;
string ty;
struct node{
	int nex,to;
}edge[maxn<<1];
int head[maxn],tot;
int dp[maxn][2];
inline void insert(int from,int to){
	edge[++tot].nex=head[from];
	head[from]=tot;
	edge[tot].to=to;
}
int ans=0x3f3f3f3f;
int val[maxn];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(N);read(M);cin>>ty;
	for(int i=1;i<=N;i++)
		read(val[i]);
	int u,v;
	for(int i=1;i<N;i++){
		read(u);read(v);
		insert(u,v);
		insert(v,u);
	}
	//dfs(1,1);
	int a,ax,b,bx;
	while(M--){
		read(a);read(ax);read(b);read(bx);
		if(a==b-1||a==b+1)
			if(ax==0&&bx==0){
				printf("-1\n");
				continue ;
			}
		memset(dp,0x3f,sizeof(dp));
		dp[1][0]=0;dp[1][1]=1;
		for(int i=1;i<N;i++){
			if(i==a){
				if(ax){
					dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
					dp[i+1][1]=min(dp[i+1][1],dp[i][1]+val[i+1]);
				}else{
					dp[i+1][1]=min(dp[i+1][1],dp[i][0]+val[i+1]);
				}
					
			}else if(i==b){
				if(bx){
					dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
					dp[i+1][1]=min(dp[i+1][1],dp[i][1]+val[i+1]);
				}else{
					dp[i+1][1]=min(dp[i+1][1],dp[i][0]+val[i+1]);
				}		
			}else{
				dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
				dp[i+1][1]=min(dp[i+1][1],dp[i][1]+val[i+1]);
				dp[i+1][1]=min(dp[i+1][1],dp[i][0]+val[i+1]);
			}
		}
		if(N==a){
			if(ax)
				printf("%d\n",dp[N][1]);
			else
				printf("%d\n",dp[N][0]);
		}else if(N==b){
			if(bx)
				printf("%d\n",dp[N][1]);
			else
				printf("%d\n",dp[N][0]);
		}else{
			printf("%d\n",min(dp[N][1],dp[N][0]));
		}
	}
}
/*
6 100 A1
1 1 1 1 100 1
1 2
2 3
3 4
4 5
5 6

*/
