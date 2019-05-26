#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define mn 200020
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
int fir[mn],nxt[mn],y[mn],tot,n,m,p[mn],x,yy,a,b,de[mn];
ll f[mn][2],ans;
char s[10];
inline void add(int x,int yy){
	nxt[++tot]=fir[x];fir[x]=tot;y[tot]=yy;
}
inline bool ch(){
	FOR(i,1,n)
		for(int j=fir[i];j;j=nxt[j])if((de[y[j]]==0||de[y[j]]==4)&&(de[i]==0||de[i]==4))return 0;
	return 1;
}
inline void dfs(int d){
	if(de[d]==1||de[d]==4){dfs(d+1);return;}
	if(d>n){
		if(!ch())return;
		ll num=0;
		FOR(i,1,n)if(de[i]==1)num+=p[i];
		ans=Min(ans,num);
		return;
	}
	de[d]=0;dfs(d+1);
	de[d]=1;dfs(d+1);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();scanf("%s",s);
	FOR(i,1,n)p[i]=read();
	FOR(i,1,n-1)x=read(),yy=read(),add(x,yy),add(yy,x);
	if(n<=10&&m<=10){
		FOR(i,1,m){
			x=read(),a=read(),yy=read(),b=read();
			FOR(j,1,n)de[j]=0;
			if(a)de[x]=1;else de[x]=4;
			if(b)de[yy]=1;else de[yy]=4;
			ans=infll;
			dfs(1);
			writeln((ans==infll?(-1):ans));	
		}
		fclose(stdin);fclose(stdout);
		return 0;
	}else
	if(s[0]=='A'){
		FOR(i,1,m){
			x=read(),a=read(),yy=read(),b=read();
			if(abs(x-yy)==1&&a==0&&b==0){writeln(-1);continue;}
			FOR(j,1,n)f[j][1]=f[j][0]=infll;
			if(x==1)f[1][1]=f[1][0]=(a?p[1]:0);else 
			if(yy==1)f[1][1]=f[1][0]=(b?p[1]:0);else f[1][1]=p[1],f[1][0]=0;
			FOR(j,2,n){
				if(x==j)f[j][1]=f[j][0]=(a?p[j]:0);else 
				if(yy==j)f[j][1]=f[j][0]=(b?p[j]:0);else {
					f[j][1]=Min(f[j-1][0],f[j-1][1])+p[j];
					if(x!=j-1&&yy!=j-1&&x!=j+1&&yy!=j+1)f[j][0]=f[j-1][1]+p[j];
				}
				
			}
			if((x==n&&a)||(yy==n&&b)||(x==n-1&&a)||(yy==n-1&&b))writeln(f[n][1]);
			else if((x==n&&!a)||(yy==n&&!b))writeln(f[n][0]);else writeln(Min(f[n][0],f[n][1]));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

