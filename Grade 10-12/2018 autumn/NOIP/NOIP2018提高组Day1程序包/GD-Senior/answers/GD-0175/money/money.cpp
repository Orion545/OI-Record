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
#define Maxn 100
#define Maxa 25000
#define INF 2147483647
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int T,n,max,ans,a[Maxn+1];
bool f[Maxa+1];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	qread(T);
	while(T--){
		qread(n);
		ans=max=0;
		for(int i=1;i<=n;i++){
			qread(a[i]);
			max=std::max(max,a[i]);	
		}
		std::sort(a+1,a+n+1);
		mes(f,false);f[0]=true;
		for(int i=1;i<=n;i++){
			if(f[a[i]]==false){
				ans++;
				for(int j=a[i];j<=max;j++){
					if(f[j-a[i]]==true)f[j]=true;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
-------
InPut1
-------
2
4
3 19 10 6
5
11 29 13 19 17
-------
OutPut1
-------
2
5
*/
