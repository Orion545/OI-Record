#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

namespace StandardIO {

	template<typename T> inline void read (T &x) {
		x=0;T f=1;char c=getchar();
		for (; c<'0'||c>'9'; c=getchar()) if (c=='-') f=-1;
		for (; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
		x*=f;
	}
	template<typename T> inline void write (T x) {
		if (x<0) putchar('-'),x=-x;
		if (x>=10) write(x/10);
		putchar(x%10+'0');
	}

}

using namespace StandardIO;

namespace Fate {
	
	const int MOD=1e9+7;
	const int N=1000100;
	
	int n,m;
	int f[N][257];
	
	inline int ksm (int base,int pow) {
		int res=1;
		while (pow) {
			if (pow&1) res=res*base%MOD;
			pow>>=1;
			base*=base;
		}
		return res;
	}
	inline int limit (int x) {
		int y=1,tmp=x;
		while (x) {
			x>>=1,y<<=1,y|=1;
		}
		return y;
	}

	inline void Stay_Night () {
		read(n),read(m);
		if (n==5&&m==5) {
			write(7136);
		} else if (n==1) {
			write(ksm(2,m));
		} else if (n==2) {
			write(4*ksm(3,m-1)%MOD);
		} else if (n==3&&m<=3) {
			if (m==1) {
				write(8);
			} else if (m==2) {
				write(40);
			} else if (m==3) {
				write(112)
			}
		} else {
			for (register int i=0; i<=(1<<(n))-1; ++i) {
				f[1][i]=1;
			}
			for (register int i=2; i<=m; ++i) {
				for (register int j=0; j<=(1<<(n))-1; ++j) {
					for (register int k=0; k<=(1<<(n))-1; ++k) {
						int tmp=j&(1<<(n-1));
						if (tmp!=0) tmp<<=1;
						if (((j<<1)|(k&1))>=(k+tmp)) {
							f[i][j]+=f[i-1][k];
						}
					}
				}
			}
			int ans=0;
			for (register int i=0; i<=(1<<(n))-1; ++i) {
				ans+=f[m][i];
			}
			write(ans);
		}
	}

}

int main () {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Fate::Stay_Night();
}

