#include <cstdio>
using namespace std;
#define il inline
#define rg register
#define ll long long
#define fn "game"

il char gtc();
il int read();

const ll mo=1000000007LL;

int N,M;
ll lg;
ll f[10][1000005];

int main(){
	freopen(fn".in","r",stdin),
	freopen(fn".out","w",stdout),
	N=read(),M=read();
	for(rg int i=1;i<=N;++i)
		f[i][1]=1LL;
	for(rg int i=1;i<=M;++i)
		f[1][i]=1LL;
	for(rg int i=2;i<=N;++i)
		for(rg int j=2;j<=M;++j)
			f[i][j]=(f[i-1][j]+f[i][j-1])%mo;
	lg=f[N][M]*(f[N][M]-1),lg>>=1,lg*=12,lg%=mo;
	printf("%lld\n",lg);
	return 0;
}

char gtc(){
	static char buff[0xFFFF],*p1=buff,*p2=buff;
	return ((p1==p2)&&(p2=(p1=buff)+fread(buff,1,0xFFFF,stdin)))?(EOF):(*p1++);
}
int read(){
	int t=0;
	char c=gtc();
	while((c<'0')||(c>'9'))
		c=gtc();
	while((c>='0')&&(c<='9'))
		t=t*10+c-'0',
		c=gtc();
	return t;
}
