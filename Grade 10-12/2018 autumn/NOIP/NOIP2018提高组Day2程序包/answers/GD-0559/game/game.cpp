#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int p=1000000007;

int n,m,a1,cur,ans,f[1024][2];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	a1=(1<<n)-1; cur=0;
	for(int s=0;s<=a1;++s)f[s][cur]=1;
	for(int i=1;i<m;++i){
		cur^=1;
		for(int s=0;s<=a1;++s){
			int t=s>>1;
			f[s][cur]=0;
			for(int k=t;k<=a1;++k)
			if((k&t)==t){
				f[s][cur]=(f[s][cur]+f[k][cur^1])%p;
			}
		}
	}
	ans=0;
	for(int s=0;s<=a1;++s)ans=(ans+f[s][cur])%p;
	printf("%d\n",ans);
	return 0;
}

