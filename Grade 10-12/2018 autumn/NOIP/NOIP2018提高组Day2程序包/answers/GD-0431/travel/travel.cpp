#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#define rep(i,st,ed) for (register int i=st;i<=ed;++i)

const int INF=0x3f3f3f3f;
const int N=20005;

struct edge {int x,y,next;} e[N*2];

int ans[N],wjp[N],rec[N],stack[N],top;
int ls[N],edCnt=1;

bool used[N],vis[N],flag;

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void add_edge(int x,int y) {
	e[++edCnt]=(edge) {x,y,ls[x]}; ls[x]=edCnt;
	e[++edCnt]=(edge) {y,x,ls[y]}; ls[y]=edCnt;
}

void dfs(int now,int from) {
	ans[++ans[0]]=now;
	std:: vector <int> vec;
	for (int i=ls[now];i;i=e[i].next) {
		if (e[i].y==from||used[i]) continue;
		vec.push_back(e[i].y);
	}
	std:: sort(vec.begin(),vec.end());
	for (int i=0;i<vec.size();++i) {
		dfs(vec[i],now);
	}
}

void pd(int now,int from) {
	if (flag) return ;
	if (vis[now]) {
		int y=0; flag=true;
		while (now!=e[y].x) {
			y=stack[top--];
			rec[++rec[0]]=y;
		}
		return ;
	}
	vis[now]=true;
	for (int i=ls[now];i;i=e[i].next) {
		if (e[i].y==from) continue;
		if (flag) return ;
		stack[++top]=i;
		pd(e[i].y,now);
		top--;
	}
}

int main(void) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	rep(i,1,m) {
		int x=read(),y=read();
		add_edge(x,y);
	}
	if (m==n-1) {
		dfs(1,0);
		rep(i,0,ans[0]) wjp[i]=ans[i];
	} else {
		rep(i,1,n) wjp[i]=INF; wjp[0]=n;
		pd(1,0);
		rep(i,1,rec[0]) {
			ans[0]=0;
			used[rec[i]]=used[rec[i]^1]=true;
			dfs(1,0);
			used[rec[i]]=used[rec[i]^1]=false;
			rep(j,1,ans[0]) {
				if (ans[j]==wjp[j]) continue;
				if (ans[j]<wjp[j]) {
					rep(k,0,ans[0]) wjp[k]=ans[k];
				}
				break;
			}
		}
	}
	rep(i,1,n) printf("%d ", wjp[i]);
	return 0;
}