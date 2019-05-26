#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
const double pi=acos(-1.0);
int n,m;
double x[100010],y[100010];
struct seg{
	double l,r;
	inline friend bool operator ==(const seg &a,const seg &b){
		return a.l==b.l&&a.r==b.r;
	}
	inline friend bool operator < (const seg &a,const seg &b){
		return a.r!=b.r?(a.r<b.r):(a.l<b.l);
	}
}s[200010];
int st[200010][19];int len,cnt;
void init(double r){
	double dis,alp,bet;int i,j;
	for(i=1;i<=n;i++){
		dis=sqrt(x[i]*x[i]+y[i]*y[i]);
		alp=acos(x[i]/dis);
		if(y[i]<0) alp=2*pi-alp;
		bet=acos(r/dis);
		s[i]=(seg){alp-bet,alp+bet};
//		s[n+i]=(seg){alp-bet+2*pi,alp+bet+2*pi};
	}
	len=n;
	sort(s+1,s+len+1);
	for(i=1;i<len;i++)
		if(s[i].l>=s[i+1].l) s[i+1]=s[i];
	len=unique(s+1,s+len+1)-s-1;
	for(i=1;i<=len;i++) s[len+i]=(seg){s[i].l+pi*2,s[i].r+pi*2};
	cnt=len;len*=2;
	for(i=0;i<=17;i++) st[len+1][i]=len+1;
	s[len+1]=(seg){1e15,1e15};
	for(i=1,j=1;i<=len;i++){
		while(j<=len&&s[j].l<=s[i].r) j++;
		st[i][0]=j;
	}
	for(j=1;j<=17;j++){
		for(i=1;i<=len;i++) st[i][j]=st[st[i][j-1]][j-1];
	}
//	cout<<"init "<<r<<'\n';
//	for(i=1;i<=len;i++) cout<<i<<' '<<s[i].l<<' '<<s[i].r<<' '<<st[i][0]<<'\n';
}
int calc(double r){
	init(r);
	int re=1e9,op,i;
	for(op=1;op<=cnt;op++){
		int u=op,vis=1,remain=cnt;
		for(i=17;i>=0;i--){
			if(st[u][i]-u<remain){
				vis+=(1<<i);
				remain-=st[u][i]-u;
				u=st[u][i];
			}
		}
//		cout<<"calc "<<op<<' '<<vis<<' '<<remain<<'\n';
		re=min(re,vis);
	}
	return re;
}
int main(){
	n=read();m=read();int i;double mind=1e15;
	for(i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		mind=min(mind,sqrt(x[i]*x[i]+y[i]*y[i]));
	}
	double l=0,r=mind,mid;
	while(r-l>1e-4){
		mid=(l+r)*0.5;
		if(calc(mid)<=m) l=mid;
		else r=mid;
	}
	printf("%.2lf\n",(l+r)*0.5);
}

