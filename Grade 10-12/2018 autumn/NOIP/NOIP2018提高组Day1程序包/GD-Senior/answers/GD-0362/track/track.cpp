#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N=50010;
int n,m; 
struct node {
	int x,y,d,next;
}a[2*N]; int len,last[N];
void ins(int x,int y,int d) {
	a[++len]=(node){x,y,d,last[x]}; last[x]=len;
}
int sum,G;
void dfs_z(int x,int f,int d) {
	if(sum<d) { sum=d; G=x; }
	for(int k=last[x];k;k=a[k].next) {
		int y=a[k].y;
		if(y!=f) dfs_z(y,x,d+a[k].d);
	}
}
bool cmp(int a,int b) { return a>b; } int h[N];
int map[1010][1010],fa[1010][1010],keyi[1010][1010]; bool v[1010][1010],cango[1010][1010];
void dfs(int st,int x,int f,int d) {
	map[st][x]=d; fa[st][x]=f; cango[st][x]=true;
	for(int k=last[x];k;k=a[k].next) {
		int y=a[k].y;
		if(y!=fa[st][x]&&v[x][y]==true) dfs(st,y,x,d+a[k].d);
	}
}
int top; 
bool pd(int t) {
	if(t>m) return true;
	for(int i=1;i<=n;i++) {
		memset(cango[i],false,sizeof(cango[i]));
		dfs(i,i,0,0);
		for(int j=1;j<=n;j++) if(i!=j) {
			if(keyi[i][j]==false) continue;
			if(map[i][j]<top) continue;
			if(cango[i][j]==false) continue;
			int x=j; 
			while(x!=i) {
				v[x][fa[i][x]]=false;
				v[fa[i][x]][x]=false;
				x=fa[i][x];
			} 
			if(pd(t+1)==true) return true;
			x=j;
			if(t==1) { keyi[i][j]=keyi[j][i]=false; }
			while(x!=i) {
				v[x][fa[i][x]]=true;
				v[fa[i][x]][x]=true;
				x=fa[i][x];
			} 
		}
	} return false;
}
int main() {
	freopen("track.in","r",stdin); freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=0; memset(last,0,sizeof(last));
	bool bk=true,bbt=true; int l=1,r=0,mn=10001;
	for(int i=1;i<n;i++) {
		int x,y,d; scanf("%d%d%d",&x,&y,&d);
		ins(x,y,d); ins(y,x,d); r+=d; mn=min(mn,d);
		if(y!=x+1) bk=false;
		if(x!=1) bbt=false;
	}
	if(m==n-1) {
		printf("%d\n",mn); return 0;
	}
	else if(m==1) {
		sum=0; dfs_z(1,0,0);
		sum=0; dfs_z(G,0,0);
		printf("%d\n",sum); return 0;
	} else if(bk==true) {
		int mid,ans;
		while(l<=r) {
			mid=(l+r)/2;
			int x=1; int d=0,s=0;
			while(x!=n) {
				for(int k=last[x];k;k=a[k].next) {
					int y=a[k].y; if(y!=x+1) continue;
					d+=a[k].d; 
					if(d>=mid) { s++; d=0; }
				} x++;
			}
			if(s>=m) { ans=mid; l=mid+1; }
			else r=mid-1;
		}
		printf("%d\n",ans); return 0;
	} else if(bbt==true) {
		int hlen=0;
		for(int k=last[1];k;k=a[k].next) {
			h[++hlen]=a[k].d;
		}
		sort(h+1,h+1+hlen,cmp);
		int ans=r;
		if(2*m<=hlen) {
			for(int i=1;i<=m;i++) {
				int d=h[i]+h[2*m-i+1];
				ans=min(ans,d);
			}
		} else {
			for(int i=1;i<=hlen;i++) {
				if(hlen-i+1>=2*m) {
					int ed=hlen;
					for(int j=i;j<=i+m-1;j++) {
						int d=h[j]+h[ed]; ans=min(ans,d);
						ed--;
					} 
					printf("%d\n",ans); return 0;
				} else { 
					ans=min(ans,h[i]); m--;
				}
			}
			printf("%d\n",ans); return 0;
		} 
	} else {
		int mid,ans;
		while(l<=r) {
			mid=(l+r)/2;
			memset(keyi,true,sizeof(keyi));
			memset(v,true,sizeof(v));
			top=mid; 
			if(pd(1)==true) { ans=mid; l=mid+1; }
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
