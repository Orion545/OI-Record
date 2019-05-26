#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#define go(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N=107;
inline int abs(int x) {
	return x>0?x:-x;
}
inline int read(int& x) {
	bool f=0;char c;
	for(;!isdigit(c=getchar());f|=(c=='-'));
	for(x=0;isdigit(c);c=getchar()) x=x*10+(c^48);
	return x=(f?-x:x);
}
inline int gcd(int a,int b) {
	int t;
	while(b)
		t=a%b,a=b,b=t;
	return a;
}
int n,t=0,a[N],f[N];
bool ok[N];
bool check3() {
	go(i,0,a[3]/a[1])
		go(j,0,a[3]/a[2])
			if(i*a[1]+j*a[2]==a[3]) return 1;
	return 0;
}
bool check4() {
	go(i,0,a[4]/a[1])
		go(j,0,a[4]/a[2])
			go(k,0,a[4]/a[3])
			if(i*a[1]+j*a[2]+k*a[3]==a[4]) return 1;
	return 0;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);while(t--) {
		bool flag=0;
		read(n);
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		go(i,1,n) read(a[i]),flag|=(a[i]==1);
		sort(a+1,a+1+n);
		if(flag || n==1) puts("1");
		else if(n==2) {
			if(a[2]%a[1]==0) puts("1");
			else puts("2");
		}
		else if(n==3) {
		_a1:
			if(check3()) {
				if(a[2]%a[1]==0) puts("1");
				else puts("2");
			}else {
				if(a[2]%a[1]==0) puts("2");
				else puts("3");
			}
		}
		else if(n==4) {
		_a2:
			if(a[2]%a[1]==0) --n;
			if(check3()) --n;
			if(check4()) --n;
			cout<<n<<"\n";
		}
		else {
			int res=n;
			go(i,2,n)
				go(j,1,i-1)
					if(a[i]%a[j]==0) {--res;ok[i]=1;break;}
			if(res==3) {int b[4],j=0;
				go(i,1,n) if(!ok[i]) b[++j]=a[i];
				go(i,1,3) a[i]=b[i];
				goto _a1;
			}
			else if(res<=2) cout<<res<<"\n";
			else if(res==4) {
				int b[5],j=0;
				go(i,1,n) if(!ok[i]) b[++j]=a[i];
				go(i,1,4) a[i]=b[i];
				goto _a2;
			}
			else {
				int yue=a[1];
				go(i,2,n) yue=gcd(yue,a[i]);
				if(yue==1) cout<<n<<"\n";
				else cout<<n-1<<"\n";
			}
		}
	}
	return 0;
}

