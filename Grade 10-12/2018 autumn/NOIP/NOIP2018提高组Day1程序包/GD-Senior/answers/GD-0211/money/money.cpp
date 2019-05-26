#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
char *FS,*FT,BB[1<<12];
//#define _()	(FS==FT&&(FT=(FS=BB)+fread(BB,1,1<<12,stdin),FS==FT)?EOF:*FS++)
#define _() getchar()
int read(){
	int i=1,x=0;
	char ch=_();
	while(!isdigit(ch)){
		if(ch==EOF)exit(0);
		if(ch=='-')i=-1;
		ch=_();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=_();
	}
	return i*x;
}

#define REP(i,a,b)	for(int i=a;i<=b;i++)
#define DOW(i,a,b)	for(int i=a;i>=b;i--)
#define INF 0x3f3f3f3f
#define N 100005
#define CL(a,b)	memset(a,b,sizeof(a))
int v[N],dp[N];


int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--){
		CL(dp,0);
		int n=read(),ans=0;
		REP(i,1,n)v[i]=read();
		sort(v+1,v+1+n);
		dp[0]=1;
		DOW(i,n,1)REP(j,0,v[n]-v[i])dp[j+v[i]]+=dp[j];
		REP(i,1,n)if(dp[v[i]]==1)ans++;
		printf("%d\n",ans);
	}
	return 0;
}

