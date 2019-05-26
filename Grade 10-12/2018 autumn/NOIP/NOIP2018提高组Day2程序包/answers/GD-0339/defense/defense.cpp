#include<cstdio>
#include<algorithm>
#include<set>
#define N 100010
#define ll long long
#define inf 9999999999
using namespace std;
struct D{
	int a,b,x,y;
}q[N];
int head[N],to[N*2],nxt[N*2],d[N];
ll dp[N][2],pre[N][2],p[N];
int n,m,eCnt;
int val[N];
bool tag[N];
char str[10];
set <int> s;
bool b=false;
inline int read(){
	int x=0,flag=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return x*flag;
}
inline void add(int u,int v){
	eCnt++;
	nxt[eCnt]=head[u];
	to[eCnt]=v;
	head[u]=eCnt;
}
void DFS(int x,int fa){
	dp[x][0]=0;
	dp[x][1]=p[x];
	if(tag[x]){
		if(val[x]==1){
			dp[x][0]=inf;
		}
		else{
			dp[x][1]=inf;
		}
	}
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa)
			continue;
		DFS(y,x);
		if(tag[y]){
			if(val[y]==1){
				dp[x][0]+=dp[y][1];
				dp[x][1]+=dp[y][1];
			}
			else{
				dp[x][0]=inf;
				dp[x][1]+=dp[y][0];
			}
		}
		else{
			dp[x][0]+=dp[y][1];
			dp[x][1]+=min(dp[y][0],dp[y][1]);
		}
	}
}
void Ini(int x){
	pre[x][0]=dp[x][0];
	pre[x][1]=dp[x][1];
	s.insert(x);
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(d[y]!=d[x]-1)
			continue;
		Ini(y);
	}
}
void Rec(int x){
	dp[x][0]=pre[x][0];
	dp[x][1]=pre[x][1];
//	s.insert(x);
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(d[y]!=d[x]-1)
			continue;
		Rec(y);
	}
}
void DFS2(int x,int fa){
//	printf("DFS %d\n",x);
	d[x]=d[fa]+1;
	dp[x][0]=0;
	dp[x][1]=p[x];
	if(tag[x]){
		if(val[x]==1){
			dp[x][0]=inf;
		}
		else{
			dp[x][1]=inf;
		}
	}
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa)
			continue;
		if(b||s.find(y)!=s.end())
			DFS2(y,x);
		if(tag[y]){
			if(val[y]==1){
				dp[x][0]+=dp[y][1];
				dp[x][1]+=dp[y][1];
			}
			else{
				dp[x][0]=inf;
				dp[x][1]+=dp[y][0];
			}
		}
		else{
			dp[x][0]+=dp[y][1];
			dp[x][1]+=min(dp[y][0],dp[y][1]);
		}
	}
//	printf("%d %d %d\n",x,dp[x][0],dp[x][1]);
}
void Solve(){
//	for(int i=1;i<=n;i++)
//		s.insert(i);
	b=true;
	DFS2(1,0); 
	b=false;
	s.clear();
	for(int i=1;i<=m;i++){
		s.clear();
		tag[q[i].a]=true;
		val[q[i].a]=q[i].x;
		tag[q[i].b]=true;
		val[q[i].b]=q[i].y;
		Ini(q[i].a);
		Ini(q[i].b);
		DFS2(1,0);
		ll res=min(dp[1][0],dp[1][1]);
		if(res>=inf)
			printf("-1\n");
		else
			printf("%lld\n",res);
		Rec(q[i].a);
		Rec(q[i].b);
		tag[q[i].a]=false;
		tag[q[i].b]=false;
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,str);
	for(int i=1;i<=n;i++)
		p[i]=read();
	for(int i=1;i<=n-1;i++){
		int u,v;
		u=read();
		v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=m;i++){
		q[i].a=read(),q[i].x=read(),q[i].b=read(),q[i].y=read();
	}
	if(n*m>=1000000){
		Solve();
		return 0;
	}
	for(int i=1;i<=m;i++){
		tag[q[i].a]=true;
		val[q[i].a]=q[i].x;
		tag[q[i].b]=true;
		val[q[i].b]=q[i].y;
		DFS(1,0);
		tag[q[i].a]=false;
		tag[q[i].b]=false;
		ll res=min(dp[1][0],dp[1][1]);
		if(res>=inf)
			printf("-1\n");
		else
			printf("%lld\n",res);
	}
	return 0;
}
