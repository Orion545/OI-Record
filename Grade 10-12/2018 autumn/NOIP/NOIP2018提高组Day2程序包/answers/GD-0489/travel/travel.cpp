#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#include<fstream>
#include<cstring>

int n,m;
bool visit[6001];
int head[6001],tot,rd[6001];
int ans[6001],tail;
bool isround[6001];
int round_start;
int tmp=9999,tmp2=9999,tmp3,cutpoint1,cutpoint2;
bool first_reach,find_cut;

struct node{
	int u,v;
}p[6001];

struct edge{
	int to,next;
}e[12001];

bool cmp(node a,node b) {
	if(a.u==b.u) return a.v>b.v;
	return a.u>b.u;
}

void build(int x,int y) {
	tot++;
	e[tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}

void dfs(int x) {
	visit[x]=1;
	tail++;
	ans[tail]=x;
	for(int i=head[x];i;i=e[i].next) {
		int y=e[i].to;
		if(!visit[y]) {
			dfs(y);
		}
	}
}

void cut_round(int x,int fa);

void dfs2(int x) {
	visit[x]=1;
	tail++;
	ans[tail]=x;
	if(isround[x]==true && first_reach==false) {
		first_reach=true;
		for(int i=head[x];i;i=e[i].next) {
			int y=e[i].to;
			if(isround[y]) {
				if(y<tmp) {
					tmp2=tmp;
					tmp=y;
				}
				else if(y<tmp2) tmp2=y;
			}
		}
		tmp3=x;
		cut_round(tmp,x);
	}
	for(int i=head[x];i;i=e[i].next) {
		int y=e[i].to;
		if((x==cutpoint1 && y==cutpoint2) || (x==cutpoint2 & y==cutpoint1)) continue;
		if(!visit[y]) dfs2(y);
	}
}

void cut_round(int x,int fa) {
	for(int i=head[x];i;i=e[i].next) {
		int y=e[i].to;
		if(!isround[y] || y==fa) continue;
		if(y>tmp2 || y==tmp3) {
			cutpoint1=x;
			cutpoint2=y;
			find_cut=true;
		}
		if(find_cut) return;
		cut_round(y,x);
	}
}

void find_round(int x,int fa) {
	visit[x]=1;
	for(int i=head[x];i;i=e[i].next) {
		int y=e[i].to;
		if(y==fa) continue;
		if(visit[y]) round_start=y;
		if(round_start!=0) break;
		find_round(y,x);
	}
	if(visit[round_start] && round_start!=0) isround[x]=true;
	visit[x]=0;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&p[i].u,&p[i].v);
		if(p[i].u>p[i].v) swap(p[i].u,p[i].v);
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++) {
		build(p[i].u,p[i].v);
		build(p[i].v,p[i].u);
	}
	if(m==n-1) {
		dfs(1);
		for(int i=1;i<=tail;i++) printf("%d ",ans[i]);
	}
	else {
		find_round(1,0);
		dfs2(1);
		for(int i=1;i<=tail;i++) printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
