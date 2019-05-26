#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<ctime>
#include<cassert>
#define ll long long
#define l(i) a[i].l
#define r(i) a[i].r
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
struct lisan{
	int pos,num,rk;
}x[800010];
struct seg{
	int l,r,num;
}a[400010];
bool cmp1(lisan l,lisan r){
	return l.pos<r.pos;
}
bool cmp2(lisan l,lisan r){
	return l.num<r.num;
}
bool cmp(seg l,seg r){
	if(l.l!=r.l) return l.l<r.l;
	return l.r<r.r;
}
bool acmp(seg l,seg r){
	return l.num<r.num;
}
int n,m,st[800010][20],val[800010];
int main(){
	freopen("3.in","r",stdin);
	freopen("my.out","w",stdout);
	n=read();m=read();int i,j=0,tot,u,ans,c1,c2;
	for(i=1;i<=n;i++){
		l(i)=read();r(i)=read();
		a[i].num=i;
		if(r(i)<l(i)) r(i)+=m;
		x[i].pos=l(i),x[i].num=i;
		x[i+n].pos=r(i),x[i+n].num=i+n;
		l(i+n)=l(i)+m,r(i+n)=min((ll)r(i)+m,(ll)m<<1);
		a[i+n].num=i+n;
		x[i+2*n].pos=l(i+n),x[i+2*n].num=i+n*2;
		x[i+n*3].pos=r(i+n),x[i+n*3].num=i+n*3;
	}
//	c1=clock();
	sort(x+1,x+(n<<2)+1,cmp1);
//	cout<<clock()-c1<<'\n';
	for(i=1;i<=(n<<2);i++){
		j++;
		x[i].rk=j;
		while(x[i+1].pos==x[i].pos&&i<(n<<2)) i++,x[i].rk=j;
		val[j]=x[i].pos;
	}
	tot=j;
//	cout<<clock()-c1<<'\n';
//	for(i=1;i<=tot;i++) cout<<val[i]<<' ';cout<<'\n';
	sort(x+1,x+(n<<2)+1,cmp2);
//	cout<<clock()-c1<<'\n';
//	for(i=1;i<=(n<<2);i++) cout<<i<<' '<<x[i].pos<<' '<<x[i].rk<<'\n';
	for(i=1;i<=n;i++){
		l(i)=x[i].rk;r(i)=x[i+n].rk;
		l(i+n)=x[i+n*2].rk;r(i+n)=x[i+n*3].rk;
	}
//	cout<<clock()-c1<<'\n';
	sort(a+1,a+(n<<1)+1,cmp);
	for(i=1;i<=(n<<1);i++){
		while(l(i+1)==l(i)&&(i<(n<<1))) i++;
		for(j=l(i);j<l(i+1);j++) st[j][0]=r(i);
	}
//	cout<<clock()-c1<<'\n';
//	cout<<"finish ÀëÉ¢»¯\n"; 
	for(j=1;j<=19;j++){
		for(i=1;i<=tot;i++) 
			st[i][j]=st[st[i][j-1]][j-1];
	}
	val[0]=2e9+1;
	sort(a+1,a+(n<<1)+1,acmp);
//	cout<<clock()-c1<<'\n';
	for(i=1;i<=n;i++){
		u=l(i);ans=0;
//		cout<<"do "<<u<<' '<<val[u]<<' '<<val[u]+m<<'\n';
		for(j=19;j>=0;j--) if(val[st[u][j]]<val[l(i)]+m) u=st[u][j],ans|=(1<<j);
		printf("%d ",ans+1);
	}
//	cout<<'\n'<<clock()-c1<<'\n';
}
