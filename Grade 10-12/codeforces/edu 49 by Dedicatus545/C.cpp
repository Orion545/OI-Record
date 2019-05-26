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
int a[1000010],num;double val[1000010];
void empty(){}
int main(){
	int T=read(),n,i,j;
	while(T--){
		n=read();int tl,tr;bool flag=1;double minans=1e15;
		for(i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);num=0;
		for(i=1;i<=n;i=j+1){
			j=i;
			while(a[j+1]==a[j]&&j<n) j++;
			if(j-i+1>=4){
				cout<<a[i]<<' '<<a[i]<<' '<<a[i]<<' '<<a[i]<<'\n';
				goto endd;
			}
			if(j-i+1>=2) num++,val[num]=a[i];
		}
		for(i=1;i<num;i++){
			double tmp=2.0+(val[i+1]-val[i])*(val[i+1]-val[i])/(val[i+1]*val[i]);
			if(tmp<minans){
				minans=tmp;
				tl=val[i];tr=val[i+1];
			}
		}
		if(flag) cout<<tl<<' '<<tl<<' '<<tr<<' '<<tr<<'\n';
		endd:empty();
	}
}
