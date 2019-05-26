#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fb(i,x) for(i=last[x];i;i=next[i])
using namespace std;
const int maxN=5e4+10,maxM=1e5+10;
bool bz1,bz2,bz[maxN];
struct zhj{
	int x,wz;
}a[maxN];
int n,i,m,last[maxN],next[maxM],tov[maxM],len[maxM],fa[maxN],
f[maxN][2],ans,mx[maxN][2],tot,up[maxN],x,y,z,j,l,r,mid,k,ff[maxN],
cnt;
void ins(int x,int y,int z){tov[++tot]=y,len[tot]=z,next[tot]=last[x],last[x]=tot;
}
void dfs(int x,int fx){
	int i,y;
	fa[x]=fx;
	fb(i,x){
		y=tov[i];
		if (y!=fx){
			up[y]=len[i],dfs(y,x);
		}
	}
}
void dfs1(int x){
	int i,y;
	fb(i,x){
		y=tov[i];
		if (y!=fa[x]){
			dfs1(y);
			if (f[y][0]+len[i]>mx[x][0]) mx[x][1]=mx[x][0],mx[x][0]=f[y][0]+len[i];
			else if (f[y][0]+len[i]>mx[x][1]) mx[x][1]=f[y][0]+len[i];
		}
	}
	f[x][0]=mx[x][0];
	f[x][1]=mx[x][0]+mx[x][1];
	ans=max(ans,f[x][1]);
}
bool cmp(zhj x,zhj y){return x.x<y.x;
}
bool pd(int x){
	int sum=0,sumx=0;
	fo(i,2,n){
		sumx+=up[i];
		if (sumx>=x) sumx=0,sum++;
	}
	return sum>=m;
}
void dfs2(int x){
	int i,y;
	fb(i,x){
		y=tov[i];
		if (y!=fa[x]){
			dfs2(y);
		}
	}
	cnt=0;
	fb(i,x){
		y=tov[i];
		if (y!=fa[x])
			a[++cnt].x=ff[y]+len[i],bz[cnt]=true;	
	}
	sort(a+1,a+cnt+1,cmp);
	fd(i,cnt,1){
		if (a[i].x>=k) ans++;
		else break;
	}
	cnt=i;
	if (cnt==1){
		ff[x]=a[1].x;
		return;
	}
	if (cnt==2){
		if (a[1].x+a[2].x>=k) ans++;
		else ff[x]=a[2].x;
		return;
	}
	if (cnt==3){
		if (a[1].x+a[2].x>=k) ans++,ff[x]=a[3].x;
		else if (a[1].x+a[3].x>=k) ans++,ff[x]=a[2].x;
		else if (a[2].x+a[3].x>=k) ans++,ff[x]=a[1].x;
		else ff[x]=a[3].x;
		return;
	}
	j=1;
	fd(i,cnt,1){
		if (j==i){
			ff[x]=a[i].x;return;
		}
		if (j>i){
			fd(j,i,1){
				if (bz[j]){
					ff[x]=a[j].x;return;
				}
			}
			return;
		}
		while (a[i].x+a[j].x<k && j<i-1) j++;
		if (a[i].x+a[j].x<k){
			ff[x]=a[i].x;return;
		}
		bz[i]=bz[j]=false,ans++,j++;
	}
}
bool pd1(int x){
	memset(ff,0,sizeof(ff));
	ans=0;k=x;
	dfs2(1);
	if (ans>=m) return true;
	else return false;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m),bz1=bz2=true;
	fo(i,1,n-1){
		scanf("%d%d%d",&x,&y,&z),ins(x,y,z),ins(y,x,z);
		if (x!=1) bz1=false;
		if (x+1!=y) bz2=false;
		r+=z;
	}
	dfs(1,0);
	if (m==1){
		dfs1(1);
		printf("%d\n",ans);
		return 0;
	}
	if (bz1){
		fo(i,2,n) a[i-1].x=up[i],a[i-1].wz=i;
		n--;
		sort(a+1,a+n+1,cmp);
		ans=1e9;
		if (m<=n/2){
			j=n;
			fo(i,n-m*2+1,n-m){
				ans=min(ans,a[i].x+a[j].x);
				j--;
			}
		}else{
			j=(n-m)*2;
			fo(i,1,n-m){
				ans=min(ans,a[i].x+a[j].x);
				j--;
			}
			j=(n-m)*2+1;
			ans=min(ans,a[j].x);
		}
		printf("%d\n",ans);
		return 0;
	}
	if (bz2){
		l=0,r/=m;
		while (l<r){
			mid=(l+r+1)/2;
			if (pd(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
		return 0;
	}
	l=0,r/=m;
	while (l<r){
		mid=(l+r+1)/2;
		if (pd1(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
