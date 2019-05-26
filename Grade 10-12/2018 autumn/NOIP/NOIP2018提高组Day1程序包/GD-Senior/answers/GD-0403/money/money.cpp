#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long lint;
#define cout cerr
#define ni (next_num<int>())
template<class T>inline T next_num(){
	T i=0;char c;
	for(;!isdigit(c=getchar())&&c!='-';);
	bool neg=c=='-';
	neg?c=getchar():0;
	for(;i=i*10-'0'+c,isdigit(c=getchar()););
	return neg?-i:i;
}
template<class A,class B>inline void apmax(A &a,const B &b){if(a<b)a=b;}
template<class A,class B>inline void apmin(A &a,const B &b){if(b<a)a=b;}
template<class T>inline void mset(T a[],int v,int n){memset(a,v,n*sizeof(T));}
template<class T>inline void mcpy(T a[],T b[],int n){memcpy(a,b,n*sizeof(T));}
const int N=110,A=25010;
int a[N];
bool f[A];
inline int Main(){
	const int n=ni;
	for(int i=1;i<=n;i++){
		a[i]=ni;
	}
	sort(a+1,a+n+1);
	const int mx=a[n];
	f[0]=true,mset(f+1,0,mx);
	int ans=0;
	for(int i=1;i<=n;i++){
		const int v=a[i];
		if(f[v])continue;
		++ans;
		for(int j=v;j<=mx;j++){
			f[j]|=f[j-v];
		}
	}
	return ans;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(int tot=ni;tot--;printf("%d\n",Main()));
	return 0;
}
