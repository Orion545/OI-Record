#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
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
int son[10000010][4],fail[10000010],cnt,n,m;bool vis[10000010];
char t[10000010],s[100010][110];
void insert(int num){
	int i,len=strlen(s[num]),cur=0,tmp;
	for(i=0;i<len;i++){
		if(s[num][i]=='E') tmp=0;
		if(s[num][i]=='W') tmp=1;
		if(s[num][i]=='N') tmp=2;
		if(s[num][i]=='S') tmp=3;
		if(!son[cur][tmp]) son[cur][tmp]=++cnt;
		cur=son[cur][tmp];
	}
}
int query(int num){
	int i,len=strlen(s[num]),cur=0,tmp,re=0;
	for(i=0;i<len;i++){
		if(s[num][i]=='E') tmp=0;
		if(s[num][i]=='W') tmp=1;
		if(s[num][i]=='N') tmp=2;
		if(s[num][i]=='S') tmp=3;
		cur=son[cur][tmp];
		if(vis[cur]) re=i+1;
//		cout<<i<<' '<<cur<<' '<<vis[cur]<<'\n';
	}
	return re;
}
queue<int>q;
void AC(){
	int i,u,v;
	for(i=0;i<4;i++){
		if(!son[0][i]) continue;
		q.push(son[0][i]);fail[son[0][i]]=0;
	}
	while(!q.empty()){
		u=q.front();q.pop();
		for(i=0;i<4;i++){
			v=son[u][i];
			if(!v) son[u][i]=son[fail[u]][i];
			else fail[v]=son[fail[u]][i],q.push(v);
		}
	}
}
void getans(){
	int i,cur=0,tmp;
	for(i=0;i<n;i++){
		if(t[i]=='E') tmp=0;
		if(t[i]=='W') tmp=1;
		if(t[i]=='N') tmp=2;
		if(t[i]=='S') tmp=3;
		cur=son[cur][tmp];tmp=cur;
		while((vis[tmp]==0)&&tmp) vis[tmp]=1,tmp=fail[tmp];
	}
}
int main(){
//	freopen("2.in","r",stdin);
//	freopen("bzoj4327.out","w",stdout);
	n=read();m=read();int i;
	scanf("%s",t);
	for(i=1;i<=m;i++) scanf("%s",s[i]),insert(i);
	AC();getans();
	for(i=1;i<=m;i++) printf("%d\n",query(i));
}
