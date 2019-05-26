#include<cstdio>
#include<cctype>
#define repu(i,x,y) for(i=x;i<=y;i++)
#define P 1000000009
#define LL long long
int read() {
	char c=getchar(); int f=0;
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) f=f*10+c-'0',c=getchar();
	return f;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read(),i,ans=1;
	if (n>m) {int t=n; n=m; m=t;}
	repu(i,1,n-1) ans=((LL)ans*(i+1))%P;
	repu(i,1,m-n+1) ans=((LL)ans*(n+1))%P;
	repu(i,1,n-1) ans=((LL)ans*(i+1))%P;
	printf("%d\n",ans);
	return 0;
}
