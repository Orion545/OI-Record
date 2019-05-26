#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000010];int a[1000010];
int main(){
	scanf("%s",s);int n=strlen(s),i,j,sum=0,k;
	for(i=1;i<=n;i++) a[i]=(s[n-i]-'0')*9;
	for(i=1;i<=n;i++){
		a[i+1]+=a[i]/10;a[i]%=10;
	}
	if(a[n+1]) n++;
	for(i=1;i<=n;i++) sum+=a[i];
	for(k=1;k<=n*10;k++){
		a[1]+=9;sum+=9;
		j=1;
		while(j<=n){
			if(a[j]<10) break;
			sum-=10;a[j]-=10;
			sum++;a[j+1]++;
			j++;
			if(j==n&&a[j+1]) n++;
		}
		if(sum<=9*k){
			printf("%d\n",k);return 0;
		}
	}
}
