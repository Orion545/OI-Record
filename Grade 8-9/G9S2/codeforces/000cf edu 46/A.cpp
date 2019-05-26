#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int as,axs,axxs,axxxs,am,al,axl,axxl,axxxl;
int bs,bxs,bxxs,bxxxs,bm,bl,bxl,bxxl,bxxxl;
int n;
int main(){
	cin>>n;int i;
	char s[10];
	for(i=1;i<=n;i++){
		scanf("%s",s);
		if(strcmp(s,"S")) as++;
		if(strcmp(s,"XS")) axs++;
		if(strcmp(s,"XXS")) axxs++;
		if(strcmp(s,"XXXS")) axxxs++;
		if(strcmp(s,"M")) am++;
		if(strcmp(s,"L")) al++;
		if(strcmp(s,"XL")) axl++;
		if(strcmp(s,"XXL")) axxl++;
		if(strcmp(s,"XXXL")) axxxl++;
	}
	for(i=1;i<=n;i++){
		scanf("%s",s);
		if(strcmp(s,"S")) bs++;
		if(strcmp(s,"XS")) bxs++;
		if(strcmp(s,"XXS")) bxxs++;
		if(strcmp(s,"XXXS")) bxxxs++;
		if(strcmp(s,"M")) bm++;
		if(strcmp(s,"L")) bl++;
		if(strcmp(s,"XL")) bxl++;
		if(strcmp(s,"XXL")) bxxl++;
		if(strcmp(s,"XXXL")) bxxxl++;
	}
	int ans=abs(bxl-axl)+abs(bxxl-axxl)+abs(bxxxl-axxxl);
	ans+=max(max(abs(am-bm),abs(al-bl)),abs(as-bs));
	printf("%d\n",ans);
} 
