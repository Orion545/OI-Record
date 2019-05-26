#include<cstdio>
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,a=0;scanf("%d",&n);
	for(int z=0,y;n--;)scanf("%d",&y),a+=y>z?y-z:0,z=y;
	printf("%d",a);
	
	return 0;
}
