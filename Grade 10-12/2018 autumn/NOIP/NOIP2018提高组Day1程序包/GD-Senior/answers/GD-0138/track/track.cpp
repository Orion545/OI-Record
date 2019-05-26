#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Pr pair<int,int>
#define mp make_pair
using namespace std;
const int N=5*(1e4)+10;
bool flag;
struct xxx{
	int y,nxt,dis;
}a[N*2];
struct Edge{
	int x,y,dis;
	void read(){
		scanf("%d%d%d",&x,&y,&dis);
		if (y!=x+1) flag=false;
	}
	friend bool operator < (Edge x,Edge y){return x.dis<y.dis;}
}rec[N];

int h[N];
int n,m,tot;
void add(int x,int y,int z){a[++tot].y=y; a[tot].nxt=h[x]; h[x]=tot; a[tot].dis=z;}
namespace Task1{/*{{{*/
	int mx[N],smx[N],dep[N],which[N];
	void dfs(int fa,int x){
		int u;
		mx[x]=0; smx[x]=0; which[x]=0;
		for (int i=h[x];i!=-1;i=a[i].nxt){
			u=a[i].y;
			if (u==fa) continue;
			dfs(x,u);
			if (mx[u]+a[i].dis>mx[x])
				smx[x]=mx[x],mx[x]=mx[u]+a[i].dis,which[x]=u;
			else
				smx[x]=max(smx[x],mx[u]+a[i].dis);
		}
	}
	void dfs1(int fa,int x,int d){
		int u,tmp;
		if (fa){
			if (which[fa]==x)
				tmp=smx[fa]+d;
			else
				tmp=mx[fa]+d;
			if (tmp>mx[x])
				smx[x]=mx[x],mx[x]=tmp,which[x]=fa;
			else
				smx[x]=max(smx[x],tmp);
		}
		for (int i=h[x];i!=-1;i=a[i].nxt){
			u=a[i].y;
			if (u==fa) continue;
			dfs1(x,u,a[i].dis);
		}
	}
	void solve(){
		int x,y,z;
		memset(h,-1,sizeof(h));
		tot=0;
		for (int i=1;i<n;++i){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z); add(y,x,z);
		}

		int ans=0;
		dfs(0,1);
		dfs1(0,1,0);
		for (int i=1;i<=n;++i) ans=max(ans,mx[i]+smx[i]);
		printf("%d\n",ans);
	}
}/*}}}*/
namespace Task2{/*{{{*/
	int vis[N*2];
	int sum,tm;
	int dfs(int x,int y,int dis,int mn){
		int u=-1,v=-1,tmpu,tmpv;
		if (dis>=mn) return 1;
		if (x!=-1){
			for (int i=h[x];i!=-1;i=a[i].nxt){
				if (vis[i]==tm) continue;
				u=a[i].y; tmpu=i;
				vis[i]=tm; vis[i^1]=tm; break;
			}
		}
		if (y!=-1){
			for (int i=h[y];i!=-1;i=a[i].nxt){
				if (vis[i]==tm) continue;
				v=a[i].y; tmpv=i;
				vis[i]=tm; vis[i^1]=tm; break;
			}
		}
		if (u==-1&&v==-1) return 0;
		if (u==-1)
			return dfs(x,v,dis+a[tmpv].dis,mn);
		if (v==-1)
			return dfs(u,y,dis+a[tmpu].dis,mn);
		if (a[tmpu].dis<a[tmpv].dis){
			if (a[tmpu].dis+dis>=mn){
				vis[tmpv]=0; vis[tmpv^1]=0;
				return dfs(u,y,dis+a[tmpu].dis,mn);
			}
			if (a[tmpv].dis+dis>=mn){
				vis[tmpu]=0; vis[tmpu^1]=0;
				return dfs(x,v,dis+a[tmpv].dis,mn);
			}
		}
		else{
			if (a[tmpv].dis+dis>=mn){
				vis[tmpu]=0; vis[tmpu^1]=0;
				return dfs(x,v,dis+a[tmpv].dis,mn);
			}
			if (a[tmpu].dis+dis>=mn){
				vis[tmpv]=0; vis[tmpv^1]=0;
				return dfs(u,y,dis+a[tmpu].dis,mn);
			}
		}
		vis[tmpu]=tm; vis[tmpu^1]=tm;
		vis[tmpv]=tm; vis[tmpv^1]=tm;
		return dfs(u,v,dis+a[tmpu].dis+a[tmpv].dis,mn);
	}
	bool check(int mn){
		int cnt=0;
		++tm;
		for (int i=tot;i>=0&&cnt<m;i-=2)
			if (vis[i]!=tm){
				vis[i]=tm; vis[i^1]=tm;
				cnt+=dfs(a[i].y,a[i^1].y,a[i].dis,mn);
			}
		return cnt>=m;
	}
	int get_ans(int r){
		int l=0,mid,ret=0;
		while (l<=r){
			mid=l+r>>1;
			if (check(mid)) ret=mid,l=mid+1;
			else r=mid-1;
		}
		return ret;
	}
}/*}}}*/
namespace Task3{/*{{{*/
	int vis[N*2],lis[N],f[N],sum[N];
	int tm,dfn_t;
	void dfs(int fa,int x){
		int u;
		for (int i=h[x];i!=-1;i=a[i].nxt){
			u=a[i].y;
			if (u==fa) continue;
			lis[++lis[0]]=a[i].dis;
			sum[lis[0]+1]=sum[lis[0]]+a[i].dis;
			dfs(x,u);
		}
	}
	bool check(int mn){
		int cnt=0;
		f[0]=0;
		for (int i=1;i<=n;++i){
			f[i]=f[i-1];
			for (int j=1;j<=i;++j){
				if (sum[i]-sum[j-1]>=mn)
					f[i]=max(f[i],f[j-1]+1);
				else break;
			}
		}
		return f[n]>=m;
	}
	int get_ans(int r){
		int l=0,mid,ret=0;
		lis[0]=0;
		dfs(0,1);
		while (l<=r){
			mid=l+r>>1;
			if (check(mid)) ret=mid,l=mid+1;
			else r=mid-1;
		}
		return ret;
	}
}/*}}}*/
void solve(){
	flag=true;
	for (int i=1;i<n;++i) rec[i].read();
	sort(rec+1,rec+1+n-1);
	memset(h,-1,sizeof(h));
	tot=-1; 
	int sum=0;
	for (int i=1;i<n;++i){
		add(rec[i].x,rec[i].y,rec[i].dis);
		add(rec[i].y,rec[i].x,rec[i].dis);
		sum+=rec[i].dis;
	}
	printf("%d\n",(flag&&n<=15)?Task3::get_ans(sum):Task2::get_ans(sum));
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);

	scanf("%d%d",&n,&m);
	if (m==1){
		Task1::solve();
		return 0;
	}
	solve();
}
