#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
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
int n,first[100010],cnte,mindep[100010],tmp[100010],cnt;
struct edge{
	int to,next;
}a[100010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
void dfs(int u){
	int i;
//	cout<<"dfs "<<u<<'\n';
	for(i=first[u];~i;i=a[i].next) dfs(a[i].to);
	cnt=0;
	for(i=first[u];~i;i=a[i].next) tmp[++cnt]=mindep[a[i].to];
	if(!cnt){mindep[u]=0;return;}
	sort(tmp+1,tmp+cnt+1);
	for(i=2;i<=cnt;i++) if(tmp[i]<=tmp[i-1]) tmp[i]=tmp[i-1]+1;
	mindep[u]=tmp[cnt]+1;
//	cout<<"return "<<u<<' '<<cnt<<' '<<mindep[u]<<'\n';
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1;
	for(i=2;i<=n;i++) t1=read(),add(t1,i);
	dfs(1);
	printf("%d\n",mindep[1]);
}
