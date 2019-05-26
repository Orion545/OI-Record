#include<map>
#include<set>
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
#define INF 2147483647
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int n,x,y,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	qread(n);
	y=0;
	for(int i=1;i<=n;i++){
		qread(x);
		ans+=std::max(x-y,0);
		y=x;
	}
	printf("%d\n",ans);
	return 0;
}
/*
-------
InPut1
-------
6
4 3 2 5 3 5
-------
OutPut1
-------
9
*/
