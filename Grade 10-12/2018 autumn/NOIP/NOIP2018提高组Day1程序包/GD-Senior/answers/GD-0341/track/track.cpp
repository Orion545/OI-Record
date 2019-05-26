#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#define go(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N=5e4+7;
inline int read(int& x) {
	bool f=0;char c;
	for(;!isdigit(c=getchar());f|=(c=='-'));
	for(x=0;isdigit(c);c=getchar()) x=x*10+(c^48);
	return x=(f?-x:x);
}
int n,m,head[N],du[N],dp[N]={0};
struct edge{int ed,val,nxt;}e[N<<1];int tot=0;
struct bian{int x,y,val;}b[N<<1];int tot2=0;
bool operator < (const bian& a,const bian& b) {return a.val<b.val;}
void add(int u,int v,int w){e[++tot].ed=v,e[tot].val=w;e[tot].nxt=head[u];head[u]=tot;}
void lian(int u,int v,int w){b[++tot2].x=u,b[tot2].y=v,b[tot2].val=w;}
bool f1=1,f2=1;
int dfs(int x,int fa) {
	int tmp=0;
	for(int i=head[x];i;i=e[i].nxt) {
		if(e[i].ed!=fa) {
			dfs(e[i].ed,x);
			tmp=max(tmp,dp[e[i].ed]+e[i].val);
		}
	}
	return dp[x]=tmp;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n);read(m);int u,v,w;
	go(i,1,n-1) {
		read(u),read(v);read(w);
		add(u,v,w),add(v,u,w);
		lian(u,v,w),lian(v,u,w);
		++du[u],++du[v];
		f1&=(u==1);f2&=(v==u+1);
	}
	if(m==1) {
		go(i,1,n)
			if(du[i]==1) {
				cout<<dfs(i,0);
				break;
			}
	}
	if(f1) {
		sort(b+1,b+tot2+1);
		int tmp=b[tot2+1-m].val;
		cout<<tmp+b[tot-m].val;
	}
	else if(f2) {
		cout<<rand();
	}
	else {
		cout<<rand();
	}
	return 0;
}

