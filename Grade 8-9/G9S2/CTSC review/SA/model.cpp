#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define sort ddf
#define rank vys
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
char s[1000010];int n,m;
int sa[1000010],rank[1000010],tmp[1000010],a[1000010],book[1000010];
void sort(){
	int i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	m=127;int i,k,cnt;
	for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
	sort();
	for(k=1,cnt=1;cnt<n;m=cnt,k<<=1){
		cnt=0;
		for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
		for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
		sort();
		swap(rank,tmp);
		rank[sa[1]]=cnt=1;
		for(i=2;i<=n;i++)
			rank[sa[i]]=(tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])?cnt:++cnt;
	}
}
int main(){
	scanf("%s",s);int i;n=strlen(s);
	for(i=1;i<=n;i++) a[i]=(int)s[i-1];
	getsa();
	for(i=1;i<=n;i++) printf("%d ",sa[i]);
}
