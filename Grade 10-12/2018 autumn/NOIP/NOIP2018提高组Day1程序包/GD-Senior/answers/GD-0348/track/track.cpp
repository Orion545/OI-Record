#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int t,v,next;
  Edge() {}
  Edge(int a,int b,int c):t(a),v(b),next(c) {}
};

Edge e[100005];
int head[50005];

int now,sum;
int num[50005],f[50005];

bool vis[50005];

int getsum(int n,int id) {
  for(int i=0;i<=n;i++) vis[i]=0;
  vis[id]=1;
  int lx=1,ans=0;
  for(int i=n;i>0;i--)
    if (!vis[i]) {
    	if (num[i]>=now) {
    		vis[i]=1;
    		ans++;
    		continue;
    	}
    	while (lx<i&&(vis[lx]||num[i]+num[lx]<now)) lx++;
    	if (lx>=i) continue;
    	vis[i]=vis[lx]=1;
    	ans++;
    }
  return ans;
}

int calc(int n) {
  sort(num+1,num+n+1);
  int s=getsum(n,0);
  sum+=s;
  int l=0,r=n;
  while (l<r) {
  	int m=((l+r)>>1)+1;
  	if (getsum(n,m)>=s) l=m; else r=m-1;
  }
  return num[l];
}

void dfs(int x,int fa) {
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) dfs(e[i].t,x);
  int cnt=0;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) num[++cnt]=f[e[i].t]+e[i].v;
  f[x]=calc(cnt);
}

int check(int m) {
  now=m;sum=0;
  dfs(1,0);
  return sum;
}

int main() {
  freopen("track.in","r",stdin);
  freopen("track.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  int sum=0;
  for(int i=1;i<n;i++) {
  	int x,y,z;
  	scanf("%d%d%d",&x,&y,&z);
  	e[2*i-1]=Edge(y,z,head[x]);
  	head[x]=2*i-1;
  	e[2*i]=Edge(x,z,head[y]);
  	head[y]=2*i;
  	sum+=z;
  }
  int l=0,r=sum;
  while (l<r) {
  	int mid=((l+r)>>1)+1;
  	if (check(mid)>=m) l=mid; else r=mid-1;
  }
  printf("%d\n",l);
  return 0;
}
