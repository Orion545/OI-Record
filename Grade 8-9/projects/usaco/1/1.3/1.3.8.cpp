/* 
ID: marcoli2 
LANG: C++ 
TASK: skidesign
*/  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int n,a[1010];
int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	int i,j,tmp,ans=inf;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=90;i++){
		tmp=0;
//		cout<<i<<endl;
		for(j=1;j<=n;j++){
			if(a[j]>=i&&a[j]<=i+17) continue;
//			cout<<j<<ends;
			if(a[j]<i) tmp+=(i-a[j])*(i-a[j]);
			else tmp+=(a[j]-i-17)*(a[j]-i-17);
		}
//		cout<<endl<<tmp<<endl;
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
}
