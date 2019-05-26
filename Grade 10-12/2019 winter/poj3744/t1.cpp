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
double a00,a01,a10,a11,b00,b01;
void qpow(int b){
	double t00,t01,t10,t11;
	while(b){
		if(b&1){
			t00=b00*a00+b01*a10;
			t01=b00*a01+b01*a11;
			b00=t00;b01=t01;
		}
		t00=a00*a00+a01*a10;
		t01=a00*a01+a01*a11;
		t10=a10*a00+a11*a10;
		t11=a10*a01+a11*a11;
		a00=t00;a01=t01;a10=t10;a11=t11;
		b>>=1;
	}
}
int pos[110];
int main(){
	int n,tmp,pre,flag,i;double f;double p;
	while(~scanf("%d%lf",&n,&p)){
		b00=1.0;b01=0.0;
		a00=p;a10=1.0-p;
		a01=1.0;a11=0.0;
		pre=1;flag=1;
		for(i=1;i<=n;i++) pos[i]=read();
		sort(pos+1,pos+n+1);
		for(i=1;i<=n;i++){
			tmp=pos[i];
//			cout<<tmp<<' '<<pre<<'\n';
			if(tmp==pre){flag=0;break;}
			qpow(tmp-pre-1);
			//f[tmp-1]=b00
			f=b00*(1.0-p);
			b00=f;b01=0.0;
			a00=p;a10=1.0-p;
			a01=1.0;a11=0.0;
//			cout<<tmp<<' '<<pre<<' '<<f<<'\n';
			pre=tmp+1;
		}
		if(!flag) puts("0.0000000");
		else printf("%.7lf\n",f);
	}
}
