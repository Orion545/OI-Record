/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#include<ctime>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("gen.in","w",stdout);
	srand(time(NULL));
	int n=50000,m=50000,t1,t2;
	printf("%d %d\n",n,m);
	while(m--){
		if(m>=20000){
			printf("0 ");
			t1=random(1,n);
			if(t1==1) t2=random(2,n);
			else t2=random(1,n-1);
			printf("%d %d\n",t1,t2);
		}
		else{
			printf("1 ");
			t1=random(1,n);
			if(t1==1) t2=random(2,n);
			else t2=random(1,n-1);
			printf("%d %d\n",t1,t2);
		}
	}
}
