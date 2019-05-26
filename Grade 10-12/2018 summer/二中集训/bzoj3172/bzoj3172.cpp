#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define end mafumafu
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
int son[1000010][26],siz[1000010],fail[1000010],cnt,end[210];
void insert(char s[],int num){
	int i,cur=0,tmp,len=strlen(s);
	for(i=0;i<len;i++){
		tmp=s[i]-'a';
		if(!son[cur][tmp]) son[cur][tmp]=++cnt;
		cur=son[cur][tmp];siz[cur]++;
	}
	end[num]=cur;
}
void AC(){
	queue<int>q;int i,u,v;
	for(i=0;i<26;i++){
		if(!son[0][i]) continue;
		q.push(son[0][i]);fail[son[0][i]]=0;
	}
	while(!q.empty()){
		u=q.front();q.pop();
		for(i=0;i<26;i++){
			v=son[u][i];
			if(!v) son[u][i]=son[fail[u]][i];
			else fail[v]=son[fail[u]][i],q.push(v);
		}
	}
}
int first[1000010],sum[1000010],cnte;
struct edge{
	int to,next;
}a[2000010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;sum[u]=siz[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);sum[u]+=sum[v];
	}
}
char s[1000010];
int main(){
	memset(first,-1,sizeof(first));
	int n=read();int i;
	for(i=1;i<=n;i++) scanf("%s",s),insert(s,i);
	AC();
	for(i=1;i<=cnt;i++){
		if(fail[i]) add(i,fail[i]);
	}
	for(i=1;i<=cnt;i++) if(!fail[i]) dfs(i,0);
	for(i=1;i<=n;i++) printf("%d\n",sum[end[i]]);
}
