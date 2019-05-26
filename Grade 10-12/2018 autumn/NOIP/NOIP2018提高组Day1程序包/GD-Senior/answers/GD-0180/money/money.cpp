#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//=====================
int k,j,i,n,t,ans,x;
int a[106];
bool bj[25006];
//=================
bool fill(int dnum,int ik) {
	bool res=false;
	int ii,in;
	//======================
	if (dnum<0)
		return false;
	if (bj[dnum]||!dnum)
		return true;
	if (!ik)
		return false;
	//-----------------------
	in=dnum/a[ik];
	//=======================
	for (ii=0;ii<=in;ii++) {
		res=fill(dnum-a[ik]*ii,ik-1);
		if (res)
			return true;
	}
	return false;
}
//======================
int main() {
	freopen("money.in","rb",stdin);
	freopen("money.out","wb",stdout);
	//==================================
	scanf("%d",&t);
	for (k=1;k<=t;k++) {
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		//=====================
		sort(a+1,a+1+n);
		memset(bj,false,sizeof(bj));
		ans=1;	x=a[1];
		if (a[1]==1) {
			printf("1\n");
			continue;
		}
		//================
		for (i=2;i<=n;i++) {
			bj[x]=true;
			if (!fill(a[i],i-1))
				ans++;
			x=a[i];
		}
		//=======================
		printf("%d\n",ans);
	}
	//============================
	return 0;
}

