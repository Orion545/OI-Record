#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define rg register
#define N 200010
#define M 25000
using namespace std;
int T,n,m,ans,a[N],b[N];
bool v[N],can[N];
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
inline void pre(){
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	memset(can,0,sizeof(can));
	memset(b,0,sizeof(b));
	ans=0; n=0; m=0;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--){
		pre();
		n=read();
		for(rg int i=1,x;i<=n;i++){
			x=a[i]=read();
			for(rg int j=x<<1;j<=M;j+=x) v[j]=1;
		}
		for(rg int i=1;i<=n;i++)if(!v[a[i]]) b[++m]=a[i];
//		printf("m=%d\n",m);
		n=m;
		sort(b+1,b+1+n);
		can[0]=1;
		for(rg int i=1;i<=n;i++){
			if(!can[b[i]]) ans++;
			for(rg int j=0;j<=M;j++)if(can[j]) can[j+b[i]]=1;
		}
//		for(rg int i=1;i<=n;i++)if(!can[a[i]]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
