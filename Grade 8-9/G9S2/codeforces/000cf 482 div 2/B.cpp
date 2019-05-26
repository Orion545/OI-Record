#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,la,lb,lc;char a[100010],b[100010],c[100010];
int ba[200]={0},bb[200]={0},bc[200]={0};
int main(){
	n=read();int i;
	scanf("%s",a);la=strlen(a);
	for(i=0;i<la;i++) ba[(int)a[i]]++;
	scanf("%s",b);lb=strlen(b);
	for(i=0;i<lb;i++) bb[(int)b[i]]++;
	scanf("%s",c);lc=strlen(c);
	for(i=0;i<lc;i++) bc[(int)c[i]]++;
	int ma=0,mb=0,mc=0;
	for(i=1;i<=150;i++) ma=max(ma,ba[i]);
	for(i=1;i<=150;i++) mb=max(mb,bb[i]);
	for(i=1;i<=150;i++) mc=max(mc,bc[i]);
	if(ma==la&&n!=0) ma=la-1; 
	else{
		ma+=n;
		if(ma>la) ma=la;
	}
	if(mb==lb&&n!=0) mb=lb-1; 
	else{
		mb+=n;
		if(mb>lb) mb=lb;
	}
	if(mc==lc&&n!=0) mc=lc-1; 
	else{
		mc+=n;
		if(mc>lc) mc=lc;
	}
//	cout<<ma<<ends<<mb<<ends<<mc<<endl;
	if((ma==mb&&ma>=mc)||(mb==mc&&mb>=ma)||(mc==ma&&mc>=mb)){
		puts("Draw");return 0;
	}
	if(ma>mb&&ma>mc){
		puts("Kuro");return 0;
	}
	if(mb>mc){
		puts("Shiro");return 0;
	}
	puts("Katie");
}
