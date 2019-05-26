#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define mn 50020
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
//---------------------------Head Files-------------------------------//
struct node{
	int x,y,h;
}a[mn];
int fir[mn],nxt[mn],y[mn],tot,n,m,f[mn],dfn[mn],cnt,an[mn],de[mn];
inline int gf(int x){return ((f[x]==x)?x:(f[x]=gf(f[x])));}
inline bool cmp(const node &a,const node &b){return ((de[a.x]==de[b.x])?(a.y>b.y):(de[a.x]<de[b.x]));}
inline void add(int x,int yy){
	nxt[++tot]=fir[x];fir[x]=tot;y[tot]=yy;
}
inline void dfs(int x,int fa){
//	cout<<x<<' '<<fa<<' '<<cnt<<endl;
	dfn[++cnt]=x;
	for(int i=fir[x];i;i=nxt[i])if(y[i]!=fa)dfs(y[i],x);
}
inline void dfs2(int x,int fa){
	de[x]=de[fa]+1;
	for(int i=fir[x];i;i=nxt[i])if(y[i]!=fa)dfs2(y[i],x);
}
inline bool ch(){
	FOR(i,2,n)if(gf(i)!=gf(i-1))return 0;
	return 1;
}
inline bool ch2(){
	FOR(i,1,n)if(dfn[i]>an[i])return 0;
	else if(dfn[i]<an[i])return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	FOR(i,1,m){
		a[i].x=read(),a[i].y=read();a[i].h=i;
		add(a[i].x,a[i].y),add(a[i].y,a[i].x);
//		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	}
	if(m==n-1){
		dfs2(1,0);
		FOR(i,1,m)if(de[a[i].x]>de[a[i].y])swap(a[i].x,a[i].y);
		sort(a+1,a+1+m,cmp);
//		FOR(i,1,m)cout<<a[i].x<<' '<<a[i].y<<endl;
		FOR(i,1,n)fir[i]=0;
		FOR(i,1,m)add(a[i].x,a[i].y);//,add(a[i].y,a[i].x);
		dfs(1,0);
		FOR(i,1,n-1)write_(dfn[i]);writeln(dfn[n]);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	bool vv=0;
	FOR(ii,1,m){
		FOR(i,1,n)fir[i]=0,f[i]=i,de[i]=0;cnt=tot=0;
		FOR(i,1,m){
			if(a[i].h!=ii)add(a[i].x,a[i].y),add(a[i].y,a[i].x),
			f[gf(a[i].x)]=gf(a[i].y);
//			a[i].h=i;
		}
		if(!ch())continue;
		dfs2(1,0);
		FOR(i,1,m)if(a[i].h!=ii&&de[a[i].x]>de[a[i].y])swap(a[i].x,a[i].y);
		sort(a+1,a+1+m,cmp);
//		writeln(ii);FOR(i,1,m)if(a[i].h!=ii)cout<<a[i].x<<' '<<a[i].y<<endl;
		FOR(i,1,n)fir[i]=0;tot=0;
		FOR(i,1,m)if(a[i].h!=ii)add(a[i].x,a[i].y);//,add(a[i].y,a[i].x);
		dfs(1,0);
		if(ch2()||!vv){FOR(i,1,n)an[i]=dfn[i];vv=1;}
//		FOR(i,1,m)write_(dfn[i]);puts("");
	}
	FOR(i,1,n-1)write_(an[i]);writeln(an[n]);
	fclose(stdin);fclose(stdout);
	return 0;
}

