#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 50005
#define INF -0x1777777
using namespace std;
struct jh{int x,y,z,next;} ljb[MAXN*2];
int n,m,i,x,y,z,ans,tot;
int last[MAXN];

void add(int x,int y,int z) {
	tot++;
	ljb[tot].x=x;
	ljb[tot].y=y;
	ljb[tot].z=z;
	ljb[tot].next=last[x];
	last[x]=tot;
}
int bfs(int root) {
	int i,j,head,tail;
	int t[MAXN],s[MAXN],dis[MAXN];
	head=1,tail=1;
	memset(t,0,sizeof(t));
	memset(dis,0,sizeof(dis));
	memset(s,0,sizeof(s));
	s[1]=root;
	while (head<=tail) {
		i=last[s[head]];
		t[s[head]]=1;
		while (i) {
			j=ljb[i].y;
			if (!t[j]) {
				dis[j]=dis[s[head]]+ljb[i].z;
				tail++;
				s[tail]=j;
			}
			i=ljb[i].next;
		}
		head++;
	}
	int ans=0;
	for (i=1; i<=n; i++) 
		ans=max(ans,dis[i]);
	return ans;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1; i<=n-1; i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	
	if (m==1) {
		ans=0;
		for (i=1; i<=n; i++)
			ans=max(ans,bfs(i));
		printf("%d\n",ans);
	}
	
	return 0;
}
