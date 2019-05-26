/* 
ID: marcoli2 
LANG: C++ 
TASK: milk
*/  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct farmer{
	int cost,size;
}a[10010];
bool cmp(farmer l,farmer r){
	return l.cost<r.cost;
}
int n,m;
int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int i,j,ans=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].cost,&a[i].size);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++){
		if(a[i].size>=m){
			ans+=m*a[i].cost;break;
		}
		else{
			ans+=a[i].size*a[i].cost;m-=a[i].size;
		}
	}
	printf("%d\n",ans);
}
