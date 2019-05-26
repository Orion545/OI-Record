#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100010];
int main(){
	scanf("%s",s);
	int n=strlen(s),i,j;
	if(n<26){
		printf("-1\n");return 0;
	}
	j=(int)'a';
	for(i=1;i<=n;i++){
		if((int)s[i-1]<=j) s[i-1]=(char)j,j++;
		if(j==(int)'z'+1) break;
	}
	if(j==(int)'z'+1) printf("%s",s);
	else puts("-1");
}
