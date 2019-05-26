/* 
ID: marcoli2 
LANG: C++ 
TASK: crypt1
*/  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[20];bool b[20];
bool check(int k){
	while(k){
		if(!b[k%10]) return 0;
		k/=10;
	}
	return 1;
}
int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int i,j,k,p,q,x=0,y=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]=1;
	for(i=1;i<=n;i++){
		x=a[i];
		for(j=1;j<=n;j++){
			x=x*10+a[j];
			for(k=1;k<=n;k++){
				x=x*10+a[k];
				for(p=1;p<=n;p++){
					y=a[p];
					for(q=1;q<=n;q++){
						y=y*10+a[q];
						if(x*a[p]<1000&&x*a[q]<1000&&x*y<10000&&check(x*a[p])&&check(x*a[q])&&check(x*y)){
//							cout<<x<<ends<<y<<ends<<x*a[p]<<ends<<x*a[q]<<ends<<x*y<<endl;
							ans++;
						} 
						y=(y-a[q])/10;
					}
					y=0;
				}
				x=(x-a[k])/10;
			}
			x=(x-a[j])/10;
		}
		x=0;
	}
	printf("%d\n",ans);
}
