#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
bool f[25020]; int a[105],n;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	while(t--){
		int n=read(),i,j,ans=0;
		memset(f,0,sizeof f);
		f[0]=1;
		for(i=1;i<=n;++i) a[i]=read();
		sort(a+1,a+1+n);
		for(i=1;i<=n;++i)
			if(!f[a[i]]) for(j=0;j+a[i]<=25000;++j) f[j+a[i]]|=f[j];
			else ++ans;
		printf("%d\n",n-ans);
	}
	return 0;
}
