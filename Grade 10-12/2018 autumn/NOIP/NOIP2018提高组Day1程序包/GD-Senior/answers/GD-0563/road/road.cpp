#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
#define Maxn 100010
int a[Maxn],b[Maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int Ans=0;
	scanf("%d",&n);
	for(register int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i]-a[i-1];
		if(b[i]>0)Ans+=b[i];
	}
	printf("%d\n",Ans);
	return 0;
}
