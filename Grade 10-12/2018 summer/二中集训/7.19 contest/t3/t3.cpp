#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define rank DEEP_DARK_FANTASY
#define ll long long
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
int rank[1000010],book[1000010],tmp[1000010],sa[1000010],a[1000010],height[1000010],n,m,K;
void sort(){
	int i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	int i,cnt,k,j;m=1000000;
	for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
	sort();
	for(k=1,cnt=1;cnt<n;k<<=1,m=cnt){
		cnt=0;
		for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
		for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
		sort();swap(rank,tmp);
		rank[sa[1]]=cnt=1;
		for(i=2;i<=n;i++)
			rank[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])?cnt:++cnt);
	}
	k=0;
	for(i=1;i<=n;height[rank[i++]]=k)
		for((k?k--:k),j=sa[rank[i]-1];a[i+k]==a[j+k];k++);
} 
bool check(int t){
	int i,re=0,tmp=0;
	for(i=1;i<=n;i++){
		if(height[i]<t){
			re=max(re,tmp);tmp=0;
		}
		else tmp++;
	}
	re=max(re,tmp);
	return (re>=(K-1));
}
int main(){
	n=read();K=read();int i;
	for(i=1;i<=n;i++) a[i]=read();
	getsa();
//	for(i=1;i<=n;i++) cout<<height[i]<<' '<<rank[i]<<' '<<sa[i]<<'\n';
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;mid++;
//		cout<<"do "<<l<<' '<<r<<' '<<mid<<' '<<'\n';
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}
/*
9 4
2 3 2 3 2 3 2 3 2

8 2
1 2 3 4 4 3 1 2 

*/

