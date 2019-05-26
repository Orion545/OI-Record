#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100];
bool a1[25000];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T;scanf("%d",&T);
	while(T--){
		int n,m=0;scanf("%d",&n);
		memset(a1,0,sizeof a1);a1[0]=1;
		for(int*z=a;z<a+n;z++)scanf("%d",z);sort(a,a+n);
		for(int z=0;z<n;z++)if(!a1[a[z]]&&++m)for(int y=a[z];y<=a[n-1];y++)a1[y-a[z]]&&(a1[y]=1);
		printf("%d\n",m);
	}
	
	return 0;
}
