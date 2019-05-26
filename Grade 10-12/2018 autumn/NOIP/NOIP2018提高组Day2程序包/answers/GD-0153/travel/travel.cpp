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
#define out(a) printf("%d\n",a);
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define maxn 5010
int a[maxn][maxn],num[maxn];
int top,z[maxn];
bool vis[maxn];
int w,h[maxn];
bool huan(int x,int fa){
	if(vis[x]){
		while(top){
			h[++w]=z[top];
			if(z[top--]==x)break;
		}
		return 1;
	}
	vis[x]=1;z[++top]=x;
	FOR(i,1,num[x])if(a[x][i]!=fa&&huan(a[x][i],x))return 1;
	top--;
	return 0;
}
bool u[maxn][maxn];
int ans[maxn],q[maxn],k;
void dfs(int x,int fa){
	q[++k]=x;
	FOR(i,1,num[x]){
		int c=a[x][i];
		if(u[x][c]||c==fa)continue;
		dfs(c,x); 
	}
}
bool check(){
	FOR(i,1,k){
		if(q[i]>ans[i])return 0;
		if(q[i]<ans[i])return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	in(n);in(m);
	FOR(i,1,m){
		int x,y;
		in(x);in(y);
		a[x][++num[x]]=y;
		a[y][++num[y]]=x;
	}
	FOR(i,1,n)sort(a[i]+1,a[i]+num[i]+1);
	if(!huan(1,0)){
		dfs(1,0); 
		FOR(i,1,k)printf("%d ",q[i]);
	}
	 else {
	 	FOR(i,1,n)ans[i]=n+1;
	 	FOR(i,2,w){
	 		u[h[i-1]][h[i-2]]=u[h[i-2]][h[i-1]]=0;
			u[h[i]][h[i-1]]=u[h[i-1]][h[i]]=1;
			k=0;
			dfs(1,0);
			if(check())FOR(i,1,k)ans[i]=q[i];
	 	}
	 	FOR(i,1,k)printf("%d ",ans[i]);
	 }
	 fclose(stdin);fclose(stdout);
	 return 0;
}
	

