#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define ld long double
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
int n,ca,cb;ld x[10],y[10],a[10],b[10],p[10];
struct node{
	ld x,y;
}t[10];int cnt;
void mul(){
	int i,j;ld re[10]={0};
	for(i=0;i<=ca;i++){
		for(j=0;j<=cb;j++) re[i+j]+=a[i]*b[j];
	}
	for(i=0;i<=ca+cb;i++) a[i]=re[i];
	ca=ca+cb;
}
void cha(){
//	cout<<"enter cha\n";
	int i,j;ld bottom;
	memset(p,0,sizeof(p)); 
	for(j=1;j<=cnt;j++){
		bottom=1;ca=cb=0;
		for(i=1;i<=cnt;i++){
			if(i==j) continue;
			bottom/=(t[j].x-t[i].x);
			if(!ca) ca=1,a[0]=-t[i].x,a[1]=1;
			else{
				cb=1,b[0]=-t[i].x,b[1]=1;
				mul();
			}
		}
//		cout<<"	finish j "<<j<<' '<<bottom<<' '<<t[j].y<<'\n'; 
		for(i=0;i<=ca;i++) p[i]+=bottom*a[i]*t[j].y;
	}
//	for(i=0;i<=n;i++) cout<<i<<' '<<p[i]<<'\n';
}
ld P(int x){
	ld tmp=1,re=0;
	for(int i=0;i<=n;i++) re+=tmp*p[i],tmp*=x;
	return re;
}
ld _abs(ld x){
	return (x<0.0)?-x:x;
}
bool cmp(ld l,ld r){
	return (_abs(l-r)<=1e-3);
}
int main(){
	while(n=read()){
		int i,j;
		for(i=1;i<=n+3;i++) x[i]=i-1,scanf("%Lf",&y[i]);
//		cout<<"finish read in\n";
		for(j=1;j<=n+3;j++){
			memset(t,0,sizeof(t));cnt=0;
			for(i=1;i<j;i++){
				if(cnt==n+1) break;
				t[++cnt]=(node){x[i],y[i]};
			}
			for(i=j+1;i<=n+3;i++){
				if(cnt==n+1) break;
				t[++cnt]=(node){x[i],y[i]};
			}
			cha();
//			cout<<"back to main() "<<x[j]<<' '<<P(x[j])<<' '<<y[j]<<' '<<x[i]<<' '<<P(x[i])<<' '<<y[i]<<'\n';
//			printf("back to main() %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n",x[j],P(x[j]),y[j],x[i],P(x[i]),y[i]);
			if(!cmp(P(x[j]),y[j])&&!cmp(P(x[i]),y[i])) continue;
			if(cmp(P(x[j]),y[j])){
				printf("%d\n",(int)x[i]);break;
			}
			else{
				printf("%d\n",(int)x[j]);break;
			}
		}
//		cout<<"finish calc\n";
	}
}

