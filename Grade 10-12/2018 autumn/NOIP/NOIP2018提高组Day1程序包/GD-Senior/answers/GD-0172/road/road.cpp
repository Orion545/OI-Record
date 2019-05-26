#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int a[100010],n,ta,big,ans,le;
bool pd;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	
	ta=2;pd=0;big=a[1];le=0;ans=0;
	while (ta<=n) {
		if (!pd && a[ta]>=a[ta-1]) big=a[ta];
		else 
		if (!pd && a[ta]<a[ta-1]) pd=1;
		else
		if (pd && a[ta]>a[ta-1]) {
			ans+=big-le;pd=0;big=a[ta];le=a[ta-1];
		}
		++ta;
	}
	
	ans+=big-le;printf("%d\n",ans);
	
	return 0;
}

