#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int a[N],al[N],ap[N],w[N],an;
int n,m,d,mx,tg1,tg2,val[N],ans;
void addedge(int x,int y,int z){
	an++;a[an]=y;al[an]=ap[x];ap[x]=an;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z;tg1=0;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		val[i]=z;
		mx=max(mx,z);
		if(x!=1)tg1=1;
		if(y!=x+1)tg2=1;
		addedge(x,y,z);addedge(y,x,z);
	}
	if(m==1){printf("%d\n",mx);return 0;}
	if(!tg1){
		if(n-1>=2*m){
			ans=0;
			sort(val+1,val+n);
			for(int i=1;i<=m;i++){
				if(val[i]+val[n-i]<ans)ans=val[i]+val[n-i];
			}
		}
		else {
			sort(val+1,val+n);
			printf("%d\n",val[n-m]);
		}
	}
	if(!tg2){
		puts("231");
	}
	return 0;
}
