#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,k,A,B,first[1010],dis[1010],vis[1010],cnte=1,ans=0,maxf=0;
struct edge{
	int to,next,w,cap;
}a[1000010];
inline void add(int u,int v,int w,int cap){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<' '<<cap<<'\n';
	a[++cnte]=(edge){v,first[u],w,cap};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],-w,0};first[v]=cnte;
}
deque<int>q;
bool spfa(int s,int t){
//	cout<<"********begin spfa\n";
	int i,u,v;
	for(i=s;i<=t;i++) dis[i]=-1,vis[i]=0;
	dis[t]=0;vis[t]=1;q.push_back(t);
	while(!q.empty()){
		u=q.front();q.pop_front();vis[u]=0;
//		cout<<"	bfs "<<u<<' '<<dis[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
//			cout<<"		try "<<v<<' '<<a[i^1].cap<<' '<<a[i^1].w<<'\n';
			if(!a[i^1].cap) continue;
			if(~dis[v]&&(dis[v]<=dis[u]+a[i^1].w)) continue;
			dis[v]=dis[u]+a[i^1].w;
			if(!vis[v]){
				vis[v]=1;
				if(!q.empty()&&(dis[v]<dis[q.front()])) q.push_front(v);
				else q.push_back(v);
			}
		}
	}
	return ~dis[s];
}
int dfs(int u,int t,int lim){
	if(u==t||!lim){return lim;}
	int i,v,f,flow=0;vis[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		if(~dis[v]&&dis[v]==dis[u]-a[i].w&&(f=dfs(v,t,min(a[i].cap,lim)))){
			a[i].cap-=f;
			a[i^1].cap+=f;
			flow+=f;
			lim-=f;
			ans+=a[i].w*f;
			if(!lim){
				vis[u]=0;
				return flow;
			}
		}
	}
	dis[u]=-1;
	return flow;
}
void mcmf(int s,int t){
	while(spfa(s,t)){
		vis[t]=1;
		while(vis[t]){
			memset(vis,0,sizeof(vis));
			maxf+=dfs(s,t,1e9);
		}
	}
}
int mp[110][110],ma[110][110],mb[110][110],dx[8],dy[8],d[110][110],ql[10010],qr[10010],in[110][110];
void solve(int num,int opx,int opy){
	int i,j,x,y,tx,ty,head=0,tail=1;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if(mp[i][j]==-1) in[i][j]=1;
		else in[i][j]=0;
		d[i][j]=1e9;
	}
//	for(i=1;i<=n;i++){
//		cout<<'	';
//		for(j=1;j<=m;j++) cout<<mp[i][j]<<' ';
//		cout<<'\n';
//	}
	ql[0]=opx;qr[0]=opy;in[opx][opy]=1;d[opx][opy]=0;
	while(head<tail){
		x=ql[head];y=qr[head];head++;
//		cout<<"	bfs "<<x<<' '<<y<<'\n';
		for(i=0;i<8;i++){
			tx=x+dx[i];ty=y+dy[i];
//			cout<<"		try "<<' '<<i<<' '<<dx[i]<<' '<<dy[i]<<' '<<tx<<' '<<ty<<' '<<in[tx][ty]<<'\n';
			if(tx<1||tx>n||ty<1||ty>m||in[tx][ty]) continue;
			d[tx][ty]=d[x][y]+1;
			in[tx][ty]=1;
			ql[tail]=tx;qr[tail]=ty;
			tail++;
		}
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if(mb[i][j]<=k||d[i][j]>=40) continue;
		
		add(num,mb[i][j],d[i][j],1);
	}
//	for(i=1;i<=n;i++){
//		cout<<'	';
//		for(j=1;j<=m;j++) cout<<d[i][j]<<' ';
//		cout<<'\n';
//	}
}
int main(){
	memset(first,-1,sizeof(first));
	memset(mp,0,sizeof(mp));
	n=read();m=read();k=read();A=read();B=read();int i,j,t2,t1;char s[110];
	dx[1]=dx[3]=dy[5]=dy[7]=A;
	dx[0]=dx[2]=dy[4]=dy[6]=-A;
	dy[0]=dx[4]=dy[1]=dx[5]=B;
	dy[2]=dx[6]=dy[3]=dx[7]=-B;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			if(s[j]=='*') mp[i][j+1]=-1;
		}
	}
	for(i=1;i<=k;i++){
		t1=read();t2=read();
		ma[t1][t2]=i;
		add(0,i,0,1);
	}
	for(i=1;i<=k;i++){
		t1=read();t2=read();
		mb[t1][t2]=i+k;
		add(i+k,2*k+1,0,1);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(ma[i][j]>=1&&ma[i][j]<=k) 
				solve(ma[i][j],i,j);
		}
	}
	
	mcmf(0,2*k+1);
	for(i=2;i<=cnte;i++){
		if(a[i].to==0&&a[i^1].cap!=0){
			puts("-1");return 0;
		}
		if(a[i].to==2*k+1&&a[i].cap!=0){
			puts("-1");return 0;
		}
	}
	cout<<ans<<'\n';
}
