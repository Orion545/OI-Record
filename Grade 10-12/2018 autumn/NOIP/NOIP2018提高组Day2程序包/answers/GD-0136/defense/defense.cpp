#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 300005
using namespace std;
struct jh{int x,y,next;} ljb[2*MAXN];
int i,j,n,m,x,y,a,b,tot,flag,t1,t2;
int poi[MAXN],last[MAXN],lock[MAXN],vis[MAXN],ans;
char type[5];

inline int read() {
	int s=0;
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}

void add(int x,int y) {
	tot++;
	ljb[tot].x=x;
	ljb[tot].y=y;
	ljb[tot].next=last[x];
	last[x]=tot;
}

int dp(int root,int zt) {
	int i,j,y,ans=0;

	
	if (zt==1) {
		//结点必须驻兵 
		ans+=poi[root];
		for (i=last[root]; i; i=ljb[i].next) {
			y=ljb[i].y;
			if (!vis[y]) {
				vis[y]=1;
				if (lock[y]==0) ans+=min(dp(y,1),dp(y,-1));
				if (lock[y]==1) ans+=dp(y,1);
				if (lock[y]==-1) ans+=dp(y,-1);
				vis[y]=0;
			}
		}
	}

	if (zt==-1) 
		for (i=last[root]; i; i=ljb[i].next) {
			y=ljb[i].y;
			if (!vis[y]) {
				vis[y]=1;
				ans+=dp(y,1);
				vis[y]=0;
			}
		}
	return ans;
}


int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	n=read(); m=read();
	scanf("%s",&type);
	
	for (i=1; i<=n; i++) 
		poi[i]=read();
	for (i=1; i<=n-1; i++) {
		x=read(); y=read();
		add(x,y);
		add(y,x);
	}
	for (i=1; i<=m; i++) {
		memset(lock,0,sizeof(lock));
		memset(vis,0,sizeof(vis));
		a=read(); x=read();
		b=read(); y=read();
		
		if (!x && !y) { 
			for (flag=0,j=last[a]; j; j=ljb[j].next)
				if (ljb[j].y==b) { flag=1; break; }
			if (flag) { printf("%d\n",-1); continue; }
		}
		//判断-1情况 
		if (x) lock[a]=x; else {
			lock[a]=-1;
			for (j=last[a]; j; j=ljb[j].next) lock[ljb[j].y]=1;
		}
		if (y) lock[b]=x; else {
			lock[b]=-1;
			for (j=last[b]; j; j=ljb[j].next) lock[ljb[j].y]=1;
		}
		if (lock[1]==0) {
			vis[1]=1;
			t1=dp(1,1);
			memset(vis,0,sizeof(vis));
			vis[1]=1;
			t2=dp(1,-1);
			ans=min(t1,t2);
		}
		else {
			vis[1]=1;
			ans=dp(1,lock[1]);
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
	
