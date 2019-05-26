#include<iostream>
#include<cstdio>
using namespace std;
int n,d1,d0,i,j,m=0,mx,mi,h;
long long k=0;
bool y,x;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&mi);
	scanf("%d",&d0);mx=d0;
	y=1;//上升 
	if(mi>mx){
		h=mi;mi=mx;mx=h;
		y=0;//下降 
	}
	for(i=0;i<n-2;i++){
	    scanf("%d",&d1);
	    if(y){//上升 
	    	if(d1<d0){//上升变下降 
	    		y=0;
	    	}
	    	else {
	    		mx=d1;
	    	}
	    }
	    else{//下降 
	    	if(d1>d0){//下降变上升 
	    		k+=(mx-m);
	    		m=d0;
	    		mx=d1;
	    		y=0;
	    	}
	    }
	    d0=d1;
	}
	k+=(mx-m);
	printf("%lld",k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
