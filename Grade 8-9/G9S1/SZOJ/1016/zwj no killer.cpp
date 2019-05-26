#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define inf 0x7fffffff
using namespace std;
struct person{
	ll x,y,vx,vy;
}p[50005];
struct seg{
	double left,right;
}s[50005];
ll n,r,cnt,tans=0;
bool cmp(seg aaa,seg bbb){
	if(aaa.left==bbb.left) return aaa.right<=bbb.right;
	if(aaa.left<bbb.left) return 1;
	else return 0;
}
void equation(double x,double y,double z,double &x1,double &x2){
	double delta=y*y-4.0*x*z;
	if(delta<0.0) return;
	x1=max((-y+sqrt(delta))/(2*x),(-y-sqrt(delta))/(2*x));
	x2=min((-y+sqrt(delta))/(2*x),(-y-sqrt(delta))/(2*x));
}
void solve(ll k){
	if(p[k].vx==p[0].vx&&p[k].vy==p[0].vy){
		if(((double)(p[k].x-p[0].x)*(p[k].x-p[0].x)+(p[k].y-p[0].y)*(p[k].y-p[0].y))<=r*r){
//			cnt++;
//			s[cnt].left=0;s[cnt].right=inf;
			tans++;
		}
		return;
	}
	ll a,b,c,d;
	a=p[k].vx-p[0].vx;b=p[k].vy-p[0].vy;
	c=p[k].x-p[0].x;d=p[k].y-p[0].y;
	ll x,y,z;
	x=a*a+b*b;y=2*a*c+2*b*d;z=c*c+d*d-r*r;
	double t1=0.0,t2=0.0;
	equation((double)x,(double)y,(double)z,t1,t2);
//	cout<<"solved "<<x<<ends<<y<<ends<<z<<ends<<t1<<ends<<t2<<endl;
	s[++cnt].left=max(0.0,t2),s[cnt].right=max(0.0,t1);
	if(s[cnt].left==0.0&&s[cnt].right==0.0) cnt--;
}
int main(){
	ll i,j,ans=0;
	scanf("%lld%lld%lld%lld%lld%lld",&n,&r,&p[0].x,&p[0].y,&p[0].vx,&p[0].vy);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&p[i].x,&p[i].y,&p[i].vx,&p[i].vy);
		solve(i);
	} 
	sort(s+1,s+cnt+1,cmp);
//	for(i=1;i<=cnt;i++) cout<<i<<ends<<s[i].left<<ends<<s[i].right<<endl;
	i=1;j=2;
	while(i<=cnt&&j<=cnt){
//		cout<<i<<ends<<j<<endl;
		if(s[i].right<s[j].left){
			i++;ans=max(ans,j-i+1);
		}
		if(j==cnt) ans=max(ans,j-i+1);
		if(s[i].right>=s[j].left) j++;
	}
	printf("%lld",ans+tans);
}
 
