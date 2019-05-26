#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005,M=100005;
int n,m,head[N],cnt,a,b,x,y,ans,p[N];
string type;
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct edge{
	int to,nxt;
}e[N<<1];
void add(int a,int b){
	e[++cnt].to=b;
	e[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int x,int f,int s,int k,int fa){
	if(s>=ans)return;
	if(k==n){
		ans=s;
		return;
	}
	if(f==1){
		for(int i=head[x];i;i=e[i].nxt){
			int v=e[i].to;
			if(v==fa)continue;
			if(v==a){
				if(x==1)dfs(v,1,s+p[v],k+1,x);
				else dfs(v,0,s,k+1,x);
			}
			else if(v==b){
				if(y==1)dfs(v,1,s+p[v],k+1,x);
				else dfs(v,0,s,k+1,x);
			}
			else {
				dfs(v,1,s+p[v],k+1,x);
				dfs(v,0,s,k+1,x);
			}
		}
	}
	else {
		for(int i=head[x];i;i=e[i].nxt){
			int v=e[i].to;
			if(v==fa)continue;
			if(v==a){
				if(x==1)dfs(v,1,s+p[v],k+1,x);
				else {
					return;
				}
			}
			else if(v==b){
				if(y==1)dfs(v,1,s+p[v],k+1,x);
				else {
					return;
				}
			}
			else {
				dfs(v,1,s+p[v],k+1,x);
			}
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();
	cin>>type;
	ans=0x3f3f3f;
	for(int i=1;i<=n;i++)p[i]=read();
	for(int u,v,i=1;i<n;i++){
		u=read();
		v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		dfs(1,0,0,1,0);
		dfs(1,1,p[1],1,0);
		if(ans!=0x3f3f3f)
			cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
