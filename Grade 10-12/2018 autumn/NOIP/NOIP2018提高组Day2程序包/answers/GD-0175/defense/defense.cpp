#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define qread(x) x=read()
#define mes(x,y) memset(x,y,sizeof(x))
#define mpy(x,y) memcpy(x,y,sizeof(x))
#define Maxn 100000
#define Maxs 4
#define INF 10000000001
inline long long read(){
	long long f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
struct Edge{
	int x,y,next;
}a[2*Maxn+1];int len,first[Maxn+1];
void ins(int x,int y){
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=first[x];first[x]=len; 
}
int n,m;
long long ans,f[Maxn+1][3],p[3][Maxn+1];
void Adp(int a,int x,int b,int y){
	if(x==0)p[0][a]=INF;
	else p[1][a]=INF;
	if(y==0)p[0][b]=INF;
	else p[1][b]=INF;
	mes(f,63);
	f[n][0]=p[1][n];
	f[n][1]=p[1][n]+INF;
	f[n][2]=p[0][n];
	for(int i=n-1;i>=1;i--){
		f[i][0]=f[i+1][1];
		f[i][1]=p[1][i]+f[i+1][2];
		f[i][2]=p[0][i]+std::min(std::min(f[i+1][0],f[i+1][1]),f[i+1][2]);
	}
 	ans=std::min(f[1][1],f[1][2]);
	if(ans>=INF)printf("-1\n");
	else printf("%lld\n",ans);
	p[0][a]=p[2][a];
	p[1][a]=0;
	p[0][b]=p[2][b];
	p[1][b]=0;
}
void CTree(int x,int fa){
	for(int k=first[x];k>0;k=a[k].next){
		int y=a[k].y;
		if(y!=fa)CTree(y,x);
	}
	f[x][0]=p[1][x];
	f[x][1]=p[1][x]+INF;
	f[x][2]=p[0][x];
	for(int k=first[x];k>0;k=a[k].next){
		int y=a[k].y;
		if(y!=fa){
			f[x][0]+=f[y][1];
			long long tmp=f[y][2];
			for(int kk=first[x];kk>0;kk=a[kk].next){
				int yy=a[kk].y;
				if(yy!=y&&yy!=fa)tmp+=std::min(f[yy][1],f[yy][2]);
			}
			f[x][1]=std::min(f[x][1],p[1][x]+tmp);
			f[x][2]+=std::min(std::min(f[y][0],f[y][1]),f[y][2]);
		}
	}
}
void Cdp(int a,int x,int b,int y){
	if(x==0)p[0][a]=INF;
	else p[1][a]=INF;
	if(y==0)p[0][b]=INF;
	else p[1][b]=INF;
	mes(f,63);
	CTree(1,1);
 	ans=std::min(f[1][1],f[1][2]);
	if(ans>=INF)printf("-1\n");
	else printf("%lld\n",ans);
	p[0][a]=p[2][a];
	p[1][a]=0;
	p[0][b]=p[2][b];
	p[1][b]=0;
}
char s[Maxs+1];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	qread(n),qread(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		qread(p[2][i]=p[0][i]);
		p[1][i]=0;
	}
	len=0;mes(first,0);
	for(int i=1;i<n;i++){
		int qread(x),qread(y);
		ins(x,y);ins(y,x);
	}
	if(s[1]=='A'){
		while(m--){
			int qread(a),qread(x),qread(b),qread(y);
			Adp(a,x,b,y);
		}
	}
	else if(s[1]=='C'){
		while(m--){
			int qread(a),qread(x),qread(b),qread(y);
			Cdp(a,x,b,y);
		}
	}
}
/*
-------
InPut1
-------
5 1 A3
1 2 3 4 5
1 2
2 3
3 4
4 5
1 1 5 1
-------
OutPut1
-------
1 3 2 5 4 6
-------
InPut2
-------
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
-------
OutPut2
-------
12
7
-1
*/
