#include <cstdio>
#include <cstring>
#define MAXN 110
#define MAXM 30000

int read(){
	char c;
	while((c=getchar())<'0' || c>'9');
	int res=c-'0';
	while((c=getchar())>='0' && c<='9') res=res*10+c-'0';
	return res;
}

int n,m;
int a[MAXM],f[MAXM];

void gao(int x){
	for(int i=x;i<=m;i++)
		f[i]|=f[i-x];
}

void solve(){
	n=read();
	m=0;
	memset(a,0,sizeof a);
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		int t=read();
		if(t>m) m=t;
		a[t]=1;
	}
	f[0]=1;
	int ans=0;
	for(int i=1;i<=m;i++)
		if(a[i] && !f[i]){
			ans++;
			gao(i);
		}
	printf("%d\n",ans);
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
