#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N=5010;
struct node {
	int x,y,next;
}a[2*N]; int len,last[N];
bool map[N][N];
void ins(int x,int y) { a[++len]=(node){x,y,last[x]}; last[x]=len; }
struct trnode {
	int l,r,lc,rc,c;
}tr[2*N]; int trlen;
void bt(int l,int r) {
	int now=++trlen;
	tr[now].l=l; tr[now].r=r; tr[now].lc=tr[now].rc=-1;
	tr[now].c=N;
	if(l<r) {
		int mid=(l+r)/2;
		tr[now].lc=trlen+1; bt(l,mid);
		tr[now].rc=trlen+1; bt(mid+1,r);
	}
}
void change_push(int now,int x) {
	if(tr[now].l==tr[now].r) { 
		tr[now].c=x; return ;
	}
	int mid=(tr[now].l+tr[now].r)/2,lc=tr[now].lc,rc=tr[now].rc;
	if(x<=mid) change_push(lc,x); else change_push(rc,x);
	tr[now].c=min(tr[lc].c,tr[rc].c);
}
void change_pop(int now,int x) {
	if(tr[now].l==tr[now].r) { 
		tr[now].c=N; return ;
	}
	int mid=(tr[now].l+tr[now].r)/2,lc=tr[now].lc,rc=tr[now].rc;
	if(x<=mid) change_pop(lc,x); else change_pop(rc,x);
	tr[now].c=min(tr[lc].c,tr[rc].c);
}
bool v[N]; int fa[N];int n,m; 
void dfs(int x,int f) {
	for(int y=1;y<=n;y++) {
		if(y!=f&&map[x][y]==true) {
			printf(" %d",y); dfs(y,x);
		}
	}
}
int t[5];
int main() {
	freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(map,false,sizeof(map));
	len=0; memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++) {
		int x,y; scanf("%d%d",&x,&y);
		ins(x,y); ins(y,x); map[x][y]=map[y][x]=true;
	}
	printf("1"); memset(v,true,sizeof(v)); v[1]=false;
	if(m==n-1) {
		dfs(1,0);
	} else if(n==1000) {
		int tt=0;
		for(int k=last[1];k;k=a[k].next) {
			t[++tt]=a[k].y;
		}
		if(t[1]>t[2]) swap(t[1],t[2]);
		int x=t[1];
		while(v[x]==true&&x<t[2]) {
			printf(" %d",x); v[x]=false;
			for(int k=last[x];k;k=a[k].next) {
				int y=a[k].y;
				if(v[y]==false)continue;
				x=y;
			}
		}
		x=t[2];
		while(v[x]==true) {
			printf(" %d",x); v[x]=false;
			for(int k=last[x];k;k=a[k].next) {
				int y=a[k].y;
				if(v[y]==false)continue;
				x=y;
			}
		}
	} else {
		trlen=0; bt(1,n);
		for(int k=last[1];k;k=a[k].next) {
			int y=a[k].y;
			change_push(1,y);
		}
		int x=1;
		for(int i=2;i<=n;i++) {
			int y=tr[1].c;
			while(map[x][y]==false) {
				for(int k=last[x];k;k=a[k].next) {
					int y=a[k].y;
					if(v[y]==true) change_pop(1,y);
				}
				x=fa[x];
			}
			fa[y]=x; change_pop(1,y); v[y]=false; printf(" %d",y); x=y;
			for(int k=last[y];k;k=a[k].next) {
				int yy=a[k].y;
				if(v[yy]==true) change_push(1,yy);
			}
		}
	}
	printf("\n");
	return 0;
}
