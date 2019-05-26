#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
void read(int &x){
	char ch=' '; x=0;
	while(ch<'0' || ch>'9') ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar()) x=x*10+ch-'0';
}
struct nod{int x,s;};
bool operator <(nod a,nod b){ return a.s>b.s; }
priority_queue<nod> q;
const int N=110,M=1e6;
const ll inf=4611686018427387883;
int n,a[N],bz[N],vis[N*N];
ll ans,f[M],dis[N*N],dis1[N*N];
ll dij(){
	fo(i,0,a[n]) dis[i]=inf,vis[i]=0;dis[0]=0;
	q.push((nod){0,0});
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;vis[x]++;
		fo(i,1,n){
			if(bz[i]) continue;
			int y=(a[i]+x)%a[n];
			if(dis[y]>dis[x]+a[i]){
				dis[y]=dis[x]+a[i];
				q.push((nod){y,dis[y]});
			}
		}
	}
	ll mx=0;fo(i,0,a[n]) mx=max(mx,dis[i]);
	return mx;
}
void gc(){
	read(n);fo(i,1,n) read(a[i]),bz[i]=0;sort(a+1,a+n+1);
	fo(i,1,n) fo(j,1,n) fo(k,1,n) if(a[k]==a[i]+a[j]) bz[k]++;
	fo(i,1,n) fo(j,i+1,n) if(!bz[i] && !bz[j] && a[i]==a[j]) bz[j]++;
	int nn=n;n=0;fo(i,1,nn) if(!bz[i]) a[++n]=a[i];
	ll s=dij();
	fo(i,1,n){ bz[i]++;if(dij()!=s) bz[i]=0; }
	nn=n;n=0;
	fo(i,1,nn) if(bz[i]) n++;
	printf("%d\n",n);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;read(T);
	while(T--) gc();
}
