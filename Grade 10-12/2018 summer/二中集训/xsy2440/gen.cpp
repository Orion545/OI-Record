#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<ctime>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
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
	int n=2000,m=2000,i,j,cntn=0;
	cout<<n<<' '<<m<<'\n';
	for(i=2;i<=n;i++){
		printf("%d %d\n",random(1,i-1),i);
	} 
	for(i=1;i<=n;i++) printf("%d\n",random(1,10));
	for(i=1;i<m;i++){
		j=random(0,1);
		if(j){
			printf("1 %d %d %d\n",random(1,n),random(1,n),random(1,10));
			cntn++;
		}
		else printf("3 %d\n",random(0,cntn));
	}
	printf("2 %d %d\n",random(1,n),random(1,n));
} 
