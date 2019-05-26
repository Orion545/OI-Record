#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int N=100000;
const int E=(N-1)*2;
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return neg==true?-x:x;
}
inline void Read(int &x){x=Read();}
//Edge Directory
struct Edge_Directory{
	int len,head[N+1],to[E+1],next[E+1];
	inline void Insert(int x,int y){to[++len]=y,next[len]=head[x],head[x]=len;}
}ed;
//Tree DP
bool fail;
int cost[N+1],need[N+1];
long long f[N+1],g[N+1];
void Tree_DP(int x,int fa){
	f[x]=g[x]=0;
	for(int e=ed.head[x];e!=0;e=ed.next[e]){
		int y=ed.to[e];
		if(y==fa)continue;
		Tree_DP(y,x);
		f[x]+=std::min(f[y],g[y]);
		g[x]+=f[y];
	}
	f[x]+=cost[x];
	if(need[x]==1)f[x]=LLONG_MAX>>1;
	else if(need[x]==2)g[x]=LLONG_MAX>>1;
	if(f[x]>=(LLONG_MAX>>1)&&g[x]>=(LLONG_MAX>>1))fail=true;
}
//Tree DP1
long long f1[N+1],g1[N+1];
void Tree_DP1(int x,int fa){
	f1[x]=g1[x]=0;
	for(int e=ed.head[x];e!=0;e=ed.next[e]){
		int y=ed.to[e];
		if(y==fa)continue;
		Tree_DP1(y,x);
		f1[x]+=std::min(f1[y],g1[y]);
		g1[x]+=f1[y];
	}
	f1[x]+=cost[x];
	if(x==1)g1[x]=LLONG_MAX>>1;
}
void Solve1(int x,int fa){
	if(x!=1)f1[x]=std::min(f1[fa],g1[fa]),g1[x]=f1[fa];
	for(int e=ed.head[x];e!=0;e=ed.next[e])
		if(ed.to[e]!=fa)Solve1(ed.to[e],x);
}
//Main
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=Read(),m=Read();
	char type[3];
	scanf("%s",type);
	for(int i=1;i<=n;++i)Read(cost[i]);
	for(int i=1;i<n;++i){
		int x=Read(),y=Read();
		ed.Insert(x,y),ed.Insert(y,x);
	}
	if(type[1]=='1'&&n*m>=20000000){
		Tree_DP1(1,0),Solve1(1,0);
		for(int i=1;i<=m;++i){
			int x=Read(),p=Read(),y=Read(),q=Read();
			printf("%d\n",q==0?g[y]:f[y]);
		}
	}
	else{
		for(int i=1;i<=m;++i){
			int x=Read(),p=Read(),y=Read(),q=Read();
			need[x]=p+1,need[y]=q+1;
			fail=false,Tree_DP(1,0);
			printf("%d\n",fail==true?-1:std::min(f[1],g[1]));
			need[x]=0,need[y]=0;
		}
	}
	return 0;
}

