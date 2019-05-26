#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int N=205,inf=1e9+7,M=3e4+10;
int T,n,i,k,fl,ans,a[N],j,mi,b[N],cnt,mx,g[M],x,f[M],q[M];
int read(){
	int sum=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
int gcd(int x,int y){
	if (!y) return x;
	  else return gcd(y,x%y);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while (T--){
		n=read(),mi=inf,mx=0;
		fo(i,1,n) a[i]=read(),mi=min(mi,a[i]),mx=max(a[i],mx);
		if (n==2){
			if (a[1]<a[2]) swap(a[1],a[2]);
			if (!(a[1]%a[2])) printf("1\n");
			  else printf("2\n");
			return 0;
		}
		b[cnt=1]=mi;
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		f[0]=1;
		int num=0;
		fo(i,1,mx) 
		  fo(j,1,n)
		    if (i>=a[j]&&f[i-a[j]]) {
		    	 if (!f[i]) q[++num]=i,f[i]=1;
		    } 
		g[mi]=g[0]=1;
		int s=1;
		while (s<=num){
			x=q[s];
			if (x>mx) break;
			int fl=1;
			fo(i,1,cnt) if (x>=b[i]&&g[x-b[i]]) {
				 fl=0;
				 break;
			} 
			if (fl) b[++cnt]=x;
			g[x]=1;
			++s;
		}
		printf("%d\n",cnt);
	}
}
