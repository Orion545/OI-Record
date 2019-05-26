#define il inline
#define rg register
#define For(i,a,b) for(rg int i=(a);i<=(b);i++)
#define rep(i,n) for(rg int i=0;i<(n);i++)
typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
const int N=100010,M=1000000007,INF=0x3f3f3f3f;
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

int n,d[N];
LL ans;

il int max(int a,int b){return a>b?a:b;}

int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	
	read(n);For(i,1,n){
		read(d[i]);
		ans+=max(0,d[i]-d[i-1]);
	}
	printf("%lld\n",ans);
	
	return 0;
}



