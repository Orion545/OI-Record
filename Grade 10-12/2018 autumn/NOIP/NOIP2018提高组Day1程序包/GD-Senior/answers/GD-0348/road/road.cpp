#include <bits/stdc++.h>
#define FR first
#define SE second

using namespace std;

typedef pair<int,int> pr;

int fir[100005];

namespace SGT {

int addv[400000],minn[400000],minv[400000];

inline void pushdown(int o) {
  if (addv[o]) {
  	minn[o*2]-=addv[o];minn[o*2+1]-=addv[o];
  	addv[o*2]+=addv[o];addv[o*2+1]+=addv[o];
  	addv[o]=0;
  }
}

inline void pushup(int o) {
  minn[o]=min(minn[o*2],minn[o*2+1]);
  minv[o]=(minn[o*2]<minn[o*2+1])?minv[o*2]:minv[o*2+1];
}

void build(int l,int r,int o) {
  if (l==r) {
  	minn[o]=fir[l];
  	minv[o]=l;
  }
  else {
  	int m=((l+r)>>1);
  	build(l,m,o*2);
  	build(m+1,r,o*2+1);
  	pushup(o);
  }
}

void update(int l,int r,int o,int lx,int rx,int p) {
  if (l>=lx&&r<=rx) {
  	addv[o]+=p;minn[o]-=p;
  }
  else {
  	pushdown(o);
  	int m=((l+r)>>1);
  	if (m>=lx) update(l,m,o*2,lx,rx,p);
  	if (m<rx) update(m+1,r,o*2+1,lx,rx,p);
  	pushup(o);
  }
}

pr query(int l,int r,int o,int lx,int rx) {
  if (l>=lx&&r<=rx) return pr(minn[o],minv[o]);
  else {
  	pushdown(o);
  	int m=((l+r)>>1);
  	if (m>=rx) return query(l,m,o*2,lx,rx);
  	if (m<lx) return query(m+1,r,o*2+1,lx,rx);
  	return min(query(l,m,o*2,lx,rx),query(m+1,r,o*2+1,lx,rx));
  }
}

}

int n,ans;

void solve(int l,int r) {
  if (l>r) return;
  pr t=SGT::query(1,n,1,l,r);
  int x=t.SE,y=t.FR;
  ans+=y;
  SGT::update(1,n,1,l,r,y);
  solve(l,x-1);
  solve(x+1,r);
}

int main() {
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&fir[i]);
  SGT::build(1,n,1);
  solve(1,n);
  printf("%d\n",ans);
  return 0;
}
