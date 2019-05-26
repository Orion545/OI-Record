#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int main(){
	int i,j,cnt;
	scanf("%d",&n);
	if(n==0){
		printf("a");return 0;
	}
	if(n==1){
		printf("aa");return 0;
	}
	for(i=0;i<26;i++){
		cnt=0;
		while((cnt+2)*(cnt+1)/2<=n) cnt++;
		n-=(cnt*(cnt+1)/2);
		if(cnt==0) continue;
		for(j=0;j<=cnt;j++) printf("%c",char('a'+i));
	}
} 
