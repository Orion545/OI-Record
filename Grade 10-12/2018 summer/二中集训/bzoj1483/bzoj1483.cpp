#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,first[1000010],siz[1000010],ans=0,real[1000010],col[1000010];
struct node{
	int next,pos;
}a[100010];
void merge(int l,int r){
//	cout<<"merge "<<l<<' '<<r<<' '<<ans<<'\n';
	if(l==r) return;
	if(siz[real[l]]>siz[real[r]]) swap(real[l],real[r]);
	l=real[l];r=real[r];
	if(first[l]==-1) return;
	int i;
	for(i=first[l];~i;i=a[i].next){
//		cout<<"	search "<<i<<' '<<a[i].next<<' '<<a[i].pos<<' '<<col[a[i].pos]<<'\n';
		if(col[a[i].pos-1]==r) ans--;
		if(col[a[i].pos+1]==r) ans--;
	}
	for(i=first[l];~i;i=a[i].next) col[a[i].pos]=r;
	for(i=first[l];~a[i].next;i=a[i].next);
	a[i].next=first[r];first[r]=first[l];first[l]=-1;
	siz[r]+=siz[l];siz[l]=0;
//	cout<<"finish merge "<<ans<<'\n';
}
int main(){
//	freopen("2.in","r",stdin);
//	freopen("1483.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++){
		t1=read();a[i].pos=i;
		if(t1!=col[i-1]) ans++;
		a[i].next=first[t1];first[t1]=i;siz[t1]++;
		real[t1]=t1;col[i]=t1;
	}
	for(i=1;i<=m;i++){
		t1=read();
		if(t1==1){
			t2=read();t3=read();
			merge(t2,t3);
		}
		else printf("%d\n",ans);
	}
}
