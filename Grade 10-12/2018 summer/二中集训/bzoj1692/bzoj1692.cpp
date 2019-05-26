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
int n,m,book[100010],rank[100010],tmp[100010],sa[100010],a[100010];
void sort(){
	int i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	int i,k,cnt;m=127;
	for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
	sort();
	for(k=1,cnt=1;cnt<n;k<<=1,m=cnt){
		cnt=0;
		for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
		for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
		sort();swap(rank,tmp);
		rank[sa[1]]=cnt=1;
		for(i=2;i<=n;i++){
			rank[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])?cnt:++cnt);
		}
	}
//	for(i=1;i<=n;i++) cout<<rank[i]<<' '<<sa[i]<<'\n';
}
int len;char s[100010];
int main(){
	len=read();n=len*2+1;int i,l,r;
	for(i=1;i<=len;i++){
		s[i]=getchar();
		while(s[i]<'A'||s[i]>'Z') s[i]=getchar();
		a[i]=a[n-i+1]=(int)s[i];
//		cout<<"get i "<<i<<' '<<s[i]<<'\n';
	}
	a[len+1]=127;
	getsa();
	l=1;r=1;int cntl=0;
	for(i=1;i<=len;i++){
		if(rank[l]<rank[len+1+r]) putchar(s[l]),l++;
		else putchar(s[len-r+1]),r++;
		cntl++;if(cntl==80) putchar('\n'),cntl=0;
	}
}

