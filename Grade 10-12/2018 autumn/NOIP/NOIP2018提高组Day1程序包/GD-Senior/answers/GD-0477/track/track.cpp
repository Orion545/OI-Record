#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=100100;
int n,m,tot,x,y,z;
int h[N],ans,a[N];
int q[N],dis[N],v[N];
int deg[N],st,d[N];
struct edge{int y,next,z;}g[N*2];

void adp(int x,int y,int z){
	g[++tot].y=y;
	g[tot].z=z;
	g[tot].next=h[x];
	h[x]=tot;
}

void inc(int &x){if (x==N-10) x=1; else x++;}
int bfs(int st){
	memset(dis,0,sizeof(dis));
	memset(v,0,sizeof(v));
	int l=0,r=1;q[1]=st;v[st]=1;
	while (l!=r){
		inc(l);int x=q[l];
		for (int i=h[x];i;i=g[i].next)
		if (dis[g[i].y]<dis[x]+g[i].z && !v[g[i].y]){
			dis[g[i].y]=dis[x]+g[i].z;
			inc(r);q[r]=g[i].y;
			v[g[i].y]=1;
		}
	}
	int id,mx=0;
	for (int i=1;i<=n;i++)
		if (mx<dis[i])
			mx=dis[i],id=i;
	ans=mx;
	return id;
}

void work1(){
	int st=bfs(1);bfs(st);
	printf("%d\n",ans);
}

void work2(){
	sort(a+1,a+n);
	if (2*m<=n-1){
		int l=n-2*m,r=n-1;ans=1e9;
		for (int i=1;i<=m;i++){
			ans=min(ans,a[l]+a[r]);
			l++;r--;
		}
		printf("%d\n",ans);
	} else {
		int t=n-1-m;
		ans=a[2*t+1];
		int l=1,r=2*t;
		for (int i=1;i<=t;i++){
			ans=min(ans,a[l]+a[r]);
			l++;r--;
		}
		printf("%d\n",ans);
	}
}

int check(int total){
	int cnt=0,now=0;
	int x=1,lst=1;
	for (int i=1;i<n;i++){
		if (now>=total) cnt++,now=0;
		now+=d[i];
	}
	if (now>total) cnt++,now=0;
	return cnt>=m;
}

void work3(){
	int l=0,r=1e9;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid))
			ans=mid,l=mid+1; else
			r=mid-1;
	}
	printf("%d\n",ans);
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int ok=1;int ok2=1;
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if (x!=1) ok=0;a[i]=z;
		if (x+1!=y) ok2=0;
		deg[x]++;deg[y]++;d[x]=z;
		adp(x,y,z);adp(y,x,z);
	}
	if (m==1){
		work1();
		return 0;
	}
	if (ok){
		work2();
		return 0;
	}
	work3();
	return 0;
}
