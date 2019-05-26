#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector> 
#include<cstdlib>
#define ll long long
#define end DEEP_DARK_FANTASY
using namespace std;
int son[30010][2],fail[30010],end[30010],ins[30010],vis[30010],cnt;
void insert(char s[]){
	int cur=0,i,tmp,len=strlen(s);
//	cout<<"insert "<<s<<' '<<cnt<<'\n';
	for(i=0;i<len;i++){
		tmp=s[i]-'0';
		if(!son[cur][tmp]) son[cur][tmp]=++cnt;
		cur=son[cur][tmp];
	}
	end[cur]=1;
}
void AC(){
	int q[30010],head=0,tail=0,i,u,v;
	for(i=0;i<2;i++){
		if(!son[0][i]) continue;
		q[tail++]=son[0][i];fail[son[0][i]]=0;
	}
	while(head<tail){
		u=q[head++];
		for(i=0;i<2;i++){
			v=son[u][i];
			if(!v) son[u][i]=son[fail[u]][i];
			else fail[v]=son[fail[u]][i],q[tail++]=v,end[v]|=end[fail[v]];
		}
	}
}
void dfs(int u){
//	cout<<"dfs "<<u<<'\n';
	int i,v;vis[u]=ins[u]=1;
	for(i=0;i<2;i++){
		v=son[u][i];if(end[v]) continue;
//		cout<<"	to "<<i<<' '<<v<<" from "<<u<<'\n';
		if(!vis[v]) dfs(v);
		else if(ins[v]){
			puts("TAK");exit(0);
		}
	}
//	cout<<"end of dfs "<<u<<'\n';
	ins[u]=0;
}
int n;char s[30010];
int main(){
	scanf("%d",&n);int i;
	for(i=1;i<=n;i++) scanf("%s",s),insert(s);
	AC();dfs(0);
	puts("NIE");
}
