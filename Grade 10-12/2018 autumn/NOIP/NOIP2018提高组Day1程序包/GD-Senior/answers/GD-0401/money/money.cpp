#include<cstdio>
#include<cstring>
#include<algorithm>
inline int read() {
	int f=1,x=0;
	char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?-1:1;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
	return f*x;
}
const int N=5e5+50;
int i,T,a[N],tot,ans,n,j,k,cc[N],SZ,tmp;
bool mp[N];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while (T--) {
		n=read();
		for (i=1;i<=n;i++) a[i]=read();
		std::sort(a+1,a+1+n);
		SZ=a[n];
		memset(mp,0,sizeof(mp));
		tot=0,ans=0;
		for (i=1;i<=n;i++) {
			if (mp[a[i]]) continue;
			ans++;
			for (j=1;j<=SZ;j++) {
				if (a[i]*j>SZ) break;
				tmp=tot;
				for (k=1;k<=tmp;k++) {
					if (cc[k]+a[i]*j>SZ) continue;
					if (!mp[cc[k]+a[i]*j]) cc[++tot]=cc[k]+a[i]*j,mp[cc[k]+a[i]*j]=1;
				}
				if (!mp[a[i]*j]) cc[++tot]=a[i]*j,mp[a[i]*j]=1;;	
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
