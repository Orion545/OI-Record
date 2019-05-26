#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define rg register
#define N 200010
int n,m,tot,a[N],s[N],type,mx,last,mn;
LL sum;
using namespace std;
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(rg int i=1;i<=n;i++) a[i]=read();
	mx=0; mn=2e9; last=0;
	for(rg int i=1;i<=n;i++){
		if(a[i-1]<a[i]&&type){
			s[i]=++tot;
			type=0;
		}
		else{
			if(a[i-1]>a[i]) type=1;
			s[i]=tot;
		}
	}
	s[n+1]=tot+1;
	for(rg int i=1;i<=n+1;i++)if(s[i]!=s[i-1]){
		sum+=mx-last; last=a[i-1]; mx=0;
		mx=max(a[i],mx);
	}
	else{
		mx=max(a[i],mx);
	}
	printf("%lld\n",sum);
	return 0;
}
