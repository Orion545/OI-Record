#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct seg{
	int l,r,len;
}a[25010],aa[25010];
int n,q,f[1001000];
int find(int x){
	return ((f[x]==x)?x:f[x]=find(f[x]));
}
bool cmp(seg l,seg r){
	return l.len>r.len;
}
bool solve(int sta){
//	cout<<"solving "<<sta<<endl;
	int i,j,l1,l2,r1,r2;
	for(i=1;i<=n+1;i++) f[i]=i;
	for(i=1;i<=sta;i++) a[i]=aa[i];
	sort(a+1,a+sta+1,cmp);
	l1=l2=a[1].l;r1=r2=a[1].r;
	for(i=2;i<=sta;i++){
//		cout<<"	in "<<i<<endl;
		if(a[i].len<a[i-1].len){
//			cout<<"		div 1:"<<endl; 
			if(find(l1)>r1) return 0;
			for(j=l2;j<=r2;j=f[j]){
//				cout<<"			"<<j<<endl;
				find(j);
				f[j]=find(j+1);
			}
			l1=l2=a[i].l;r1=r2=a[i].r;
		}
		else{
			l1=max(l1,a[i].l);l2=min(l2,a[i].l);
			r1=min(r1,a[i].r);r2=max(r2,a[i].r);
			if(r1<l1) return 0;
		}
	}
	if(find(l1)>r1) return 0;
	else return 1;
}
int main(){
	int l,r,mid,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=q;i++) scanf("%d%d%d",&aa[i].l,&aa[i].r,&aa[i].len);
	l=1;r=q+1;
	while(l<r){
		mid=(l+r)>>1;
		if(solve(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d",((l>q)?0:l));
} 
