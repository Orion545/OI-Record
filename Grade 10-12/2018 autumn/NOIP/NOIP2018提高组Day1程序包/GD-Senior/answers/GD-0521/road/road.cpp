#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define INF 1e9
using namespace std;
int a[100010],res[100010];
int n,ans;
inline int rd(){
	int ret=0;char c=getchar();
	for(;!isdigit(c);)c=getchar();
	for(;isdigit(c);)ret=ret*10+c-'0',c=getchar();
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd(),
		res[i]=a[i]-a[i-1];
	int i=1,j=2;
	while(i<=n){
		if(res[i]==0)i++;
		while(res[i]!=0){
			if(res[j]<0){
				int tmp=min(-res[j],res[i]);
				res[j]+=tmp;
				res[i]-=tmp;
				ans+=tmp;
				if(res[j]!=0)j--;
			}
			j++;
			if(j>n)break;
		}
		if(j>n)break;
	}
	for(int i=1;i<=n;i++)
		ans+=res[i];
	printf("%d\n",ans);
	return 0;
}