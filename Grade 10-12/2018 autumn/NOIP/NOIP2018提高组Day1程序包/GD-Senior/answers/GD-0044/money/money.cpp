#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
#define F(i,x,y) for(int i=x;i<=y;++i)

using namespace std;

const int M=55010;
long long n,ans;
long long a[M];
bool f[M];
long long read(){
	long long ret=0;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	while((ch>='0'&&ch<='9')) ret=ret*10+ch-'0',ch=getchar();
	return ret;
}

void work1(){
	for(int i=n;i;i--){
		memset(f,false,sizeof(f));
		F(k,1,i-1) f[a[k]]=true;
		
		F(j,a[1],a[i]){
			if(!f[j]) continue;
			F(k,1,i-1){
				if(j+a[k]>a[i]) break;
				f[j+a[k]]=true;
				if(f[a[i]]) break;
			}
			if(f[a[i]]) break;
		}
		if(f[a[i]]) ans--;
	}
}

//long long f2[M];
//int tot=0,to[M*2],las[M*2],nxt[M*2];
//void Link(int x,int y,int z){
//	to[++tot]=y;
//	nxt[tot]=las[x];
//	las[x]=tot;
//}
//void work2(){
//	for(int i=n;i>1;i--){
//		memset(f2,0x7f/3,sizeof(f2));
//		f2[0]=0;
//		
//		tot=0;
//		memset(las,0,sizeof(las));
//		dij();
//		if(f2[a[i]%a[i-1]]+a[i-1]<=a[i]) ans--; 
//	}
//}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	long long _=read();
	while(_--){
		n=read();
	
		F(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		
		ans=n;
		
		work1();

		
		printf("%lld\n",ans);
	}
	return 0;
}
