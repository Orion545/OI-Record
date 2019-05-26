#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int a[1010][1010],n,m;
int main(){
	n=read();int i,j,k,t1,t2,t3;
	for(i=1;i<=n;i++) a[1][i]=read();
	for(i=2;i<=3;i++){
		for(j=1;j<=n;j++){
			a[i][j]=0;
			for(k=1;k<=j;k++)
				if(a[i-1][k]==a[i-1][j]) a[i][j]++;
		}
	}
	m=read();
	while(m--){
		t1=read();t2=read();t3=read();
		if(t1==2) printf("%d\n",a[(t2&1)?3:2][t3]);
		else{
			a[1][t3]=t2;
			for(i=2;i<=3;i++){
				for(j=1;j<=n;j++){
					a[i][j]=0;
					for(k=1;k<=j;k++)
						if(a[i-1][k]==a[i-1][j]) a[i][j]++;
				}
			}
		}
	}
}
