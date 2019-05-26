#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//=====================
int n,i,pos_mark,ma;
long long ans;
int a[100066];
bool bj;
//======================
int main() {
	freopen("road.in","rb",stdin);
	freopen("road.out","wb",stdout);
	//===============================
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]>a[i-1]) {
			if (!bj) {
				pos_mark=i-1;
				bj=true;
				ma=a[i]-a[i-1];
			}
			else
				ma+=a[i]-a[i-1];
		}
		if (a[i]<a[i-1]) {
			bj=false;
			ans+=(long long)ma;
			ma=0;
		}
	}
	ans+=ma;
	//========================
	printf("%d",ans);
	//============================
	return 0;
}

