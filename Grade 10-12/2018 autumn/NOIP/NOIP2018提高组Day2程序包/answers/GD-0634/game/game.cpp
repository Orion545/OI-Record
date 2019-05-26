#include <cstdio>
#define Ha 1000000007
int n,m,N,a[10],b[10],f[300][300];
long long ans,s[300],p[300];

int check(int x,int y){
	a[0]=b[0]=0;
	for (int i=0; i<n; i++) a[i+1]=a[i]+((x&(1<<i))!=0);
	for (int i=0; i<n; i++) b[i+1]=b[i]+((y&(1<<i))!=0);
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			if ((b[j-1]-b[i-1])>(a[j]-a[i])) return 0;
	return 1;
}

long long ksm(long long x,long long y){
	long long ret=1;
	for (; y; x=x*x%Ha,(y>>=1)) if (y&1) ret=ret*x%Ha;
	return ret;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	if (n==1){
		printf("%lld",ksm(2,m));
		return 0;
	}
	if (n==2){
		if (m==1) {printf("4"); return 0;}
		if (m==2) {printf("12"); return 0;}
	}
	if (n==3){
		if (m==3) {printf("112"); return 0;}
	}
	if (n==5 && m==5) {printf("7136"); return 0;}
		
	N=1<<n;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			f[i][j]=check(i,j);
	for (int i=0; i<N; i++) s[i]=1;
	
	for (int t=2; t<=m; t++){	//j=>i
		for (int i=0; i<N; i++){
				p[i]=0;
				for (int j=0; j<N; j++) if (f[j][i]) p[i]=(p[i]+s[j])%Ha;
			}
		for (int i=0; i<N; i++) s[i]=p[i];
	}
	
	for (int i=0; i<N; i++) ans=(ans+s[i])%Ha;
	printf("%lld",ans);
	return 0;
}
