#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define mp make_pair
using namespace std;
const int dx[9]={0,1,1,1,0,0,-1,-1,-1},dy[9]={0,-1,0,1,-1,1,-1,0,1};
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,r,c,first[2100010],First[2100010],cnt=0,Cnt=0;
int dfn[2100010],low[2100010],num=0;
int s[2100010]={0},top=0;
int belong[2100010],tot=0,dp[2100010],siz[2100010],in[2100010];
bool vis[2100010];
int x[100010],y[100010];
struct edge{
	int from,to,next;
}a[2000010];
struct Edge{
	int to,next;
}e[2000010];
inline void add(int u,int v){
//	cout<<"add "<<u<<ends<<v<<endl;
	a[++cnt]=(edge){u,v,first[u]};first[u]=cnt;
}
inline void Add(int u,int v){
	e[++Cnt]=(Edge){v,First[u]};First[u]=Cnt;
}
map<pair<int,int>,int>m;
void tarjan(int u){
//	cout<<"tarjan "<<u<<endl;
	int i,v;vis[u]=1;
	dfn[u]=low[u]=++num;
	s[++top]=u;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(belong[v]) continue;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++tot;
		while(s[top]!=u){
			belong[s[top]]=tot;
			if(s[top]>r+c) siz[tot]++;
//			qlt[tot].push_back(s[top]);
			s[top--]=0;
		}
		belong[s[top]]=tot;
		if(s[top]>r+c) siz[tot]++;
//		qlt[tot].push_back(s[top]);
		s[top--]=0;
	}
}
int q[2100010],head=0,tail=0;
int main(){
	memset(first,-1,sizeof(first));
	memset(First,-1,sizeof(First));
	int i,t1,t2,t3,t4,j,u,v,ans=0;
	map<pair<int,int>,int>::iterator tmp;
	memset(first,-1,sizeof(first));
	n=read();r=read();c=read();
	for(i=1;i<=n;i++){
		t1=read();t2=read();t3=read();
		x[i]=t1;y[i]=t2;
		m[mp(t1,t2)]=i;
		add(t1,r+c+i);add(t2+r,i+r+c);
		if(t3==1) add(r+c+i,t1);
		if(t3==2) add(r+c+i,r+t2);
		if(t3==3) vis[i]=1;
	}
	for(i=1;i<=n;i++){
		if(!vis[i]) continue;
		t1=x[i];t2=y[i];
		for(j=1;j<=8;j++){
			t3=t1+dx[j];t4=t2+dy[j];
			tmp=m.find(mp(t3,t4));
			if(tmp==m.end()) continue;
			add(r+c+i,r+c+tmp->second);
		}
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=r+c+n;i++) if(!vis[i]) tarjan(i);
//	cout<<"end of tarjan"<<endl;
//	for(i=1;i<=r+c+n;i++) cout<<belong[i]<<ends;
//	for(i=1;i<=tot;i++){
//		for(j=0;j<qlt[i].size();j++) cout<<qlt[i][j]<<ends;
//		cout<<endl;
//	}
	for(i=1;i<=cnt;i++){
		if(!belong[a[i].from]||!belong[a[i].to]) continue;
		if(belong[a[i].from]==belong[a[i].to]) continue;
		Add(belong[a[i].from],belong[a[i].to]);in[belong[a[i].to]]++;
	}
//	cout<<"end of Add\n";
	for(i=1;i<=tot;i++) if(!in[i]) q[tail++]=i,dp[i]=siz[i];
	while(head<tail){
		u=q[head++];
		for(i=First[u];~i;i=e[i].next){
			v=e[i].to;
			dp[v]=max(dp[v],dp[u]+siz[v]);in[v]--;
			if(!in[v]) q[tail++]=v;
		}
	}
	for(i=1;i<=tot;i++) ans=max(ans,dp[i]);
	printf("%d",ans);
}
