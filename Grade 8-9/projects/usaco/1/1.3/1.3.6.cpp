/* 
ID: marcoli2 
LANG: C++ 
TASK: combo
*/  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[4],b[4];
int abs(int l,int r){
	if(l>r) swap(l,r);
	return min(r-l,l+n-r);
}
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int i,j,k,ans=0;
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&b[1],&b[2],&b[3]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if((abs(i,a[1])<=2&&abs(j,a[2])<=2&&abs(k,a[3])<=2)||(abs(i,b[1])<=2&&abs(j,b[2])<=2&&abs(k,b[3])<=2)){
//					cout<<i<<ends<<j<<ends<<k<<endl;
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
}
