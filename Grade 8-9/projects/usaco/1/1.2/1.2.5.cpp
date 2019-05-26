/* 
ID: marcoli2 
LANG: C++ 
TASK: palsquare
*/  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x;
void change(int ori,int base,int re[100]){
	memset(re,0,100);
	while(ori){
		re[++re[0]]=ori%base;
		ori/=base;
	}
	return;
}
bool check(int k){
	int t1[100],t2[100];
	change(k,x,t1);change(k*k,x,t2);
	int i=1,j=t2[0],flag=1;
	while(j-i>=1){
		if(t2[i]!=t2[j]){
			flag=0;break;
		} 
		i++;j--;
	}
	return flag;
}
int main(){
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int tmp1[100],tmp2[100],i,j;
	scanf("%d",&x);
	for(i=1;i<=300;i++){
		if(check(i)){
			change(i,x,tmp1);change(i*i,x,tmp2);
			for(j=tmp1[0];j>=1;j--){
				if(tmp1[j]<=9) printf("%d",tmp1[j]);
				else printf("%c",char('A'+char(tmp1[j]-10)));
			}
			printf(" ");
			for(j=tmp2[0];j>=1;j--){
				if(tmp2[j]<=9) printf("%d",tmp2[j]);
				else printf("%c",char('A'+char(tmp2[j]-10)));
			}
			printf("\n");
		} 
	}
}
