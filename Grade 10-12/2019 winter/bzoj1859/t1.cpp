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
int n,p[10];
struct node{
	double r1,r2,h1,h2;//r1<r2,h1<h2;
	node(){}
	node(double aa,double bb,double cc,double dd){r1=aa;r2=bb;h1=cc;h2=dd;}
	double slope(){return (h2-h1)/(r2-r1);}
}a[10],tmp[10];
double calc(node l,node r){
	double x=l.h1;
	l.h1-=x;l.h2-=x;
	if(l.r2<=r.r1) return x+l.h2;
	if(l.slope()>r.slope()){
		if(r.r2>=l.r2){
			double k=l.h2-(l.r2-r.r1)*r.slope();
			k=max(k,0.0);
			return x+k;
		}
		double k=l.h2-r.h2-(l.r2-r.r2)*l.slope();
		k=max(k,0.0);
		return x+k;
	}
	else{
		if(r.r1<l.r1) return x;
		double k=l.h2-(l.r2-r.r1)*l.slope();
		k=max(k,0.0);
		return x+k;
	}
}
int main(){
	n=read();int i,j,t1,t2,t3;double maxn,ans=1e9;
	for(i=1;i<=n;i++){
		t1=read();t2=read();t3=read();
		a[i]=node(t2,t3,0,t1);
	}	
	for(i=1;i<=n;i++) p[i]=i;
	while(1){
		memset(tmp,0,sizeof(tmp));
		tmp[0]=node(1e19,1e20,0,0);
		for(i=1;i<=n;i++){
			maxn=0;
			for(j=0;j<i;j++) maxn=max(maxn,calc(tmp[j],a[p[i]]));
			tmp[i]=node(a[p[i]].r1,a[p[i]].r2,a[p[i]].h1+maxn,a[p[i]].h2+maxn);
		}
		maxn=0;
		for(i=1;i<=n;i++) maxn=max(maxn,tmp[i].h2);
		ans=min(ans,maxn);
		if(!next_permutation(p+1,p+n+1)) break;
	}
	printf("%.0lf\n",ans);
}
