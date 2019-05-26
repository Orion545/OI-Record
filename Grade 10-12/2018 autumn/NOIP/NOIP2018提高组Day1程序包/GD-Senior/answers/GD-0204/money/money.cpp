/***************************************************
*This code is By @1353055672(ligen).               *
*Noip 2018 rp++                                    *
***************************************************/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define ll long long
#define ull unsigned long long
#define infint (int)(1<<30)
#define infll (ll)(1e18)
#define mod (int)(1e9+7)
#define FOR(a,b,c) for(register ll a=b;a<=c;++a)
#define FORD(a,b,c) for(register ll a=b;a>=c;--a)
using namespace std;
inline ll read(){
	char c=getchar();
	int f=1;ll x=0;
	for(;c<'0'||c>'9';f=((c=='-')?-1:f),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+c-'0',c=getchar());
	return x*f;
}
char cc[120];
inline void write(ll x){
	if(x==0){putchar('0');return;}
	if(x<0)putchar('-'),x=-x;
	int l=0;
	while(x)cc[++l]=x%10+'0',x/=10;
	FORD(i,l,1)putchar(cc[i]);
}
inline void write_(ll x){write(x);putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
inline ll gcd(ll a,ll b){return ((b==0)?a:gcd(b,a%b));}
inline ll lcm(ll a,ll b){return 1ll*a/gcd(a,b)*b;}
//------------------------------Head Files---------------------------//
const int mn=32800;
int n,a[120],m,g[mn],er[mn];
inline int lb(int x){
	return x&(-x);
}
inline bool ch(int f,int x){
	if(f==0)return x==0;
	int l=lb(f),nxf=f-l;
	l=er[l];
	if(x%a[l]==0)return 1;
	for(int i=0;x>=a[l]*i;i++)if(ch(nxf,x-a[l]*i))return 1;
	return 0;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	while(t--){
		n=read(),m=(1<<n)-1;
		FOR(i,0,m)g[i]=infint;
		g[0]=0;
		FOR(i,1,n)a[i]=read(),g[(1<<(i-1))]=1,er[1<<(i-1)]=i;
		FOR(i,1,m){
			FOR(j,1,n)if(!(i&(1<<(j-1)))){
				if(ch(i,a[j]))g[i|(1<<(j-1))]=Min(g[i|(1<<(j-1))],g[i]);
				else g[i|(1<<(j-1))]=Min(g[i|(1<<(j-1))],g[i]+1);
			}
		}
		writeln(g[m]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

