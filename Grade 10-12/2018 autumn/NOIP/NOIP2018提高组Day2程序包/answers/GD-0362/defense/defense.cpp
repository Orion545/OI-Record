#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
const int N=300010;
struct node {
	int x,y,next;
}a[2*N]; int len,last[N];
void ins(int x,int y) { a[++len]=(node){x,y,last[x]}; last[x]=len; }
int p[N]; ll f[N][3];
int A,B,X,Y;
char s[5];
void Dp(int x,int fa) {
	for(int k=last[x];k;k=a[k].next) {
		int y=a[k].y;
		if(y!=fa) {
			Dp(y,x);
			f[x][0]+=f[y][1];
			f[x][1]+=min(f[y][0],f[y][1]);
		}
	}
}
int main() {
	freopen("defense.in","r",stdin); freopen("defense.out","w",stdout);	
	int n,m; scanf("%d%d%s",&n,&m,s+1);
	len=0; memset(last,0,sizeof(last));
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<n;i++) {
		int x,y; scanf("%d%d",&x,&y);
		ins(x,y); ins(y,x);
	}
	while(m--) {
		scanf("%d%d%d%d",&A,&X,&B,&Y);
		memset(f,63,sizeof(f));
		for(int i=1;i<=n;i++) {
			f[i][1]=ll(p[i]);
			f[i][0]=0; 
		}
		f[A][1-X]=1e11;
		f[B][1-Y]=1e11;
		Dp(1,0);
		ll ans=min(f[1][0],f[1][1]);
		if(ans>=1e11) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
