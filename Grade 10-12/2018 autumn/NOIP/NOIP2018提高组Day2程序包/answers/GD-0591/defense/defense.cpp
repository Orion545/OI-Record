#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rg register
#define il inline
#define For(i,a,b) for(rg int i=(a);i<=(b);i++)
#define rep(i,n) for(rg int i=0;i<(n);i++)
typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;

//freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);

il void read(int &x){
	x=0;char c=getchar();int f=1;
	while((c<'0'||c>'9')&&(c!=EOF)){if(c=='-')f=-1;c=getchar();}
	if(c==EOF)return;
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
const int N=100010,INF=0x3f3f3f3f;
struct edge{int to,nex;}e[N<<1];
int h[N],tot;
il void add(int u,int v){
	e[++tot].to=v;e[tot].nex=h[u];h[u]=tot;
}

char str[4];
int n,m;
int c[N];
int ask[N];
bool vis[N];
int dp(int x,int k){
	if((ask[x]!=-1)&&(ask[x]!=k))return -1;
	if(k==0){
		int res=0;
		for(rg int i=h[x],j;i;i=e[i].nex){
			j=e[i].to;
			if(vis[j])continue;
			vis[j]=1;
			int ret=dp(j,1);
			vis[j]=0;
			if(ret==-1)return -1;
			res+=ret;
		}
		return res;
	}else{
		int res=c[x];
		for(rg int i=h[x],j;i;i=e[i].nex){
			j=e[i].to;
			if(vis[j])continue;
			vis[j]=1;
			int ret1=dp(j,1);int ret2=dp(j,0);vis[j]=0;
			if(ret1>ret2)swap(ret1,ret2);
			if(ret1!=-1)
			res+=ret1;else if(ret2!=-1)res+=ret2;else return -1;
		}
		return res;
	}
	
}

int main(){
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,str);
	For(i,1,n)read(c[i]);
	For(i,2,n){
		int u,v;read(u);read(v);add(u,v);add(v,u);//printf("%d %d\n",u,v);
	}
	memset(ask,-1,sizeof ask);
	//For(i,1,n)printf("%d ",c[i]);
	//printf("%d\n",dp(1,0));
	For(i,1,m){
		int a,b,cc,d;
		read(a);read(b);read(cc);read(d);
		//memset(vis,0,sizeof vis);
		ask[a]=b;ask[cc]=d;
		vis[1]=1;
		int ans1=dp(1,0),ans2=dp(1,1);vis[1]=0;
		if(ans2<ans1)swap(ans1,ans2);
		if(ans1==-1){
			printf("%d\n",ans2);
		}else printf("%d\n",ans1);
		ask[a]=-1;ask[cc]=-1;
	}
	
	return 0;
}




