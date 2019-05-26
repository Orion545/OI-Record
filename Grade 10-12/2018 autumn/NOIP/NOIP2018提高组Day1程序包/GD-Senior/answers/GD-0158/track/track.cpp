#include<cstdio>
#include<algorithm>
#include<cstring>
#define link(x,y,z) e[++tot]=y,nt[tot]=fi[x],fi[x]=tot,len[tot]=z
#define F(x) for(int i=fi[x];i;i=nt[i])
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=5e4+5,M=2*N;
int e[M],fi[N],nt[M],tot,len[M];
ll ans,n,m,f[N],z[N],s[N];
int x[N],y[N];
void dfs(int x,int fa){
	F(x){
		int y=e[i];if(y==fa) continue;
		dfs(y,x);
		f[x]=max(f[x],f[y]+len[i]);
	}
	int cnt=0;
	ans=max(ans,f[x]);
	F(x){
		int y=e[i];if(y==fa) continue;
		if(f[y]+len[i]==f[x] && !cnt) { cnt++;continue; }
		ans=max(ans,f[x]+f[y]+len[i]);
	}
}
void gc1(){
	fo(i,1,n-1);dfs(1,0);
	printf("%lld\n",ans);
}
bool cmp(int x,int y){ return x>y; }
void gc2(){
	sort(z+1,z+n,cmp);
	fo(i,1,m) z[i]+=z[2*m-i+1];
	sort(z+1,z+m+1);
	printf("%lld\n",z[1]);
}
void gc3(){
	ll l=0,r=0,ans=0;
	fo(i,1,n-1) s[y[i]]=z[i];
	fo(i,2,n) s[i]+=s[i-1];r=s[n];
	while(l<=r){
		ll mid=l+r>>1;
		int ls=1,cnt=0;
		fo(i,2,n) if(s[i]-s[ls]>=mid) cnt++,ls=i;
		if(cnt>=m) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld\n",ans);
}
ll K;
int v[N],sm;
ll b[N],cnt,g[N];
int ask(int x,int fa){
	f[x]=g[x]=0;
	F(x) if(e[i]!=fa) ask(e[i],x),f[x]+=f[e[i]];
	cnt=0;F(x) if(e[i]!=fa) b[++cnt]=g[e[i]]+len[i];
	
	fo(i,1,cnt) v[i]=0;sm=0;
	sort(b+1,b+cnt+1);
	fo(i,1,cnt) if(!v[i]){
		if(b[i]>=K) f[x]++,v[i]++;
		else fo(j,i+1,cnt) if(!v[j] && b[i]+b[j]>=K){
			v[i]=v[j]=1;f[x]++;
			break;
		}
	}
	int cc=cnt;cnt=0;
	fo(i,1,cc) if(!v[i]) b[++cnt]=b[i];
	g[x]=b[cnt];
}
int d[N];
void gc4(){
	ll l=0,r=0,ans=0;int mx=0;
	fo(i,1,n-1) r+=z[i];
	fo(i,1,n) mx=max(mx,d[i]);
	while(l<=r){
		K=l+r>>1;ask(1,0);
		if(f[1]>=m) l=K+1,ans=K;
		else r=K-1;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int c1=0,c2=0;
	fo(i,1,n-1){
		scanf("%d%d%lld",&x[i],&y[i],&z[i]);
		link(x[i],y[i],z[i]),link(y[i],x[i],z[i]);
		c1+=(x[i]!=1);c2+=(y[i]!=x[i]+1);
		d[x[i]]++,d[y[i]]++;
	}
	int mx=0;fo(i,1,n) mx=max(mx,d[i]);
	if(m==1) gc1();
	else if(!c1) gc2();
	else if(!c2) gc3();
	else if(mx<=4) gc4();
}

