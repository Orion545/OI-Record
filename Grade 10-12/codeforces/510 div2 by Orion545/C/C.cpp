#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,AAA[200005],curr[200005],tot,maxx=-2e9,pos,cnt,xc[200005],cur;
void init(){
	int i;
	for(i=1;i<=n;i++){
		if(AAA[i]<0){
			tot++;
			if(AAA[i]>maxx) maxx=AAA[i],pos=i;
		}
		else if(AAA[i]==0) curr[++cnt]=i;
		else if(AAA[i]>0) xc[++cur]=i;
	}
}
int main(){
	n=read();int i;
	for(i=1;i<=n;i++) AAA[i]=read();
	init();
	if(cnt==n||(cnt==n-1&&!cur)){
		if(cnt==n-1) curr[++cnt]=pos;
		for(i=1;i<=n;i++)
			if(AAA[i]==0){pos=i;break;}
		for(i=1;i<=n;i++) 
			if(!(i==pos)) printf("1 %d %d\n",curr[i],curr[pos]);
		return 0;
	}
	if(tot%2==1) curr[++cnt]=pos;
	for(i=1;i<=n;i++) 
		if((AAA[i]<0&&i!=pos)||(i==pos&&((tot&1)==0))) xc[++cur]=i;
	for(i=2;i<=cnt;i++) 
		printf("1 %d %d\n",curr[i],curr[1]);
	if(cnt>0)
		printf("2 %d\n",curr[1]);
	for(i=2;i<=cur;i++)
		printf("1 %d %d\n",xc[i],xc[1]);
}
