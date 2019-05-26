#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define of(i,l,r) for(int i=l;i>=r;--i)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define fin(str) freopen(str,"r",stdin)
#define fou(str) freopen(str,"w",stdout)
#define debug(x) cerr<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long ll;
inline int rd()
{static int x,f;static char ch;
	x=0;f=1;ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
struct edge{
	int v,next;
	edge(int v=0,int next=0):v(v),next(next){}
}e[N<<1];
int n,m,p[N],bo[N];
int tot=0,head[N];
ll f[N][2][2];
char s[10];

inline void add(int u,int v){e[++tot]=edge(v,head[u]);head[u]=tot;}

namespace solve1{

void dfs(int u,int fat)
{
	f[u][0][0]=0;
	f[u][1][0]=p[u];
	ll mn1=100000000000,mn2=100000000000,sum1=0,sum2=0;
	fe(i,u){
		int v=e[i].v;if(v==fat)continue;
		dfs(v,u);
		f[u][0][0]+=f[v][0][1];
		f[u][1][0]+=min(f[v][0][0],f[v][0][1]);
		ll mn=100000000000;
		fo(j,0,1)fo(k,0,1)mn=min(mn,f[v][j][k]);
		sum1+=mn;
		mn2=min(min(f[v][1][0],f[v][1][1])-mn,mn2);
		mn=100000000000;
		fo(j,1,1)fo(k,0,1)mn=min(mn,f[v][j][k]);
		sum2+=mn;
		mn=min(f[v][0][1],mn);
		mn1=min(min(f[v][1][0],f[v][1][1])-mn,mn1);
	}
	f[u][0][1]=sum2+mn1;
	f[u][1][1]=sum1+mn2+p[u];
	fo(i,0,1)fo(j,0,1)f[u][i][j]=min(f[u][i][j],100000000000ll);
	if(~bo[u]){
		if(bo[u])f[u][0][1]=f[u][0][0]=100000000000;
		else f[u][1][0]=f[u][1][1]=100000000000;
	}
}

inline void gao()
{
	memset(bo,-1,sizeof bo);
	ll ans;
	fo(i,1,m){
		int a=rd(),x=rd(),b=rd(),y=rd();
		if(!x&&!y){
			bool flag=0;
			fe(j,a)
				if(e[j].v==b){flag=1;break;}
			if(flag){puts("-1");continue;}
		}
		bo[a]=x;bo[b]=y;
		dfs(1,0);
		ans=min(f[1][0][1],f[1][1][0]);
		ans=min(f[1][1][1],ans);
		printf("%I64d\n",ans);
//		cerr<<ans<<endl;
		bo[a]=bo[b]=-1;
	}
//	fo(i,1,n){
//		fo(j,0,1)fo(k,0,1)cerr<<f[i][j][k]<<' ';
//		cerr<<endl<<endl;
//	}
}

}

int main()
{
	fin("defense.in");fou("defense.out");
	n=rd();m=rd();scanf("%s",s);
	fo(i,1,n)p[i]=rd();
	fo(i,2,n){
		int x=rd(),y=rd();
		add(x,y);add(y,x);
	}
	if(n<=2000&&m<=2000)solve1::gao();
//	else if(s[0]=='A')solve2::gao();
//	else solve3::gao();
	return 0;
}

