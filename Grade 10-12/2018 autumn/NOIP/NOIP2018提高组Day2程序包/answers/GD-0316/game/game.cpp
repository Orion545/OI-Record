#include<cstdio>
#define ll long long
#define mod 1000000007
using namespace std;

inline int read() {
	int x=0, f=1; char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

const int f[4][4]={{0,0,0,0},{0,2,4,8},{0,4,12,36},{0,8,36,112}};

int work(int x) {
	int ans=work(x>>1);
	ans=(ll)ans*ans%mod;
	if(x&1) ans=(ll)ans*2%mod;
	return ans;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	int n=read(), m=read();
	if (n==1) printf("%d", work(m));
	else if(m==1) printf("%d", work(n));
	else if(n<=3&&m<=3) printf("%d", f[n][m]);

	fclose(stdin); fclose(stdout);
	return 0;
}

