#include<cstdio>
#include<cstring>
using namespace std;

#define min(a,b) (a<b?a:b)
const int N=100010;
int di[N];

void read(int &x){
	register char tmp=getchar();x=0;
	while(tmp<=32)	tmp=getchar();
	while(tmp>32)	x=(x<<1)+(x<<3)+tmp-'0',tmp=getchar();
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
//	for(int i=1;i<=n;++i)	scanf("%d",di+i);
	for(int i=1;i<=n;++i)	read(di[i]);
	int ans=0,lans=0;
	int le,ri=1,mi;
	register int k=le+1;
	do{
		lans=ans;
		le=0;mi=0x3f3f3f3f;
		for(ri=1;ri<=n;++ri){
			if(!di[ri]){
				if(ri-le>1){
					for(k=le+1;k<ri-4;k+=4){
						di[k]-=mi;
						di[k+1]-=mi;
						di[k+2]-=mi;
						di[k+3]-=mi;
					}
					for(;k<ri;++k){
						di[k]-=mi;
					}
				}
				if(ri-le>1)	ans+=mi;
				le=ri;
				mi=0x3f3f3f3f;
			}else	mi=min(mi,di[ri]);
		}
		if(ri-le>1)	for(register int k=le+1;k<ri;++k)	di[k]-=mi;
		if(ri-le>1)	ans+=mi;
//		if(cha==true)	lw=nw;
	}while(ans!=lans);
	printf("%d\n",ans);
	return 0;
}
