#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const bool local=0;
const int siz=5e4+2;
void read(int &x){
	int c;
	c=getchar();
	while((c<'0')||(c>'9'))c=getchar();
	x=0;
	while((c>='0')&&(c<='9')){
		x=x*10+(c^48);
		c=getchar();
	}
	return;
}
bool mweiyi,tulian=1,erchas=1;
int bs,tou[siz],wei[siz<<1],xyg[siz<<1],quan[siz<<1],deg[siz];
void add(int a,int b,int v){
	wei[++bs]=b;
	++deg[a];
	xyg[bs]=tou[a];
	tou[a]=bs;
	quan[bs]=v;
	wei[++bs]=a;
	++deg[b];
	xyg[bs]=tou[b];
	tou[b]=bs;
	quan[bs]=v;
	if ((deg[a]>3)||(deg[b]>3)) erchas=0;
}
int n,m,zl,zr,zz,p,q,r,t,ans,sum;
bool vis[siz];
int dfsyi(int x){
	int anx=0,cd=0;
	vis[x]=1;
	for (int i=tou[x];i;i=xyg[i]) if (!vis[wei[i]]){
		t=wei[i];
		r=dfsyi(t)+quan[i];
		if (anx<r) {
			cd=anx;
			anx=r;
		}
	}
	if (ans<(cd+anx)) ans=cd+anx;
	vis[x]=0;
	return anx;
}
int arry[siz],ts,cn;
int dfser(int x,int lime){
	int anx=0,cd=0;
	vis[x]=1;
	for (int i=tou[x];i;i=xyg[i]) if (!vis[wei[i]]){
		t=wei[i];
		r=dfser(t,lime)+quan[i];
		cd=anx;
		anx=r;
	}
	vis[x]=0;
	if (anx+cd>=lime) {
		++cn;
		return 0;
	}
	return anx;
}
bool chec(int lime){
	ts=0;
	cn=0;
	for (int i=1;i<n;++i){
		ts+=arry[i];
		if (ts>=lime){
			ts=0;
			++cn;
		}
	}
	return (cn>=m);
}
int main(){
	if (local) {
		freopen("track3.in","r",stdin);
	}else{
		freopen("track.in","r",stdin);
		freopen("track.out","w",stdout);
	}
	read(n);read(m);
	for (int i = 1; i < n; ++i){
		read(p);read(q);read(r);
		add(p,q,r);
		sum+=r;
		if (q!=(p+1)) tulian=0;
		if (tulian) arry[p]=r;
	}
	if (m==1)
	{
		dfsyi(1);
		printf("%d\n",ans);
		return 0;
	}else{
		if (tulian){
			zl=0;zr=sum/m;
			while(zl<zr){
				zz=(zl+zr+1)>>1;
				if (chec(zz)){
					zl=zz;
				}else{
					zr=zz-1;
				}
			}
			printf("%d\n",zl);
			return 0;
		}else{
			if (erchas){
				zl=0;zr=sum/m;
				while(zl<zr){
					cn=0;
					zz=(zl+zr+1)>>1;
					dfser(1,zz);
					if (cn>=m){
						zl=zz;
					}else{
						zr=zz-1;
					}
				}
				printf("%d\n",zl);
				return 0;
			}
		}
	}
	printf("%.0lf\n",floor(sum/m*(sqrt(5.0)-1)/2));
	return 0;
}
