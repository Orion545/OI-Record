#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int N=50000+255;
int head[N],to[N*2],nex[N*2],w[N*2],d[N];
int a[N],s[N];
int n,m,tot,ans,id,x,y,z,num;
bool used[N];
bool vis[N];
void add(int x,int y,int z){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
	w[tot]=z;
}
void dfs(int x,int y){
	vis[x]=1;
	if (y>ans){
		ans=y;
		id=x;
	}
	for (int i=head[x];i;i=nex[i]){
		int v=to[i];
		if (vis[v]) continue;
		dfs(v,w[i]+y);
	}
}
void Dfs(int x,int y){
	vis[x]=1;
	if (y>ans){
		ans=y;
		id=x;
	}
	for (int i=head[x];i;i=nex[i]){
		int v=to[i];
		if (vis[v]) continue;
		dfs(v,w[i]+y);
	}
}
void solve1(){
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	ans=0;
	Dfs(id,0);
	printf("%d",ans);
}
bool cmb(int a,int b){
	return a>b;
}
bool pd(int x){
	memset(used,0,sizeof(used));
	int cnt=0;
	fo(i,1,n-1){
		if (a[i]>=x) {
			used[i]=1;cnt++;
			continue;
		}
		if (cnt==m) return 1;
		int k=n-1;
		while ((a[k]+a[i]<x||used[k])&&k>0) k--;
		if (a[k]+a[i]<x||!k||k==i) return 0;
		used[k]=used[i]=1;
		cnt++;
	}
	return 0;
}
void solve2(){
	sort(a+1,a+n,cmb);
	int l=1,r=a[1]+a[2]+1;
	while (l<r){
		int mid=l+r>>1;
		if (pd(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d",l-1);
}
bool pd1(int x){
	int i=2,cnt=0;
	while (i<=n){
		if (cnt==m) return 1;
		int j=i;
		while (j<=n&&s[j]-s[i-1]<x) j++;
		if (j==n+1) return 0;
		cnt++;i=j+1;
		if (cnt==m) return 1;
	}
	return 0;
}
void DD(int x,int y){
	for (int i=head[x];i;i=nex[i]){
		if(to[i]!=y) {
			s[++num]=s[num]+w[i];
			s[num]+=s[x];
			DD(to[i],x);
		}
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool p=1,p2=1;
	fo(i,1,n-1){
		scanf("%d%d%d",&x,&y,&z);
		if (x!=1) p=0;
		if (y!=x+1) p2=0;
		add(x,y,z);add(y,x,z);
		a[i]=z;
		d[x]++;d[y]++;
	}
	if (m==1){
		solve1();
		return 0;
	}
	if (p==1){
		solve2();
		return 0;
	}
	if (p2==1){
		int tt;
		fo(i,1,n) if (d[i]==1) {
			tt=i;
			break;
		}
		int sum=0;
		num=1;
		DD(tt,0);
		int l=1,r=s[n]/m+255;
		while (l<r){
			int mid=l+r>>1;
			if (pd1(mid)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l-1);
		return 0;
	}
	return 0;
}
