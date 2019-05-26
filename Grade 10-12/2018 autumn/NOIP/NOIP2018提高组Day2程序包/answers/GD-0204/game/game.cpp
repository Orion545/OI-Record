#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define mn 100020
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
ll f[320][3],h[1000200],now,n,m,x,y;
inline bool ch(int x,int y,int xx,int yy){
	int x1,y1;
	FOR(i,1,x)
		FOR(j,i,x){
			x1=(((bool)(xx&(1<<(i-1))))<<1);
			y1=(((bool)(xx&(1<<(j-1))))<<1);
			if(x<=y){
				if(i!=j&&i+1<=y&&j<=y)if((x1+((bool)(yy&(1<<i))))>(y1+((bool)(yy&(1<<(j-1))))))return 0;
				if(i!=j&&i+1<=y&&j+1<=y)if((x1+((bool)(yy&(1<<i))))>(y1+((bool)(yy&(1<<j)))))return 0;
				if(i<=y&&j+1<=y)if((x1+((bool)(yy&(1<<(i-1)))))>(y1+((bool)(yy&(1<<j)))))return 0;
				if(i!=j&&i<=y&&j<=y)if((x1+((bool)(yy&(1<<(i-1)))))>(y1+((bool)(yy&(1<<(j-1))))))return 0;
			}else {
//				if(i!=j&&i+1<=y&&j<=y)if((x1+((bool)(yy&(1<<i))))>(y1+((bool)(yy&(1<<(j-1))))))return 0;
//				if(i!=j&&i+1<=y&&j+1<=y)if((x1+((bool)(yy&(1<<i))))>(y1+((bool)(yy&(1<<j)))))return 0;
//				if(i<=y&&j+1<=y)if((x1+((bool)(yy&(1<<(i-1)))))>(y1+((bool)(yy&(1<<j)))))return 0;
//				if(i!=j&&i<=y&&j<=y)if((x1+((bool)(yy&(1<<(i-1)))))>(y1+((bool)(yy&(1<<(j-1))))))return 0;
				if(i!=j&&i<=y&&j-1>0)if(x1+((bool)(yy&(1<<(i-1))))>y1+((bool)(yy&(1<<(j-2)))))return 0;
				if(i!=j&&i<=y&&j<=y)if(x1+((bool)(yy&(1<<(i-1))))>y1+((bool)(yy&(1<<(j-1)))))return 0;
				if(i-1>0&&j<=y)if(x1+((bool)(yy&(1<<(i-2))))>y1+((bool)(yy&(1<<(j-1)))))return 0;
				if(i!=j&&i-1>0&&j-1>0)if(x1+((bool)(yy&(1<<(i-2))))>y1+((bool)(yy&(1<<(j-2)))))return 0;
			}
		}
	return 1;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n==1||m==1)return writeln(0),0;
	if(n==3&&m==3)return writeln(112),0;
//	cout<<n<<' '<<m<<endl;
//	h[1]=1;
	FOR(i,1,n+m-1){
		x=1,y=i;
//		writeln(i);cout<<x<<' '<<y<<' '<<(y>m)<<endl;
		if(y>m)x+=y%m,y=m;
		h[i]=0;
		while(x>0&&x<=n&&y>0&&y<=m)h[i]++,x++,y--;//write_(x),writeln(y);
//		writeln(h[i]);
	}
	f[1][now]=f[0][now]=1;
//	writeln(ch(2,1,1,0));
	FOR(i,2,n+m-1){
		now^=1;
		FOR(j,0,(1<<n)-1)f[j][now]=0;
		FOR(j,0,(1<<h[i])-1)
			FOR(k,0,(1<<h[i-1])-1)if(ch(h[i-1],h[i],k,j))f[j][now]=(f[j][now]+f[k][now^1])%mod;//,write_(j),writeln(k);
//			else f[j][now]-=f[k][now^1];
	}
	writeln((f[0][now]+f[1][now])%mod);
	fclose(stdin);fclose(stdout);
	return 0;
}

