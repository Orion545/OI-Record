#include<algorithm>

#include<iostream>

#include<cstring>

#include<cstdio>

#include<cmath>

#define LL long long

#define M 200020

#define eps (1e-6) 

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

int n,m,on,flag0,flag1;

long double l,r,X[M],Y[M],ans;

bool check(long double x){

	long double maxn=1e16,minn=-1e16,len;int i;

//	minn*=maxn,maxn*=maxn; 

	for(i=1;i<=n;i++){

		len=sqrtl(x*x-(x-Y[i])*(x-Y[i]));

//		printf("%.5Lf\n",len);

		minn=max(minn,X[i]-len);
		maxn=min(maxn,X[i]+len);

	}

//	printf("%.5Lf  %.5Lf       %.5Lf\n",minn,maxn,x*x);

	return minn<=maxn;

}

void erfen(long double &l,long double &r){
	
		long double MDMDMDMD;

		MDMDMDMD=(l+r)/2;

		if(check(MDMDMDMD)) r=MDMDMDMD-eps,ans=MDMDMDMD;

		else l=MDMDMDMD+eps;
	
}


int main(){

	//freopen(".in","r",stdin);

	//freopen(".out","w",stdout);

	n=read();int i;

	for(i=1;i<=n;i++){

		cin>>X[i]>>Y[i];

		if(Y[i]>0.0) flag0++;
		if(Y[i]<0.0) flag1++;

	}

	if(flag0*flag1>0){
		puts("-1");
		return 0;
	}

	if(flag1){
		for(i=1;i<=n;i++) 
			Y[i]=-Y[i];
	}

	for(i=1;i<=n;i++) 
		l=max(l,Y[i]*0.5); 
	
	r=1e16;

	for(i=1;i<=120;i++){
		
		erfen(l,r);

	}

	printf("%.10lf\n",(double)ans);

	return 0;

}

