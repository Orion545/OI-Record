#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#define N 5005
using namespace std;
int n,m,head[N],nxt[N*2],to[N*2],num,ans[N],t,ye[N],team[N*2],l,r;
bool sign[N*2],vis[N],qaq;
void read(int &x){
	x=0;
	char c;
	int w=1;
	for (c=getchar();c<'0'||c>'9';c=getchar()) if (c=='-') w=-1;
	for (;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
	x*=w;
}
void add(int u,int v){
	num++;
	nxt[num]=head[u];
	head[u]=num;
	to[num]=v;
	num++;
	nxt[num]=head[v];
	head[v]=num;
	to[num]=u;
}
bool cmp(const int a,const int b){
	return (a<b);
}
void check0(int x){
	int tmp[N],r=0;
	vis[x]=true;
	printf("%d ",x);
	for (int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if (!vis[v]){
			vis[v]=true;
			tmp[++r]=v;
		}
	}
	sort(tmp+1,tmp+1+r,cmp);
	for (int i=1;i<=r;++i)
		check0(tmp[i]);
}
void panduan(){
	for (int i=1;i<=n;++i)
		if (ye[i]>ans[i]) return;
	else if (ye[i]<ans[i]) break;
	for (int i=1;i<=n;++i)
		ans[i]=ye[i];
}
void check1(int x){
	int tmp[N],r=0;
	vis[x]=true;
	if (t==n) {panduan();return;}
	for (int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if ((!vis[v])&&(!sign[i])){
			vis[v]=true;
			tmp[++r]=v;
		}
	}
	sort(tmp+1,tmp+1+r,cmp);
	for (int i=1;i<=r;++i){
		ye[++t]=tmp[i];
		check1(tmp[i]);
	}
}
bool BFS(){
	int cnt=1;
	team[++r]=1;
	vis[1]=true;
	while (l<r){
		int u=team[++l];
		for (int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if (!vis[v]){
				vis[v]=true;
				team[++r]=v;
				++cnt;
			}
		}
	}
	if (cnt==n) return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
		ans[i]=5001;
	memset(sign,false,sizeof(sign));
	num=0;
	for (int u,v,i=1;i<=m;++i){
		read(u);
		read(v);
		add(u,v);
	}
	if (m==n-1) check0(1);
	else{
		ye[1]=1;
		for (int i=1;i<num;i+=2){
			l=r=0;
			t=1;
			qaq=false;
			memset(vis,false,sizeof(vis));
			sign[i]=sign[i+1]=true;
			if (BFS()){
						memset(vis,false,sizeof(vis));
						check1(1);
						}
			sign[i]=sign[i+1]=false;
		}
		for (int i=1;i<=n;++i)
			printf("%d ",ans[i]);
	}
	return 0;
}
