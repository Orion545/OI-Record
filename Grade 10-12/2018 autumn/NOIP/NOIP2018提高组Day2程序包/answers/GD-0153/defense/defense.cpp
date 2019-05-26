#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define clr(x,y) memset(x,y,sizeof(x))
#define in(a) a=read()
#define out(a) printf("%d\n",a)
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define maxn 200010
int l,nxt[maxn*2],head[maxn*2],to[maxn*2],X[maxn*2];
void add(int x,int y){l++;nxt[l]=head[x];head[x]=l;to[l]=y;}
int v[maxn];
ll f[maxn][2];
void dfs(int x,int fa){
	FORL(i,x){
		int c=to[i];
		if(c==fa)continue;
		dfs(c,x);
		f[x][1]+=min(f[c][0],f[c][1]);
		f[x][0]+=f[c][1];	
	}
}
int n,m;
ll a[maxn][2],b[maxn][2];
void baoli1(){
	FOR(i,1,n){
		a[i][0]=a[i-1][1];
		a[i][1]=min(a[i-1][1],a[i-1][0])+v[i];
	}
	FORD(i,n,1){
		b[i][0]=b[i+1][1];
		b[i][1]=min(b[i+1][1],b[i+1][0])+v[i];
	}
	FOR(i,1,m){
		int A,x,B,y;
		in(A);in(x);in(B);in(y);
		(!x&&!y)?out(-1):printf("%lld\n",a[A][x]+b[B][y]); 
	}
}
void baoli2(){
	FOR(i,2,n){
		a[i][0]=a[i-1][1];
		a[i][1]=min(a[i-1][1],a[i-1][0])+v[i];
	}
	FORD(i,n,2){
		b[i][0]=b[i+1][1];
		b[i][1]=min(b[i+1][1],b[i+1][0])+v[i];
	}
	FOR(i,1,m){
		int A,x,B,y;
		in(A);in(x);in(B);in(y);
		printf("%lld\n",v[1]+a[B][y]+b[B][y]-v[B]*y);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char s[10];
	in(n);in(m);scanf("%s",s);
	FOR(i,1,n)in(v[i]);
	FOR(i,1,n-1){
		int x,y;
		in(x);in(y);
		add(x,y);add(y,x);
	}
	if(s[0]=='A'&&s[1]=='2'){
		baoli1();
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(s[0]=='A'&&s[1]=='1'){
		baoli2();
		fclose(stdin);fclose(stdout);
		return 0;
	}
	dfs(1,0);
	FOR(i,1,m){
		int a,x,b,y;
		in(a);in(x);in(b);in(y);
		FOR(j,1,n)f[j][0]=0,f[j][1]=v[j];
		f[a][!x]=(1ll<<50);f[b][!y]=(1ll<<50); 
		dfs(1,0);
		ll c=min(f[1][0],f[1][1]);
		if(c<(1ll<<50))printf("%lld\n",c); 
		 else out(-1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

