#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define rank DEEP_DARK_FANTASY
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
struct SuffixArray{
	int n,m,tmp[500010],sa[500010],rank[500010],a[500010],book[500010];
	void sort(){
		int i;
		for(i=0;i<=m;i++) book[i]=0;
		for(i=1;i<=n;i++) book[rank[i]]++;
		for(i=1;i<=m;i++) book[i]+=book[i-1];
		for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
	}
	void getsa(){
		m=1001;int i;
		for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
		sort();
		for(int k=1,cnt=1;cnt<n;m=cnt,k<<=1){
			cnt=0;
			for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
			for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
			sort();swap(tmp,rank);
			rank[sa[1]]=cnt=1;
			for(i=2;i<=n;i++)
				rank[sa[i]]=(tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])?cnt:++cnt;
		}
	}
}SA;
int n,m,s1[200010],s2[200010];
int main(){
	int i,j;
	n=read();
	for(i=0;i<n;i++) s1[i]=read();
	m=read();
	for(i=0;i<m;i++) s2[i]=read();
	for(i=0;i<n;i++) SA.a[i+1]=s1[i];
	SA.a[n+1]=1001;
	for(i=0;i<m;i++) SA.a[i+n+2]=s2[i];
	SA.a[n+m+2]=1001;
	SA.n=n+m+2;
	SA.getsa();
	i=1;j=n+2;
	while(i<=n&&j<=n+m+1){
		if(SA.rank[i]<SA.rank[j]) printf("%d ",SA.a[i]),i++;
		else printf("%d ",SA.a[j]),j++;
	}
	for(;i<=n;i++) printf("%d ",SA.a[i]);
	for(;j<=n+m+1;j++) printf("%d ",SA.a[j]);
	puts("");
}
