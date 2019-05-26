#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int l,r,x,y,len,lazy;
	node(){
		l=r=lazy=len=0;
	}
}a[200100];
void build(int l,int r,int num){
	a[num].l=l;a[num].r=r;
	a[num].x=a[num].y=a[num].len=r-l+1;
	int mid=(l+r)>>1;
	if(l!=r){
		build(l,mid,num<<1);build(mid+1,r,(num<<1)+1);
	}
}
void clear(int num){
	if(a[num].l==a[num].r||!a[num].lazy) return;
	int son=num<<1;
	if(a[num].lazy==2){
		a[son].x=a[son].y=a[son].len=a[son].r-a[son].l+1;
		a[son+1].x=a[son+1].y=a[son+1].len=a[son+1].r-a[son+1].l+1;
		a[son].lazy=a[son+1].lazy=1;
	}
	else{
		a[son].x=a[son].y=a[son].len=0;
		a[son+1].x=a[son+1].y=a[son+1].len=0;
		a[son].lazy=a[son+1].lazy=2;
	}
	a[num].lazy=0;
}
int find(int len,int num){
//	cout<<"find "<<len<<ends<<num<<endl;
	int son=num<<1;
	clear(num);clear(son);clear(son+1);
	if(a[num].x>=len) return a[num].l;
	if(a[son].len>=len) return find(len,son);
	if(a[son].y+a[son+1].x>=len) return a[son].r-a[son].y+1;
	return find(len,son+1);
}
void update(int num){
//	cout<<"update "<<num<<endl;
	int son=num<<1;
	clear(son);clear(son+1);
	a[num].x=((a[son].len==a[son].r-a[son].l+1)?a[son].x+a[son+1].x:a[son].x);
	a[num].y=((a[son+1].len==a[son+1].r-a[son+1].l+1)?a[son+1].y+a[son].y:a[son+1].y);
//	cout<<a[num].len<<endl;
    a[num].len=max(a[son].len,a[son+1].len);
//	cout<<a[num].len<<endl;
    a[num].len=max(a[num].len,a[son].y+a[son+1].x);
//	cout<<a[num].len<<endl;
}
void checkin(int l,int r,int num){
	clear(num);
	if(a[num].l>r||a[num].r<l) return;
	if(a[num].l>=l&&a[num].r<=r){
		a[num].x=a[num].y=a[num].len=0;a[num].lazy=1;return;
	}
	int mid=(a[num].l+a[num].r)>>1,son=num<<1;
	if(mid>=l) checkin(l,r,son);
	if(mid<r) checkin(l,r,son+1);
	update(num);
}
void checkout(int l,int r,int num){
	clear(num);
	if(a[num].l>r||a[num].r<l) return;
	if(a[num].l>=l&&a[num].r<=r){
		a[num].x=a[num].y=a[num].len=a[num].r-a[num].l+1;a[num].lazy=2;return;
	}
	int mid=(a[num].l+a[num].r)>>1,son=num<<1;
	if(mid>=l) checkout(l,r,son);
	if(mid<r) checkout(l,r,son+1);
	update(num);
}
int n,m,ans;
int main(){
	int i,t1,t2,t3;
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(i=1;i<=m;i++){
		scanf("%d",&t1);
		if(t1==1){
			scanf("%d",&t2);
			if(a[1].len<t2){
				printf("0\n");continue;
			}
			ans=find(t2,1);
			printf("%d\n",ans);
			checkin(ans,ans+t2-1,1);
		}
		else{
			scanf("%d%d",&t2,&t3);
			checkout(t2,t2+t3-1,1);
		}
	}
}
