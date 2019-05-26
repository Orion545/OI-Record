#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int x,d,a[32],tot=0;
vector<int>ans;
int main(){
	x=read();d=read();int i,tmp=1,j;
	for(i=1;i<31;i++) a[i]=a[i-1]*2+1;
	i=30;
	while(x){
		while(x<a[i]) i--;
		while(x>=a[i]) x-=a[i],ans.push_back(i),tot+=i;
	}
	if(tot>10000){
		printf("-1");return 0;
	}
	printf("%d\n",tot);
	for(i=0;i<ans.size();i++){
		for(j=1;j<=ans[i];j++) printf("%d ",tmp);
		tmp+=d;
	}
}

