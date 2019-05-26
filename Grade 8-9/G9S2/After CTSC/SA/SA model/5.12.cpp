#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rank ddf
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
char s[100010];int n,m;
int a[100010],rank[100010],tmp[100010],book[100000],sa[100010],height[100010];
void bsort(){
//	cout<<"bsort "<<m<<endl;
	int i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	int i,cnt,k,j;m=127;
	for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
	bsort();
	for(k=1,cnt=1;cnt<n;m=cnt,k<<=1){
//		cout<<"now "<<cnt<<ends<<n<<ends<<m<<endl;
		cnt=0;
		for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
		for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
		bsort();
		swap(rank,tmp);
		rank[sa[1]]=cnt=1;
		for(i=2;i<=n;i++)
			rank[sa[i]]=(tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])?cnt:++cnt;
	}
	for(i=1;i<=n;height[rank[i]]=k,i++){
		for(k=k?k-1:k,j=sa[rank[i]-1];a[i+k]==a[j+k];k++);
	}
}
int main(){
	scanf("%s",s);int i;n=strlen(s);
	for(i=1;i<=n;i++) a[i]=(int)s[i-1];
	getsa();
	for(i=1;i<=n;i++) printf("%d ",sa[i]);
}
