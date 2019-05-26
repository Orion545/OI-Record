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
#define mn 100020
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
const int mxn=1000000;
int f[mn][30],b[mn],q[mxn+20][3],n,h,t,bb[mn];
struct node{
	int x,h;
}a[mn];
inline int Mi(int x,int y){
	if(x>y)swap(x,y);
	int k=log2(y-x+1);
	return Min(f[x][k],f[y-(1<<k)+1][k]);
}
inline bool cmp(const node &a,const node &b){return ((a.x==b.x)?a.h<b.h:a.x<b.x);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	FOR(i,1,n)a[i].x=read(),a[i].h=i,f[i][0]=a[i].x;
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=Min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	int ls=0;
	while(a[ls].x==0&&ls<=n)ls++;
	if(ls>n)return writeln(0),0;
	ls--;
	sort(a+1,a+1+n,cmp);
	h=0,t=0;
	FOR(i,1,n){
		if(!b[a[i].x]){
			b[a[i].x]=i;
			if(i>1)bb[a[i-1].x]=i-1;
		}
		if(a[i].x==0&&a[i].h>ls){
//			if(a[i].h-1==ls){ls=a[i].h;continue;}
			q[++t][0]=ls+1,q[t][1]=a[i].h-1;
			ls=a[i].h;
		}
	}
	bb[a[n].x]=n;
//	FOR(i,0,5)cout<<i<<' '<<b[i]<<' '<<bb[i]<<endl;
	q[++t][0]=ls+1,q[t][1]=n;
	int x,y,ans=0,mi,z;
	while(h!=t){
		h++;
		if(h==mxn)h=0;
		x=q[h][0],y=q[h][1],z=q[h][2];
		if(x>y)continue;
		mi=Mi(x,y)-z;
		ans+=mi;
//		cout<<x<<' '<<y<<' '<<z<<' '<<h<<' '<<t<<' '<<mi<<' '<<ans<<endl;//int xx=read();
		if(x==y)continue;
		ls=x-1;
		FOR(i,b[mi+z],bb[mi+z])if(x<=a[i].h&&a[i].h<=y){
			t++;if(t==mxn)t=0;
			q[t][0]=ls+1,q[t][1]=a[i].h-1,q[t][2]=mi+z;
			ls=a[i].h;
		}
		t++;if(t==mxn)t=0;
		q[t][0]=ls+1,q[t][1]=y,q[t][2]=mi+z;
	}
	writeln(ans);
	fclose(stdin);fclose(stdout);
	return 0;
}

