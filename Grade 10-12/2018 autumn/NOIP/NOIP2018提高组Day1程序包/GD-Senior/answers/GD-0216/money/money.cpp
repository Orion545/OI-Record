#include <iostream>
#include <cstdio>
#include <algorithm>

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
	
	const int N=101;
	
	int T;
	int n,ans;
	int a[N];
	int killed[N];
	
	int gcd (int a,int b) {
		return (b==0)?a:gcd(b,a%b);
	}
	inline int calc2 (int a,int b,int c) {
		for (register int i=0; i<=(c/a)+1; ++i) {
			int tmp=(c-i*a)/b;
			if (a*i+tmp*b==c&&tmp>=0) {
//				cout<<a<<'*'<<i<<'+'<<b<<'*'<<tmp<<'='<<c<<endl;
				return 1;
			}
		}
		return 0;
	}

	inline void Stay_Night () {
		read(T);
		while (T--) {
			read(n),ans=n;
			for (register int i=1; i<=n; ++i) {
				read(a[i]),killed[i]=0;
			}
			sort(a+1,a+n+1);
//			for (register int i=1; i<=n; ++i) {
//				cout<<a[i]<<' ';
//			}cout<<endl;
			for (register int i=1; i<=n; ++i) {
				if (killed[i]) continue;
				for (register int j=i+1; j<=n; ++j) {
					if (killed[j]) continue;
					if (a[j]%a[i]==0&&!killed[j]) --ans,killed[j]=1;//,cout<<a[i]<<' '<<a[j]<<endl;;
					if (killed[j]) continue;
					for (register int k=j+1; k<=n; ++k) {
						if (killed[k]) continue;
						if ((a[k]%a[i]==0)||(a[k]%a[j]==0)) {
							--ans,killed[k]=1;
//							cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
						} else if (calc2(a[i],a[j],a[k])) {
							--ans,killed[k]=1;
//							cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
						}
					}
				}
			}
			write(ans),putchar('\n');
		}
	}

}

int main () {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	Fate::Stay_Night();
	return 0;
}

