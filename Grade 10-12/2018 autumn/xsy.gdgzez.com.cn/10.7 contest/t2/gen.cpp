#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	std::ios::sync_with_stdio(false);
	int n=100000,o=0,m=100,i,len,t1,t2,j;
	printf("%d %d\n",n,o);
	for(i=1;i<=n;i++){
		len=random(1,10);
		for(j=0;j<len;j++) putchar('a'+(char)(random(0,25)));
		putchar(' ');
	}
	putchar('\n');
	for(i=2;i<=n;i++) printf("%d ",random(1,i-1));
	puts("");
	printf("%d\n",m);
	while(m--){
		t1=random(1,n);t2=random(1,n);
		len=random(1,1000);
		printf("%d %d ",t1,t2);
		for(j=0;j<len;j++) putchar('a'+(char)(random(0,25)));
		putchar('\n');
	}
}
