#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define N 200010
#define rg register
using namespace std;
int n,m,tot,cnt,last[N],a[N],b[N],l,r,in[N];
LL dis[N],ans;
bool type1=1,type2=1;
struct edge{
	int to,pre,w;
}e[N];
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void dfs(int x,int fa){
	for(rg int i=last[x],to;i;i=e[i].pre)if((to=e[i].to)!=fa){
		dis[to]=dis[x]+e[i].w; dfs(to,x);
	}
}
void dfs2(int x,int fa){
	for(rg int i=last[x],to;i;i=e[i].pre)if((to=e[i].to)!=fa){
		b[++cnt]=e[i].w; dfs2(to,x);
	}
}
inline bool check(int x){
	int l=1,r=n-1,cnt=0;
	while(l<r){
		while(a[l]+a[r]<x&&l<r) l++;
		if(l<r||(l==r&&a[r]>=x)) cnt++,l++,r--;
	}
	return cnt>=m;
}
inline bool check2(int x){
	int sum=0,cnt=0;
	for(rg int i=1;i<=n;i++){
		sum+=b[i];
		if(sum>=x) sum=0,cnt++;
	}
	return cnt>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	for(rg int i=1;i<n;i++){
		int u=read(),v=read(),w=read();
		if(u>v) swap(u,v); 
		if(u!=1) type1=0; 
		if(u!=v-1) type2=0;
		e[++tot]=(edge){v,last[u],w}; last[u]=tot;
		e[++tot]=(edge){u,last[v],w}; last[v]=tot;
		a[i]=w;
		in[u]++; in[v]++;
	}
	if(m==1){
		dfs(1,0);
		int mx=0,pos=0;
		for(rg int i=1;i<=n;i++)if(dis[i]>mx){
			mx=dis[i],pos=i;
		}
		memset(dis,0,sizeof(dis));
		dfs(pos,0);
		for(rg int i=1;i<=n;i++) ans=max(ans,dis[i]);
		printf("%lld\n",ans);
		return 0;
	}
	if(type1){
		sort(a+1,a+n);
		for(rg int i=1;i<n;i++) r+=a[i];
		l=0; r++;
		while(l+1<r){
			int mid=(l+r)>>1;
//			printf("%d %d\n",l,r);
			if(check(mid)) l=mid; else r=mid;
		}
		printf("%d\n",l);
		return 0;
	}
	if(type2){		
		int pos=0;
		for(rg int i=1;i<=n;i++)if(in[i]==1) pos=i;
		dfs2(pos,0);
//		for(rg int i=1;i<n;i++) printf("%d ",b[i]); puts("b");
		for(rg int i=1;i<n;i++) r+=b[i];
		l=0; r++;
		while(l+1<r){
			int mid=(l+r)>>1;
//			printf("%d %d\n",l,r);
			if(check2(mid)) l=mid; else r=mid;
		}
		printf("%d\n",l);
		return 0;
	}
}
