#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
struct node{
	double a,b,x,y,rate,slope;int id;
	friend inline bool operator <(node l,node r){
		return l.slope>r.slope;
	}
}a[100010],tmp[100010];
int n;double dp[100010];
double getk(int l,int r){
	if(!r) return -1e9;
	if(fabs(a[l].x-a[r].x)<1e-8) return 0;
	return (a[l].y-a[r].y)/(a[l].x-a[r].x);
}
int s[100010];
void solve(int l,int r){
	int i,j,cntl,cntr,top,mid=(l+r)>>1;

	if(l==r){
		dp[l]=max(dp[l-1],dp[l]);
//		cout<<"get "<<l<<' '<<a[l].id<<' '<<dp[l]<<'\n';
		a[l].y=dp[l]/(a[l].a*a[l].rate+a[l].b);
		a[l].x=a[l].y*a[l].rate;
		return;
	}

//	cout<<"****solve "<<l<<' '<<r<<' '<<mid<<'\n';

	cntl=l-1;cntr=mid;
	for(i=l;i<=r;i++){
		if(a[i].id<=mid) tmp[++cntl]=a[i];
		else tmp[++cntr]=a[i];
	}
	for(i=l;i<=r;i++) a[i]=tmp[i];

	solve(l,mid);

	top=0;
	for(i=l;i<=mid;i++){
		while(top>1&&getk(s[top-1],s[top])<getk(s[top],i)+1e-8) top--;
		s[++top]=i;
	}
	j=1;
	for(i=mid+1;i<=r;i++){
		while(j<top&&getk(s[j],s[j+1])+1e-8>a[i].slope) j++;
		dp[a[i].id]=max(dp[a[i].id],a[s[j]].x*a[i].a+a[s[j]].y*a[i].b);
	}
	
	solve(mid+1,r);

	cntl=l;cntr=mid+1;
	for(top=l;top<=r;top++){
		if(cntr>r||(cntl<=mid&&((a[cntl].x<a[cntr].x+1e-8)||((fabs(a[cntl].x-a[cntr].x)<1e-8)&&(a[cntl].y<a[cntr].y+1e-8))))) tmp[top]=a[cntl++];
		else tmp[top]=a[cntr++];
	}
	for(i=l;i<=r;i++) a[i]=tmp[i];
}
int main(){
	n=read();int i;
	double S;scanf("%lf",&S);
	dp[0]=S;
	for(i=1;i<=n;i++){
		scanf("%lf%lf%lf",&a[i].a,&a[i].b,&a[i].rate);
		a[i].slope=(-a[i].a/a[i].b);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	solve(1,n);
	printf("%.2lf\n",dp[n]);
}
