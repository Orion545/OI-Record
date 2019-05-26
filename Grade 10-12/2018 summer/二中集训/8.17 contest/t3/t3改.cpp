#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 220000
using namespace std;
int a[N],b[N],sum[N],l[N],r[N],A,B,ans0[N],ans1[N];
int q,n,x;
int main(){
	scanf("%d",&x);
	scanf("%d",&n);
	n++;
	for(int i=1;i<=n;i++){
		if(i<n)scanf("%d",&a[i]);
		else a[i]=1200000000;
		b[i]=a[i]-a[i-1];
		b[i]=b[i]*((i&1)?-1:1);
		sum[i]=sum[i-1]+b[i];
	}
	l[0]=0,r[0]=x;
	for(int i=1;i<=n;i++){
		l[i]=l[i-1];
		r[i]=r[i-1];
		l[i]=max(l[i],-sum[i]);
		r[i]=min(r[i],x-sum[i]);
	}
//	for(int i=1;i<=n;i++)printf("%d %d\n",l[i],r[i]);
	A=0,B=x;
	for(int i=1;i<=n;i++){
		A=A+b[i];
		B=B+b[i];
		A=max(A,0);A=min(A,x);
		B=max(B,0);B=min(B,x);
		ans0[i]=A;
		ans1[i]=B;
	}
//	for(int i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",ans1[i]);printf("\n");
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int X,y;
		scanf("%d%d",&X,&y);
		int p=lower_bound(a+1,a+1+n,X)-a;
		if(a[p]>X)p--;
//		printf("%d %d %d\n",X,y,p);
		int ans=0;
		if(y<=l[p]){
			ans=ans0[p];
		}
		if(y>=r[p]){
			ans=ans1[p];
		}
		if(y>=l[p]&&y<=r[p]){
			ans=y+sum[p];
		}
		if(p&1)ans+=X-a[p];
		else ans-=X-a[p];
		ans=max(ans,0);
		ans=min(ans,x);
		printf("%d\n",ans);
	}
}
