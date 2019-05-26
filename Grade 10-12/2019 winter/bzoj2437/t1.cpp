#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n,m,q,cnt,cnte=-1,first[2010];
struct edge{
	int to,next;
}a[800010];
inline void add(int u,int v){
//	cout<<"add "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
int x[50][50],num[50][50],vis[2010],pre[2010],del[2010],val[2010],cur,re[2010];
bool dfs(int u){
	int i,v;
//	cout<<"dfs "<<u<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(del[v]||vis[v]==cur) continue;
		vis[v]=cur;
		if(pre[v]==-1||dfs(pre[v])){
//			cout<<"	try "<<u<<' '<<v<<"	success "<<1<<'\n';
			pre[v]=u;pre[u]=v;
			return 1;
		}
	}
//	cout<<"finish dfs "<<u<<' '<<0<<'\n';
	return 0;
}
const int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,j,k,t1,t2,s1,s2;char ss[2010];
	for(i=1;i<=n;i++){
		scanf("%s",ss);
		for(j=1;j<=m;j++){
			if(ss[j-1]=='X'||ss[j-1]=='.') x[i][j]=1;
			else x[i][j]=0;
			if(ss[j-1]=='.') s1=i,s2=j;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(x[i][j]==0&&(abs(i-s1)+abs(j-s2))&1) num[i][j]=++cnt;
			if(x[i][j]==1&&(abs(i-s1)+abs(j-s2))%2==0) num[i][j]=++cnt;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(num[i][j]==0) continue;
//			cout<<"check num "<<i<<' '<<j<<' '<<num[i][j]<<'\n';
			for(k=0;k<4;k++){
				if(num[i+dx[k]][j+dy[k]]) add(num[i][j],num[i+dx[k]][j+dy[k]]);
			}
		}
	}
	memset(pre,-1,sizeof(pre));
	for(i=1;i<=cnt;i++){
		if(pre[i]==-1){
			cur++;
			dfs(i);
		}
	}
//	cout<<"beginning\n";
//	for(i=1;i<=cnt;i++) cout<<i<<' '<<pre[i]<<'\n';
	q=read();q*=2;
	for(i=1;i<=q;i++){
		if(pre[num[s1][s2]]!=-1){
			t1=pre[num[s1][s2]];
			pre[num[s1][s2]]=pre[t1]=-1;
			del[num[s1][s2]]=1;
			cur++;
			re[i]=dfs(t1);
		}
		else{
			del[num[s1][s2]]=1;
			re[i]=1;
		}
		s1=read();s2=read();
	}
	int ans=0;
	for(i=1;i<q;i+=2){
		if(!re[i]&&!re[i+1]) ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<q;i+=2){
		if(!re[i]&&!re[i+1]){
			printf("%d\n",(i+1)>>1);
		}
	}
}
