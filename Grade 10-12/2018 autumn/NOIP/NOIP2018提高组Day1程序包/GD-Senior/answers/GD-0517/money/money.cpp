#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define repu(i,x,y) for(i=x;i<=y;i++)
#define N 101
int a[N],f[50001];
int read() {
	char c=getchar(); int f=0;
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) f=f*10+c-'0',c=getchar();
	return f;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while (T--) {
		int n=read(),i,j,t,ans;
		memset(f,0,sizeof f); f[0]=1; ans=n;
		repu(i,1,n) a[i]=read();
		std::sort(a+1,a+n+1); t=a[n];
		repu(i,1,n) 
			if (f[a[i]])
				ans--;
			else
				repu(j,a[i],t) if (f[j-a[i]]) f[j]=1;
		printf("%d\n",ans);
	}
	return 0;
}
