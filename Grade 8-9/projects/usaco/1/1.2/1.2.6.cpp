/* 
ID: marcoli2 
LANG: C++ 
TASK: dualpal
*/  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int check(int ori,int base){
	int re[100]={0};
	while(ori){
		re[++re[0]]=ori%base;
		ori/=base;
	}
	int i=1,j=re[0],flag=1;
	while(j-i>=0){
		if(re[i]!=re[j]){
			flag=0;break;
		} 
		i++;j--;
	}
	return flag;
}
int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	scanf("%d%d",&n,&s);
	int cnt=0,k=s,i,flag;
	while(cnt<n){
		k++;flag=0;
		for(i=2;i<=10;i++){
			flag+=check(k,i);
			if(flag>=2) break;
		}
		if(flag>=2) printf("%d\n",k),cnt++;
	}
	return 0;
}
