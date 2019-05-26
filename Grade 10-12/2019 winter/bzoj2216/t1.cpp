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
int n,a[500010],q[500010],l[500010],r[500010],p[500010],head,tail;
double getval(int j,int i){
	return 1.0*a[j]-1.0*a[i]+1.0*sqrt((double)(i-j));
}
int main(){
	n=read();int i,L,R,mid;
	for(i=1;i<=n;i++) a[i]=read();
	head=0,tail=0;
	for(i=1;i<=n;i++){
		while(head<tail&&r[q[head]]<i) head++;
		if(head<tail){
			l[q[head]]=i;
			p[i]=max(p[i],(int)ceil(getval(q[head],i)));
		}
		if(head<tail&&getval(q[tail-1],n)>getval(i,n)) continue;
		r[i]=n;
		while(head<tail&&getval(q[tail-1],l[q[tail-1]])<=getval(i,l[q[tail-1]])) tail--;
		if(head<tail){
			L=l[q[tail-1]],R=r[q[tail-1]];
			while(L<R){
				mid=(L+R)>>1;
				if(getval(i,mid)<=getval(q[tail-1],mid)) L=mid+1;
				else R=mid;
			}
			l[i]=L;r[q[tail-1]]=L-1;
		}
		else l[i]=i+1;
		q[tail++]=i;
	}

	reverse(a+1,a+n+1);
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(q,0,sizeof(q));
	head=0;tail=0;

	for(i=1;i<=n;i++){
		while(head<tail&&r[q[head]]<i) head++;
		if(head<tail){
			l[q[head]]=i;
			p[n-i+1]=max(p[n-i+1],(int)ceil(getval(q[head],i)));
		}
		if(head<tail&&getval(q[tail-1],n)>getval(i,n)) continue;
		r[i]=n;
		while(head<tail&&getval(q[tail-1],l[q[tail-1]])<=getval(i,l[q[tail-1]])) tail--;
		if(head<tail){
			L=l[q[tail-1]],R=r[q[tail-1]];
			while(L<R){
				mid=(L+R)>>1;mid++;
				if(getval(i,mid)<=getval(q[tail-1],mid)) L=mid+1;
				else R=mid-1;
			}
			l[i]=L;r[q[tail-1]]=L-1;
		}
		else l[i]=i+1;
		q[tail++]=i;
	}
	
	for(i=1;i<=n;i++) printf("%d\n",p[i]);
}
