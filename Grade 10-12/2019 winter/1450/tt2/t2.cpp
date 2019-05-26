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
int n,m,a[1000010],cnt[310][100010],pre[310][200010],cur[100010];
int blk,tot;
inline int op(int num){return blk*(num-1)+1;}
inline int ed(int num){return min(blk*num,n);}
inline int id(int num){return num/blk+(num%blk!=0);}
inline void change(int pos,int val){
	int p=id(pos),i;
	for(i=p;i<=tot;i++) pre[i][cnt[i][a[pos]]]--;
	for(i=p;i<=tot;i++) cnt[i][a[pos]]--;
	a[pos]=val;
	for(i=p;i<=tot;i++) cnt[i][a[pos]]++;
	for(i=p;i<=tot;i++) pre[i][cnt[i][a[pos]]]++;
}
inline void build(){
	int i,j;
	for(j=1;j<=tot;j++){
		for(i=1;i<=ed(j);i++)
			cnt[j][a[i]]++;
	}
	for(j=1;j<=tot;j++){
		memset(cur,0,sizeof(cur));
		for(i=1;i<=ed(j);i++){
			cur[a[i]]++;
			pre[j][cur[a[i]]]++;
//			cout<<"cnt "<<j<<' '<<i<<' '<<cur[a[i]]<<' '<<pre[j][cur[a[i]]]<<'\n';
		}
	}
}
inline int query(int x,int pos){
	if(x==1) return a[pos];
	int i,sum=0,p=id(pos);x--;
	sum=cnt[p-1][a[pos]];
	for(i=op(p);i<=pos;i++) sum+=(a[i]==a[pos]);
//	cout<<"half query "<<sum<<' '<<a[pos]<<'\n';
	if(x&1) return sum;
	int re=pre[p-1][sum];
	for(i=op(p);i<=pos;i++){
		cnt[p-1][a[i]]++;
		re+=(cnt[p-1][a[i]]==sum);
	}
	for(i=op(p);i<=pos;i++) cnt[p-1][a[i]]--;
	return re;
}
int main(){
	n=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++) a[i]=read();
	blk=400;tot=n/blk+(n%blk!=0);
	build();
	m=read();
	while(m--){
		t1=read();t2=read();t3=read();
		if(t1==1) change(t3,t2);
		else printf("%d\n",query(t2,t3));
	}
}
