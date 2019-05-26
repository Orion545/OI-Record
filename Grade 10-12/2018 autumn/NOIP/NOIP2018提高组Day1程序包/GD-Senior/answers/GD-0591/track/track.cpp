#define il inline
#define rg register
#define For(i,a,b) for(rg int i=(a);i<=(b);i++)
#define rep(i,n) for(rg int i=0;i<(n);i++)
typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
const int N=50010,M=1000000007,INF=0x3f3f3f3f;
#include<cstdio>
#include<cstring>

//freopen(".in","r",stdin);freopen(".out","w",stdout);

il void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||c>'9')&&(c!=EOF)){if(c=='-')f=-1;c=getchar();}
	if(c==EOF)return;
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}

struct edge{int to,nex,w;}e[100010];
int h[N],tot;
il void add(int u,int v,int w){
	e[++tot].to=v;e[tot].nex=h[u];e[tot].w=w;h[u]=tot;
	e[++tot].to=u;e[tot].nex=h[v];e[tot].w=w;h[v]=tot;
}

int n,m;
int ml,mml=INF;
int ans;

//m==1
int d[N];
bool bfv[N];
void bf(int x){
	for(rg int i=h[x],j;i;i=e[i].nex)
	if(!bfv[j=e[i].to]){
		bfv[j]=1;
		d[j]=d[x]+e[i].w;
		bf(j);
	}
}

//graph==link
int qwq[N];
il bool pwp(int len){
	int res,wow;res=0;wow=0;
	For(i,1,n){wow+=qwq[i];if(wow>=len){res++;wow=0;}}
	return (res>=m);
}
il void waqwq(){
	n--;
	For(i,1,n){qwq[i]=e[h[i]].w;}
	rg int l=1,r=ml,mid;
	while(l<=r)
		(pwp(mid=((l+r)>>1)))?l=(ans=mid)+1:r=mid-1;
}


bool vis[N];
int dfs(int x,int le,int len){
	int res=0;
	if(le>=len){
		res=1;
		for(rg int i=h[x],j;i;i=e[i].nex)if(!vis[j=e[i].to]){
			vis[j]=1;
			res+=dfs(j,e[i].w,len);
			vis[j]=0;
		}
		return res;
	}else{
		int md=0,dd,tmd;
		for(rg int i=h[x],j;i;i=e[i].nex)if(!vis[j=e[i].to]){
			vis[j]=1;
			tmd=dfs(j,e[i].w,len);
			dd=dfs(j,le+e[i].w,len)-tmd;
			md=md>dd?md:dd;
			res+=tmd;
		}
		return md+res;
	}
}
il bool check(int len){
	memset(vis,0,sizeof vis);
	For(i,1,n){vis[i]=1;if(dfs(i,0,len)>=m)return 1;vis[i]=0;}
	return 0;
}


int main(){
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	read(n);read(m);
	
	if(m==1){
		For(i,2,n){
			int ai,bi,li;read(ai);read(bi);read(li);
			add(ai,bi,li);
		}
		int s,ls=0;
		bf(1);For(i,1,n)if(d[i]>ls){s=i;ls=d[i];}
		
		memset(d,0,sizeof d);memset(bfv,0,sizeof bfv);
		bf(s);
		int lt=0;For(i,1,n)if(d[i]>lt)lt=d[i];
		printf("%d\n",lt);return 0;
	}
	
	
	bool noiporz=1;
	For(i,2,n){
		int ai,bi,li;read(ai);read(bi);read(li);
		//printf("%d %d %d\n",ai,bi,li);
		add(ai,bi,li);if(bi!=(ai+1))noiporz=0;ml+=li;
		mml=li<mml?li:mml;
	}ml/=m;
	//if a link
	if(noiporz){waqwq();printf("%d\n",ans);return 0;}
	
	
	rg int l=1,r=ml,mid;
	while(l<=r)
		check(mid=((l+r)>>1))?l=(ans=mid)+1:r=mid-1;
	
	printf("%d\n",ans);
	
	return 0;
}



