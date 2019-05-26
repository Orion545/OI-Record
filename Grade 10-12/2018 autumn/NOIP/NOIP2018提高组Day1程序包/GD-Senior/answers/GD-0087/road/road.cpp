#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+7;
int i,j,k,l,t,n,m,ans,a[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d",&n);
    fo(i,1,n){
	    scanf("%d",&a[i]);
	    if(t>a[i])ans+=t-a[i];
	    t=a[i];
	}
    if(t)ans+=t;
	printf("%d\n",ans);
}
