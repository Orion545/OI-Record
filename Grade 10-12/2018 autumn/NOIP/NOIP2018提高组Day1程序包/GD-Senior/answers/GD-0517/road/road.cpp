#include<cstdio>
#include<cctype>
#define repu(i,x,y) for(i=x;i<=y;i++)
#define N 100001
int a[N];
int read() {
	char c=getchar(); int f=0;
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) f=f*10+c-'0',c=getchar();
	return f;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),ans=0,i,j,flag=1;
	repu(i,1,n) a[i]=read();
	repu(i,1,n-1)
		if (a[i]>a[i+1]) ans+=a[i]-a[i+1];
	ans+=a[n];
	printf("%d\n",ans);
	return 0;
}
