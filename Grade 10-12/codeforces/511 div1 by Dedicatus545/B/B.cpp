#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;

void print(ll x){
	cout<<x<<'\n';
}

int main(){
	ll SDFSDF=0,TEPAN=0,tt1,tt2;
					scanf("%I64d%I64d",&SDFSDF,&TEPAN);
					
					
					
	if(SDFSDF>TEPAN) swap(SDFSDF,TEPAN);

	tt1=(TEPAN-(TEPAN%6));tt2=max(0ll,(TEPAN%6-3)*2);
				
				
				
				if(SDFSDF==1){print(tt1+tt2);return 0;}

	if((SDFSDF+TEPAN)%2){
					if(SDFSDF%2==0){
						int tmp=SDFSDF;SDFSDF=TEPAN;TEPAN=tmp;
					}
		if(SDFSDF==3){
			if(TEPAN==2) {print(4);return 0;}
								else {print(SDFSDF*TEPAN);return 0;}
		}
					else if(SDFSDF==7){
			if(TEPAN==2) {print(12);return 0;}
						else {print(SDFSDF*TEPAN);return 0;}
							}
				print(SDFSDF*TEPAN);return 0;
	}
	
	if(((SDFSDF&1)==0)&((TEPAN&1)==0)){ 
		if(TEPAN==2&&SDFSDF==2) {print(0);return 0;}
		else {print(SDFSDF*TEPAN);return 0;}
	}

	print(SDFSDF*TEPAN-1);return 0;
}
