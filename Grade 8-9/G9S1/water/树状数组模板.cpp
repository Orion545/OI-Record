#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') re=re*10+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,x[500010],a[500010];
int lowbit(int x){
	return x&-x;
}
void add(int x,int num){
	for(int i=x;i<=n;i+=lowbit(i)) a[i]+=num;
}
int sum(int x){
	int re=0;
	for(int i=x;i>0;i-=lowbit(i)) re+=a[i];
	return re;
}
int main(){
	int t1,t2,t3;
	n=read();m=read();
	for(int i=1;i<=n;i++) x[i]=read(),add(i,x[i]);
	for(int i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		if(t1==1) add(t2,t3);
		else printf("%d\n",sum(t3)-sum(t2-1));
	}
}
