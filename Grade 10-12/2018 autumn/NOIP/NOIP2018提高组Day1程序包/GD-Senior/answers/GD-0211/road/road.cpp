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
#define INF 0x3f3f3f3f
#define N 100005

int v[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),ans=0,lo=0;
	REP(i,1,n)v[i]=read();
	REP(i,1,n)if(v[i]>=v[i-1]&&v[i]>=v[i+1]){
		ans+=v[i]-lo;
		lo=v[i];
	}else lo=min(lo,v[i]);
	printf("%d\n",ans);
	return 0;
}
