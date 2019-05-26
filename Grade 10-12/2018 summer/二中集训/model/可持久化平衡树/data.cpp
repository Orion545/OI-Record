#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<ctime>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	int n=10000,m=20000,cnt1=0,t1,t2,i;
	printf("%d\n",n);
	printf("%d\n",m);
	for(i=1;i<=n;i++) printf("%d ",random(1,10000));
	puts("");
	for(i=1;i<=m;i++){
		t1=random(1,3);
		if(t1==1){
			t2=random(1,n);
			cnt1++;printf("%d %d %d\n",t1,t2,random(t2,n));
		}
		if(t1==2){
			t2=random(1,n);
			printf("%d %d %d\n",t1,t2,random(t2,n));
		}
		if(t1==3){
			printf("3 %d\n",random(0,cnt1));
		}
	}
}
