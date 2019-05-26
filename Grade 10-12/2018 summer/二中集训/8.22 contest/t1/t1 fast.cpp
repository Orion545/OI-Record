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
struct seg{
	int l,r,num;
}a[400010];
bool cmp(seg l,seg r){
	if(l.l!=r.l) return l.l<r.l;
	return l.r<r.r;
}
bool acmp(seg l,seg r){
	return l.num<r.num;
}
int n,m,st[800010][20],val[800010];
int main(){
//	freopen("3.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();m=read();int i,j=0,tot,u,ans,c1,c2,le,ri;
	for(i=1;i<=n;i++){
		l(i)=read();r(i)=read();
		a[i].num=i;
		if(r(i)<l(i)) r(i)+=m;
		l(i+n)=l(i)+m,r(i+n)=min((ll)r(i)+m,(ll)m<<1);
		a[i+n].num=i+n;
	}
//	c1=clock();
//	cout<<clock()-c1<<'\n';
//	for(i=1;i<=(n<<2);i++) cout<<i<<' '<<x[i].pos<<' '<<x[i].rk<<'\n';
//	cout<<clock()-c1<<'\n';
	sort(a+1,a+(n<<1)+1,cmp);
	le=1;ri=1;j=0;
	while(le<=(n<<1)&&ri<=(n<<1)){
		if(l(le)<r(ri)){
			j++;val[j]=l(le);
			while(l(le)==l(le)+1) l(le)=j,le++;
			l(le)=j;le++;
			continue;
		}
		if(l(le)>r(ri)){
			j++;val[j]=r(ri);
			while(r(ri)==r(ri)+1) r(ri)=j,ri++;
			r(ri)=j;ri++;
			continue;
		}
		if(l(le)==r(ri)){
			int tmp=l(le);j++;val[j]=l(le);
			while(tmp==l(le)) l(le)=j,le++;
			while(tmp==r(ri)) r(ri)=j,ri++;
			continue;
		}
	}
	while(le<=(n<<1)){
		j++;val[j]=l(le);
		while(l(le)==l(le)+1) l(le)=j,le++;
		l(le)=j;le++;
	}
	while(ri<=(n<<1)){
		j++;val[j]=r(ri);
		while(r(ri)==r(ri)+1) r(ri)=j,ri++;
		r(ri)=j;ri++;
	}
	tot=j;
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
