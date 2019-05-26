#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
	double v,t;
}a[500010];
node q[500010];int n,L,head,tail;
double tot=0,totv=0;
int main(){
	n=read();L=read();int i;ll lim;
	for(i=1;i<=n;i++) a[i].t=read(),a[i].v=read();
	tot+=(a[1].v*a[1].t);totv+=a[1].v;
	q[tail++]=(node){a[1].v,a[1].t};
//	cout<<"first "<<tot<<' '<<totv<<'\n';
	printf("%.10lf\n",tot/totv);
	for(i=2;i<=n;i++){
		lim=a[i].v;
		while(head<tail&&lim>=q[head].v){
			lim-=q[head].v;
			tot-=q[head].v*q[head].t;
			totv-=q[head].v;
			head++;
		}
		q[head].v-=lim;
		tot-=lim*q[head].t;
		totv-=lim;
//		cout<<"after dec "<<i<<' '<<tot<<' '<<totv<<' '<<lim<<' '<<q[head].t<<'\n';
		q[tail]=(node){a[i].v,a[i].t};
		tot+=a[i].v*a[i].t;
		totv+=a[i].v;
//		cout<<"after add "<<i<<' '<<tot<<' '<<totv<<'\n';
		while(head<tail&&q[tail].t<q[tail-1].t) 
			q[tail-1]=(node){q[tail].v+q[tail-1].v,(q[tail].t*q[tail].v+q[tail-1].t*q[tail-1].v)/(q[tail].v+q[tail-1].v)},tail--;
		printf("%.10lf\n",tot/totv);
		tail++;
	}
}
