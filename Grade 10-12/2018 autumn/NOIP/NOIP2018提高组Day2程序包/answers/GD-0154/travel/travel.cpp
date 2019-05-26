#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 5010
#define P(a) putchar(a)
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
struct note{
	int to,next;
}edge[N<<1];
int tot,head[N];
bool bz[N][N];
bool bz1[N][N];
int i,j,k,l,n,m;
int u,v;
int ans[N],zs,Ans[N];
int du[N];
int map[N][N],fa[N];
int c[N][2],cnt;
int vis1[N],CNT;
bool vis[N];
int read(){
	int fh=0,rs=0;char ch=0;
	while((ch<'0'||ch>'9')&&(ch^'-'))ch=getchar();
	if(ch=='-')fh=1,ch=getchar();
	while(ch>='0'&&ch<='9')rs=(rs<<3)+(rs<<1)+(ch^'0'),ch=getchar();
	return fh?-rs:rs;
}
void write(int x){
	if(x>9)write(x/10);
	P(x%10+'0');
}
void lb(int x,int y){
	edge[++tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
	du[y]++;
}
void dg(int x){
	int i;
	vis[x]=1;
	ans[++zs]=x;
	fo(i,1,map[x][0]){
		if(fa[x]==map[x][i])continue;
		if(vis[map[x][i]])continue;
		fa[map[x][i]]=x;
		lb(x,map[x][i]);
		dg(map[x][i]);
	}
}
void dg1(int x){
	int i;
	vis[x]=1;
	fo(i,1,map[x][0]){
		if(map[x][i]==fa[x])continue;
		if(vis[map[x][i]]&&!bz1[x][map[x][i]]&&!bz1[map[x][i]][x]){
			int w=x;
			while(w^map[x][i]){
				cnt++;
				c[cnt][0]=w;
				c[cnt][1]=fa[w];
				w=fa[w];
			}
			cnt++;
			c[cnt][0]=x;
			c[cnt][1]=map[x][i];
			bz1[x][map[x][i]]=bz1[map[x][i]][x]=1;
		}else
		if(!vis[map[x][i]]){
			fa[map[x][i]]=x;
			dg1(map[x][i]);
		}
	}
}
void dg2(int x){
	int i;
	Ans[++zs]=x;
	vis1[x]=CNT;
	fo(i,1,map[x][0]){
		if(!bz[x][map[x][i]])continue;
		if(vis1[map[x][i]]==CNT)continue;
		dg2(map[x][i]);
	}
}
bool compa(){
	int i;
	fo(i,1,n){
		if(ans[i]<Ans[i])return 0;
		if(ans[i]>Ans[i])return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	fo(i,1,m){
		u=read(),v=read();
		bz[u][v]=1;
		bz[v][u]=1;
	}
	fo(i,1,n){
		fo(j,1,n)if(bz[i][j])
			map[i][++map[i][0]]=j;
	}
	dg(1);
	if(m==n-1){
		fo(i,1,n)write(ans[i]),P(' ');
		return 0;
	}
	memset(vis,0,sizeof(vis));
	memset(fa,0,sizeof(fa));
	cnt=0;
	dg1(1);
	fo(i,1,cnt){
		bz[c[i][0]][c[i][1]]=bz[c[i][1]][c[i][0]]=0;
		zs=0;
		CNT++;
		dg2(1);
		if(compa()){
			fo(j,1,n)ans[j]=Ans[j];
		}
		bz[c[i][0]][c[i][1]]=bz[c[i][1]][c[i][0]]=1;
	}
	fo(i,1,n)write(ans[i]),P(' ');
	return 0;
}
