#include <iostream>
#include <cstdio>
using namespace std ;
int lrd,zz,ans=0,ls;
int rd[100005];

void l (int sl, int bss){
	if(rd[bss]==0) return;
	if(rd[bss]-sl<0){
		if (bss-1!=0) l(rd[bss],bss-1);
		rd[bss]=0;
	}
	if(rd[bss]-sl>=0){
		if (bss-1!=0) l(sl,bss-1);
		rd[bss]=rd[bss]-sl;
	}
}
void r (int sr,int bss){
	if(rd[bss]==0) return;
	if(rd[bss]-sr<0){
		if (bss+1<=lrd) r(rd[bss],bss+1);
		rd[bss]=0;
	}
	if(rd[bss]-sr>=0){
		if (bss+1<=lrd) r(sr,bss+1);
		rd[bss]=rd[bss]-sr;
	}	
}

void os(){
	for (;;){
		zz=1;
		ls=rd[1];
		for (int i=2;i<=lrd;i++){
			if (rd[i]>ls){
				zz=i;
				ls=rd[i];	
			}
		}
		if(ls==0) return;
		if(zz!=1)   l(ls,zz-1);
		if(zz!=lrd) r(ls,zz+1);
		rd[zz]=0;
		ans+=ls;
	}
}

int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> lrd;
	for (int i=1;i<=lrd;i++)cin >> rd[i];
	os();
	cout << ans;
	return 0;
}
