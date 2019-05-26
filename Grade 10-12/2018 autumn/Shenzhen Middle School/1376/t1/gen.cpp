#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<ctime>
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
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int x[110][110];
int main(){
	int n=10,m=10,k=8,A=random(1,4),B=random(1,4);
	int i,j,tmp,t1,t2;
	cout<<n<<' '<<m<<' '<<k<<' '<<A<<' '<<B<<'\n';
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			tmp=random(1,100);
			if(tmp>90) x[i][j]=-1,putchar('*');
			else putchar('.');
		}
		putchar('\n');
	}
	for(i=1;i<=k;i++){
		t1=random(1,n);t2=random(1,m);
		while(x[t1][t2]!=0){
			t1=random(1,n);
			t2=random(1,m);
		}
		cout<<t1<<' '<<t2<<'\n';
		x[t1][t2]=i;
	}
	for(i=1;i<=k;i++){
		t1=random(1,n);t2=random(1,m);
		while(x[t1][t2]!=0){
			t1=random(1,n);
			t2=random(1,m);
		}
		cout<<t1<<' '<<t2<<'\n';
		x[t1][t2]=i+k;
	}
}
