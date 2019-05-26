#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=25005,inf=0x7fffffff;

int n,a[N],b[N],tot,dis[N],pos[N];
bool vis[N];

bool cmp(int x,int y) {return dis[x]<dis[y];}
void chk_min(int &x,int y) {x=y<x?y:x;}

void solve() {
	n=read();tot=0;
	fo(i,0,25000) vis[i]=0;
	fo(i,1,n) {
		int x=read();
		if (!vis[x]) a[++tot]=x;
		vis[x]=1;
	}
	n=tot;
	sort(a+1,a+n+1);
	fo(i,0,a[1]-1) dis[i]=inf;dis[0]=0;
	int cnt=1;
	fo(i,2,n) {
		if (dis[a[i]%a[1]]<=a[i]) continue;
		cnt++;
		fo(j,0,a[1]-1) vis[j]=0;
		fo(j,0,a[1]-1)
			if (!vis[j]) {
				int x=j;tot=0;
				do {
					vis[b[++tot]=x]=1;
					(x+=a[i])%=a[1];	
				} while (x!=j);
				fo(k,1,tot-1) if (dis[b[k]]!=inf) chk_min(dis[b[k+1]],dis[b[k]]+a[i]);
				if (dis[b[tot]]!=inf) chk_min(dis[b[1]],dis[b[tot]]+a[i]);
				fo(k,1,tot-1) if (dis[b[k]]!=inf) chk_min(dis[b[k+1]],dis[b[k]]+a[i]);
				if (dis[b[tot]]!=inf) chk_min(dis[b[1]],dis[b[tot]]+a[i]);
			}
	}
	printf("%d\n",cnt);
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(int ty=read();ty;ty--) solve();
	return 0;
}
