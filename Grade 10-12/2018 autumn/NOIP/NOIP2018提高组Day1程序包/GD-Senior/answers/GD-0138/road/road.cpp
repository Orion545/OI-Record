#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+10;
int a[N];
int n,ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	int last=0,x;
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<=n;++i){
		x=a[i];
		if (x>last)
			ans+=x-last;
		last=x;
	}
	printf("%d\n",ans);

}
