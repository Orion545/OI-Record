#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[100010],b[100010],i;
long long ans;
int main(){
	freopen("taxi.in","r",stdin);
	freopen("taxi.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),ans+=abs(a[i]-b[i]);
	a[++n]=m;b[n]=0;
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(i=1;i<=n;i++) ans+=abs(a[i]-b[i]);
	printf("%lld",ans);
} 
/*#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define inc(i,j,k) for(int i=j;i<=k;i++)
#define maxn 100010
using namespace std;
 
inline int read(){
    char ch=getchar(); int f=1,x=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return f*x;
}
int n,m,a[maxn],b[maxn]; long long ans;
int main(){
    n=read(); m=read(); inc(i,1,n)a[i]=read(),b[i]=read(); inc(i,1,n)ans+=abs(a[i]-b[i]);
    a[++n]=m; b[n]=0; sort(a+1,a+n+1); sort(b+1,b+n+1); inc(i,1,n)ans+=abs(a[i]-b[i]);
    printf("%lld",ans); return 0;
}*/
