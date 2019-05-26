#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
	int h,num,l,r,fa;
	ll w,ans;
	node(){
		h=w=num=l=r=fa=0;
	}
}a[100010];
bool cmp(node left,node right){
	return left.h>right.h;
}
int n;ll t;
bool vis[100010];
void build(int k,int f,int l,int r){
//	cout<<"build "<<k<<ends<<f<<ends<<l<<ends<<r<<endl;
	int i,tmp;
	a[k].fa=f;vis[k]=1;
	if(k>=n) return;
	for(i=k+1;i<=n;i++) if(!vis[i]&&(l<=a[i].num&&r>=a[i].num)) break;
	if(i==n+1) return;
	tmp=i;
	if(a[tmp].num<a[k].num){
		a[k].l=tmp;
		build(tmp,k,l,a[k].num-1);
		for(i=tmp+1;i<=n;i++){
			if(a[i].num>a[k].num&&!vis[i]&&l<=a[i].num&&r>=a[i].num){
				a[k].r=i;
				build(i,k,a[k].num+1,r);
			}
		}
	}
	else{
		a[k].r=tmp;
		build(tmp,k,a[k].num+1,r);
		for(i=tmp+1;i<=n;i++){
			if(a[i].num<a[k].num&&!vis[i]&&l<=a[i].num&&r>=a[i].num){
				a[k].l=i;
				build(i,k,l,a[k].num-1);
			}
		}
	}
	/*
	for(i=k+1;i<=n;i++) if(!vis[i]&&((flag==0)?1:((flag==1)?(a[i].num<a[a[k].fa].num):(a[i].num>a[a[k].fa].num))))break;
	if(i==n+1) return;
	tmp=i;
	if(a[tmp].num<a[k].num){
		a[k].l=tmp;
		build(tmp,k,1);
		for(i=tmp+1;i<=n;i++){
			if(a[i].num>a[k].num&&!vis[i]&&((flag==0)?1:((flag==1)?(a[i].num<a[a[k].fa].num):(a[i].num>a[a[k].fa].num)))){
				a[k].r=i;
				build(i,k,2);break;
			}
		}
	}
	else{
		a[k].r=tmp;
		build(tmp,k,2);
		for(i=tmp+1;i<=n;i++){
			if(a[i].num<a[k].num&&!vis[i]){
				a[k].l=i;
				build(i,k,1);break;
			}
		}
	}
	*/
//	cout<<"son "<<k<<ends<<a[k].l<<ends<<a[k].r<<endl;
	a[k].w+=a[a[k].l].w+a[a[k].r].w;
	return;
}
void calc(int k){
	vis[k]=1;
	if(a[k].num<a[n].num){
		if(a[k].r!=0&&!vis[a[k].r]){
			calc(a[k].r);
		}
		if(a[k].l!=0&&!vis[a[k].l]){
			calc(a[k].l);
		}
	}
	else{
		if(a[k].l!=0&&!vis[a[k].l]){
			calc(a[k].l);
		}
		if(a[k].r!=0&&!vis[a[k].r]){
			calc(a[k].r);
		}
	}
	a[k].ans=t+a[k].w;
	t+=a[k].w*(a[a[k].fa].h-a[k].h);
	if(!vis[a[k].fa]) calc(a[k].fa);
	return;
}
bool cmp_(node left,node right){
	return left.num<right.num;
}
int main(){
	freopen("alake.10.in","r",stdin);
	freopen("alake.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].w,&a[i].h);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
//	cout<<endl<<endl; 
//	for(i=1;i<=n;i++) cout<<a[i].w<<ends<<a[i].h<<endl;
	build(1,1,1,n);
//	cout<<endl<<endl;
//	for(i=1;i<=n;i++) cout<<a[i].w<<ends;
//	cout<<endl<<endl;
	memset(vis,0,sizeof(vis));
	t=a[n].w*(a[a[n].fa].h-a[n].h);
	a[n].ans=a[n].w;vis[n]=1;
	calc(a[n].fa);
	sort(a+1,a+n+1,cmp_);
	for(i=1;i<=n;i++) printf("%lld\n",a[i].ans);
}
