#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,son[110][30],vis[110][110],lis[11010],cnt,ans[1100010],len,ok[110];
bool dfs(int u1,int u2){
	if(vis[u1][u2]) return 0;
//	cout<<"dfs "<<u1<<' '<<u2<<'\n';
	if(u1==1&&u2==1) return 1;
	vis[u1][u2]=1;
	int i,flag;
	for(i=1;i<=m;i++){
		lis[++cnt]=i;
		flag=dfs(son[u1][i],son[u2][i]);
		if(flag) return 1;
		lis[cnt--]=0;
	}
	return 0;
}
int walk(int u){
	for(int i=1;i<=cnt;i++) u=son[u][lis[i]];
	return u;
}
int main(){
	n=read();m=read();int i,j,flag;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) son[i][j]=read()+1;
	}
	for(i=2;i<=n;i++){
		if(ok[j]) continue;
		memset(vis,0,sizeof(vis));
		memset(lis,0,sizeof(lis));cnt=0;
		flag=dfs(1,i);
		if(!flag){
			puts("[impossible]");return 0;
		}
		for(j=1;j<=cnt;j++) ans[++len]=lis[j];
		for(j=2;j<=n;j++) if(walk(j)==1) ok[j]=1;
	}
	for(i=1;i<=len;i++) putchar(ans[i]+'a'-1);
}
