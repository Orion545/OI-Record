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
#define mn 100020
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
int fir[mn],nxt[mn],y[mn],c[mn],sum[mn],x,yy,z,n,m,mx[mn],tot,In[mn],a[mn];
ll su;
inline void add(int x,int yy,int z){
	nxt[++tot]=fir[x];fir[x]=tot;y[tot]=yy;c[tot]=z;In[x]++;
}
inline void dfs(int x,int fa){
	bool v=0;
	for(int i=fir[x];i;i=nxt[i])if(y[i]!=fa){
		sum[y[i]]=sum[x]+c[i];
		v=1;
		dfs(y[i],x);
		mx[x]=Max(mx[x],mx[y[i]]);
	}
	if(!v)mx[x]=sum[x];
}
inline void so1(){
	dfs(1,0);
	ll ans=0,mx1=0,mx2=0;
//	FOR(i,1,n)write_(mx[i]);puts("");
	for(int i=fir[1];i;i=nxt[i]){
		if(mx[y[i]]>=mx1)mx2=mx1,mx1=mx[y[i]];
		else if(mx[y[i]]>=mx2)mx2=mx[y[i]];
//		cout<<y[i]<<' '<<mx1<<' '<<mx2<<endl;
	}
	ans=mx1+mx2;
	writeln(ans);
	return;
}
int cnt;
inline void dfs2(int x,int fa){
	for(int i=fir[x];i;i=nxt[i])if(y[i]!=fa){
		a[++cnt]=c[i];dfs2(y[i],x);
	}
}
inline bool ch(int x){
	int sum=0,ans=0;
	FOR(i,1,cnt){
		sum+=a[i];
		if(sum>=x)ans++,sum=0;
	}
//	cout<<x<<' '<<ans<<endl;
	return ans>=m;
}
inline void so2(){
	int l=0,r=su+1,mid,x=0;
	FOR(i,1,n)if(In[i]==1){x=i;break;}
	cnt=0;dfs2(x,0);
	while(l+1<r){
		mid=(l+r)>>1;
		if(ch(mid))l=mid;else r=mid;
	}
	if(ch(r))l=r;
	writeln(l);
	return;
}
inline bool cmp2(int a,int b){return a>b;}
inline void so3(){
	cnt=0;
	for(int i=fir[1];i;i=nxt[i])a[++cnt]=c[i];
	sort(a+1,a+1+cnt,cmp2);
	ll ans=infll;
//	FOR(i,1,cnt)write_(a[i]);puts("");
	int r=m*2;
	FOR(i,1,m)ans=Min(ans,a[r]+a[i]),r--;//,cout<<i<<' '<<r<<endl;
	writeln(ans);
	return;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	bool li=1,ai1=1;
	FOR(i,1,n-1){
		x=read(),yy=read(),z=read(),add(x,yy,z),add(yy,x,z);
		if(yy!=x+1)li=0;
		if(x!=1)ai1=0;
		su+=z;
	}
	if(m==1)so1();else if(li)so2();else
	if(ai1)so3();
	fclose(stdin);fclose(stdout);
	return 0;
}

