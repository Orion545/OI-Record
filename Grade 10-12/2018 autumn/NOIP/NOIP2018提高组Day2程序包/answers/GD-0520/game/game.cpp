#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define of(i,l,r) for(int i=l;i>=r;--i)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define fin(str) freopen(str,"r",stdin)
#define fou(str) freopen(str,"w",stdout)
using namespace std;
typedef long long ll;
inline int rd()
{static int x,f;static char ch;
	x=0;f=1;ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int MaxS=266,mod=1000000007;
int n,m,bin[100010],f[2][MaxS],trans[MaxS][MaxS],t[MaxS];
int g[10];

inline int pls(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return (ll)a*b%mod;}

inline bool check(int us,int vs)
{
	fo(i,2,n)if(!(us&bin[i-1])&&(vs&bin[i-2]))return 0;
	return 1;
}

int main()
{
	fin("game.in");fou("game.out");
	n=rd();m=rd();
	bin[0]=1;fo(i,1,max(n,m))bin[i]=mul(bin[i-1],2);
	if(n==1||m==1){
		printf("%d\n",bin[max(n,m)]);
		return 0;
	}
	int u=0,v=1,S=(1<<n)-1;
	fo(us,0,S)
		fo(vs,0,S)if(check(us,vs))trans[us][++t[us]]=vs;
	fo(s,0,S){
		cerr<<s<<":"<<endl;
		fo(i,1,t[s])cerr<<trans[s][i]<<' ';cerr<<endl<<endl;
	}
	fo(i,0,S)f[u][i]=1;
	fo(i,2,m){
		memset(f[v],0,sizeof f[v]);
		fo(s,0,S){
			fo(j,1,t[s])f[v][trans[s][j]]=pls(f[v][trans[s][j]],f[u][s]);
		}
		swap(u,v);
	}
	int ans=0;
	fo(i,0,S)ans=pls(ans,f[u][i]);
	printf("%d\n",ans);
	cerr<<ans<<endl;//!!!!!!!!!!!!
	return 0;
}

